#pragma once
#include "stdafx.h"

//warningmsglist������������ƣ�ÿһ�ֶ�Ӧһ��������
const int kMaxWarningType = 100;

//warning��ö�ٶ���
enum warningType{
	//�ʷ�����
	NUMTOOBIG = 0, 

	//�������
	TOOMANYCASE,
};

//warning�Ľṹ��
typedef struct{
	int lineCount;
	warningType id;
	std::string *token;
}warning;

