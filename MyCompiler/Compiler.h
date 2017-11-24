#pragma once
#include "stdafx.h"
#include "token.h"
#include "errorHandler.h"
#include "warningHandler.h"
//最大保留字空间
const int kMaxReserve = 100;
//最大单词数量空间
const int kMaxWord = 100;

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

	//判断标识符或者保留字是否相等
	bool isIdEqual(std::string id1, std::string id2);



	//处理sym
	void handleSym();

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
};

