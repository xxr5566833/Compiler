#pragma once
#include "Compiler.h"

//������һ�μĴ����ķ���״̬���ں�����ʼʱ���棬�ں�������ʱ�ָ�����mips�Ĵ����ı���ͻָ�һ��
typedef struct{
	int tempReg[9];
	int tempRegIndex ;
	std::string *symReg[8];
	int symRegIndex;
}regAllocStack;
