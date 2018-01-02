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
	bool connect[100];
}ConflictNode;

const int kMaxRegAvailable = 14;