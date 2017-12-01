#include "Compiler.h"
#include "grammar.h"

const tokenType PROGRAM_BEGIN[] = {CONST, INT, CHAR, VOID};

const int PROGRAM_BEGIN_SIZE = 4;

const tokenType CONSTSTATE_BEGIN[] = {CONST};

const int CONSTSTATE_BEGIN_SIZE = 1;

const tokenType BEGINWITHVAR_BEGIN[] = {INT, CHAR, VOID};

const int BEGINWITHVAR_BEGIN_SIZE = 3;

const tokenType INT_BEGIN[] = {PLUS, MINUS, ZERO, UNSIGNEDINT};

const int INT_BEGIN_SIZE = 4;

const tokenType CONSTDEF_BEGIN[] = {INT, CHAR};

const tokenType CONSTANT_BEGIN[] = {SINGLECHAR, PLUS, MINUS, ZERO, UNSIGNEDINT};

const int CONSTANT_BEGIN_SIZE = 5;

const tokenType VARPARALIST_BEGIN[] = {ID, LPARENT, PLUS, MINUS, SINGLECHAR, ZERO, UNSIGNEDINT};

const tokenType FACTOR_BEGIN[] = {ID, LPARENT, PLUS, MINUS, SINGLECHAR, ZERO, UNSIGNEDINT};

const tokenType TERM_BEGIN[] = {ID, LPARENT, PLUS, MINUS, SINGLECHAR, ZERO, UNSIGNEDINT};

const tokenType EXPRESSION_BEGIN[] = {ID, LPARENT, PLUS, MINUS, SINGLECHAR, ZERO, UNSIGNEDINT};

const tokenType VARDEF_BEGIN[] = {LBRACKET, COMMA, SEMI};

const int VARDEF_BEGIN_SIZE = 3;

const tokenType DECHEAD_BEGIN[] = {INT, CHAR};

const int DECHEAD_BEGIN_SIZE = 2;

const tokenType PARA_BEGIN[] = {INT, CHAR};

const tokenType NOPARAFUNCDEF_BEGIN[] = {LBRACE};

const tokenType HAVEPARAFUNCDEF_BEGIN[] = {LPARENT};

const tokenType NOTMAINVOIDFUNCDEF_BEGIN[] = {ID};

const tokenType MAINDEF_BEGIN[] = {MAIN};

const tokenType BEGINWITHFUNC_BEGIN[] = {VOID, INT, CHAR};

const tokenType CONDITION_BEGIN[] = {IF};

const tokenType CASESTATEMENT_BEGIN[] = {CASE};

const tokenType CASETAB_BEGIN[] = {CASE};

const tokenType SWITCHSTATEMENT_BEGIN[] = {SWITCH};

const tokenType WHILESTATEMENT_BEGIN[] = {WHILE};

const tokenType SCANFSTATEMENT_BEGIN[] = {SCANF};

const tokenType PRINTFSTATEMENT_BEGIN[] = {PRINTF};

const tokenType RETURNSTATEMENT_BEGIN[] = {RETURN};

const tokenType STATEMENT_BEGIN[] = {IF, WHILE, LBRACE, SCANF, PRINTF, SEMI, SWITCH, RETURN, ID};

const int STATEMENT_BEGIN_SIZE = 9;

const tokenType STATEMENTLIST_BEGIN[] = {IF, WHILE, LBRACKET, SCANF, PRINTF, SEMI, SWITCH, RETURN, ID};

//TODO 这里不需要语句列，复合语句的开始单词集合

const tokenType VARSTATE_BEGIN[] = {INT, CHAR};

const tokenType COMSTATEMENT_BEGIN[] = {CONST, INT, CHAR, IF, WHILE, LBRACKET, SCANF, PRINTF, SEMI, SWITCH, RETURN, ID};

//关系运算符集合需要写一下

const tokenType RELATION_OPERATOR[] = {LESSEQU, MOREEQU, EQU, NEQU, LESS, MORE,};

const int RELATION_OPERATOR_SIZE = 6;

 

bool Compiler:: isInRange(const tokenType range[], int size)
{
	int t = this->tok.id;
	
	for(int i = 0 ; i < size ; ++i)
	{
		if(range[i] == t)
			return true;
	}
	return false;
}

