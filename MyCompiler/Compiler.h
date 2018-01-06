#pragma once
#include "stdafx.h"
#include "token.h"
#include "errorHandler.h"
#include "warningHandler.h"
#include "symbolTab.h"
#include "midcode.h"
#include "objectCode.h"
#include "optimization.h"
//最大保留字空间
const int kMaxReserve = 100;
//最大单词数量空间
const int kMaxWord = 100;
//最大符号表空间
const int kMaxSymbol = 5000;
//分函数最大符号表空间
const int kMaxFuncSymbol = 500;
//最多有多少个函数
const int kMaxFuncNum = 500;
//hash索引最大值
const int kMaxHash = 4096;
//函数参数的个数最大值
const int kMaxParaNum = 20;
//四元式最大数量
const int kMaxMidCode = 5000;
//最大常量字符串数
const int kMaxStringNum = 1000;
//最大基本快的数量
const int kMaxBasicBlock = 1000;
//最大临时变量的数量
const int kMaxTemp = 1000;

//标识符的类型  与种类分开
enum eRetType {INTRET = 7, CHARRET, VOIDRET, NOTTYPE };
//标识符的种类，分别是常量，简单变量，数组变量，函数，参数类型
enum eSymType {CONSTSYM, SIMPLESYM, ARRAYSYM, FUNCSYM, PARASYM};


typedef struct 
{
	std::string *name;
	//C++中枚举类型不能作为参数。。这里只能用int来表示
	eRetType returnType;
	eSymType symbolType;
	//对于数组，它表示数组的长度，对于函数，它表示参数的个数，对于常数，它表示这个常数的值，对于变量或者形式参数或者局部变量，目前设置为-1
	int feature;
	//对于函数，ref记录了它在分函数表中的位置,当然main没有这个ref
	int ref;
	//记录下声明的行数，便于报错和调试
	int decLine;
	//记录下使用的行数，便于报错和调试
	std::vector<int> *useLine;
	//因为使用hash分离链表法，所以这里记录冲突项的位置，默认为-1
	int link;
	//关于函数还必须要获得它的参数的个数和类型，所以这里专门给函数开一个数组，规定最大参数个数
	eRetType paraList[kMaxParaNum];
	//所处的地址
	int address;
	//记录下这个局部变量在这个函数的每个基本块里的使用情况
	bool flag[kMaxBasicBlock];
	//记录下这个标识符对应的寄存器，仅仅对临时变量和简单变量以及参数变量有效
	int regIndex;
}symbol;

unsigned int BKDRHash(char *str);

class Compiler
{
public:
	Compiler(char *path);
	void begin();
	//打印当前符号表信息，便于调试
	void printSymTab();
	//辅助函数 int to string
	void int2string(std::string *s, int value);
	//统一转换为小写
	void str2Lower(std::string *oldstr, std::string *newstr);
	~Compiler();

private:
	//文件流指针
	std::fstream file;
	//当前字符
	char c;
	//当前读入的字符集合
	std::string sym;
	//inSym()执行后，保存的当前 单词
	token tok;
	//当前行数
	int lineCount ;

	//保留字集合，因为要比较是不是保留字必须要一个个字符进行比较
	std::string reserve[kMaxReserve];
	//单词标志输出数组，与枚举类型一一对应
	std::string wordOutput[kMaxWord];

	//初始化
	void initWordArray();
	void setup();

	//与错误处理有关的
	void skip();

	//与sym有关的
	void clearSym();
	void symAppend();
	void inSym();

	bool isEof();
	void nextChar();
	void retract();

	//跳过不处理
	void skipSpace();


	//读一类
	void readUntilNotLetterOrNum();

	//判断
	//判断单个字符
	bool isSpace();
	bool isTab();
	bool isNewLine();
	bool isSq();
	bool isDq();
	bool isZero();
	bool isLess();
	bool isMore();
	bool isEqu();
	//Em表示感叹号
	bool isEm();

	bool isLetter();
	bool isNumber();
	bool isPlusOrMinus();
	bool isStarOrDiv();

	bool isInStringRange();

	//判断标识符或者保留字是否相等
	bool isIdEqual(std::string id1, std::string id2);
	//处理sym
	void handleSym();


