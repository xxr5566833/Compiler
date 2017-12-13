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

void Compiler:: int_(int *value)
{
	//std::cout << "���� <����>" <<std::endl;
	bool flag = true;
	int result = 0;
	if(this->tok.id == PLUS || this->tok.id == MINUS)
	{
		flag = this->tok.id == PLUS;
		this->inSym();
		if(this->tok.id == UNSIGNEDINT)
		{
			result = this->tok.val.number;
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
		//˵���������޷�������
		result = this->tok.val.number;
		this->inSym();
	}
	*value = flag ? result : - result;
	std::cout << "����һ�� <����>" <<std::endl;
}

void Compiler:: constDef()
{
	//std::cout << "���� <��������>" << std::endl;
	eSymType symboltype = CONSTSYM;
	if(this->tok.id == INT)
	{
		eRetType returntype = INTRET;
		do{
			int value = 0;
			std::string *name = 0;
			this->inSym();
			if(this->tok.id == ID)
			{
				name =this->tok.val.str; 
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
					this->int_(&value);
					symbol *sym = 0;
					if(!this->find(name, &sym, true))
					{
						this->push(name, returntype, symboltype, value, this->lineCount);
					}
					else{
						this->errorHandle(DUPLICATEDEF);
					}
				}
				else{
					this->errorHandle(NOTINT);
				}
			}
			else{
				//���Ǳ�ʶ������ô��ʲôҲ����
				this->errorHandle(NOTID);
			}

		}while(this->tok.id == COMMA);
	}
	else if(this->tok.id == CHAR)
	{
		eRetType returntype = CHARRET;
		do{
			int value = 0;
			std::string *name = 0;
			this->inSym();
			if(this->tok.id == ID)
			{
				//�����ʶ����Ϣ
				name =this->tok.val.str; 
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
					value = this->tok.val.c;
					symbol *sym = 0;
					if(!this->find(name, &sym, true))
					{
						this->push(name, returntype, symboltype, value, this->lineCount);
					}
					else{
						this->errorHandle(DUPLICATEDEF);
						//TODO ����
					}
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

void Compiler:: constant(int *value, eRetType *rettype)
{
	//std::cout << "���� <����>" << std::endl;
	if(this->tok.id == SINGLECHAR)
	{
		//�����ַ�
		*rettype = CHARRET;
		*value = this->tok.val.c;
		this->inSym();

	}
	else{
		//��ôһ���������Ŀ�ʼ����
		*rettype = INTRET;
		this->int_(value);
	}

	std::cout << "����һ�� <����>" << std::endl;
}

void Compiler:: varParaList(symbol *sym)
{
	//std::cout << "���� <ֵ������>" << std::endl;
	eRetType type = NOTTYPE;
	int paraindex = 0;
	std::string *temppara = new std::string();
	this->expression(&type, temppara);
	this->pushMidCode(REALPARAOP, new std::string(), new std::string(), temppara);
	if(sym->feature > paraindex)
	{
		if(sym->paraList[paraindex] != type)
		{
			this->errorHandle(PARATYPEDISMATCH);
			return ;
		}
	}
	else{
		this->errorHandle(PARANUMDISMATCH);
		return ;
	}
	paraindex ++;
	while(this->tok.id == COMMA)
	{
		eRetType type = NOTTYPE;
		this->inSym();
		std::string *temppara = new std::string();
		this->expression(&type, temppara);
		this->pushMidCode(REALPARAOP, new std::string(), new std::string(), temppara);
		if(sym->feature > paraindex)
		{
			if(sym->paraList[paraindex] != type)
			{
				this->errorHandle(PARATYPEDISMATCH);
			}
		}
		else{
			this->errorHandle(PARANUMDISMATCH);
		}
		paraindex ++;
	}
	if(paraindex != sym->feature)
	{
		this->errorHandle(PARANUMDISMATCH);
	}
	std::cout << "����һ�� <ֵ������>" << std::endl;
}

void Compiler::factor(eRetType *resulttype, std::string *operand)
{
	//std::cout<< "���� <����>" << std::endl;
	//�������ƣ���󸳸� *operand
	std::string *resultoperand = new std::string();
	if(this->tok.id == ID)
	{
		symbol *sym = 0;
		if(!this->find(this->tok.val.str, &sym, false))
		{
			this->errorHandle(IDNOTDEF);
			return ;
		}
		*resulttype = sym->returnType;
		this->inSym();
		if(this->tok.id == LBRACKET)
		{
			//˵��������Ԫ��ֵ
			if(sym->symbolType != ARRAYSYM)
			{
				this->errorHandle(NOTANARRAY);
				return ;
			}
			eRetType type = NOTTYPE;
			this->inSym();
			std::string *temp = new std::string();
			this->expression(&type, temp);
			if(type != INTRET)
			{
				this->errorHandle(NOTAINT);
				//TODO��������
				return ;
			}
			this->genTemp(resultoperand);
			this->pushMidCode(RARRAYOP, sym->name, temp, resultoperand);
			if(this->tok.id == RBRACKET)
			{
				this->inSym();

			}
			else{
				this->errorHandle(NOTRBRACKET);

			}
		}
		else if(this->tok.id == LPARENT){
			//˵����һ����������
			if(sym->symbolType != FUNCSYM)
			{
				this->errorHandle(NOTAFUNC);
				return ;
			}
			if(sym->returnType == VOID)
			{
				this->errorHandle(NORETURNVALUE);
				return ;
			}
			this->inSym();
			this->varParaList(sym);
			if(this->tok.id == RPARENT)
			{
				//ִ����غ�������
				this->pushMidCode(CALLOP, new std::string(), new std::string(), sym->name);
				resultoperand = new std::string("#RET");
				this->inSym();
			}
			else{
				this->errorHandle(NOTRPARENT);

			}
		}
		else{
			if(sym->symbolType == SIMPLESYM || sym->symbolType == PARASYM)
			{
				//��ʶ��ֱ����Ϊ����������
				resultoperand = sym->name;
			}
			else if(sym->symbolType == FUNCSYM){
				if(sym->feature != 0)
				{
					//���ﶼ���޲κ������ã��������ﲻ����һ���вκ���
					this->errorHandle(NOTANOPARAFUNC);
					return ;
				}
				this->pushMidCode(CALLOP, new std::string(), new std::string(), sym->name);
				resultoperand = new std::string("#RET");
			}
			//��Ҫ���ǳ�����ʶ��
			else if(sym->symbolType == CONSTSYM){
				resultoperand = sym->name;
			}
			else{
				this->errorHandle(INVALIDID);
			}
		}
	}
	else if(this->tok.id == LPARENT)
	{
		this->inSym();
		this->expression(resulttype, resultoperand);
		if(this->tok.id == RPARENT)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTRPARENT);
		}
	}
	else if(this->isInRange(CONSTANT_BEGIN, CONSTANT_BEGIN_SIZE)){
		int value;
		this->constant(&value, resulttype);
		std::string *constvalue = new std::string();
		this->int2string(constvalue, value);
		*resultoperand = *constvalue;
	}
	else{
		this->errorHandle(NOTFACTOR);
	}
	*operand = *resultoperand;

	std::cout<< "����һ�� <����>" << std::endl;
}

void Compiler:: term(eRetType *resulttype, std::string *operand)
{
	//std::cout << "���� <��>" << std::endl;
	//��������term�����շ��ص��м����
	std::string *factoroperand = new std::string();
	this->factor(resulttype, factoroperand);
	std::string *resultoperand = new std::string();
	//����ͳһ�ٲ���һ����ʱ������ȡ��factor�����Ĳ����������������ʱ������Ϊ���Ĳ�����
	this->genTemp(resultoperand);
	this->pushMidCode(ASSIGNOP, factoroperand, new std::string(), resultoperand);
	while(this->tok.id == STAR || this->tok.id == DIV)
	{
		bool isstar = this->tok.id == STAR;
		eRetType fact = NOTTYPE;
		std::string *factoroperand2 = new std::string();
		this->inSym();
		this->factor(&fact, factoroperand2);
		if(isstar)
		{
			this->pushMidCode(MULOP, resultoperand, factoroperand2, resultoperand);
		}
		else{
			this->pushMidCode(DIVOP, resultoperand, factoroperand2, resultoperand);
		}
		*resulttype = INTRET;
	}
	*operand = *resultoperand;
	std::cout << "����һ�� <��>" << std::endl;
}

void Compiler:: expression(eRetType *resulttype, std::string *operand)
{
	//std::cout << "���� <���ʽ>" << std::endl;
	//��ʾ����+ - ����У���ôΪtrue
	std::string *termoperand1 = new std::string();
	bool flag = false;
	bool neg = false;
	if(this->tok.id == PLUS || this->tok.id == MINUS)
	{
		//������Ӧ����Ԫʽ
		flag = true;
		neg = MINUS == this->tok.id;
		this->inSym();
	}
	this->term(resulttype, termoperand1);
	if(neg)
	{
		this->pushMidCode(SUBOP, new std::string("0"), termoperand1, termoperand1);
	}
	*resulttype = flag ? INTRET : *resulttype;
	while(this->tok.id ==PLUS || this->tok.id == MINUS)
	{
		bool isplus = this->tok.id == PLUS;
		eRetType result = NOTTYPE;
		std::string *termoperand2 = new std::string();
		this->inSym();
		this->term(&result, termoperand2);
		*resulttype = INTRET;
		if(isplus)
		{
			this->pushMidCode(ADDOP, termoperand1, termoperand2, termoperand1);
		}
		else{
			this->pushMidCode(SUBOP, termoperand1, termoperand2, termoperand1);
		}
	}
	*operand = *termoperand1;
	std::cout << "����һ�� <���ʽ>" << std::endl;
}

void Compiler:: varDef(eRetType rettype, std::string *name)
{
	//std::cout << "���� <�������崦��>" << std::endl;
	symbol *sym = 0;
	if(this->find(name, &sym, true))
	{
		this->errorHandle(DUPLICATEDEF);
		//�����ݶ�����Ϊֱ��return
		return ;
	}
	if(this->tok.id == SEMI)
	{
		//����֮ǰ�ļ򵥱�����ʶ��
		this->push(name, rettype, SIMPLESYM, -1, this->lineCount);
		this->inSym();
		std::cout << "����һ�� <�������崦��>" << std::endl; ;
		return ;
	}
	else if(this->tok.id == LBRACKET)
	{
		//����[��ͷ����ô�Ǹ�����
		int feature = -1;
		this->inSym();
		if(this->tok.id == UNSIGNEDINT)
		{
			//��������
			feature = this->tok.val.number;
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
		}
		if(this->tok.id == RBRACKET)
		{
			//��������
			this->push(name, rettype, ARRAYSYM, feature, this->lineCount);
			this->inSym();
		}
		else{
			this->errorHandle(NOTRBRACKET);
		}
	}
	else
	{
		//˵����ʱ��һ�����ţ���ô������Ҫ������֮ǰ�ļ򵥱�����ʶ����ע�����ﲻ��ҪinSym�ˣ�ֱ�ӽ��������ѭ��
		this->push(name, rettype, SIMPLESYM, -1, this->lineCount);
	}
	while(this->tok.id == COMMA)
	{
		std::string *symname = 0;
		this->inSym();
		if(this->tok.id == ID)
		{
			symbol *sym = 0;
			if(this->find(this->tok.val.str, &sym, true))
			{
				this->errorHandle(DUPLICATEDEF);
				//�������ֱ��return
				return ;
			}
			//�����ڱ�ʶ����Ϣ
			symname = this->tok.val.str; 
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
		}
		int feature = -1;
		if(this->tok.id == LBRACKET)
		{
			//˵����һ������
			this->inSym();
			if(this->tok.id == UNSIGNEDINT)
			{
				//��������
				feature = this->tok.val.number;
				this->inSym();
			}
			else{
				this->errorHandle(NOTUNSIGNEDINT);
			}
			if(this->tok.id == RBRACKET)
			{
				//��������
				this->push(symname, rettype, ARRAYSYM, feature, this->lineCount);
				this->inSym();
			}
			else{
				this->errorHandle(NOTRBRACKET);
			}
		}
		else{
			//����򵥱���
			this->push(symname, rettype, SIMPLESYM, -1, this->lineCount);
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

void Compiler:: decHead(eRetType *rettype, std::string **name)
{
	//std::cout << "���� <����ͷ��>" << std::endl;
	if(this->tok.id == INT)
	{
		*rettype = INTRET;
	
	}
	else if(this->tok.id == CHAR)
	{
		*rettype = CHARRET;
	}
	else{
		this->errorHandle(NOTINTORCHAR);
	}
	this->inSym();
	if(this->tok.id == ID)
	{
		//�����ʶ��
		*name = this->tok.val.str;
		this->inSym();
	}
	else{
		this->errorHandle(NOTID);
	}
	std::cout << "����һ�� <����ͷ��>" << std::endl;

}

void Compiler:: para(symbol *sym)
{
	//std::cout << "���� <����>" << std::endl;
	std::string *name = 0;
	eRetType rettype = NOTTYPE;
	this->decHead(&rettype, &name);
	if(!name)
		return ;
	sym->paraList[sym->feature++] = rettype;
	symbol *tempsym = 0;
	if(this->find(name, &tempsym, true))
	{
		this->errorHandle(DUPLICATEDEF);
		return ;
	}
	else{
		this->push(name, rettype, PARASYM, -1, this->lineCount);
	}
	while(this->tok.id == COMMA){
		std::string *name = 0;
		eRetType rettype = NOTTYPE;
		this->inSym();
		this->decHead(&rettype, &name);
		if(!name )
			return ;
		sym->paraList[sym->feature++] = rettype;
		symbol *tempsym = 0;
		if(this->find(name, &tempsym, true))
		{
			this->errorHandle(DUPLICATEDEF);
			return ;
		}
		else{
			this->push(name, rettype, PARASYM, -1, this->lineCount);
		}
	}

	std::cout << "����һ�� <����>" << std::endl;
}

void Compiler:: noParaFuncDef(symbol *sym)
{
	//std::cout << "���� <�޲κ������崦��>" << std::endl;
	
	//ͬʱע��ά�����ű�index
	if(this->tok.id == LBRACE)
	{
		//index ָ�����ĵ�һ����ʶ��
		this->inSym();
	}
	else{
		this->errorHandle(NOTLBRACE);
	}
	bool returnflag = false;
	this->pushMidCode(FUNCBEGINOP, new std::string(), new std::string(), sym->name);
	this->comStatement(&returnflag, sym->returnType);
	if(this->tok.id == RBRACE)
	{
		//�˳�����
		this->inSym();
		if(!returnflag && sym->returnType != VOIDRET)
		{
			//���û���κ�return�����ҷ����������з���ֵ�����ͣ���ô����
			this->errorHandle(NONERETURN);
			return ;
		}
	}
	else{
		this->errorHandle(NOTRBRACKET);
	}
	this->pushMidCode(RETOP, new std::string(), new std::string(), sym->name);
	std::cout << "����һ�� <�޲κ������崦��>" << std::endl;
}

void Compiler:: haveParaFuncDef(symbol *sym)
{
	//std::cout << "���� <�вκ������崦��>" << std::endl;
	this->inSym();
	this->para(sym);
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	this->noParaFuncDef(sym);
	std::cout << "����һ�� <�вκ������崦��>" << std::endl;
}


void Compiler:: notMainVoidFuncDef()
{
	//std::cout << "���� <��ͨ�޷���ֵ��������>" << std::endl;
	eRetType rettype = VOIDRET;
	std::string *name = this->tok.val.str;
	symbol *sym = 0;;
	//�����ʶ��
	if(this->find(name, &sym, true))
	{
		this->errorHandle(DUPLICATEDEF);
		return ;
	}
	else{
		sym = this->push(name, rettype, FUNCSYM, 0, this->lineCount);
	}
	this->inSym();
	//����index������address����Ϊ����һ���µĺ�������Ҫ������������ľֲ������ĵ�ַ
	this->inFunc();
	if(this->tok.id == LPARENT)
	{
		this->haveParaFuncDef(sym);
	}
	else{
		this->noParaFuncDef(sym);
	}
	this->pop();
	std::cout << "����һ�� <��ͨ�޷���ֵ��������>" << std::endl;
}

void Compiler:: mainDef()
{
	//std::cout << "���� <����������>" << std::endl;
	std::string *name = new std::string("main");
	if(this->tok.id == MAIN)
	{
		//����main
		this->inSym();
	}
	else{
		this->errorHandle(NOTMAIN);
	}
	//��main����������ű�
	this->push(name, VOIDRET, FUNCSYM, 0, this->lineCount);
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
		this->inFunc();
		this->inSym();
	}
	else{
		this->errorHandle(NOTLBRACE);
	}
	bool returnflag = false;
	this->pushMidCode(FUNCBEGINOP, new std::string(), new std::string(), new std::string("main"));
	this->comStatement(&returnflag, VOIDRET);
	//����������void������Ҫ�����û��return
	if(this->tok.id == RBRACE)
	{
		this->pop();
		std::cout << "����һ�� <����������>" << std::endl;

		this->pushMidCode(EXITOP, new std::string(), new std::string(), new std::string());
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
		std::string *name = 0;
		eRetType rettype = NOTTYPE;
		symbol *sym = 0;
		this->decHead(&rettype, &name);
		//�������������ʶ��
		if(!name)
		{
			return ;
		}
		if(this->find(name, &sym, true))
		{
			this->errorHandle(DUPLICATEDEF);
			return ;
		}
		else{
			sym = this->push(name, rettype, FUNCSYM, 0, this->lineCount);
		}
		this->inFunc();
		if(this->tok.id == LPARENT)
		{
			this->haveParaFuncDef(sym);
		}
		else{
			this->noParaFuncDef(sym);
		}
		this->pop();
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
		std::string *name = 0;
		eRetType rettype = NOTTYPE;
		symbol *sym = 0;
		this->decHead(&rettype, &name);
		if(!name)
			return;
		if(this->isInRange(VARDEF_BEGIN, VARDEF_BEGIN_SIZE))
		{
			this->varDef(rettype, name);
			this->beginWithVar();
		}
		else if(this->tok.id == LPARENT)
		{
			symbol *sym = 0;
			if(this->find(name, &sym, true))
			{
				this->errorHandle(DUPLICATEDEF);
				return ;
			}
			else{
				sym = this->push(name, rettype, FUNCSYM, 0, this->lineCount);
			}
			this->inFunc();
			this->haveParaFuncDef(sym);
			this->pop();
			this->beginWithFunc();
		}
		else{
			symbol *sym = 0;
			if(this->find(name, &sym, true))
			{
				this->errorHandle(DUPLICATEDEF);
				return ;
			}
			else{
				sym = this->push(name, rettype, FUNCSYM, 0, this->lineCount);
			}
			this->inFunc();
			this->noParaFuncDef(sym);
			this->pop();
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

void Compiler:: condition(std::string *label)
{
	//std::cout << "���� <����>" << std::endl;
	eRetType rettype = NOTTYPE;
	std::string *tempoperand1 = new std::string();
	this->expression(&rettype, tempoperand1);
	if(this->isInRange(RELATION_OPERATOR, RELATION_OPERATOR_SIZE))
	{
		//�����ϵ�����
		int token = this->tok.id ;

		eRetType rettype2 = NOTTYPE;
		std::string *tempoperand2 = new std::string();
		this->inSym();
		this->expression(&rettype2, tempoperand2);
		//������Ͳ�һ������ô����ͳһת��Ϊint����
		//�������
		switch(token)
		{
		case EQU:
			this->pushMidCode(NEQUOP, tempoperand1, tempoperand2, label);
			break;
		case NEQU:
			this->pushMidCode(EQUOP, tempoperand1, tempoperand2, label);
			break;
		case LESSEQU:
			this->pushMidCode(MOREOP, tempoperand1, tempoperand2, label);
			break;
		case LESS:
			this->pushMidCode(MOREEQUOP, tempoperand1, tempoperand2, label);
			break;
		case MORE:
			this->pushMidCode(LESSEQUOP, tempoperand1, tempoperand2, label);
			break;
		case MOREEQU:
			this->pushMidCode(LESSOP, tempoperand1, tempoperand2, label);
			break;

		}
	}
	else{
		this->pushMidCode(EQUOP, tempoperand1, new std::string("0"), label);
	}
	
	std::cout << "����һ�� <����>" << std::endl;
}

void Compiler:: ifStatement(bool *returnflag, eRetType returntype)
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
	std::string *elselabel = new std::string();
	this->genLabel(elselabel);
	std::string *endlabel = new std::string();
	this->genLabel(endlabel);
	this->condition(elselabel);
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), endlabel);
	this->pushMidCode(LABOP, new std::string(), new std::string(), elselabel);
	if(this->tok.id == ELSE)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTELSE);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(LABOP, new std::string(), new std::string(), endlabel);
	std::cout << "����һ�� <�������>" << std::endl;
}

void Compiler:: caseStatement(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *nextlab)
{
	//std::cout << "���� <��������>" << std::endl;
	this->inSym();
	eRetType casetype = NOTTYPE;
	int value = 0;
	if(this->isInRange(CONSTANT_BEGIN, CONSTANT_BEGIN_SIZE))
	{
		this->constant(&value, &casetype);
		if(casetype != switchtype)
		{
			this->errorHandle(CASESWITCHDISMATCH);
			return ;
		}
		std::string *constoperand = new std::string();
		this->genTemp(constoperand);
		std::string *constvalue = new std::string();
		this->int2string(constvalue, value);
		this->pushMidCode(ASSIGNOP, constvalue, new std::string(), constoperand);
		this->pushMidCode(NEQUOP, constoperand, switchtemp, nextlab);
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
		this->statement(returnflag, returntype);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), donelab);
	std::cout << "����һ�� <��������>" << std::endl;
}

void Compiler:: caseTab(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab)
{
	//std::cout << "���� <�����>" << std::endl;
	if(this->tok.id == CASE)
	{
		do{
			std::string *nextlab = new std::string();
			this->genLabel(nextlab);
			this->caseStatement(switchtype, switchtemp, returnflag, returntype, donelab, nextlab);
			this->pushMidCode(LABOP, new std::string(), new std::string(), nextlab);
		}while(this->tok.id == CASE);
	}
	else{
		this->errorHandle(NOTCASE);
	}
	std::cout << "����һ�� <�����>" << std::endl;
}

void Compiler:: switchStatement(bool *returnflag, eRetType returntype)
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
	eRetType switchtype = NOTTYPE;
	std::string *switchtemp = new std::string();
	this->expression(&switchtype, switchtemp);
	
	//����ʱ�ı��
	std::string *done = new std::string();
	this->genLabel(done);
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
	this->caseTab(switchtype, switchtemp, returnflag, returntype, done);
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
			this->statement(returnflag, returntype);
		}
		else{
			this->errorHandle(NOTSTATEMENT);
		}
	}
	this->pushMidCode(LABOP, new std::string(), new std::string(), done);
	if(this->tok.id == RBRACE){
		this->inSym();
	}
	else{
		this->errorHandle(NOTRBRACE);
	}
	std::cout << "����һ�� <������>" << std::endl;
}

