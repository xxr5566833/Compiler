#include "stdafx.h"
#include "Compiler.h"

//全局常量定义区：
//类别编码 ：





//保留字：
//const
const char *CONSTSY = "const";
//int
const char *INTSY = "int";
//char
const char *CHARSY = "char";
//void
const char *VOIDSY = "void";

//main
const char *MAINSY = "main";
//if
const char *IFSY = "if";
//else
const char *ELSESY = "else";
//while
const char *WHILESY = "while";
//switch
const char *SWITCHSY = "switch";
//case
const char *CASESY = "case";
//default
const char *DEFAULTSY = "default";
//scanf
const char *SCANFSY = "scanf";
//printf
const char *PRINTFSY = "printf";
//return 
const char *RETURNSY = "return";


//+
const char PLUSSY = '+';
//-
const char MINUSSY = '-';
//*
const char STARSY = '*';
// /
const char DIVSY = '/';
// <
const char LESSSY = '<';
// >
const char MORESY = '>';
// '
const char SQSY = '\'';
//"
const char DQSY = '\"';
//,
const char COMMASY = ',';
//;
const char SEMISY = ';';
//=
const char ASSIGNSY = '=';
//[
const char LBRACKETSY = '[';
//]
const char RBRACKETSY = ']';
//{
const char LBRACESY = '{';
//}
const char RBRACESY = '}';
//(
const char LPARENTSY = '(';
//)
const char RPARENTSY = ')';
//<=
const char *LESSEQUSY = "<=";
//>=
const char *MOREEQUSY = ">=";
//==
const char *EQUSY = "==";
//!=
const char *NEQUSY = "!=";




Compiler::Compiler(char *path)
{
	this->file = std::fstream(path, std::ios::in);
	this->sym = std::string();
}


Compiler::~Compiler()
{
	this->file.close();
	this->sym.clear();
	
}

void Compiler:: begin()
{
	this->setup();
	this->initWordArray();
	int i = 0;
	while(1)
	{
		int id = this->inSym();
		if(id  == -1)
		{
			return ;
		}
		++i;
		if(i == 907)
			std::cout << "ok" << std::endl;
		std::cout << i << " ";
		std::cout << this->wordOutput[this->word.id] << " ";
		std::cout << this->sym << std::endl;
	}
}

void Compiler:: initWordArray()
{
	this->wordOutput[NOTYPE] = "NOTYPE";
	this->wordOutput[ID] = "ID";
	this->wordOutput[UNSIGNEDINT] = "UNSIGNEDINT";
	this->wordOutput[SINGLECHAR] = "SINGLECHAR";
	this->wordOutput[STRING] = "STRING";
	this->wordOutput[CONST] = "CONST";
	this->wordOutput[INT] = "INT";
	this->wordOutput[CHAR] = "CHAR";
	this->wordOutput[VOID] = "VOID";
	this->wordOutput[MAIN] = "MAIN";
	this->wordOutput[IF] = "IF";
	this->wordOutput[ELSE] = "ELSE";
	this->wordOutput[WHILE] = "WHILE";
	this->wordOutput[SWITCH] = "SWITCH";
	this->wordOutput[CASE] = "CASE";
	this->wordOutput[DEFAULT] = "DEFAULT";
	this->wordOutput[SCANF] = "SCANF";
	this->wordOutput[PRINTF] = "PRINTF";
	this->wordOutput[RETURN] = "RETURN";
	this->wordOutput[PLUS] = "PLUS";
	this->wordOutput[MINUS] = "MINUS";
	this->wordOutput[STAR] = "STAR";
	this->wordOutput[DIV] = "DIV";
	this->wordOutput[LESS] = "LESS";
	this->wordOutput[MORE] = "MORE";
	this->wordOutput[SQ] = "SQ";
	this->wordOutput[DQ] = "DQ";
	this->wordOutput[COMMA] = "COMMA";
	this->wordOutput[SEMI] = "SEMI";
	this->wordOutput[ASSIGN] = "ASSIGN";
	this->wordOutput[LBRACKET] = "LBRACKET";
	this->wordOutput[RBRACKET] = "RBRACKET";
	this->wordOutput[LBRACE] = "LBRACE";
	this->wordOutput[RBRACE] = "RBRACE";
	this->wordOutput[LPARENT] = "LPARENT";
	this->wordOutput[RPARENT] = "RPARENT";
	this->wordOutput[LESSEQU] = "LESSEQU";
	this->wordOutput[MOREEQU] = "MOREEQU";
	this->wordOutput[EQU] = "EQU";
	this->wordOutput[NEQU] = "NEQU";
}

