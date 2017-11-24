#pragma once
#include "stdafx.h"
#include "token.h"
#include "errorHandler.h"
#include "warningHandler.h"
//������ֿռ�
const int kMaxReserve = 100;
//��󵥴������ռ�
const int kMaxWord = 100;

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
	token tok;
	//��ǰ����
	int lineCount ;

	//�����ּ���
	std::string reserve[kMaxReserve];
	//���ʱ�־������飬��ö������һһ��Ӧ
	std::string wordOutput[kMaxWord];
	//��ʼ��
	void initWordArray();
	void setup();

	//��������йص�
	void skip();

	//��sym�йص�
	void clearSym();
	void symAppend();
	void inSym();

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

	//�жϱ�ʶ�����߱������Ƿ����
	bool isIdEqual(std::string id1, std::string id2);



	//����sym
	void handleSym();

	//�������
	//�ʷ������Ĵ���
	std::vector<error*> errorList;
	std::string *errorMsgList[kMaxErrorType];
	void errorHandle(errorType errodId);
	void errorSetup();
	void errorPrint();

	//������
	std::vector<warning*> warningList;
	std::string *warningMsgList[kMaxWarningType];
	void warningHandle(warningType warningId);
	void warningSetup();
	void warningPrint();
};

