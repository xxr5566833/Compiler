#include "Compiler.h"

//һЩ�����������˵��

const char *SQMISMATCHMSG = "\' �޷�ƥ��";

const char *DQMISMATCHMSG = "\" �޷�ƥ��";

const char *INVALIDCHARMSG = "\'��\'�а�Χ���ַ��������ķ��Ĺ涨��Χ���ķ��涨�ַ��ķ�Χ�����ڢټӷ�������ڳ˷����������ĸ������";

const char *ONLYEMMSG = "!����û�г���=";

const char *INVALIDVTMSG = "�������ķ��涨����ķ��ս����";


const char *NOTUNSIGNEDINTMSG = "Ӧ����һ����0���޷���������";

const char *NOTASSIGNMSG = "Ӧ����һ�� =";

const char *NOTINTMSG = "����һ������";

const char *NOTIDMSG = "����һ����ʶ��";

const char *NOTSINGLECHARMSG = "����һ���ַ�";

const char *NOTINTORCHARMSG = "���� int �� char";

const char *NOTSEMIMSG = "����һ���ֺ�;";

const char *NOTRBRACKETMSG = "����һ�� ��������] ";

const char *NOTRPARENTMSG = "����һ�� ��С����)";

const char *NOTFACTORMSG = "����һ�� <����>�Ŀ�ʼ���� ��������<��ʶ��> ( + - <�ַ�> 0 �� �޷������� ����֮һ";

const char *NOTLBRACEMSG = "����һ�� �������{";

const char *NOTMAINMSG = "���� main������";

const char *NOTLPARENTMSG = "���� ��С����(";

const char *NOTSTATEMENTMSG = "���� һ�����";

const char *NOTELSEMSG = "ȱ�� else";

const char *NOTCONSTANTMSG = "���� ����";

const char *NOTCOLONMSG = "���� ð��:";

const char *NOTCASEMSG = "ȱ�� case";

const char *NOTRBRACEMSG = "ȱ�� �Ҵ�����}";

const char *NOTVARDEFMSG = "���Ǳ����������ȷ���� [ ; �� ,";

//���壺

const char *DUPLICATEDEFMSG = "��ʶ���ظ����壡";

const char *PARATYPEDISMATCHMSG = "ֵ���������β����Ͳ�һ��!";

const char *PARANUMDISMATCHMSG = "ֵ�κ��βε�������һ��";

const char *IDNOTDEFMSG = "��ʶ��δ����";

const char *NOTAINTMSG = "����һ��int�ͱ��ʽ";

const char *NOTANARRAYMSG = "����һ���������͵ı�ʶ��";

const char *NOTAFUNCMSG = "��ʶ������һ��������";

const char *NOTANOPARAFUNCMSG = "����һ���޲εĺ���";

const char *INVALIDIDMSG = "����һ������ȷʹ�õı�ʶ��";

const char *NOTASIMPLEMSG = "����һ���򵥱�����ʶ��";

const char *CASESWITCHDISMATCHMSG = "case���ĳ������ͺ�switch���ı��ʽ���Ͳ�һ�£�";

const char *NONERETURNMSG = "�з���ֵ���͵ĺ���û��һ��return��";

const char *CANNOTRETURNMSG = "void����return һ��ʵ�ʵ�ֵ";

const char *RETURNTYPEDISMATCHMSG = "return�����ͺͺ�������ʱ�����Ͳ�һ��";

const char *INTTOCHARNOTALLOWMSG = "������Ӱ�int���͸���char���ͣ�";

const char *NORETURNVALUEMSG = "����һ���з���ֵ�ĺ���";

const char *CASEVALUEDUPLICATEMSG = "case��ĳ����������ظ�";

const char *ARRAYINDEXOUTOFRANGEMSG = "�����±�Խ�磡";

const char *DIVZEROMSG = "���ܳ���0";


//����дһ�°�

const tokenType UNSIGNEDINT_FOLLOW[] = {LESSEQU, MOREEQU, EQU, NEQU, LESS, MORE, PLUS, MINUS, STAR, DIV, COMMA, COLON, SEMI, RBRACKET, RPARENT};

const int UNSIGNEDINT_FOLLOW_SIZE = 15;

const tokenType INT_ASSIGN_FOLLOW[] = {PLUS, MINUS, ZERO, UNSIGNEDINT, COMMA, SEMI };

const int INT_ASSIGN_FOLLOW_SIZE = 6;

const tokenType DUPLICATEDEF_FOLLOW[] = {COMMA, SEMI};

const int DUPLICATEDEF_FOLLOW_SIZE = 2;

const tokenType NOTID_FOLLOW[] = {COMMA, SEMI};

const int NOTID_FOLLOW_SIZE = 2;

const tokenType NOTSINGLECHAR_FOLLOW[] = {COMMA, SEMI};

