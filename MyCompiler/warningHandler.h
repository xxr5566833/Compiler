#pragma once
#include "stdafx.h"

//warningmsglist的最大种类限制，每一种对应一个输出语句
const int kMaxWarningType = 100;

//warning的枚举定义
enum warningType{
	//词法分析
	NUMTOOBIG = 0, 

	//语义分析
	TOOMANYCASE,
};

//warning的结构体
typedef struct{
	int lineCount;
	warningType id;
	std::string *token;
}warning;