void Compiler:: int_()
{
	//std::cout << "进入 <整数>" <<std::endl;
	if(this->tok.id == PLUS || this->tok.id == MINUS)
	{
		this->inSym();
		if(this->tok.id == UNSIGNEDINT)
		{
			//赋值
			this->inSym();
		}
		else{
			this->errorHandle(NOTUNSIGNEDINT);

		}
	}
	else if(this->tok.id == ZERO)
	{
		this->inSym();
	}
	else {
		//数字赋值
		this->inSym();
	}
	std::cout << "这是一个 <整数>" <<std::endl;
}

void Compiler:: constDef()
{
	//std::cout << "进入 <常量定义>" << std::endl;
	if(this->tok.id == INT)
	{
		//赋值
		do{
			this->inSym();
			if(this->tok.id == ID)
			{
				//保存标识符
				this->inSym();
				if(this->tok.id == ASSIGN)
				{
					this->inSym();
				}
				else{
					this->errorHandle(NOTASSIGN);
				}
				if(this->isInRange(INT_BEGIN, INT_BEGIN_SIZE))
				{
					this->int_();
				}
				else{
					this->errorHandle(NOTINT);
				}
			}
			else{
				this->errorHandle(NOTID);
			}

		}while(this->tok.id == COMMA);
	}
	else if(this->tok.id == CHAR)
	{
		do{
			this->inSym();
			if(this->tok.id == ID)
			{
				//报存标识符信息
				this->inSym();
				if(this->tok.id == ASSIGN)
				{
					this->inSym();
				}
				else{
					this->errorHandle(NOTASSIGN);
				}
				if(this->tok.id == SINGLECHAR)
				{
					this->inSym();
				}
				else{
					this->errorHandle(NOTSINGLECHAR);
				}

			}
			else{
				this->errorHandle(NOTID);
			}
		}while(this->tok.id == COMMA);
	}
	else{
		this->errorHandle(NOTINTORCHAR);
	}
	std::cout << "这是一个 <常量定义>" << std::endl;
}

void Compiler:: constState()
{
	//std::cout << "进入 <常量说明>" << std::endl;
	do{
		this->inSym();
		this->constDef();
		if(this->tok.id == SEMI)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
	}while(this->tok.id == CONST);

	std::cout << "这是一个 <常量说明>" << std::endl;
}

void Compiler:: constant()
{
	//std::cout << "进入 <常量>" << std::endl;
	if(this->tok.id == SINGLECHAR)
	{
		//处理字符
		this->inSym();

	}
	else{
		//那么一定是整数的开始单词
		this->int_();
	}

	std::cout << "这是一个 <常量>" << std::endl;
}

void Compiler:: varParaList()
{
	//std::cout << "进入 <值参数表>" << std::endl;
	this->expression();
	while(this->tok.id == COMMA)
	{
		this->inSym();
		this->expression();
	}
	std::cout << "这是一个 <值参数表>" << std::endl;
}

void Compiler::factor()
{
	//std::cout<< "进入 <因子>" << std::endl;
	if(this->tok.id == ID)
	{
		this->inSym();
		if(this->tok.id == LBRACKET)
		{
			this->inSym();
			this->expression();
			if(this->tok.id == RBRACKET)
			{
				this->inSym();

			}
			else{
				this->errorHandle(NOTRBRACKET);

			}
		}
		else if(this->tok.id == LPARENT){
			this->inSym();
			this->varParaList();
			if(this->tok.id == RPARENT)
			{
				//执行相关函数调用
				this->inSym();

			}
			else{
				this->errorHandle(NOTRPARENT);

			}
		}
		else{
			//检查是函数还是简单变量
		}
	}
	else if(this->tok.id == LPARENT)
	{
		this->inSym();
		this->expression();
		if(this->tok.id == RPARENT)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTRPARENT);
		}
	}
	else if(this->isInRange(CONSTANT_BEGIN, CONSTANT_BEGIN_SIZE)){
		this->constant();
	}
	else{
		this->errorHandle(NOTFACTOR);
	}

	std::cout<< "这是一个 <因子>" << std::endl;
}

void Compiler:: term()
{
	//std::cout << "进入 <项>" << std::endl;
	this->factor();
	while(this->tok.id == STAR || this->tok.id == DIV)
	{
		this->inSym();
		this->factor();
	}
	std::cout << "这是一个 <项>" << std::endl;
}

