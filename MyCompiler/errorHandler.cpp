#include "errorHandler.h"
#include "Compiler.h"

//һЩ�����������˵��

const char *SQMISMATCHMSG = "\' �޷�ƥ��";

const char *DQMISMATCHMSG = "\" �޷�ƥ��";

const char *INVALIDCHARMSG = "\'��\'�а�Χ���ַ��������ķ��Ĺ涨��Χ���ķ��涨�ַ��ķ�Χ�����ڢټӷ�������ڳ˷����������ĸ������";

const char *ONLYEMMSG = "!����û�г���=";

const char *INVALIDVTMSG = "�������ķ��涨����ķ��ս����";

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