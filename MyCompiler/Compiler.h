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
const int kMaxFuncSymbol = 1000;
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
const int kMaxBasicBlock = 2000;
//最大临时变量的数量
const int kMaxTemp = 1000;
//最多目标代码条数
const int kMaxMipsCodes = 10000;

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
	/*------------词法分析相关------------*/
	//文件流指针
	std::fstream file;
	//当前字符
	char c;
	//读下一个字符
	void nextChar();
	//让文件指针下一次读到的单词还是当前这个单词，并维护行数，即字符回溯
	void retract();
	//当前读入的字符集合
	std::string sym;
	//保存的当前,单词,具体定义见token.h
	token tok;
	//当前行数
	int lineCount ;
	//判断文件是否结束
	bool isEof();



	//保留字集合，因为要比较是不是保留字必须要一个个字符进行比较
	std::string reserve[kMaxReserve];
	//单词标志输出数组，与枚举类型一一对应
	std::string wordOutput[kMaxWord];
	////初始化单词类型的string输出，与枚举一一对应，主要用于一开始的词法分析的单词输出，之后没有实际意义
	void initWordArray();
	//建立保留字表，便于得到当前单词是不是一个保留字
	void setup();
	//与sym有关的
	//清空sym字符串，便于输入新的单词
	void clearSym();
	//把当前字符添加到当前字符串数组
	void symAppend();
	//表示读入一个新的单词，保存在tok中，为语法分析所使用
	void inSym();
	//词法分析中所需要用到的判断：
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
	//判断当前字符是否在给定的文法范围内
	bool isInStringRange();

	//判断标识符或者保留字是否相等
	bool isIdEqual(std::string id1, std::string id2);
	//专门用于处理当前是保留字还是标识符
	void handleSym();

	//跳过空白字符不处理，注意维护lineCount
	void skipSpace();



	/*----------------语法分析相关----------------*/
	//语法成分：
	//<整数>
	void int_(int *value);
	//<常量定义>
	void constDef();
	//<常量声明>
	void constState();
	//<常量>
	void constant(int *value, eRetType *rettype);
	//<参数表>
	void varParaList(symbol *sym);
	//<因子>
	void factor(eRetType *resulttype, std::string *operand);
	//<项>
	void term(eRetType *resulttype, std::string *operand);
	//<表达式>
	void expression(eRetType *type, std::string *operand);
	//<变量定义处理>
	void varDef(eRetType rettype, std::string *name);
	//<声明头部>
	void decHead(eRetType *rettype, std::string **name);
	//<参数>
	void para(symbol *sym);
	//<无参函数定义>
	void noParaFuncDef(symbol *sym);
	//<有参函数定义>
	void haveParaFuncDef(symbol *sym);
	//<非main的void类型的函数定义>
	void notMainVoidFuncDef();
	//<main函数定义>
	void mainDef();
	//<可能以函数定义开始的程序>
	void beginWithFunc();
	//<可能以变量声明开始的程序>
	void beginWithVar();
	//<程序>
	void program();
	//<条件>
	void condition(std::string *label);
	//<条件语句>
	void ifStatement(bool *returnflag, eRetType returntype, std::string *name);
	//<情况子语句>
	void caseStatement(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *nextlab, int *caseconst, std::string *name);
	//<情况表>
	void caseTab(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *name);
	//<情况语句>
	void switchStatement(bool *returnflag, eRetType returntype, std::string *name);
	//<循环语句>
	void whileStatement(bool *returnflag, eRetType returntype, std::string *name);
	//<读语句>
	void scanfStatement();
	//<写语句>
	void printfStatement();
	//<返回语句>
	void returnStatement(bool *returnflag, eRetType returntype, std::string *name);
	//<语句>
	void statement(bool *returnflag, eRetType returntype, std::string *name);
	//<语句列>
	void statementList(bool *returnflag, eRetType returntype, std::string *name);
	//<变量声明>
	void varState();
	//<复合语句>
	void comStatement(bool *returnflag, eRetType returntype, std::string *name);

	//判断单词是否在给定的范围内
	bool isInRange(const tokenType range[], const int size);




	/*-----------------错误处理相关-----------------*/
	//处理错误
	std::vector<error*> errorList;
	std::string *errorMsgList[kMaxErrorType];
	void errorHandle(errorType errodId);
	void errorSetup();
	void errorPrint();
	//跳读
	void skip(const tokenType follow[], const int size);
	void skip(tokenType toktype);
	//根据错误的类型跳读
	void errorSkip(errorType id);
	//处理警告
	std::vector<warning*> warningList;
	std::string *warningMsgList[kMaxWarningType];
	void warningHandle(warningType warningId);
	void warningSetup();
	void warningPrint();

	/*----------------符号表相关----------------*/
	//符号表
	symbol *symTab[kMaxSymbol];
	//hash表
	int symHash[kMaxHash];
	//分程序索引
	int index;
	//指示当前符号表的第一个空闲位置
	int top;
	//指示当前变量/常量该存储的位置
	int address;
	//保存全局变量分配区的分配情况
	int globalAddress;
	//符号表的一些初始化
	void initSymTab();
	//查找,根据local参数是局部查找还是全局查找
	bool find(std::string *name, symbol **sym, bool local);
	//插入该符号
	symbol* push(std::string *name, eRetType returntype, eSymType symboltype, int feature, int decline);

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
	//进入一个函数时
	void inFunc();
	//删除符号表直到this->index的前一个，并维护this->index this->top，注意释放空间,还要维护hash表
	void pop();
	//字符串数组，记录可能用到的字符串
	std::string *stringTab[kMaxStringNum];
	int stringNum ;
	//需要一个数组记录所有的字符串的相对偏移,如果不能用.asciiz的话，到时候根据字符串的下标，得到其起始地址直接输出也可以
	int stringAddress[kMaxStringNum];
	void pushString(std::string *str, int *strindex);
	void genMessage(std::string *str, int num);

	//打印一个符号
	void printSym(symbol *sym);
	//符号表打印文件
	std::fstream symtabFile;
	//打印符号表到文件
	void writeSymtoFile();



	/*----------------中间代码相关----------------*/
	//把一个中间代码写到指定的文件中
	void writeMidCode(midcode *code, std::fstream &tofile);
	//把一个中间代码控制台输出
	void writeMidCode(midcode *code);
	//把整个四元式写入文件
	void writeMidCodetoFile(std::fstream &tofile);
	//四元式数组
	midcode* codes[kMaxMidCode];
	//四元式数量
	int midindex;
	//保存一个四元式
	void pushMidCode(midop op, std::string *operand1, std::string *operand2, std::string *rst);
	//在语法分析时生成中间代码需要一些初始化
	void initMidCode();
	//label和临时变量需要有个生成函数,而且分别有个不断增长的量来维护
	void genTemp(std::string *temp);
	int temp;
	void genLabel(std::string *lab);
	int label;
	//优化前四元式文件
	std::fstream midFileBefore;
	//优化后四元式的文件
	std::fstream midFileAfter;

	/*------------------优化相关------------------*/
	//记录该句四元式是否是某一个基本块的开始，如果已经有记录，那么就不要重复记录，防止出现长度为0的基本块
	bool blockBeginFlag[kMaxMidCode];
	//记录每个基本块的开始的四元式的index
	int blockBegin[kMaxBasicBlock];
	//记录数量
	int blockIndex;
	//分成基本块
	void divideToBlock();
	//初始化基本块之间的连接关系
	void initBlockConnect();
	//划分基本块后的情况的输出文件
	std::fstream blockFile;
	//记录每个基本块的信息
	Block* blockArray[kMaxBasicBlock];
	//根据label，返回其所在的基本块index，在小优化时会用到
	void findLabel(std::string *label, int *index);
	//优化一开始的初始化
	void initOptimize();
	//把基本块的信息输出到基本块文件中
	void writeBlockToFile();
	//一些小的优化
	void smallOptimize();

	//数据流分析输出文件：
	std::fstream dataAnalysisFile;
	//数据流分析方法
	void dataFlowAnalysis();
	//需要一个记录每个函数的基本块开始情况的数据结构
	int funcBlockBegin[kMaxFuncNum];
	//需要一个方法得到这个局部变量在函数表中的下标
	void getIndexInTab(int *index, int funcref, std::string *name);
	void findNodeInTab(ListNode *nodelist[], int length, std::string *name, ListNode **x);
	//这里设置一个成员变量，用于记录每个基本块的out集合，便于dag图删去不需要的临时变量
	bool **outData;
	bool canAdd(bool flag[], Node *x, Node* midqueue[], int length, Node *dag[]);

	//DAG图方法
	void DAG();
	//dag图以及小的优化的信息
	std::fstream dagFile;
	/*--------------------目标代码相关--------------------*/
	//目标代码优化前文件
	std::fstream objectFileBefore;
	//目标代码优化后文件
	std::fstream objectFileAfter;
	//目标代码数组
	std::string *mipsCodes[kMaxMipsCodes];
	//下标
	int mipsIndex;
	//初始化目标代码生成
	void objectInit();
	//初始化寄存器池，此时寄存器池只是记录当前使用该寄存器的变量名称
	void regInit();
	//初始化字符串定义
	void initAscii();
	//生成目标代码
	void generate();
	//生成一条指令
	void generateOrder(std::string *order, std::string *rd, std::string *rs, std::string *rt);
	void generateOrder(std::string *order, std::string *rs, int baseaddress, std::string *rt);
	void generateOrder(std::string *order, std::string *rs, int num);
	void generateOrder(std::string *order, std::string *rd, std::string *rt, int imme);
	void generateOrder(std::string *order, std::string *rs, std::string *label);
	void generateOrder(std::string *order, std::string *target);
	void generateOrder(std::string *order);
	//把这个命令保存到目标代码数组中
	void pushOrder(std::string *order);
	//把当前目标代码写到相应的文件中
	void writeMipsOrderToFile(std::fstream &tofile);

	//函数开始
	void funcBegin(std::string *name);
	//当前编译的函数在函数表中的位置
	int currentRef;
	//生成label
	void genMipsLabel(std::string *label);
	//寻找标识符地址
	void findSym(std::string *name, symbol **resultsym, bool *global);
	//loadword
	void getUseReg(std::string *rs, std::string *reg);
	//storeword
	void getResultReg(std::string *rd, std::string *reg);
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



	


};