const int NOTSINGLECHAR_FOLLOW_SIZE = 2;

const tokenType NOTINTORCHAR_FOLLOW[] = {SEMI};

const int NOTINTORCHAR_FOLLOW_SIZE = 1;

const tokenType IDNOTDEF_FOLLOW[] = {PLUS, MINUS, STAR, DIV, RPARENT, SEMI, RBRACKET, LESSEQU, MOREEQU, EQU, NEQU, LESS, MORE};

const int IDNOTDEF_FOLLOW_SIZE = 13;

const tokenType NOTANARRAY_FOLLOW[] = {PLUS, MINUS, STAR, DIV, RPARENT, SEMI, RBRACKET, LESSEQU, MOREEQU, EQU, NEQU, LESS, MORE};

const int NOTANARRAY_FOLLOW_SIZE = 13;

const tokenType NOTAFUNC_FOLLOW[] = {PLUS, MINUS, STAR, DIV, RPARENT, SEMI, RBRACKET, LESSEQU, MOREEQU, EQU, NEQU, LESS, MORE};

const int NOTAFUNC_FOLLOW_SIZE = 13;

const tokenType NOTFACTOR_FOLLOW[] = {PLUS, MINUS, STAR, DIV, RPARENT, SEMI, RBRACKET, LESSEQU, MOREEQU, EQU, NEQU, LESS, MORE, COMMA, COLON};

const int NOTFACTOR_FOLLOW_SIZE = 15;

const tokenType NOTSTATEMENT_FOLLOW[] = {IF, WHILE, LBRACKET, SCANF, PRINTF, SEMI, SWITCH, RETURN, ID, ELSE, RBRACE};

const int NOTSTATEMENT_FOLLOW_SIZE = 11;

const tokenType NOTCONSTANT_FOLLOW[] = {COLON};

const int NOTCONSTANT_FOLLOW_SIZE = 1;

void Compiler:: errorHandle(errorType id)
{
	error *err = new error();
	err->id = id;
	err->lineCount = this->lineCount + 1;
	err->token = new std::string(this->sym);

	this->errorList.push_back(err);
	this->errorSkip(id);
}

void Compiler::errorSkip(errorType id)
{
	switch(id)
	{
	case NOTUNSIGNEDINT:
		this->skip(UNSIGNEDINT_FOLLOW, UNSIGNEDINT_FOLLOW_SIZE);
		break;
	case NOTASSIGN:
		this->skip(INT_ASSIGN_FOLLOW, INT_ASSIGN_FOLLOW_SIZE);
		break;
	case DUPLICATEDEF:
		this->skip(DUPLICATEDEF_FOLLOW, DUPLICATEDEF_FOLLOW_SIZE);
		break;
	case NOTINT:
		this->skip(UNSIGNEDINT_FOLLOW, UNSIGNEDINT_FOLLOW_SIZE);
		break;
	case NOTID:
		this->skip(NOTID_FOLLOW, NOTID_FOLLOW_SIZE);
		break;
	case NOTSINGLECHAR:
		this->skip(NOTSINGLECHAR_FOLLOW, NOTSINGLECHAR_FOLLOW_SIZE);
		break;
	case NOTINTORCHAR:
		this->skip(NOTINTORCHAR_FOLLOW, NOTINTORCHAR_FOLLOW_SIZE);
		break;
	case IDNOTDEF:
		this->skip(IDNOTDEF_FOLLOW, IDNOTDEF_FOLLOW_SIZE);
		break;
	case NOTANARRAY:
		this->skip(NOTANARRAY_FOLLOW, NOTANARRAY_FOLLOW_SIZE);
		break;
	case NOTAFUNC:
		this->skip(NOTAFUNC_FOLLOW, NOTAFUNC_FOLLOW_SIZE);
		break;
	case NOTFACTOR:
		this->skip(NOTFACTOR_FOLLOW, NOTFACTOR_FOLLOW_SIZE);
		break;
	case NOTSTATEMENT:
		this->skip(NOTSTATEMENT_FOLLOW, NOTSTATEMENT_FOLLOW_SIZE);
		break;
	case NOTCONSTANT:
		this->skip(NOTCONSTANT_FOLLOW, NOTCONSTANT_FOLLOW_SIZE);
		break;
	}
}

void Compiler::skip(const tokenType follow[], const int size)
{
	//����ֱ������ָ���ĵ���
	while(!this->isInRange(follow, size))
	{	
		this->inSym();
	}
}

