#include "stdafx.h"
#include "Compiler.h"
#include "token.h"
#include "errorHandler.h"
#include "warningHandler.h"
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
//:
const char COLONSY = ':';
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
	this->wordOutput[COLON] = "COLON";
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
	this->file.putback(this->c);
	if(this->c == '\n')
		this->lineCount -= 1;
}

bool Compiler::isEof()
{
	return this->file.peek() == EOF;
}

void Compiler:: nextChar()
{
	this->c = this->file.get();
	while(this->c < 0 && this->c != -1 )
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
		if(this->isNewLine())
			this->lineCount += 1;
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

bool Compiler:: isIdEqual(std::string id1, std::string id2)
{
	std::string::iterator p = id1.begin();
	std::string::iterator q = id2.begin();

	while(p != id1.end() && q != id2.end() && tolower(*p) == tolower(*q))
	{
		++p;
		++q;
	}
	return p == id1.end() && q == id2.end();
}

//处理sym

void Compiler::handleSym()
{
	//先查是不是保留字
	for (int i = CONST; i <= RETURN; ++i) {
		if (this->isIdEqual(this->sym, this->reserve[i])) {
			this->tok.val.str = new std::string(this->reserve[i]);
			this->tok.output = new std::string(this->reserve[i]);
			this->tok.id = i;
			return ;
		}
	}
	this->tok.output = new std::string(this->sym);
	this->tok.val.str = new std::string(this->sym);
	this->tok.id = ID;
}

void Compiler::inSym()
{
	this->tok.id = NOTYPE;
	this->nextChar();
	this->skipSpace();
	if(this->isEof())
	{
		return ;
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
		this->handleSym();
		return ;
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
				this->tok.val.c = this->sym[1];
				this->tok.id = SINGLECHAR;
				this->tok.output = new std::string(this->sym);
			}
			else {
				this->errorHandle(SQMISMATCH);
			}
		}
		else {
			this->errorHandle(INVALIDCHAR);
		}
		return ;
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
			//strValue中不存前后的 双引号
			this->tok.val.str = new std::string(this->sym.substr(1, this->sym.length() - 2));
			this->tok.id = STRING;
			this->tok.output = new std::string(this->sym);
		}
		else {
			this->errorHandle(DQMISMATCH);
		}
		return ;
	}
	if(this->isNumber())
	{
		this->symAppend();
		if(this->isZero())
		{
			this->tok.val.number = 0;
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
			if(this->sym.length() > kMaxDigits)
			{
				this->warningHandle(NUMTOOBIG);	
			}
			this->tok.val.number = atoi(this->sym.substr(0, kMaxDigits).c_str());
			this->tok.output = new std::string(this->sym);
		}
		this->tok.id = UNSIGNEDINT;
		return ;
	}
	if(this->isLess())
	{
		this->symAppend();
		this->nextChar();
		if(this->isEqu())
		{
			this->symAppend();
			this->tok.val.str = new std::string(LESSEQUSY);
			this->tok.id = LESSEQU;
			this->tok.output = new std::string(LESSEQUSY);
		}
		else{
			this->retract();
			this->tok.id = LESS;
			this->tok.val.c = LESSSY;
			this->tok.output = new std::string(this->sym);
		}
		return ;
	}
	if(this->isMore())
	{
		this->symAppend();
		this->nextChar();
		if(this->isEqu())
		{
			this->symAppend();
			this->tok.id = MOREEQU;
			this->tok.val.str = new std::string(MOREEQUSY);
			this->tok.output = new std::string(this->sym);
		}
		else{
			this->retract();
			this->tok.id = MORE;
			this->tok.val.c = MORESY;
			this->tok.output = new std::string(this->sym);
		}
		return ;
	}
	if(this->isEqu())
	{
		this->symAppend();
		this->nextChar();
		if(this->isEqu())
		{
			this->symAppend();
			this->tok.id = EQU;
			this->tok.val.str = new std::string(EQUSY);
			this->tok.output = new std::string(this->sym);
		}
		else{
			this->retract();
			this->tok.id = ASSIGN;
			this->tok.val.c = ASSIGNSY;

		}
		return ;
	}
	if(this->isEm())
	{
		this->symAppend();
		this->nextChar();
		if(this->isEqu())
		{
			this->symAppend();
			this->tok.id = NEQU;
			this->tok.val.str = new std::string(NEQUSY);
		}
		else{
			this->retract();
			this->errorHandle(ONLYEM);
		}
		return ;
	}
	//接下来就是一些单字符,接下来只需要区分它们的id就好
	this->symAppend();
	this->tok.val.c = this->c;
	switch(this->c)
	{
	case PLUSSY :
		this->tok.id = PLUS;
		break;
	case MINUSSY:
		this->tok.id = MINUS;
		break;
	case STARSY:
		this->tok.id = STAR;
		break;
	case DIVSY:
		this->tok.id = DIV;
		break;
	case COMMASY:
		this->tok.id = COMMA;
		break;
	case SEMISY:
		this->tok.id = SEMI;
		break;
	case COLONSY:
		this->tok.id = COLON;
		break;
	case LBRACKETSY:
		this->tok.id = LBRACKET;
		break;
	case RBRACKETSY:
		this->tok.id = RBRACKET;
		break;
	case LBRACESY:
		this->tok.id = LBRACE;
		break;
	case RBRACESY:
		this->tok.id = RBRACE;
		break;
	case LPARENTSY:
		this->tok.id = LPARENT;
		break;
	case RPARENTSY:
		this->tok.id = RPARENT;
		break;
	default:
		this->errorHandle(INVALIDVT);
	}

}
