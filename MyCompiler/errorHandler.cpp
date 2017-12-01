#include "errorHandler.h"
#include "Compiler.h"

//һЩ�����������˵��

const char *SQMISMATCHMSG = "\' �޷�ƥ��";

const char *DQMISMATCHMSG = "\" �޷�ƥ��";

const char *INVALIDCHARMSG = "\'��\'�а�Χ���ַ��������ķ��Ĺ涨��Χ���ķ��涨�ַ��ķ�Χ�����ڢټӷ�������ڳ˷����������ĸ������";

const char *ONLYEMMSG = "!����û�г���=";

const char *INVALIDVTMSG = "�������ķ��涨����ķ��ս����";


const char *NOTUNSIGNEDINTMSG = "Ӧ����һ����0���޷���������";

const char *NOTASSIGNMSG = "Ӧ����һ�� =";

const char *NOTINTMSG = "����һ������";

const char *NOTIDMSG = "����һ����ʶ��";

const char *NOTSINGLECHARMSG = "����һ���ַ�";

const char *NOTINTORCHARMSG = "���� int �� char";

const char *NOTSEMIMSG = "����һ���ֺ�;";

const char *NOTRBRACKETMSG = "����һ�� ��������] ";

const char *NOTRPARENTMSG = "����һ�� ��С����)";

const char *NOTFACTORMSG = "����һ�� <����>�Ŀ�ʼ���� ��������<��ʶ��> ( + - <�ַ�> 0 �� �޷������� ����֮һ";

const char *NOTLBRACEMSG = "����һ�� �������{";

const char *NOTMAINMSG = "���� main������";

const char *NOTLPARENTMSG = "���� ��С����(";

const char *NOTSTATEMENTMSG = "���� һ�����";

const char *NOTELSEMSG = "ȱ�� else";

const char *NOTCONSTANTMSG = "���� ����";

const char *NOTCOLONMSG = "���� ð��:";

const char *NOTCASEMSG = "ȱ�� case";

const char *NOTRBRACEMSG = "ȱ�� �Ҵ�����}";

const char *NOTVARDEFMSG = "���Ǳ����������ȷ���� [ ; �� ,";
 
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