void Compiler:: expression()
{
	//std::cout << "进入 <表达式>" << std::endl;
	if(this->tok.id == PLUS || this->tok.id == MINUS)
	{
		this->inSym();
	}
	this->term();
	while(this->tok.id ==PLUS || this->tok.id == MINUS)
	{
		this->inSym();
		this->term();
	}
	std::cout << "这是一个 <表达式>" << std::endl;
}

void Compiler:: varDef()
{
	//std::cout << "进入 <变量处理定义>" << std::endl;
	if(this->tok.id == SEMI)
	{
		//处理之前的标识符
		this->inSym();
		std::cout << "这是一个 <变量处理定义>" << std::endl; ;
		return ;
	}
	else if(this->tok.id == LBRACKET)
	{
		
		this->inSym();
		if(this->tok.id == UNSIGNEDINT)
		{
			//处理数字
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
		}
		if(this->tok.id == RBRACKET)
		{
			//处理数组
			this->inSym();
		}
		else{
			this->errorHandle(NOTRBRACKET);
		}
	}
	while(this->tok.id == COMMA)
	{
		//处理之前的标识符
		this->inSym();
		if(this->tok.id == ID)
		{
			//处理标识符
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
		}
		if(this->tok.id == LBRACKET)
		{
			this->inSym();
			if(this->tok.id == UNSIGNEDINT)
			{
				//处理数字
				this->inSym();
			}
			else{
				this->errorHandle(NOTUNSIGNEDINT);
			}
			if(this->tok.id == RBRACKET)
			{
				//处理数组
				this->inSym();
			}
			else{
				this->errorHandle(NOTRBRACKET);
			}
		}
		else{
			//处理简单变量
		}

	}
	if(this->tok.id == SEMI)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTSEMI);
	}
	std::cout << "这是一个 <变量处理定义>" << std::endl;
}

void Compiler:: decHead()
{
	//std::cout << "进入 <声明头部>" << std::endl;
	if(this->tok.id == INT || this->tok.id == CHAR)
	{
		//类型是int/char
	}
	else{
		this->errorHandle(NOTINTORCHAR);
	}
	this->inSym();
	if(this->tok.id == ID)
	{
		//处理标识符
		this->inSym();
	}
	else{
		this->errorHandle(NOTID);
	}
	std::cout << "这是一个 <声明头部>" << std::endl;

}

void Compiler:: para()
{
	//std::cout << "进入 <参数>" << std::endl;
	this->decHead();
	while(this->tok.id == COMMA){
		this->inSym();
		this->decHead();
	}

	std::cout << "这是一个 <参数>" << std::endl;
}

void Compiler:: noParaFuncDef()
{
	//std::cout << "进入 <无参函数定义处理>" << std::endl;
	if(this->tok.id == LBRACE)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLBRACE);
	}
	this->comStatement();
	if(this->tok.id == RBRACE)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRBRACKET);
	}
	std::cout << "这是一个 <无参函数定义处理>" << std::endl;
}

void Compiler:: haveParaFuncDef()
{
	//std::cout << "进入 <有参函数定义处理>" << std::endl;
	this->inSym();
	this->para();
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	this->noParaFuncDef();
	std::cout << "这是一个 <有参函数定义处理>" << std::endl;
}

void Compiler:: notMainVoidFuncDef()
{
	//std::cout << "进入 <普通无返回值函数定义>" << std::endl;
	//处理标识符
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->haveParaFuncDef();
	}
	else{
		this->noParaFuncDef();
	}
	std::cout << "这是一个 <普通无返回值函数定义>" << std::endl;
}

void Compiler:: mainDef()
{
	//std::cout << "进入 <主函数定义>" << std::endl;
	if(this->tok.id == MAIN)
	{
		//处理main
		this->inSym();
	}
	else{
		this->errorHandle(NOTMAIN);
	}
	if(this->tok.id == LPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLPARENT);
	}
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	if(this->tok.id == LBRACE)
	{
		std::cout << "这是一个 <主函数定义>" << std::endl;
		return ;
	}
	else{
		this->errorHandle(NOTLBRACE);
	}
	this->comStatement();
	if(this->tok.id == RBRACE)
	{
		return ;
	}
	else{
		this->errorHandle(NOTRBRACKET);
	}

}