void Compiler:: whileStatement(bool *returnflag, eRetType returntype)
{
	//std::cout << "���� <ѭ�����>" << std::endl;
	std::string *whilelab = new std::string();
	this->genLabel(whilelab);
	std::string *endlab = new std::string();
	this->genLabel(endlab);
	this->pushMidCode(LABOP, new std::string(), new std::string(), whilelab);
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTLPARENT);
	}
	this->condition(endlab);
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRBRACE);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), whilelab);
	this->pushMidCode(LABOP, new std::string(), new std::string(), endlab);
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
		//���������ʶ��
		symbol *sym = 0;
		if(!this->find(this->tok.val.str, &sym, false))
		{
			this->errorHandle(IDNOTDEF);
			return ;
		}
		if(sym->symbolType != SIMPLESYM && sym->symbolType != PARASYM)
		{
			this->errorHandle(NOTASIMPLE);
		}
		//���ݱ�ʶ�������ͣ��ж��������ַ�������������
		switch(sym->returnType)
		{
		case INTRET:
			this->pushMidCode(SCANFOP, new std::string("int"), new std::string(), sym->name);
			break;
		case CHARRET:
			this->pushMidCode(SCANFOP, new std::string("char"), new std::string(), sym->name);
			break;
		}
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
			//���������ʶ��
			symbol *sym = 0;
			if(!this->find(this->tok.val.str, &sym, false))
			{
				this->errorHandle(IDNOTDEF);
				return ;
			}
			if(sym->symbolType != SIMPLESYM && sym->symbolType != PARASYM)
			{
				this->errorHandle(NOTASIMPLE);
			}
			switch(sym->returnType)
			{
			case INTRET:
				this->pushMidCode(SCANFOP, new std::string("int"), new std::string(), sym->name);
				break;
			case CHARRET:
				this->pushMidCode(SCANFOP, new std::string("char"), new std::string(), sym->name);
				break;
			}
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
		this->pushString(this->tok.val.str);
		std::string *num = new std::string();
		this->int2string(num, this->stringNum - 1);
		this->pushMidCode(PRINTFOP, new std::string(), new std::string(), num);
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
	eRetType rettype = NOTTYPE;
	std::string *temp = new std::string();
	this->expression(&rettype, temp);
	switch(rettype)
	{
	case INTRET:
		this->pushMidCode(PRINTFOP, new std::string("int"), new std::string(), temp);
		break;
	case CHARRET:
		this->pushMidCode(PRINTFOP, new std::string("char"), new std::string(), temp);
		break;
	}
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	std::cout << "����һ�� <д���>" << std::endl;
}

