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

//TODO ���ﲻ��Ҫ����У��������Ŀ�ʼ���ʼ���

const tokenType VARSTATE_BEGIN[] = {INT, CHAR};

const tokenType COMSTATEMENT_BEGIN[] = {CONST, INT, CHAR, IF, WHILE, LBRACKET, SCANF, PRINTF, SEMI, SWITCH, RETURN, ID};

//��ϵ�����������Ҫдһ��

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
	//std::cout << "���� <����>" <<std::endl;
	if(this->tok.id == PLUS || this->tok.id == MINUS)
	{
		this->inSym();
		if(this->tok.id == UNSIGNEDINT)
		{
			//��ֵ
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
		//���ָ�ֵ
		this->inSym();
	}
	std::cout << "����һ�� <����>" <<std::endl;
}

void Compiler:: constDef()
{
	//std::cout << "���� <��������>" << std::endl;
	if(this->tok.id == INT)
	{
		//��ֵ
		do{
			this->inSym();
			if(this->tok.id == ID)
			{
				//�����ʶ��
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
				//�����ʶ����Ϣ
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
	std::cout << "����һ�� <��������>" << std::endl;
}

void Compiler:: constState()
{
	//std::cout << "���� <����˵��>" << std::endl;
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

	std::cout << "����һ�� <����˵��>" << std::endl;
}

void Compiler:: constant()
{
	//std::cout << "���� <����>" << std::endl;
	if(this->tok.id == SINGLECHAR)
	{
		//�����ַ�
		this->inSym();

	}
	else{
		//��ôһ���������Ŀ�ʼ����
		this->int_();
	}

	std::cout << "����һ�� <����>" << std::endl;
}

void Compiler:: varParaList()
{
	//std::cout << "���� <ֵ������>" << std::endl;
	this->expression();
	while(this->tok.id == COMMA)
	{
		this->inSym();
		this->expression();
	}
	std::cout << "����һ�� <ֵ������>" << std::endl;
}

void Compiler::factor()
{
	//std::cout<< "���� <����>" << std::endl;
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
				//ִ����غ�������
				this->inSym();

			}
			else{
				this->errorHandle(NOTRPARENT);

			}
		}
		else{
			//����Ǻ������Ǽ򵥱���
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

	std::cout<< "����һ�� <����>" << std::endl;
}

void Compiler:: term()
{
	//std::cout << "���� <��>" << std::endl;
	this->factor();
	while(this->tok.id == STAR || this->tok.id == DIV)
	{
		this->inSym();
		this->factor();
	}
	std::cout << "����һ�� <��>" << std::endl;
}

void Compiler:: expression()
{
	//std::cout << "���� <���ʽ>" << std::endl;
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
	std::cout << "����һ�� <���ʽ>" << std::endl;
}

void Compiler:: varDef()
{
	//std::cout << "���� <����������>" << std::endl;
	if(this->tok.id == SEMI)
	{
		//����֮ǰ�ı�ʶ��
		this->inSym();
		std::cout << "����һ�� <����������>" << std::endl; ;
		return ;
	}
	else if(this->tok.id == LBRACKET)
	{
		
		this->inSym();
		if(this->tok.id == UNSIGNEDINT)
		{
			//��������
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
		}
		if(this->tok.id == RBRACKET)
		{
			//��������
			this->inSym();
		}
		else{
			this->errorHandle(NOTRBRACKET);
		}
	}
	while(this->tok.id == COMMA)
	{
		//����֮ǰ�ı�ʶ��
		this->inSym();
		if(this->tok.id == ID)
		{
			//�����ʶ��
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
				//��������
				this->inSym();
			}
			else{
				this->errorHandle(NOTUNSIGNEDINT);
			}
			if(this->tok.id == RBRACKET)
			{
				//��������
				this->inSym();
			}
			else{
				this->errorHandle(NOTRBRACKET);
			}
		}
		else{
			//����򵥱���
		}

	}
	if(this->tok.id == SEMI)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTSEMI);
	}
	std::cout << "����һ�� <����������>" << std::endl;
}

void Compiler:: decHead()
{
	//std::cout << "���� <����ͷ��>" << std::endl;
	if(this->tok.id == INT || this->tok.id == CHAR)
	{
		//������int/char
	}
	else{
		this->errorHandle(NOTINTORCHAR);
	}
	this->inSym();
	if(this->tok.id == ID)
	{
		//�����ʶ��
		this->inSym();
	}
	else{
		this->errorHandle(NOTID);
	}
	std::cout << "����һ�� <����ͷ��>" << std::endl;

}

void Compiler:: para()
{
	//std::cout << "���� <����>" << std::endl;
	this->decHead();
	while(this->tok.id == COMMA){
		this->inSym();
		this->decHead();
	}

	std::cout << "����һ�� <����>" << std::endl;
}

