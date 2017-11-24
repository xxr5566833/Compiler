#include "errorHandler.h"
#include "Compiler.h"

//一些错误输出语句的说明

const char *SQMISMATCHMSG = "\' 无法匹配";

const char *DQMISMATCHMSG = "\" 无法匹配";

const char *INVALIDCHARMSG = "\'和\'中包围的字符不符合文法的规定范围，文法规定字符的范围仅限于①加法运算符②乘法运算符③字母④数字";

const char *ONLYEMMSG = "!后面没有出现=";

const char *INVALIDVTMSG = "出现了文法规定以外的非终结符！";

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
	errorMsgList[SQMISMATCH] = new std::string(SQMISMATCHMSG);
	errorMsgList[DQMISMATCH] = new std::string(DQMISMATCHMSG);
	errorMsgList[INVALIDCHAR] = new std::string(INVALIDCHARMSG);
	errorMsgList[ONLYEM] = new std::string(ONLYEMMSG);
	errorMsgList[INVALIDVT] = new std::string(INVALIDVTMSG);
}

void Compiler:: errorPrint()
{
	this->errorSetup();
	int s = this->errorList.size();
	for(unsigned int i = 0; i < this->errorList.size(); ++i)
	{
		warning *err = warningList[i];
		std::string *msg = new std::string();
		*msg += err->lineCount + ": ";
		*msg += "error " + err->id;
		*msg += ": ";
		*msg += *(err->token) + " ";
		*msg += *(this->warningMsgList[err->id]) + "\n";
		std::cout << *msg ;
		delete msg;
	}
}