#pragma once
#include "stdafx.h"
//��������������
const int kMaxErrorType = 100;


//��������ö�ٱ�������
enum errorType{
	//�ʷ�������
	 SQMISMATCH = 0, DQMISMATCH, INVALIDCHAR, ONLYEM, INVALIDVT
};
//����Ľṹ����������
typedef struct {
	errorType id;
	std::string *token;
	int lineCount;
}error;