void Compiler:: returnStatement(bool *returnflag, eRetType returntype)
{
	//std::cout << "���� <�������>" << std::endl;
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
		eRetType rettype = NOTTYPE;
		std::string *temp = new std::string();
		this->expression(&rettype, temp);
		if(returntype == VOIDRET)
		{
			this->errorHandle(CANNOTRETURN);
			return ;
		}
		else 
		{
			//int / char
			this->pushMidCode(ASSIGNOP, temp, new std::string(), new std::string("#RET"));
			if(returntype != rettype)
			{
				this->errorHandle(RETURNTYPEDISMATCH);
				return ;
			}
		}
		*returnflag = true;
		if(this->tok.id == RPARENT)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTRPARENT);
		}
	}
	if(returntype != VOIDRET && !(*returnflag) )
	{
		//���˵��int ������ char��ȴʲô�������أ�Ҳ����
		this->errorHandle(RETURNTYPEDISMATCH);
		return ;
	}
	std::cout << "����һ�� <�������>" << std::endl;
}

void Compiler:: statement(bool *returnflag, eRetType returntype)
{
	//std::cout << "���� <���>" << std::endl;
	std::string *name = this->tok.val.str;
	symbol *sym = 0;
	switch(this->tok.id)
	{
	case IF:
		this->ifStatement(returnflag, returntype);
		break;
	case WHILE:
		this->whileStatement(returnflag, returntype);
		break;
	case LBRACE:
		this->inSym();
		this->statementList(returnflag, returntype);
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
		this->switchStatement(returnflag, returntype);
		break;
	case RETURN:
		this->returnStatement(returnflag, returntype);
		if(this->tok.id == SEMI)
		{
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
		break;
	case ID:
		if(!this->find(name, &sym, false))
		{
			this->errorHandle(IDNOTDEF);
			return ;
		}
		this->inSym();
		if(this->tok.id == LPARENT)
		{
			//˵����һ���вκ������ã���Ҫ������ǲ���һ������
			if(sym->symbolType != FUNCSYM)
			{
				this->errorHandle(NOTAFUNC);
				return ;
			}
			this->inSym();
			this->varParaList(sym);
			this->pushMidCode(CALLOP, new std::string(), new std::string(), sym->name);
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
			//˵���Ǹ��򵥱������߲���������������Ҫ���򵥱���
			if(sym->symbolType != SIMPLESYM && sym->symbolType != PARASYM)
			{
				this->errorHandle(NOTASIMPLE);
			}
			this->inSym();
			eRetType rettype = NOTTYPE;
			std::string *expressoperand = new std::string();
			this->expression(&rettype, expressoperand);
			//����ֵ
			//����������鸳ֵһ���������Ϊ
			//char -> int ��ô��char ��ascii��int
			//char -> char ��ô��ֱ�Ӱ�char��intֵ��char
			//int-> char ��int��ֵ��char ����ǲ�������ģ�
			//int->int
			if(sym->returnType == CHARRET && rettype == INTRET)
			{
				this->errorHandle(INTTOCHARNOTALLOW);
				return ;
			}
			this->pushMidCode(ASSIGNOP, expressoperand, new std::string(), sym->name);
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
			//˵����һ�������������Ҫ���
			if(sym->symbolType != ARRAYSYM)
			{
				this->errorHandle(NOTANARRAY);
			}
			this->inSym();
			eRetType rettype = NOTTYPE;
			std::string *indexoperand = new std::string();
			this->expression(&rettype, indexoperand);


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
			eRetType righttype = NOTTYPE;
			std::string *tempoperand = new std::string();
			this->expression(&righttype, tempoperand);
			//�����int��char���͸�ֵ����ô������
			this->pushMidCode(LARRAYOP, tempoperand, indexoperand, name);
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
			//�޲����ĺ������ã���Ҫ�������ǲ���һ���޲κ���
			if(sym->symbolType != FUNCSYM || sym->feature != 0)
			{
				this->errorHandle(NOTANOPARAFUNC);
				return ;
			}
			this->pushMidCode(CALLOP, new std::string(), new std::string(), name);
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

void Compiler:: statementList(bool *returnflag, eRetType returntype)
{
	//std::cout << "���� <�����>" << std::endl;
	while(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype);
	}
	std::cout << "����һ�� <�����>" << std::endl;
}

void Compiler:: varState()
{
	//std::cout << "���� <����˵��>" << std::endl;
	eRetType rettype = NOTTYPE;
	std::string *name = 0;
	this->decHead(&rettype, &name);
	if(!name)
		return ;
	if(this->isInRange(VARDEF_BEGIN, VARDEF_BEGIN_SIZE))
	{
		this->varDef(rettype, name);
	}
	else{
		this->errorHandle(NOTVARDEF);
	}
	while(this->isInRange(DECHEAD_BEGIN, DECHEAD_BEGIN_SIZE))
	{
		eRetType rettype = NOTTYPE;
		std::string *name = 0;
		this->decHead(&rettype, &name);
		if(!name)
			return ;
		if(this->isInRange(VARDEF_BEGIN, VARDEF_BEGIN_SIZE))
		{
			this->varDef(rettype, name);
		}
		else{
			this->errorHandle(NOTVARDEF);
		}
	}
	std::cout << "����һ�� <����˵��>" << std::endl;
}

void Compiler:: comStatement(bool *returnflag, eRetType returntype)
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
	this->statementList(returnflag, returntype);

	std::cout << "����һ�� <�������>" << std::endl;
}