//建立保留字表：
//CONST, INT, CHAR, VOID, MAIN, IF, ELSE, WHILE, SWITCH, CASE, DEFAULT, SCANF, PRINTF, RETURN
void Compiler::setup()
{
	this->reserve[CONST] = std::string(CONSTSY);
	this->reserve[INT] = std::string(INTSY);
	this->reserve[CHAR] = std::string(CHARSY);
	this->reserve[VOID] = std::string(VOIDSY);
	this->reserve[MAIN] = std::string(MAINSY);
	this->reserve[IF] = std::string(IFSY);
	this->reserve[ELSE] = std::string(ELSESY);
	this->reserve[WHILE] = std::string(WHILESY);
	this->reserve[SWITCH] = std::string(SWITCHSY);
	this->reserve[CASE] = std::string(CASESY);
	this->reserve[DEFAULT] = std::string(DEFAULTSY);
	this->reserve[SCANF] = std::string(SCANFSY);
	this->reserve[PRINTF] = std::string(PRINTFSY);
	this->reserve[RETURN] = std::string(RETURNSY);
}

//与错误处理有关的
void Compiler::error(int errorId)
{
	return;
}

//和sym有关的：
void Compiler:: clearSym()
{
	this->sym.clear();
}

void Compiler::symAppend()
{
	this->sym.append(1, this->c);
}

void Compiler::retract()
{
	this->file.putback(c);
}

bool Compiler::isEof()
{
	return this->file.eof();
}

void Compiler:: nextChar()
{
	if (this->isEof())
	{
		this->error(0);
	}
	this->c = this->file.get();
	while(this->c < 0 && this->c != -1)
	{
		this->c = this->file.get();
	}
	//std::cout << this->c << std::endl;
}

//跳过不处理
void Compiler::skipSpace()
{
	while (this->isNewLine() || this->isSpace() || this->isTab())
	{
		this->nextChar();
	}
}

void Compiler:: skipNote()
{
	if(this->c == '//')
	{
		this->nextChar();
		while(this->c != '\n')
		{
			this->nextChar();
		}
	}
}


//判断类型

bool Compiler::isSpace()
{
	return this->c == ' ';
}

bool Compiler::isTab()
{
	return this->c == '\t';
}

bool Compiler::isNewLine()
{
	return this->c == '\n';
}

bool Compiler::isSq()
{
	return this->c == SQSY;
}

bool Compiler::isDq()
{
	return this->c == DQSY;
}

bool Compiler::isZero()
{
	return this->c == '0';
}

bool Compiler:: isLess()
{
	return this->c == '<';
}

bool Compiler:: isMore()
{
	return this->c == '>';
}

bool Compiler:: isEqu()
{
	return this->c == '=';
}

bool Compiler:: isEm()
{
	return this->c == '!';
}

bool Compiler::isPlusOrMinus()
{
	return this->c == '+' || this->c == '-';
}

bool Compiler::isStarOrDiv()
{
	return this->c == '*' || this->c == '/';
}

bool Compiler::isNumber()
{
	return this->c >= '0' && this->c <= '9';
}

bool Compiler::isLetter()
{
	return this->c == '_' || (this->c >= 'A' && this->c <= 'Z')
		|| (this->c >= 'a' && this->c <= 'z');
}

bool Compiler::isInStringRange()
{
	return this->c == 32 || this->c == 33 || (this->c >= 35 && this->c <=  126);
}

//处理sym

int Compiler::handleSym()
{
	//先查是不是保留字
	for (int i = CONST; i <= RETURN; ++i) {
		if (this->sym.compare(this->reserve[i]) == 0) {
			this->word.word.str = new std::string(this->reserve[i]);
			this->word.output = new std::string(this->reserve[i]);
			this->word.id = i;
			return i;
		}
	}
	this->word.output = new std::string(this->sym);
	this->word.word.str = new std::string(this->sym);
	this->word.id = ID;
	return ID;
}

