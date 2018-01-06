#pragma once

#include "Compiler.h"

typedef struct node{
	midop op;
	std::string *mainname;
	int xindex;
	int yindex;
	int parentindex[30];
	int parentnum;
	int index;
	//是否主名字空缺
	bool flag;
	bool isLeaf;
}Node;

typedef struct listnode{
	std::string *name;
	int index;
}ListNode;

typedef struct {
	int prearray[400];
	int prenum;
	//后继块最多有两个！
	//next1固定为正常执行的后继基本块，next2固定为跳转执行的后继基本块
	int next1;
	int next2;
}Block;


typedef struct{
	//连接的结点数量
	int edgenum;
	//连接哪些结点
	bool connect[1000];
}ConflictNode;

//保留4个寄存器 $t9 $t8 $t7 $s7 作为灵活用的寄存器
const int kMaxRegAvailable = 14;