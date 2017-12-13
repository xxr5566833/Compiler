#include "warningHandler.h"
#include "Compiler.h"




//��ͬ���͵�warning��Ӧ�������䣬��enumһһ��Ӧ

const char *NUMTOOBIGMSG = "�޷������������������λ��";

const char *TOOMANYCASEMSG = "case����������������";

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
	//�ʷ�
	this->warningMsgList[NUMTOOBIG]		=	new std::string(NUMTOOBIGMSG);

	//����
	this->warningMsgList[TOOMANYCASE]	=	new std::string(TOOMANYCASEMSG);
}

void Compiler:: warningPrint()
{
	//��ͬ���͵�warning��Ӧ�������䣬��enumһһ��Ӧ
	this->warningSetup();
	for(unsigned int i = 0; i < this->warningList.size(); ++i)
	{
		warning *war = warningList[i];
		std::stringstream msg = std::stringstream();
		msg << "line:" << war->lineCount << "\t" << "��" << *war->token << "�ĸ���:" << *(this->warningMsgList[war->id]) << "\n";
		std::cout << msg.str() ;
	}
}
