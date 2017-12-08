#pragma once
#include "Compiler.h"

enum midop{
	//实参初始化
	REALPARAOP,
	//调用函数op
	CALLOP,
	//函数返回op
	RETOP,
	//其他操作数给数组元素赋值
	LARRAYOP,
	//数组元素给其他操作数赋值
	RARRAYOP,
	//简单变量赋值
	ASSIGNOP,
	//加减乘除，还有个取负
	ADDOP, SUBOP, MULOP, DIVOP,NEGOP,
	//关系运算符
	EQUOP, NEQUOP, MOREOP, MOREEQUOP, LESSOP, LESSEQUOP,
	//生成标号的op
	LABOP,
	//无条件跳转的op
	GOTOOP,
	//函数开始，注意这里main就是全局的，不需要，函数结束就是FUNCEND
	FUNCBEGINOP,
	//输入输出
	SCANFOP, PRINTFOP,
	//程序结束
	EXITOP,
	
};


typedef struct {
	midop op;
	std::string *op1name;
	std::string *op2name;
	std::string *rstname;
}midcode;