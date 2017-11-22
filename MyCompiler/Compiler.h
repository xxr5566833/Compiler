#pragma once
#include "stdafx.h"

//������ֿռ�
const int kMaxReserve = 100;
//��󵥴������ռ�
const int kMaxWord = 100;
//���ʵ�ö�ٱ�������
enum eSym {
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

	COMMA, SEMI, ASSIGN, LBRACKET, RBRACKET, LBRACE, RBRACE, LPARENT, RPARENT, 
	//˫�ַ�
	LESSEQU, MOREEQU, EQU, NEQU
};

//����union
typedef union {
	char c;
	int number;
	std::string *str;


} symVal;

typedef struct sym{
	symVal word;
	int id;
	std::string *output;
}symbol;

class Compiler
{
public:
	Compiler(char *path);
	void begin();
	~Compiler();

private:
	//�ļ���ָ��
	std::fstream file;
	//��ǰ�ַ�
	char c;
	//��ǰ����
	std::string sym;
	symbol word;
	//�����ּ���
	std::string reserve[kMaxReserve];
	//���ʱ�־������飬��ö������һһ��Ӧ
	std::string wordOutput[kMaxWord];
	//��ʼ��
	void initWordArray();
	void setup();

	//��������йص�
	void error(int errodId);
	void skip();

	//��sym�йص�
	void clearSym();
	void symAppend();
	int inSym();

	bool isEof();
	void nextChar();
	void retract();

	//����������
	void skipSpace();
	void skipNote();

	//��һ��
	void readUntilNotLetterOrNum();

	//�ж�
	//�жϵ����ַ�
	bool isSpace();
	bool isTab();
	bool isNewLine();
	bool isSq();
	bool isDq();
	bool isZero();
	bool isLess();
	bool isMore();
	bool isEqu();
	//Em��ʾ��̾��
	bool isEm();

	bool isLetter();
	bool isNumber();
	bool isPlusOrMinus();
	bool isStarOrDiv();

	bool isInStringRange();
	bool isWord();

	//����sym
	int handleSym();
};