void Compiler:: beginWithFunc()
{
	//std::cout << "进入  <可能以函数定义开始的程序>" << std::endl;
	if(this->tok.id == VOID)
	{
		//类型是void
		this->inSym();
		if(this->tok.id == ID)
		{
			this->notMainVoidFuncDef();
			this->beginWithFunc();
		}
		else{
			this->mainDef();
		}
	}
	else{
		this->decHead();
		if(this->tok.id == LPARENT)
		{
			this->haveParaFuncDef();
		}
		else{
			this->noParaFuncDef();
		}
		this->beginWithFunc();
	}

	std::cout << "这是一个  <可能以函数定义开始的程序>" << std::endl;
}

void Compiler:: beginWithVar()
{
	//std::cout << "进入 <可能以变量定义开始的程序>" << std::endl;
	if(this->tok.id == VOID)
	{
		this->inSym();
		if(this->tok.id == ID)
		{
			this->notMainVoidFuncDef();
			this->beginWithFunc();
		}
		else{
			this->mainDef();
		}
	}
	else{
		this->decHead();
		if(this->isInRange(VARDEF_BEGIN, VARDEF_BEGIN_SIZE))
		{
			this->varDef();
			this->beginWithVar();
		}
		else if(this->tok.id == LPARENT)
		{
			this->haveParaFuncDef();
			this->beginWithFunc();
		}
		else{
			this->noParaFuncDef();
			this->beginWithFunc();
		}
	}
	std::cout << "这是一个 <可能以变量定义开始的程序>" << std::endl;

}


void Compiler:: program()
{
	//std::cout << "进入 <程序>" << std::endl;
	this->inSym();

	if(this->tok.id == CONST)
	{
		this->constState();
	}
	this->beginWithVar();

	std::cout << "这是一个 <程序>" << std::endl;

}

void Compiler:: condition()
{
	//std::cout << "进入 <条件>" << std::endl;
	this->expression();
	if(this->isInRange(RELATION_OPERATOR, RELATION_OPERATOR_SIZE))
	{
		//处理关系运算符
		this->inSym();
		this->expression();
	}
	std::cout << "这是一个 <条件>" << std::endl;
}

void Compiler:: ifStatement()
{
	//std::cout << "进入 <条件语句>" << std::endl;
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLPARENT);
	}
	this->condition();
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement();
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	if(this->tok.id == ELSE)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTELSE);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement();
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	std::cout << "这是一个 <条件语句>" << std::endl;
}

void Compiler:: caseStatement()
{
	//std::cout << "进入 <情况子语句>" << std::endl;
	this->inSym();
	if(this->isInRange(CONSTANT_BEGIN, CONSTANT_BEGIN_SIZE))
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTCONSTANT);
	}
	if(this->tok.id == COLON)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTCOLON);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement();
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	std::cout << "这是一个 <情况子语句>" << std::endl;
}

void Compiler:: caseTab()
{
	//std::cout << "进入 <情况表>" << std::endl;
	if(this->tok.id == CASE)
	{
		do{
			this->caseStatement();
		}while(this->tok.id == CASE);
	}
	else{
		this->errorHandle(NOTCASE);
	}
	std::cout << "这是一个 <情况表>" << std::endl;
}

void Compiler:: switchStatement()
{
	//std::cout << "进入 <情况语句>" << std::endl;
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLPARENT);
	}
	this->expression();
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	if(this->tok.id == LBRACE)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLBRACE);
	}
	this->caseTab();
	if(this->tok.id == DEFAULT)
	{
		this->inSym();
		if(this->tok.id == COLON)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTCOLON);
		}
		if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
		{
			this->statement();
		}
		else{
			this->errorHandle(NOTSTATEMENT);
		}
	}
	if(this->tok.id == RBRACE){
		this->inSym();
	}
	else{
		this->errorHandle(NOTRBRACE);
	}
	std::cout << "这是一个 <情况语句>" << std::endl;
}

void Compiler:: whileStatement()
{
	//std::cout << "进入 <循环语句>" << std::endl;
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLPARENT);
	}
	this->condition();
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRBRACE);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement();
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	std::cout << "这是一个 <循环语句>" << std::endl;
}

void Compiler::scanfStatement()
{
	//std::cout << "进入 <读语句>" << std::endl;; 
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLPARENT);
	}
	if(this->tok.id == ID)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTID);
	}
	while(this->tok.id == COMMA)
	{
		this->inSym();
		if(this->tok.id == ID)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
		}
	}
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	std::cout << "这是一个 <读语句>" << std::endl;
}

