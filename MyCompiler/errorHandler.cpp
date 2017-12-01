#include "errorHandler.h"
#include "Compiler.h"

//一些错误输出语句的说明

const char *SQMISMATCHMSG = "\' 无法匹配";

const char *DQMISMATCHMSG = "\" 无法匹配";

const char *INVALIDCHARMSG = "\'和\'中包围的字符不符合文法的规定范围，文法规定字符的范围仅限于①加法运算符②乘法运算符③字母④数字";

const char *ONLYEMMSG = "!后面没有出现=";

const char *INVALIDVTMSG = "出现了文法规定以外的非终结符！";


const char *NOTUNSIGNEDINTMSG = "应该是一个非0的无符号整数！";

const char *NOTASSIGNMSG = "应该有一个 =";

const char *NOTINTMSG = "不是一个整数";

const char *NOTIDMSG = "不是一个标识符";

const char *NOTSINGLECHARMSG = "不是一个字符";

const char *NOTINTORCHARMSG = "不是 int 或 char";

const char *NOTSEMIMSG = "不是一个分号;";

const char *NOTRBRACKETMSG = "不是一个 右中括号] ";

const char *NOTRPARENTMSG = "不是一个 右小括号)";

const char *NOTFACTORMSG = "不是一个 <因子>的开始单词 ，即不是<标识符> ( + - <字符> 0 或 无符号整数 其中之一";

const char *NOTLBRACEMSG = "不是一个 左大括号{";

const char *NOTMAINMSG = "不是 main保留字";

const char *NOTLPARENTMSG = "不是 左小括号(";

const char *NOTSTATEMENTMSG = "不是 一条语句";

const char *NOTELSEMSG = "缺少 else";

const char *NOTCONSTANTMSG = "不是 常量";

const char *NOTCOLONMSG = "不是 冒号:";

const char *NOTCASEMSG = "缺少 case";

const char *NOTRBRACEMSG = "缺少 右大括号}";

const char *NOTVARDEFMSG = "不是变量定义的正确符号 [ ; 或 ,";
 
void Compiler:: errorHandle(errorType id)
{
	std::cout << this->sym << std::endl;
	error *err = new error();
	err->id = id;
	err->lineCount = this->lineCount;
	err->token = new std::string(this->sym);

	this->errorList.push_back(err);
}

void Compiler:: errorSetup()
{
	this->errorMsgList[SQMISMATCH]			=	new std::string(SQMISMATCHMSG);
	this->errorMsgList[DQMISMATCH]			=	new std::string(DQMISMATCHMSG);
	this->errorMsgList[INVALIDCHAR]			=	new std::string(INVALIDCHARMSG);
	this->errorMsgList[ONLYEM]				=	new std::string(ONLYEMMSG);
	this->errorMsgList[INVALIDVT]			=	new std::string(INVALIDVTMSG);
	this->errorMsgList[NOTUNSIGNEDINT]		=	new std::string(NOTUNSIGNEDINTMSG);
	this->errorMsgList[NOTASSIGN]			=	new std::string(NOTASSIGNMSG);
	this->errorMsgList[NOTINT]				=	new std::string(NOTINTMSG);
	this->errorMsgList[NOTID]				=	new std::string(NOTIDMSG);
	this->errorMsgList[NOTSINGLECHAR]		=	new std::string(NOTSINGLECHARMSG);
	this->errorMsgList[NOTINTORCHAR]		=	new std::string(NOTINTORCHARMSG);
	this->errorMsgList[NOTSEMI]				=	new std::string(NOTSEMIMSG);
	this->errorMsgList[NOTRBRACKET]			=	new std::string(NOTRBRACKETMSG);
	this->errorMsgList[NOTRPARENT]			=	new std::string(NOTRPARENTMSG);
	this->errorMsgList[NOTFACTOR]			=	new std::string(NOTFACTORMSG);
	this->errorMsgList[NOTLBRACE]			=	new std::string(NOTLBRACEMSG);
	this->errorMsgList[NOTMAIN]				=	new std::string(NOTMAINMSG);
	this->errorMsgList[NOTLPARENT]			=	new std::string(NOTLPARENTMSG);
	this->errorMsgList[NOTSTATEMENT]		=	new std::string(NOTSTATEMENTMSG);
	this->errorMsgList[NOTELSE]				=	new std::string(NOTELSEMSG);	
	this->errorMsgList[NOTCONSTANT]			=	new std::string(NOTCONSTANTMSG);
	this->errorMsgList[NOTCOLON]			=	new std::string(NOTCOLONMSG);
	this->errorMsgList[NOTCASE]				=	new std::string(NOTCASEMSG);
	this->errorMsgList[NOTRBRACE]			=	new std::string(NOTRBRACEMSG);
	this->errorMsgList[NOTVARDEF]			=	new std::string(NOTVARDEFMSG);
}

void Compiler:: errorPrint()
{
	this->errorSetup();
	int s = this->errorList.size();
	for(unsigned int i = 0; i < this->errorList.size(); ++i)
	{
		error *err = errorList[i];
		std::string *msg = new std::string();
		char linecount[10];
		sprintf(linecount, "%d", err->lineCount);
		*msg += (std::string(linecount) + ": ");
		*msg += "error ";
		char id[10];
		sprintf(id, "%d", err->id);
		*msg += id;
		*msg += ": ";
		*msg += *(err->token) + " ";
		*msg += *(this->errorMsgList[err->id]) + "\n";
		std::cout << *msg ;
		delete msg;
	}
}