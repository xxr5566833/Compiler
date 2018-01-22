#pragma once
#include "Compiler.h"

//函数参数的个数最大值
const int kMaxParaNum = 20;
//最大基本块的数量
const int kMaxBasicBlock = 2000;
//标识符的类型  与种类分开
enum eRetType {INTRET = 7, CHARRET, VOIDRET, NOTTYPE };
//标识符的种类，分别是常量，简单变量，数组变量，函数，参数类型
enum eSymType {CONSTSYM, SIMPLESYM, ARRAYSYM, FUNCSYM, PARASYM};


typedef struct 
{
	std::string *name;
	//C++中枚举类型不能作为参数。。这里只能用int来表示
	eRetType returnType;
	eSymType symbolType;
	//对于数组，它表示数组的长度，对于函数，它表示参数的个数，对于常数，它表示这个常数的值，对于变量或者形式参数或者局部变量，目前设置为-1
	int feature;
	//对于函数，ref记录了它在分函数表中的位置,当然main没有这个ref
	int ref;
	//记录下声明的行数，便于报错和调试
	int decLine;
	//因为使用hash分离链表法，所以这里记录冲突项的位置，默认为-1
	int link;
	//关于函数还必须要获得它的参数的个数和类型，所以这里专门给函数开一个数组，规定最大参数个数
	eRetType paraList[kMaxParaNum];
	//所处的地址
	int address;
	//记录下这个局部变量在这个函数的每个基本块里的使用情况
	bool flag[kMaxBasicBlock];
	//记录下这个标识符对应的寄存器，仅仅对临时变量和简单变量以及参数变量有效
	int regIndex;
}symbol;