#pragma once
#include "stdafx.h"
#include "token.h"
#include "errorHandler.h"
#include "warningHandler.h"
#include "symbolTab.h"
#include "midcode.h"
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

//标识符的类型  与种类分开
enum eRetType {INTRET = 7, CHARRET, VOIDRET, NOTTYPE };
//标识符的种类，分别是常量，简单变量，数组变量，函数，形式参数类型
enum eSymType {CONSTSYM, SIMPLESYM, ARRAYSYM, FUNCSYM, PARASYM};


typedef struct 
{
	std::string *name;
	//C++中枚举类型不能作为参数。。这里只能用int来表示
	eRetType returnType;
	eSymType symbolType;
	//对于数组，它表示数组的长度，对于函数，它表示参数的个数，对于常数，它表示这个常数的值，对于变量或者形式参数，目前设置为-1
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
	~Compiler();

private:
	//文件流指针
	std::fstream file;
	//当前字符
	char c;
	//当前单词
	std::string sym;
	token tok;
	//当前行数
	int lineCount ;

	//保留字集合
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
	void ifStatement(bool *returnflag, eRetType returntype);
	void caseStatement(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *nextlab);
	void caseTab(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab);
	void switchStatement(bool *returnflag, eRetType returntype);
	void whileStatement(bool *returnflag, eRetType returntype);
	void scanfStatement();
	void printfStatement();
	void returnStatement(bool *returnflag, eRetType returntype);
	void statement(bool *returnflag, eRetType returntype);
	void statementList(bool *returnflag, eRetType returntype);
	void varState();
	void comStatement(bool *returnflag, eRetType returntype);

	//处理错误
	//词法分析的错误
	std::vector<error*> errorList;
	std::string *errorMsgList[kMaxErrorType];
	void errorHandle(errorType errodId);
	void errorSetup();
	void errorPrint();

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
	//记录编译完的分函数的符号个数，这里分函数不包括最后的main
	int funcSymNum[kMaxFuncNum];
	//记录有多少个分函数
	int funcNum;
	//记录当前分函数的符号个数
	int currentFuncSymNum;
	//打印一个符号
	void printSym(symbol *sym);
	//进入一个函数时
	void inFunc();

	//常量区
	std::string *stringTab[kMaxStringNum];
	int stringNum ;

	void pushString(std::string *str);
	void genMessage(std::string *str, int num);

	//四元式相关
	void writeMidCode(midcode *code);
	//四元式文件
	std::fstream midFile;
	//四元式数组
	midcode* codes[kMaxMidCode];
	//数组指针
	int midindex;
	//保存一个四元式
	void pushMidCode(midop op, std::string *operand1, std::string *operand2, std::string *rst);
	//init
	void initMidCode();
	//label和临时变量需要有个生成函数,而且分别有个不断增长的量来维护
	void genTemp(std::string *temp);
	int temp;
	void genLabel(std::string *lab);
	int label;


};

