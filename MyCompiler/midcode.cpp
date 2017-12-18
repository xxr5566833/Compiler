#include "Compiler.h"


//临时变量首个标识符

const char *tempid = "$t";

//label首个标识符

const char *labelid = "$label";

//字符串标识符

const char *messageid = "$Message";

//统一中间代码的标识符
//临时变量就临时生成，简单变量，数组变量和常量就用原来的标识符，函数标识符作为label，有参函数调用后的返回变量统一用RET

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
//可能的op
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

void Compiler:: pushMidCode(midop op,std::string *operand1, std::string *operand2, std::string *rst, bool optimize)
{
	midcode *code = new midcode();
	code->op = op;
	code->op1name = new std::string();
	*(code->op1name) = *operand1;
	code->op2name = new std::string();
	*(code->op2name) = *operand2;
	code->rstname = new std::string();
	*(code->rstname) = *rst;
	if(optimize)
		this->optimizeCodes[this->optimizeMidIndex++] = code;
	else
		this->codes[this->midindex ++] = code;
	this->writeMidCode(code, false, true, optimize);
}




void Compiler:: writeMidCode(midcode *code, bool stdflag, bool fileflag, bool optimize)
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
	//这里忘了写生成标号的情况了！
	case LABOP :
		ss << rst << ":";
	
	}
	ss << "\n"; 
	if(fileflag)
	{
		if(!optimize)
		{
			this->midFile << ss.str();
		}
		else{
			this->optimizeFile << ss.str();
		}
	}
		
	if(stdflag)
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

bool Compiler::isOperandNumber(std::string *rs)
{
	return (*rs)[0] >= '0' && (*rs)[0] <= '9' || (*rs)[0] == '-';
}

bool Compiler::isOperandTemp(std::string *rs)
{
	return (*rs)[0] == '$';
}

bool Compiler::isOperandRet(std::string *rs)
{
	return (*rs)[0] == '#';
}

bool Compiler::isOperandId(std::string *rs)
{
	return (*rs)[0] == '_' || ((*rs)[0] >= 'A' && (*rs)[0] <= 'Z')
		|| ((*rs)[0] >= 'a' && (*rs)[0] <= 'z');
}