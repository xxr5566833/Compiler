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

	 //����ͷ��ű����:
	 //�ظ�����
	 DUPLICATEDEF,
	 //ֵ�����β����Ͳ�ƥ��
	 PARATYPEDISMATCH,
	 //ֵ�����β�������ƥ��
	 PARANUMDISMATCH,
	 //��ʶ��δ����
	 IDNOTDEF,
	 //����һ��int�͵ı��ʽ
	 NOTAINT,
	 //����һ�������͵ı�ʶ��
	 NOTANARRAY,
	 //����һ��������
	 NOTAFUNC,
	 //����һ���޲κ���
	 NOTANOPARAFUNC,
	 //����һ������ȷʹ�õı�ʶ��������������ȴ��Ϊ�򵥱���
	 INVALIDID,
	 //����һ���򵥱���
	 NOTASIMPLE,
	 //case���ĳ������ͺ�switch�ı��ʽ���Ͳ�һ��
	 CASESWITCHDISMATCH,
	 //�з���ֵ���͵ĺ�������û��һ��return
	 NONERETURN,
	 //VOID����returnһ��int char����ȴreturn��
	 CANNOTRETURN,
	 //return���ͺͺ����������Ͳ�һ��
	 RETURNTYPEDISMATCH,
	 //������int -> char�ĸ�ֵ
	 INTTOCHARNOTALLOW,
	 //����һ���з���ֵ�ĺ���
	 NORETURNVALUE,


};
//����Ľṹ����������
typedef struct {
	errorType id;
	std::string *token;
	int lineCount;
}error;