	//语法分析相关：
	//判断
	bool isInRange(const tokenType range[], int size);
	//语法成分：
	void int_(int *value);
	void constDef();
	void constState();
	void constant(int *value, eRetType *rettype);
	void varParaList(symbol *sym);
	void factor(eRetType *resulttype, std::string *operand);
	void term(eRetType *resulttype, std::string *operand);
	void expression(eRetType *type, std::string *operand);
	void varDef(eRetType rettype, std::string *name);
	void decHead(eRetType *rettype, std::string **name);
	void para(symbol *sym);
	void noParaFuncDef(symbol *sym);
	void haveParaFuncDef(symbol *sym);
	void notMainVoidFuncDef();
	void mainDef();
	void beginWithFunc();
	void beginWithVar();
	void program();
	void condition(std::string *label);
	void ifStatement(bool *returnflag, eRetType returntype, std::string *name);
	void caseStatement(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *nextlab, int *caseconst, std::string *name);
	void caseTab(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *name);
	void switchStatement(bool *returnflag, eRetType returntype, std::string *name);
	void whileStatement(bool *returnflag, eRetType returntype, std::string *name);
	void scanfStatement();
	void printfStatement();
	void returnStatement(bool *returnflag, eRetType returntype, std::string *name);
	void statement(bool *returnflag, eRetType returntype, std::string *name);
	void statementList(bool *returnflag, eRetType returntype, std::string *name);
	void varState();
	void comStatement(bool *returnflag, eRetType returntype, std::string *name);

	//处理错误
	std::vector<error*> errorList;
	std::string *errorMsgList[kMaxErrorType];
	void errorHandle(errorType errodId);
	void errorSetup();
	void errorPrint();
	//跳读
	void errorSkip(tokenType id);

	//处理警告
	std::vector<warning*> warningList;
	std::string *warningMsgList[kMaxWarningType];
	void warningHandle(warningType warningId);
	void warningSetup();
	void warningPrint();

	//符号表相关
	symbol *symTab[kMaxSymbol];
	int symHash[kMaxHash];
	//分程序索引
	int index;
	//指示当前符号表的第一个空闲位置
	int top;
	//指示当前变量/常量该存储的位置
	int address;
	//保存全局变量分配区的分配情况
	int globalAddress;

	void initSymTab();
	//查找,根据local参数是局部查找还是全局查找
	bool find(std::string *name, symbol **sym, bool local);
	//插入
	symbol* push(std::string *name, eRetType returntype, eSymType symboltype, int feature, int decline);

	//删除符号表直到this->index的前一个，并维护this->index this->top，注意释放空间,还要维护hash表
	void pop();
	//为了以后便于生成目标代码，这里必须要把编译完的函数的符号信息记录下来
	symbol **funcSymTab[kMaxFuncSymbol];
	//记录编译完的分函数的符号个数
	int funcSymNum[kMaxFuncNum];
	//记录分函数的所需最大地址
	int funcMaxAddress[kMaxFuncNum];
	//记录有多少个分函数
	int funcNum;
	//记录当前分函数的符号个数
	int currentFuncSymNum;
	//打印一个符号
	void printSym(symbol *sym);
	//进入一个函数时
	void inFunc();
	//符号表打印文件
	std::fstream symtabFile;
	//打印符号表到文件
	void writeSymtoFile();

	//常量区
	std::string *stringTab[kMaxStringNum];
	int stringNum ;
	//需要一个数组记录所有的字符串的相对偏移,如果不能用.asciiz的话，到时候根据字符串的下标，得到其起始地址直接输出也可以
	int stringAddress[kMaxStringNum];
	//需要一个来记录字符串占用了多少空间
	int strAddress;
	void pushString(std::string *str);
	void genMessage(std::string *str, int num);

	//四元式相关
	void writeMidCode(midcode *code, std::fstream &tofile);
	//专门作为控制台输出
	void writeMidCode(midcode *code);
	//把整个四元式写入文件
	void writeMidCodetoFile(std::fstream &tofile);
	//四元式文件
	std::fstream midFile;
	//四元式数组
	midcode* codes[kMaxMidCode];
	//数组指针
	int midindex;
	//保存一个四元式
	void pushMidCode(midop op, std::string *operand1, std::string *operand2, std::string *rst, bool optimize);
	//init
	void initMidCode();
	//label和临时变量需要有个生成函数,而且分别有个不断增长的量来维护
	void genTemp(std::string *temp);
	int temp;
	void genLabel(std::string *lab);
	int label;

	//优化后四元式的文件
	std::fstream optimizeFile;
	//优化后四元式数组
	midcode* optimizeCodes[kMaxMidCode];
	int optimizeMidIndex;