int Compiler::inSym()
{
	int symid = NOTYPE;
	this->nextChar();
	this->skipSpace();
	this->skipNote();
	if(this->isEof())
	{
		return -1;
	}
	this->clearSym();
	if (this->isLetter()) 
	{
		this->symAppend();
		
		this->nextChar();
		while (this->isLetter() || this->isNumber()) {
			this->symAppend();
			this->nextChar();
		}
		this->retract();
		symid = this->handleSym();
		return symid;
	}
	if (this->isSq())
	{
		this->symAppend();
		this->nextChar();
		if (this->isLetter() || this->isNumber() || this->isPlusOrMinus()
			|| this->isStarOrDiv())
		{
			this->symAppend();
			this->nextChar();
			if (this->isSq())
			{
				this->symAppend();
				symid = SINGLECHAR;
				this->word.word.c = this->sym[1];
				this->word.id = SINGLECHAR;
				this->word.output = new std::string(this->sym);
			}
			else {
				this->error(0);
			}
		}
		else {
			this->error(0);
		}
		return symid;
	}
	if (this->isDq())
	{
		this->symAppend();
		this->nextChar();
		while (this->isInStringRange())
		{
			this->symAppend();
			this->nextChar();
		}
		if (this->isDq())
		{
			this->symAppend();
			symid = STRING;
			//strValue中不存前后的 双引号
			this->word.word.str = new std::string(this->sym.substr(1, this->sym.length() - 2));
			this->word.id = STRING;
			this->word.output = new std::string(this->sym);
		}
		else {
			this->error(0);
		}
		return symid;
	}
	if(this->isNumber())
	{
		this->symAppend();
		if(this->isZero())
		{
			this->word.word.number = 0;
		}
		else{
			this->nextChar();
			while(this->isNumber())
			{
				this->symAppend();
				this->nextChar();				
				//这里一开始错误：忘了加nextChar()
			}
			this->retract();
			//TODO: 需要判断数字的大小，不要超过int
			this->word.word.number = atoi(this->sym.c_str());
			this->word.output = new std::string(this->sym);
		}
		symid = UNSIGNEDINT;
		this->word.id = UNSIGNEDINT;
		return symid;
	}
	if(this->isLess())
	{
		this->symAppend();
		this->nextChar();
		if(this->isEqu())
		{
			this->symAppend();
			symid = LESSEQU;
			this->word.word.str = new std::string(LESSEQUSY);
			this->word.id = LESSEQU;
			this->word.output = new std::string(LESSEQUSY);
		}
		else{
			this->retract();
			symid = LESS;
			this->word.id = LESS;
			this->word.word.c = LESSSY;
			this->word.output = new std::string(this->sym);
		}
		return symid;
	}
	if(this->isMore())
	{
		this->symAppend();
		this->nextChar();
		if(this->isEqu())
		{
			this->symAppend();
			symid = MOREEQU;
			this->word.id = MOREEQU;
			this->word.word.str = new std::string(MOREEQUSY);
			this->word.output = new std::string(this->sym);
		}
		else{
			this->retract();
			symid = MORE;
			this->word.id = MORE;
			this->word.word.c = MORESY;
			this->word.output = new std::string(this->sym);
		}
		return symid;
	}
	if(this->isEqu())
	{
		this->symAppend();
		this->nextChar();
		if(this->isEqu())
		{
			this->symAppend();
			symid = EQU;
			this->word.id = EQU;
			this->word.word.str = new std::string(EQUSY);
			this->word.output = new std::string(this->sym);
		}
		else{
			this->retract();
			symid = ASSIGN;
			this->word.id = ASSIGN;
			this->word.word.c = ASSIGNSY;

		}
		return symid;
	}
	if(this->isEm())
	{
		this->symAppend();
		this->nextChar();
		if(this->isEqu())
		{
			this->symAppend();
			symid = NEQU;
			this->word.id = NEQU;
			this->word.word.str = new std::string(NEQUSY);
		}
		else{
			this->retract();
			this->error(0);
		}
		return symid;
	}
	switch(this->c)
	{
	case PLUSSY :
		symid = PLUS;
		this->word.id = PLUS;
		this->symAppend();
		this->word.word.c = PLUSSY;
		break;
	case MINUSSY:
		symid = MINUS;
		this->symAppend();
		this->word.id = MINUS;
		this->word.word.c = MINUSSY;
		break;
	case STARSY:
		symid = STAR;
		this->symAppend();
		this->word.id = STAR;
		this->word.word .c = STARSY;
		break;
	case DIVSY:
		symid = DIV;
		this->word.id = DIV;
		this->symAppend();
		this->word.word.c = DIVSY;
		break;
	case COMMASY:
		symid = COMMA;
		this->word.id = COMMA;
		this->symAppend();
		this->word.word.c = COMMASY;
		break;
	case SEMISY:
		symid = SEMI;
		this->symAppend();
		this->word.id = SEMI;
		this->word.word.c = SEMISY;
		break;
	case LBRACKETSY:
		symid = LBRACKET;
		this->symAppend();
		this->word.id = LBRACKET;
		this->word.word.c = LBRACKETSY;
		break;
	case RBRACKETSY:
		symid = RBRACKET;
		this->symAppend();
		this->word.id = RBRACKET;
		this->word.word.c = RBRACKETSY;
		break;
	case LBRACESY:
		symid = LBRACE;
		this->symAppend();
		this->word.id = LBRACE;
		this->word.word.c = LBRACESY;
		break;
	case RBRACESY:
		symid = RBRACE;
		this->symAppend();
		this->word.id = RBRACE;
		this->word.word.c = RBRACESY;
		break;
	case LPARENTSY:
		symid = LPARENT;
		this->symAppend();
		this->word.id = LPARENT;
		this->word.word.c = LPARENTSY;
		break;
	case RPARENTSY:
		symid = RPARENT;
		this->symAppend();
		this->word.id = RPARENT;
		this->word.word.c = RPARENTSY;
		break;
	default:
		this->error(0);

	}

	return symid;
}
