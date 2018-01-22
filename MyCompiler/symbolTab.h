#pragma once
#include "Compiler.h"

//���������ĸ������ֵ
const int kMaxParaNum = 20;
//�������������
const int kMaxBasicBlock = 2000;
//��ʶ��������  ������ֿ�
enum eRetType {INTRET = 7, CHARRET, VOIDRET, NOTTYPE };
//��ʶ�������࣬�ֱ��ǳ������򵥱����������������������������
enum eSymType {CONSTSYM, SIMPLESYM, ARRAYSYM, FUNCSYM, PARASYM};


typedef struct 
{
	std::string *name;
	//C++��ö�����Ͳ�����Ϊ������������ֻ����int����ʾ
	eRetType returnType;
	eSymType symbolType;
	//�������飬����ʾ����ĳ��ȣ����ں���������ʾ�����ĸ��������ڳ���������ʾ���������ֵ�����ڱ���������ʽ�������߾ֲ�������Ŀǰ����Ϊ-1
	int feature;
	//���ں�����ref��¼�����ڷֺ������е�λ��,��Ȼmainû�����ref
	int ref;
	//��¼�����������������ڱ���͵���
	int decLine;
	//��Ϊʹ��hash�������������������¼��ͻ���λ�ã�Ĭ��Ϊ-1
	int link;
	//���ں���������Ҫ������Ĳ����ĸ��������ͣ���������ר�Ÿ�������һ�����飬�涨����������
	eRetType paraList[kMaxParaNum];
	//�����ĵ�ַ
	int address;
	//��¼������ֲ����������������ÿ�����������ʹ�����
	bool flag[kMaxBasicBlock];
	//��¼�������ʶ����Ӧ�ļĴ�������������ʱ�����ͼ򵥱����Լ�����������Ч
	int regIndex;
}symbol;