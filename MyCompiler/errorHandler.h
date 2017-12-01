#pragma once
#include "stdafx.h"
//��������������
const int kMaxErrorType = 100;


//��������ö�ٱ�������
enum errorType{
	//�ʷ�������
	 SQMISMATCH = 0, DQMISMATCH, INVALIDCHAR, ONLYEM, INVALIDVT,
	 //�﷨������
	 //���Ƿ�0�޷�������
	 NOTUNSIGNEDINT,
	 //���� = 
	 NOTASSIGN,
	 //��������
	 NOTINT,
	 //���Ǳ�ʶ��
	 NOTID,
	 //�����ַ�
	 NOTSINGLECHAR,
	 //����int �� char
	 NOTINTORCHAR,
	 //���Ƿֺ�;
	 NOTSEMI,
	 //������������
	 NOTRBRACKET,
	 //������С����
	 NOTRPARENT,
	 //����һ�����ӵĿ�ʼ����
	 NOTFACTOR,
	 //����һ���������
	 NOTLBRACE,
	 //�����Ҵ�����
	 NOTRBRACE,
	 //����main������
	 NOTMAIN,
	 //������С����(
	 NOTLPARENT,
	 //�������
	 NOTSTATEMENT,
	 //����else
	 NOTELSE,
	 //���ǳ���
	 NOTCONSTANT,
	 //����ð�ţ�
	 NOTCOLON,
	 //����case
	 NOTCASE,
	 //���Ǳ�������Ŀ�ʼ���� [ , ;
	 NOTVARDEF,


};
//����Ľṹ����������
typedef struct {
	errorType id;
	std::string *token;
	int lineCount;
}error;
