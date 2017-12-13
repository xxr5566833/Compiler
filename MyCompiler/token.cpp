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




//初始化单词类型的string输出，与枚举一一对应
void Compiler:: initWordArray()
{
	this->wordOutput[NOTYPE] = "NOTYPE";
	this->wordOutput[ID] = "ID";
	this->wordOutput[UNSIGNEDINT] = "UNSIGNEDINT";
	this->wordOutput[ZERO] = "ZERO";
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

//建立保留字表，便于得到当前单词是不是一个保留字
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
//清空已经读入的字符数组
void Compiler:: clearSym()
{
	this->sym.clear();
}
//把当前字符加入到当前字符数组
void Compiler::symAppend()
{
	this->sym.append(1, this->c);
}
//让文件指针下一次读到的单词还是当前这个单词，并维护行数
void Compiler::retract()
{
	this->file.putback(this->c);
	if(this->c == '\n')
		this->lineCount -= 1;
}
//返回文件是否读完
bool Compiler::isEof()
{
	return this->file.peek() == EOF;
}
/*读下一个字符，有个问题就是当使用notepad++替换功能时，开头会莫名多出三个字符，且ascii值都小于0  。。
所以这里设置了这个while，当然不能把EOF给空过去。。
*/
void Compiler:: nextChar()
{
	this->c = this->file.get();
	while(this->c < 0 && this->c != -1 )
	{
		this->c = this->file.get();
	}
	//std::cout << this->c << std::endl;
}

//跳过空白字符不处理，注意维护lineCount
void Compiler::skipSpace()
{
	while (this->isNewLine() || this->isSpace() || this->isTab())
	{
		if(this->isNewLine())
			this->lineCount += 1;
		this->nextChar();
	}
}



//判断类型
//判断三大空白字符
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
//注意下划线
bool Compiler::isLetter()
{
	return this->c == '_' || (this->c >= 'A' && this->c <= 'Z')
		|| (this->c >= 'a' && this->c <= 'z');
}
//判断是否在文法给定的字符串的字符范围内
bool Compiler::isInStringRange()
{
	return this->c == 32 || this->c == 33 || (this->c >= 35 && this->c <=  126);
}
//判断两个string类型的标识符是否相等，注意这里是不区分大小写的判断
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

//专门用于处理当前是保留字还是标识符
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
	//这里每一次一开始都要自己读入一个字符，和后面的语法分析不一样
	this->tok.id = NOTYPE;
	if(this->isEof())
	{
		return ;
	}
	//先读进一个字符，再调用跳过空格方法
	this->nextChar();
	this->skipSpace();
	this->clearSym();
	//可能是标识符或保留字
	if (this->isLetter()) 
	{
		//每一次判断正确，都需要把当前字符加入到合法字符数组中，就和语法分析那里一样，一旦正确，那么读下一个单词
		this->symAppend();		
		this->nextChar();
		while (this->isLetter() || this->isNumber()) {
			this->symAppend();
			this->nextChar();
		}

		this->retract();
		this->handleSym();
		//std::cout << this->sym << std::endl;
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
				//跳过单引号
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
		//std::cout << this->sym << std::endl;
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
		//这里和<字符>不同，字符串两个双引号之间可能一个字符都没有
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
		//std::cout << this->sym << std::endl;
		return ;
	}
	if(this->isNumber())
	{
		this->symAppend();
		if(this->isZero())
		{
			this->tok.val.number = 0;
			this->tok.id = ZERO;
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
			this->tok.id = UNSIGNEDINT;
		}
		this->tok.output = new std::string(this->sym);
		//std::cout << this->sym << std::endl;
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
		//std::cout << this->sym << std::endl;
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
		//std::cout << this->sym << std::endl;
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
			this->tok.output = new std::string(this->sym);
		}
		//std::cout << this->sym << std::endl;
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
		//std::cout << this->sym << std::endl;
		return ;
	}
	//接下来就是一些单字符,接下来只需要区分它们的id就好
	this->symAppend();
	//std::cout << this->sym << std::endl;
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