void Compiler:: errorSetup()
{
	//�ʷ�����
	this->errorMsgList[SQMISMATCH]			=	new std::string(SQMISMATCHMSG);
	this->errorMsgList[DQMISMATCH]			=	new std::string(DQMISMATCHMSG);
	this->errorMsgList[INVALIDCHAR]			=	new std::string(INVALIDCHARMSG);
	this->errorMsgList[ONLYEM]				=	new std::string(ONLYEMMSG);
	this->errorMsgList[INVALIDVT]			=	new std::string(INVALIDVTMSG);

	//�﷨����
	this->errorMsgList[NOTUNSIGNEDINT]		=	new std::string(NOTUNSIGNEDINTMSG);
	this->errorMsgList[NOTASSIGN]			=	new std::string(NOTASSIGNMSG);
	this->errorMsgList[NOTINT]				=	new std::string(NOTINTMSG);
	this->errorMsgList[NOTID]				=	new std::string(NOTIDMSG);
	this->errorMsgList[NOTSINGLECHAR]		=	new std::string(NOTSINGLECHARMSG);
	this->errorMsgList[NOTINTORCHAR]		=	new std::string(NOTINTORCHARMSG);
	this->errorMsgList[NOTSEMI]				=	new std::string(NOTSEMIMSG);
	this->errorMsgList[NOTRBRACKET]			=	new std::string(NOTRBRACKETMSG);
	this->errorMsgList[NOTRPARENT]			=	new std::string(NOTRPARENTMSG);
	this->errorMsgList[NOTFACTOR]			=	new std::string(NOTFACTORMSG);
	this->errorMsgList[NOTLBRACE]			=	new std::string(NOTLBRACEMSG);
	this->errorMsgList[NOTMAIN]				=	new std::string(NOTMAINMSG);
	this->errorMsgList[NOTLPARENT]			=	new std::string(NOTLPARENTMSG);
	this->errorMsgList[NOTSTATEMENT]		=	new std::string(NOTSTATEMENTMSG);
	this->errorMsgList[NOTELSE]				=	new std::string(NOTELSEMSG);	
	this->errorMsgList[NOTCONSTANT]			=	new std::string(NOTCONSTANTMSG);
	this->errorMsgList[NOTCOLON]			=	new std::string(NOTCOLONMSG);
	this->errorMsgList[NOTCASE]				=	new std::string(NOTCASEMSG);
	this->errorMsgList[NOTRBRACE]			=	new std::string(NOTRBRACEMSG);
	this->errorMsgList[NOTVARDEF]			=	new std::string(NOTVARDEFMSG);
	
	//����ͷ��ű�
	this->errorMsgList[DUPLICATEDEF]		=	new std::string(DUPLICATEDEFMSG);
	this->errorMsgList[PARATYPEDISMATCH]	=	new std::string(PARATYPEDISMATCHMSG);
	this->errorMsgList[PARANUMDISMATCH]		=	new std::string(PARANUMDISMATCHMSG);
	this->errorMsgList[IDNOTDEF]			=	new std::string(IDNOTDEFMSG);
	this->errorMsgList[NOTAINT]				=	new std::string(NOTAINTMSG);
	this->errorMsgList[NOTANARRAY]			=	new std::string(NOTANARRAYMSG);	
	this->errorMsgList[NOTAFUNC]			=	new std::string(NOTAFUNCMSG);
	this->errorMsgList[NOTANOPARAFUNC]		=	new std::string(NOTANOPARAFUNCMSG);
	this->errorMsgList[INVALIDID]			=	new std::string(INVALIDIDMSG);
	this->errorMsgList[NOTASIMPLE]			=	new std::string(NOTASIMPLEMSG);
	this->errorMsgList[CASESWITCHDISMATCH]	=	new std::string(CASESWITCHDISMATCHMSG);
	this->errorMsgList[NONERETURN]			=	new std::string(NONERETURNMSG);
	this->errorMsgList[CANNOTRETURN]		=	new std::string(CANNOTRETURNMSG);
	this->errorMsgList[RETURNTYPEDISMATCH]	=	new std::string(RETURNTYPEDISMATCHMSG);
	this->errorMsgList[INTTOCHARNOTALLOW]	=	new std::string(INTTOCHARNOTALLOWMSG);
	this->errorMsgList[NORETURNVALUE]		=	new std::string(NORETURNVALUEMSG);
	this->errorMsgList[CASEVALUEDUPLICATE]	=	new std::string(CASEVALUEDUPLICATEMSG);
	this->errorMsgList[ARRAYINDEXOUTOFRANGE]=	new std::string(ARRAYINDEXOUTOFRANGEMSG);
	this->errorMsgList[DIVZERO]				=	new std::string(DIVZEROMSG);
}

void Compiler:: errorPrint()
{
	this->errorSetup();
	int s = this->errorList.size();
	for(unsigned int i = 0; i < this->errorList.size(); ++i)
	{
		error *err = errorList[i];
		std::stringstream msg = std::stringstream();
		msg << "line:" << err->lineCount << "\t" << "��" << *err->token << "�ĸ���:" << *(this->errorMsgList[err->id]) << "\n";
		std::cout << msg.str() ;
	}
}