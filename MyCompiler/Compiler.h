#pragma once
#include "stdafx.h"

//最大保留字空间
const int kMaxReserve = 100;
//最大单词数量空间
const int kMaxWord = 100;
//单词的枚举变量定义
enum eSym {
	//notype
	NOTYPE = 0,
	//标识符
	ID,
	//无符号整数常量
	UNSIGNEDINT,
	//字符常量
	SINGLECHAR,
	//字符串常量
	STRING,
	//保留字：
	CONST, INT, CHAR, VOID, MAIN, IF, ELSE, WHILE, SWITCH, CASE, DEFAULT, SCANF, PRINTF, RETURN,
	//单字符
	PLUS, MINUS, STAR, DIV, LESS, MORE, SQ, DQ,

	COMMA, SEMI, ASSIGN, LBRACKET, RBRACKET, LBRACE, RBRACE, LPARENT, RPARENT, 
	//双字符
	LESSEQU, MOREEQU, EQU, NEQU
};

//声明union
typedef union {
	char c;
	int number;
	std::string *str;


} symVal;

typedef struct sym{
	symVal word;
	int id;
	std::string *output;
}symbol;

class Compiler
{
public:
	Compiler(char *path);
	void begin();
	~Compiler();

private:
	//文件流指针
	std::fstream file;
	//当前字符
	char c;
	//当前单词
	std::string sym;
	symbol word;
	//保留字集合
	std::string reserve[kMaxReserve];
	//单词标志输出数组，与枚举类型一一对应
	std::string wordOutput[kMaxWord];
	//初始化
	void initWordArray();
	void setup();

	//与错误处理有关的
	void error(int errodId);
	void skip();

	//与sym有关的
	void clearSym();
	void symAppend();
	int inSym();

	bool isEof();
	void nextChar();
	void retract();

	//跳过不处理
	void skipSpace();
	void skipNote();

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
	bool isWord();

	//处理sym
	int handleSym();
};

