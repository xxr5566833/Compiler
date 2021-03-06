#pragma once
#include "stdafx.h"
//单词的枚举变量定义
enum tokenType {
	//notype
	NOTYPE = 0,
	//标识符
	ID,
	//非0无符号整数常量
	UNSIGNEDINT,
	//0单独作为一类，以保证和老师给定的无符号整数相一致
	ZERO,
	//<字符>所文法中两个单引号之间的那个语法成分
	SINGLECHAR,
	//字符串常量
	STRING,
	//保留字：
	CONST, INT, CHAR, VOID, MAIN, IF, ELSE, WHILE, SWITCH, CASE, DEFAULT, SCANF, PRINTF, RETURN,
	//单字符
	PLUS, MINUS, STAR, DIV, LESS, MORE, SQ, DQ,

	COMMA, SEMI, COLON, ASSIGN, LBRACKET, RBRACKET, LBRACE, RBRACE, LPARENT, RPARENT, 
	//双字符
	LESSEQU, MOREEQU, EQU, NEQU
};

//声明union
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

//一些限制：
const int kMaxDigits = 10;