#include "warningHandler.h"
#include "Compiler.h"




//不同类型的warning对应的输出语句，与enum一一对应

const char *NUMTOOBIGMSG = "无符号整数常量超过最大位数";

const char *TOOMANYCASEMSG = "case超出了最大个数上限";

/*
创建相应的warning结构体
并添加到this->warningList中
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
	//词法
	this->warningMsgList[NUMTOOBIG]		=	new std::string(NUMTOOBIGMSG);

	//语义
	this->warningMsgList[TOOMANYCASE]	=	new std::string(TOOMANYCASEMSG);
}

void Compiler:: warningPrint()
{
	//不同类型的warning对应的输出语句，与enum一一对应
	this->warningSetup();
	for(unsigned int i = 0; i < this->warningList.size(); ++i)
	{
		warning *war = warningList[i];
		std::stringstream msg = std::stringstream();
		msg << "line:" << war->lineCount << "\t" << "在" << *war->token << "的附近:" << *(this->warningMsgList[war->id]) << "\n";
		std::cout << msg.str() ;
	}
}
