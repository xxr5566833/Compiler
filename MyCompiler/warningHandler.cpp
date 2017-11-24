#include "warningHandler.h"
#include "Compiler.h"




//��ͬ���͵�warning��Ӧ�������䣬��enumһһ��Ӧ

const char *NUMTOOBIGMSG = "�޷������������������λ��";

/*
������Ӧ��warning�ṹ��
����ӵ�this->warningList��
*/
void Compiler:: warningHandle(warningType id)
{
	warning *war = new warning();
	war->id = id;
	war->lineCount = this->lineCount;
	war->token = new std::string(this->sym);

	this->warningList.push_back(war);
	
}

void Compiler:: warningSetup()
{
	this->warningMsgList[NUMTOOBIG] = new std::string(NUMTOOBIGMSG);
}

void Compiler:: warningPrint()
{
	//��ͬ���͵�warning��Ӧ�������䣬��enumһһ��Ӧ
	this->warningSetup();
	for(unsigned int i = 0; i < this->warningList.size(); ++i)
	{
		warning *war = warningList[i];
		std::string *msg = new std::string();
		*msg += war->lineCount + ": ";
		*msg += *(war->token) + " ";
		*msg += *(this->warningMsgList[war->id]) + "\n";
		std::cout << *msg ;
		delete msg;
	}
}
