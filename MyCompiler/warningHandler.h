#pragma once
#include "stdafx.h"

//warningmsglist������������ƣ�ÿһ�ֶ�Ӧһ��������
const int kMaxWarningType = 100;

//warning��ö�ٶ���
enum warningType{
	NUMTOOBIG = 0, 
};

//warning�Ľṹ��
typedef struct{
	int lineCount;
	warningType id;
	std::string *token;
}warning;