	//优化相关
	//分成基本块
	void divideToBlock();
	//每个基本块的数据结构
	Block* blockArray[kMaxBasicBlock];
	//根据label，返回其所在的基本块index
	void findLabel(std::string *label, int *index);
	//优化一开始的初始化
	void initOptimize();
	void printBlock();
	//一些小的优化
	void smallOptimize();
	//初始化基本块之间的连接关系
	void initBlockConnect();
	//输出连接关系
	void printBlockConnect();
	//数据流分析
	void dataFlowAnalysis();
	//需要一个记录每个函数的基本块开始情况的数据结构
	int funcBlockBegin[kMaxFuncNum];
	//需要一个方法得到这个局部变量在函数表中的下标
	void getIndexInTab(int *index, int funcref, std::string *name);
	void findNodeInTab(ListNode *nodelist[], int length, std::string *name, ListNode **x);
	

	//这里设置一个成员变量，用于记录每个基本块的out集合，便于dag图删去不需要的临时变量
	//这个在活跃变量分析时设置
	bool **outData;
	bool canAdd(bool flag[], Node *x, Node* midqueue[], int length, Node *dag[]);
	void DAG();

	bool blockBeginFlag[kMaxBasicBlock];
	int blockBegin[kMaxBasicBlock];
	int blockIndex;
	//划分基本块后的情况的输出文件
	std::fstream blockFile;
	int tempMap[kMaxTemp];


	//目标代码生成
	std::fstream objectFile;
	//初始化寄存器池
	void objectInit();
	//初始化字符串定义
	void initAscii();
	//生成目标代码
	void generate();
	//存全局常量
	void initConstAndVar(symbol *sym, int initaddress);
	//当前占用的空间
	int mipsAddress;
	//生成一条指令
	void generateOrder(std::string *order, std::string *rd, std::string *rs, std::string *rt);
	void generateOrder(std::string *order, std::string *rs, int baseaddress, std::string *rt);
	void generateOrder(std::string *order, std::string *rs, int num);
	void generateOrder(std::string *order, std::string *rd, std::string *rt, int imme);
	void generateOrder(std::string *order, std::string *rs, std::string *label);
	void generateOrder(std::string *order, std::string *target);
	void generateOrder(std::string *order);
	void printOrder(std::string *order);
	//函数的开始
	void funcBegin(std::string *name);
	//当前编译的函数在函数表中的位置
	int currentRef;
	//生成label
	void genMipsLabel(std::string *label);
	//寻找标识符地址
	void findSym(std::string *name, symbol **resultsym, bool *global);
	//loadword
	void loadReg(std::string *rs, std::string *reg);
	//storeword
	void storeReg(std::string *rd, std::string *reg);
	//writeback
	void writeBack(std::string *rd, std::string *reg);
	//处理跳转
	void handleBranch(midcode *code);
	//处理无条件跳转
	void handleGoto(std::string *label);
	//处理实参
	void handleRealPara(std::string *para);
	//处理数组赋给其他值
	void handleRarray(midcode *code);
	//处理函数调用
	void handleCall(std::string *name);
	//处理函数结束
	void handleRet(std::string *name);
	//处理运算
	void handleAdd(midcode *code);
	void handleSub(midcode *code);
	void handleMulOrDiv(midcode *code);

	//处理输入
	void handleScanf(midcode *code);
	//处理输出
	void handlePrintf(midcode *code);
	//处理结束
	void handleExit();
	//处理其他值给数组
	void handleLarray(midcode *code);

	//判断操作数的类型
	//判断这个操作数是不是一个数字(- 或者是 数字开头)
	bool isOperandNumber(std::string *operand);
	//判断这个操作数是不是一个临时变量
	bool isOperandTemp(std::string *operand);
	//判断这个操作数是不是一个返回值
	bool isOperandRet(std::string *operand);
	//判断是不是一个标识符
	bool isOperandId(std::string *operand);

	//根据kMaxRegAvailable 的数量决定的可用寄存器的数量，对于每一个，如果是0，那么表示未被分配，如果不是0，那么表示被对应的变量分配
	std::string *allReg[kMaxRegAvailable];
	
	void allocReg(std::string *operand, std::string *reg);
	//保存函数调用之前的寄存器的使用情况，便于之后恢复
	std::string *regStack[kMaxRegAvailable];
	void saveReg();
	void loadReg();



	


};

