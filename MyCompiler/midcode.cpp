#include "Compiler.h"


//��ʱ�����׸���ʶ��

const char *tempid = "$t";

//label�׸���ʶ��

const char *labelid = "$label";

//�ַ�����ʶ��

const char *messageid = "$Message";

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
	std::string rst = *(code->rstname);
	std::string op1name = *(code->op1name);
	std::string op2name = *(code->op2name);
	switch(code->op)
	{
	case REALPARAOP:
		ss << midrealpara << " " << rst;
		break;
	case RARRAYOP:
		ss << rst << " " << "=" << " " << op1name << "[" << op2name << "]";
		break;
	case CALLOP:
		ss << midcall << " " << rst;
		break;
	case GOTOOP:
		ss << midgoto << " " << rst;
		break;
	case FUNCBEGINOP:
		ss<< midinit << " " << rst;
		break;
	case RETOP:
		ss << midret << " " << rst;
		break;
	case ASSIGNOP:
		ss << rst << " " << midassign << " " << op1name;
		break;
	case MULOP:
		ss << rst << " " << midassign << " " << op1name << " " << midmul << " " << op2name;
		break;
	case DIVOP:
		ss << rst << " " << midassign << " " << op1name << " " << middiv << " " << op2name;
		break;
	case ADDOP:
		ss << rst << " " << midassign << " " << op1name << " " << midadd << " " << op2name;
		break;
	case SUBOP:
		ss << rst << " " << midassign << " " << op1name << " " << midsub << " " << op2name;
		break;
	case EQUOP:
		ss << "if" << " " << op1name << " " << midequ << " " << op2name << " " << "then goto" << " " << rst;
		break;
	case NEQUOP:
		ss << "if" << " " << op1name << " " << midnequ << " " << op2name << " " << "then goto" << " " << rst;
		break;
	case MOREOP:
		ss << "if" << " " << op1name << " " << midmore << " " << op2name << " " << "then goto" << " " << rst;
		break;
	case MOREEQUOP:
		ss << "if" << " " << op1name << " " << midmoreequ << " " << op2name << " " << "then goto" << " " << rst;
		break;
	case LESSOP:
		ss << "if" << " " << op1name << " " << midless << " " << op2name << " " << "then goto" << " " << rst;
		break;
	case LESSEQUOP:
		ss << "if" << " " << op1name << " " << midlessequ << " " << op2name << " " << "then goto" << " " << rst;
		break;
	case SCANFOP:
		ss << midscanf << " " << op1name << " " << rst;
		break;
	case PRINTFOP:
		ss << midprintf << " " << rst;
		break;
	case LARRAYOP:
		ss << rst << "[" <<	op2name << "]" << " " << midassign << " " << op1name;
		break;
	case EXITOP:
		ss << midexit << " ";
		break;
	//��������д���ɱ�ŵ�����ˣ�
	case LABOP :
		ss << rst << ":";
	
	}
	ss << "\n"; 
	this->midFile << ss.str();
	//std::cout << ss.str();
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