#include "Compiler.h"


//��ʱ�����׸���ʶ��

const char *tempid = "$_";

//label�׸���ʶ��

const char *labelid = "Label_";

//�ַ�����ʶ��

const char *messageid = "Message_";

//ͳһ�м����ı�ʶ��
//��ʱ��������ʱ���ɣ��򵥱�������������ͳ�������ԭ���ı�ʶ����������ʶ����Ϊlabel���вκ������ú�ķ��ر���ͳһ��RET

const char *midRET = "RET";

const char *midret = "ret";

const char *midlarray = "[]=";

const char *midrarray = "=[]";

const char *midcall = "call";

const char *midgoto = "goto";

const char *midinit = "init";

const char *midneg = "-";

const char *midassign = "=";

const char *middiv = "\\";

const char *midmul = "*";

const char *midadd = "+";

const char *midsub = "-";

const char *midequ = "==";

const char *midnequ = "!=";

const char *midmoreequ = ">=";

const char *midmore = ">";

const char *midlessequ = "<=";

const char *midless = "<";

const char *midscanf = "scanf";

const char *midprintf = "printf";

const char *midrealpara = "push";

const char *midexit = "exit";
//���ܵ�op
const char *midconst = "const";


const char *midint = "int";

const char *midchar = "char";

const char *midvoid = "void";

const char *midvar = "var";

const char *midpara = "para";





const char *midBNZ = "BNZ";

const char *midBZ = "BZ";

void Compiler::int2string(std::string *s, int value)
{
	std::stringstream ss = std::stringstream();
	ss << value;
	*s = ss.str();
}

void Compiler:: pushMidCode(midop op,std::string *operand1, std::string *operand2, std::string *rst)
{
	midcode *code = new midcode();
	code->op = op;
	code->op1name = operand1;
	code->op2name = operand2;
	code->rstname = rst;
	this->codes[this->midindex ++] = code;
	this->writeMidCode(code);
}

void Compiler:: writeMidCode(midcode *code)
{
	std::stringstream ss = std::stringstream();
	switch(code->op)
	{
	case REALPARAOP:
		ss << midrealpara << " ";
		break;
	case RARRAYOP:
		ss << midrarray << " ";
		break;
	case CALLOP:
		ss << midcall << " ";
		break;
	case GOTOOP:
		ss << midgoto << " ";
		break;
	case FUNCBEGINOP:
		ss<< midinit << " ";
		break;
	case RETOP:
		ss << midret << " ";
		break;
	case NEGOP:
		ss << midneg << " ";
		break;
	case ASSIGNOP:
		ss << midassign << " ";
		break;
	case MULOP:
		ss << midmul << " ";
		break;
	case DIVOP:
		ss << middiv << " ";
		break;
	case ADDOP:
		ss << midadd << " ";
		break;
	case SUBOP:
		ss << midsub << " ";
		break;
	case EQUOP:
		ss << midequ << " ";
		break;
	case NEQUOP:
		ss << midnequ << " ";
		break;
	case MOREOP:
		ss << midmore << " ";
		break;
	case MOREEQUOP:
		ss << midmoreequ << " ";
		break;
	case LESSOP:
		ss << midless << " ";
		break;
	case LESSEQUOP:
		ss << midlessequ << " ";
		break;
	case SCANFOP:
		ss << midscanf << " ";
		break;
	case PRINTFOP:
		ss << midprintf << " ";
		break;
	case LARRAYOP:
		ss << midlarray << " ";
	case EXITOP:
		ss << midexit < " ";
	
	}
	ss << *(code->op1name) << " ";
	ss << *(code->op2name) << " ";
	ss << *(code->rstname) << "\n";
	this->midFile << ss.str();
	std::cout << ss.str();
}

void Compiler::initMidCode()
{
	this->midindex = 0;
	this->label = 0;
	this->temp = 0;
	this->stringNum = 0;
}

void Compiler:: genTemp(std::string *temp)
{
	std::stringstream ss = std::stringstream();
	ss << tempid;
	ss << this->temp++;
	*temp = ss.str();
}

void Compiler:: genLabel(std::string *lab)
{
	std::stringstream ss = std::stringstream();
	ss << labelid;
	ss << this->label++;
	*lab = ss.str();
}

void Compiler:: pushString(std::string *str)
{
	this->stringTab[this->stringNum ++] = str;
}

void Compiler ::genMessage(std::string *str, int num)
{
	std::stringstream ss = std::stringstream();
	ss << messageid;
	ss << num;
	*str = ss.str();
}