void Compiler:: printfStatement()
{
	//std::cout << "进入 <写语句>" << std::endl;
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLPARENT);
	}
	if(this->tok.id == STRING)
	{
		//写字符串
		this->inSym();
		if(this->tok.id == COMMA)
		{
			this->inSym();
		}
		else{
			if(this->tok.id == RPARENT)
			{
				this->inSym();
			}
			else{
				this->errorHandle(NOTRPARENT);
			}
			std::cout << "这是一个 <写语句>" << std::endl;
			return ;
		}
	}
	this->expression();
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	std::cout << "这是一个 <写语句>" << std::endl;
}

void Compiler:: returnStatement()
{
	//std::cout << "进入 <返回语句>" << std::endl;
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
		this->expression();
		if(this->tok.id == RPARENT)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTRPARENT);
		}
	}
	std::cout << "这是一个 <返回语句>" << std::endl;
}

void Compiler:: statement()
{
	//std::cout << "进入 <语句>" << std::endl;
	switch(this->tok.id)
	{
	case IF:
		this->ifStatement();
		break;
	case WHILE:
		this->whileStatement();
		break;
	case LBRACE:
		this->inSym();
		this->statementList();
		if(this->tok.id == RBRACE)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTRBRACE);
		}
		break;
	case SCANF:
		this->scanfStatement();
		if(this->tok.id == SEMI)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
		break;
	case PRINTF:
		this->printfStatement();
		if(this->tok.id == SEMI)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
		break;
	case SWITCH:
		this->switchStatement();
		break;
	case RETURN:
		this->returnStatement();
		if(this->tok.id == SEMI)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
		break;
	case ID:
		this->inSym();
		if(this->tok.id == LPARENT)
		{
			this->inSym();
			this->varParaList();
			if(this->tok.id == RPARENT)
			{
				this->inSym();
			}
			else{
				this->errorHandle(NOTRPARENT);
			}
			if(this->tok.id == SEMI)
			{
				this->inSym();
			}
			else{
				this->errorHandle(NOTSEMI);
			}
		}
		else if(this->tok.id == ASSIGN)
		{
			this->inSym();
			this->expression();
			if(this->tok.id == SEMI)
			{
				this->inSym();
			}
			else{
				this->errorHandle(NOTSEMI);
			}
		}
		else if(this->tok.id == LBRACKET)
		{
			this->inSym();
			this->expression();
			if(this->tok.id == RBRACKET)
			{
				this->inSym();
			}
			else{
				this->errorHandle(NOTRBRACKET);
			}
			if(this->tok.id == ASSIGN)
			{
				this->inSym();
			}
			else{
				this->errorHandle(NOTASSIGN);
			}
			this->expression();
			if(this->tok.id == SEMI)
			{
				this->inSym();
			}
			else{
				this->errorHandle(NOTSEMI);
			}
		}
		else if(this->tok.id == SEMI)
		{
			//无参数的函数调用
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
		break;
	case SEMI:
		std::cout << "这是一个 <空>语句" << std::endl;
		this->inSym();
		break;

	}
	std::cout << "这是一个 <语句>" << std::endl;
}

void Compiler:: statementList()
{
	//std::cout << "进入 <语句列>" << std::endl;
	while(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement();
	}
	std::cout << "这是一个 <语句列>" << std::endl;
}

void Compiler:: varState()
{
	//std::cout << "进入 <变量说明>" << std::endl;
	this->decHead();
	if(this->isInRange(VARDEF_BEGIN, VARDEF_BEGIN_SIZE))
	{
		this->varDef();
	}
	else{
		this->errorHandle(NOTVARDEF);
	}
	while(this->isInRange(DECHEAD_BEGIN, DECHEAD_BEGIN_SIZE))
	{
		this->decHead();
		if(this->isInRange(VARDEF_BEGIN, VARDEF_BEGIN_SIZE))
		{
			this->varDef();
		}
		else{
			this->errorHandle(NOTVARDEF);
		}
	}
	std::cout << "这是一个 <变量说明>" << std::endl;
}

void Compiler:: comStatement()
{
	//std::cout << "进入 <复合语句>" << std::endl;
	if(this->tok.id == CONST)
	{
		this->constState();
	}
	if(this->isInRange(DECHEAD_BEGIN, DECHEAD_BEGIN_SIZE))
	{
		this->varState();
	}
	this->statementList();

	std::cout << "这是一个 <复合语句>" << std::endl;
}