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
	//�Ƿ������ֿ�ȱ
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
	//��̿������������
	//next1�̶�Ϊ����ִ�еĺ�̻����飬next2�̶�Ϊ��תִ�еĺ�̻�����
	int next1;
	int next2;
}Block;


typedef struct{
	//���ӵĽ������
	int edgenum;
	//������Щ���
	bool connect[1000];
}ConflictNode;

//����4���Ĵ��� $t9 $t8 $t7 $s7 ��Ϊ����õļĴ���
const int kMaxRegAvailable = 14;