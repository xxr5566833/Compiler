#pragma once
#include "Compiler.h"

enum midop{
	//ʵ�γ�ʼ��
	REALPARAOP,
	//���ú���op
	CALLOP,
	//��������op
	RETOP,
	//����������������Ԫ�ظ�ֵ
	LARRAYOP,
	//����Ԫ�ظ�������������ֵ
	RARRAYOP,
	//�Ӽ��˳�
	ADDOP, SUBOP, MULOP, DIVOP,
	//��ϵ�����
	EQUOP, NEQUOP, MOREOP, MOREEQUOP, LESSOP, LESSEQUOP,
	//���ɱ�ŵ�op
	LABOP,
	//��������ת��op
	GOTOOP,
	//������ʼ��ע������main����ȫ�ֵģ�����Ҫ��������������FUNCEND
	FUNCBEGINOP,
	//�������
	SCANFOP, PRINTFOP,
	//�������
	EXITOP,
	//��op
	NOTOP,
	
};


typedef struct {
	midop op;
	std::string *op1name;
	std::string *op2name;
	std::string *rstname;
}midcode;