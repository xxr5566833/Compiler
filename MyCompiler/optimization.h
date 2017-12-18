#pragma once

#include "Compiler.h"

typedef struct node{
	midop op;
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
