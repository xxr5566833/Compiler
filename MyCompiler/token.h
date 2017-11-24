#pragma once
#include "stdafx.h"
//���ʵ�ö�ٱ�������
enum tokenType {
	//notype
	NOTYPE = 0,
	//��ʶ��
	ID,
	//�޷�����������
	UNSIGNEDINT,
	//�ַ�����
	SINGLECHAR,
	//�ַ�������
	STRING,
	//�����֣�
	CONST, INT, CHAR, VOID, MAIN, IF, ELSE, WHILE, SWITCH, CASE, DEFAULT, SCANF, PRINTF, RETURN,
	//���ַ�
	PLUS, MINUS, STAR, DIV, LESS, MORE, SQ, DQ,

	COMMA, SEMI, COLON, ASSIGN, LBRACKET, RBRACKET, LBRACE, RBRACE, LPARENT, RPARENT, 
	//˫�ַ�
	LESSEQU, MOREEQU, EQU, NEQU
};

//����union
typedef union {
	char c;
	int number;
	std::string *str;


} tokenVal;

typedef struct token{
	tokenVal val;
	int id;
	std::string *output;
}token;

//һЩ���ƣ�
const int kMaxDigits = 9;