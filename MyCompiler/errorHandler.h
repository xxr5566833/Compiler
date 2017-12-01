#pragma once
#include "stdafx.h"
//最大错误类型限制
const int kMaxErrorType = 100;


//错误类型枚举变量声明
enum errorType{
	//词法分析的
	 SQMISMATCH = 0, DQMISMATCH, INVALIDCHAR, ONLYEM, INVALIDVT,
	 //语法分析的
	 //不是非0无符号整数
	 NOTUNSIGNEDINT,
	 //不是 = 
	 NOTASSIGN,
	 //不是整数
	 NOTINT,
	 //不是标识符
	 NOTID,
	 //不是字符
	 NOTSINGLECHAR,
	 //不是int 或 char
	 NOTINTORCHAR,
	 //不是分号;
	 NOTSEMI,
	 //不是右中括号
	 NOTRBRACKET,
	 //不是右小括号
	 NOTRPARENT,
	 //不是一个因子的开始单词
	 NOTFACTOR,
	 //不是一个左大括号
	 NOTLBRACE,
	 //不是右大括号
	 NOTRBRACE,
	 //不是main保留字
	 NOTMAIN,
	 //不是左小括号(
	 NOTLPARENT,
	 //不是语句
	 NOTSTATEMENT,
	 //不是else
	 NOTELSE,
	 //不是常量
	 NOTCONSTANT,
	 //不是冒号：
	 NOTCOLON,
	 //不是case
	 NOTCASE,
	 //不是变量定义的开始符号 [ , ;
	 NOTVARDEF,


};
//错误的结构体类型声明
typedef struct {
	errorType id;
	std::string *token;
	int lineCount;
}error;
