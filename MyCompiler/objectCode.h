#pragma once
#include "Compiler.h"

//保存上一次寄存器的分配状态，在函数开始时保存，在函数返回时恢复，与mips寄存器的保存和恢复一致
typedef struct{
	int tempReg[9];
	int tempRegIndex ;
	std::string *symReg[8];
	int symRegIndex;
}regAllocStack;
