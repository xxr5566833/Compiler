#pragma once
#include "stdafx.h"
//最大错误类型限制
const int kMaxErrorType = 100;


//错误类型枚举变量声明
enum errorType{
	//词法分析的
	 SQMISMATCH = 0, DQMISMATCH, INVALIDCHAR, ONLYEM, INVALIDVT
};
//错误的结构体类型声明
typedef struct {
	errorType id;
	std::string *token;
	int lineCount;
}error;