void Compiler:: noParaFuncDef()
{
	//std::cout << "���� <�޲κ������崦��>" << std::endl;
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
	std::cout << "����һ�� <�޲κ������崦��>" << std::endl;
}

void Compiler:: haveParaFuncDef()
{
	//std::cout << "���� <�вκ������崦��>" << std::endl;
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
	std::cout << "����һ�� <�вκ������崦��>" << std::endl;
}

void Compiler:: notMainVoidFuncDef()
{
	//std::cout << "���� <��ͨ�޷���ֵ��������>" << std::endl;
	//�����ʶ��
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->haveParaFuncDef();
	}
	else{
		this->noParaFuncDef();
	}
	std::cout << "����һ�� <��ͨ�޷���ֵ��������>" << std::endl;
}

void Compiler:: mainDef()
{
	//std::cout << "���� <����������>" << std::endl;
	if(this->tok.id == MAIN)
	{
		//����main
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
		std::cout << "����һ�� <����������>" << std::endl;
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
	//std::cout << "����  <�����Ժ������忪ʼ�ĳ���>" << std::endl;
	if(this->tok.id == VOID)
	{
		//������void
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

	std::cout << "����һ��  <�����Ժ������忪ʼ�ĳ���>" << std::endl;
}

void Compiler:: beginWithVar()
{
	//std::cout << "���� <�����Ա������忪ʼ�ĳ���>" << std::endl;
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
	std::cout << "����һ�� <�����Ա������忪ʼ�ĳ���>" << std::endl;

}


void Compiler:: program()
{
	//std::cout << "���� <����>" << std::endl;
	this->inSym();

	if(this->tok.id == CONST)
	{
		this->constState();
	}
	this->beginWithVar();

	std::cout << "����һ�� <����>" << std::endl;

}

void Compiler:: condition()
{
	//std::cout << "���� <����>" << std::endl;
	this->expression();
	if(this->isInRange(RELATION_OPERATOR, RELATION_OPERATOR_SIZE))
	{
		//�����ϵ�����
		this->inSym();
		this->expression();
	}
	std::cout << "����һ�� <����>" << std::endl;
}

void Compiler:: ifStatement()
{
	//std::cout << "���� <�������>" << std::endl;
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
	std::cout << "����һ�� <�������>" << std::endl;
}

void Compiler:: caseStatement()
{
	//std::cout << "���� <��������>" << std::endl;
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
	std::cout << "����һ�� <��������>" << std::endl;
}

void Compiler:: caseTab()
{
	//std::cout << "���� <�����>" << std::endl;
	if(this->tok.id == CASE)
	{
		do{
			this->caseStatement();
		}while(this->tok.id == CASE);
	}
	else{
		this->errorHandle(NOTCASE);
	}
	std::cout << "����һ�� <�����>" << std::endl;
}

void Compiler:: switchStatement()
{
	//std::cout << "���� <������>" << std::endl;
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
	std::cout << "����һ�� <������>" << std::endl;
}

void Compiler:: whileStatement()
{
	//std::cout << "���� <ѭ�����>" << std::endl;
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
	std::cout << "����һ�� <ѭ�����>" << std::endl;
}

void Compiler::scanfStatement()
{
	//std::cout << "���� <�����>" << std::endl;; 
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
	std::cout << "����һ�� <�����>" << std::endl;
}

void Compiler:: printfStatement()
{
	//std::cout << "���� <д���>" << std::endl;
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
		//д�ַ���
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
			std::cout << "����һ�� <д���>" << std::endl;
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
	std::cout << "����һ�� <д���>" << std::endl;
}

void Compiler:: returnStatement()
{
	//std::cout << "���� <�������>" << std::endl;
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
	std::cout << "����һ�� <�������>" << std::endl;
}

void Compiler:: statement()
{
	//std::cout << "���� <���>" << std::endl;
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
			//�޲����ĺ�������
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
		break;
	case SEMI:
		std::cout << "����һ�� <��>���" << std::endl;
		this->inSym();
		break;

	}
	std::cout << "����һ�� <���>" << std::endl;
}

void Compiler:: statementList()
{
	//std::cout << "���� <�����>" << std::endl;
	while(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement();
	}
	std::cout << "����һ�� <�����>" << std::endl;
}

void Compiler:: varState()
{
	//std::cout << "���� <����˵��>" << std::endl;
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
	std::cout << "����һ�� <����˵��>" << std::endl;
}

void Compiler:: comStatement()
{
	//std::cout << "���� <�������>" << std::endl;
	if(this->tok.id == CONST)
	{
		this->constState();
	}
	if(this->isInRange(DECHEAD_BEGIN, DECHEAD_BEGIN_SIZE))
	{
		this->varState();
	}
	this->statementList();

	std::cout << "����һ�� <�������>" << std::endl;
}