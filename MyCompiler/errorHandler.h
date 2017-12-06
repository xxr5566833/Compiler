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

	 //语义和符号表相关:
	 //重复定义
	 DUPLICATEDEF,
	 //值参与形参类型不匹配
	 PARATYPEDISMATCH,
	 //值参与形参数量不匹配
	 PARANUMDISMATCH,
	 //标识符未定义
	 IDNOTDEF,
	 //不是一个int型的表达式
	 NOTAINT,
	 //不是一个数组型的标识符
	 NOTANARRAY,
	 //不是一个函数名
	 NOTAFUNC,
	 //不是一个无参函数
	 NOTANOPARAFUNC,
	 //不是一个被正确使用的标识符，比如数组名却作为简单变量
	 INVALIDID,
	 //不是一个简单变量
	 NOTASIMPLE,
	 //case语句的常量类型和switch的表达式类型不一致
	 CASESWITCHDISMATCH,
	 //有返回值类型的函数定义没有一句return
	 NONERETURN,
	 //VOID不能return一个int char，它却return了
	 CANNOTRETURN,
	 //return类型和函数定义类型不一致
	 RETURNTYPEDISMATCH,
	 //不允许int -> char的赋值
	 INTTOCHARNOTALLOW,
	 //不是一个有返回值的函数
	 NORETURNVALUE,


};
//错误的结构体类型声明
typedef struct {
	errorType id;
	std::string *token;
	int lineCount;
}error;
