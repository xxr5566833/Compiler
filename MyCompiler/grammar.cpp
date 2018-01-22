#include "Compiler.h"

////////////////////////////////////////////////
//�﷨�������								  //
//											  //
////////////////////////////////////////////////

const int kMaxCaseNum = 11;

const tokenType INT_BEGIN[] = {PLUS, MINUS, ZERO, UNSIGNEDINT};

const int INT_BEGIN_SIZE = 4;

const tokenType CONSTANT_BEGIN[] = {SINGLECHAR, PLUS, MINUS, ZERO, UNSIGNEDINT};

const int CONSTANT_BEGIN_SIZE = 5;

const tokenType VARDEF_BEGIN[] = {LBRACKET, COMMA, SEMI};

const int VARDEF_BEGIN_SIZE = 3;

const tokenType DECHEAD_BEGIN[] = {INT, CHAR};

const int DECHEAD_BEGIN_SIZE = 2;

const tokenType STATEMENT_BEGIN[] = {IF, WHILE, LBRACE, SCANF, PRINTF, SEMI, SWITCH, RETURN, ID};

const int STATEMENT_BEGIN_SIZE = 9;

const tokenType VARSTATE_BEGIN[] = {INT, CHAR};

const int VARSTATE_BEGIN_SIZE = 2;

//��ϵ�����������Ҫдһ��

const tokenType RELATION_OPERATOR[] = {LESSEQU, MOREEQU, EQU, NEQU, LESS, MORE,};

const int RELATION_OPERATOR_SIZE = 6;



const tokenType FACTOR_FOLLOW[] = {PLUS, MINUS, STAR, DIV, SEMI, COMMA, RPARENT, RBRACKET};

const int FACTOR_FOLLOW_SIZE = 8;

const tokenType END[] = {COMMA, SEMI};

const int END_SIZE = 2;
 
const tokenType UNSIGNEDINT_FOLLOW[] = {LESSEQU, MOREEQU, EQU, NEQU, LESS, MORE, PLUS, MINUS, STAR, DIV, COMMA, COLON, SEMI, RBRACKET, RPARENT};

const int UNSIGNEDINT_FOLLOW_SIZE = 15;

//��Ϊ0��Ϊһ���������������֣�����������һ��ȫ�ֵ�����ʾ
std::string *ZEROOPERAND = new std::string("0");

bool Compiler:: isInRange(const tokenType range[],const int size)
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
			//�������ţ����Ǻ��治��һ���޷�����������ô��ʱ���б���
			this->errorHandle(NOTUNSIGNEDINT);
			this->skip(UNSIGNEDINT_FOLLOW, UNSIGNEDINT_FOLLOW_SIZE);
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
	//std::cout << "����һ�� <����>" <<std::endl;
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
					//ȱ��=���ţ���ʱ����ֱ���������������ַ�
					this->errorHandle(NOTASSIGN);
					this->skip(INT_BEGIN, INT_BEGIN_SIZE);
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
					this->skip(END, END_SIZE);
				}
			}
			else{
				//���Ǳ�ʶ������ô���������Ż��߷ֺ�
				this->errorHandle(NOTID);
				this->skip(END, END_SIZE);
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
					this->skip(SINGLECHAR);
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
					this->skip(END, END_SIZE);
				}

			}
			else{
				this->errorHandle(NOTID);
				this->skip(END, END_SIZE);
			}
		}while(this->tok.id == COMMA);
	}
	else{
		this->errorHandle(NOTINTORCHAR);
		this->skip(SEMI);
		//����һ��int������char������ֱ���ֺ�
	}
	//std::cout << "����һ�� <��������>" << std::endl;
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
			//ȱ�ٷֺ�
			this->errorHandle(NOTSEMI);
		}
	}while(this->tok.id == CONST);

	//std::cout << "����һ�� <����˵��>" << std::endl;
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

	//std::cout << "����һ�� <����>" << std::endl;
}

void Compiler:: varParaList(symbol *sym)
{
	//std::cout << "���� <ֵ������>" << std::endl;
	eRetType type = NOTTYPE;
	int paraindex = 0;
	std::string temppara = std::string();
	this->expression(&type, &temppara);
	this->pushMidCode(REALPARAOP, &temppara, ZEROOPERAND, &temppara);
	if(sym->feature > paraindex)
	{
		if(sym->paraList[paraindex] != type)
		{
			//�������Ͳ�ƥ�䣬������
			this->errorHandle(PARATYPEDISMATCH);
		}
	}
	else{
		//����������ƥ��
		this->errorHandle(PARANUMDISMATCH);
		this->skip(RPARENT);
		return ;
	}
	paraindex ++;
	while(this->tok.id == COMMA)
	{
		eRetType type = NOTTYPE;
		this->inSym();
		std::string temppara = std::string();
		this->expression(&type, &temppara);
		this->pushMidCode(REALPARAOP, &temppara, ZEROOPERAND, &temppara);
		if(sym->feature > paraindex)
		{
			if(sym->paraList[paraindex] != type)
			{
				//���Ͳ�ƥ�䲻����
				this->errorHandle(PARATYPEDISMATCH);
			}
		}
		else{
			//������ƥ�䲻����
			this->errorHandle(PARANUMDISMATCH);
			this->skip(RPARENT);
			return ;
		}
		paraindex ++;
		//�ͷſռ�
	}
	if(paraindex != sym->feature)
	{
		//������ƥ�䲻����
		this->errorHandle(PARANUMDISMATCH);
		this->skip(RPARENT);
		return ;
	}
}

void Compiler::factor(eRetType *resulttype, std::string *operand)
{
	//std::cout<< "���� <����>" << std::endl;
	//�������ƣ���󸳸� *operand
	if(this->tok.id == ID)
	{
		symbol *sym = 0;
		if(!this->find(this->tok.val.str, &sym, false))
		{
			//˵�������ʶ��û�б����壬��ô��ʱ������������������ӵķ���
			this->errorHandle(IDNOTDEF);
			this->skip(FACTOR_FOLLOW, FACTOR_FOLLOW_SIZE);
			return ;
		}
		*resulttype = sym->returnType;
		this->inSym();
		if(this->tok.id == LBRACKET)
		{
			//˵��������Ԫ��ֵ
			if(sym->symbolType != ARRAYSYM)
			{
				//��ʶ������һ�����飬��ô��ʱ���������������ӵķ�������
				this->errorHandle(NOTANARRAY);
			}
			eRetType type = NOTTYPE;
			this->inSym();
			std::string indextemp = std::string();
			this->expression(&type, &indextemp);
			if(type != INTRET)
			{
				//����һ��int�͵ı��ʽ��������������
				this->errorHandle(NOTAINT);
			}
			if(this->isOperandNumber(&indextemp))
			{
				//������ʽ���ص���һ����������ô�������Ҫ��������±��Ƿ�Խ��
				int constvalue = atoi(indextemp.c_str());
				//ע�⻹Ҫ��0�Ƚ�
				if(constvalue >= sym->feature || constvalue < 0)
				{
					//�±�Խ�粻����
					this->errorHandle(ARRAYINDEXOUTOFRANGE);
				}
			}
			this->genTemp(operand);
			this->pushMidCode(RARRAYOP, sym->name, &indextemp, operand);
			if(this->tok.id == RBRACKET)
			{
				this->inSym();

			}
			else{
				//ȱ���������ţ�Ĭ������д�ˣ�������
				this->errorHandle(NOTRBRACKET);

			}
		}
		else if(this->tok.id == LPARENT){
			//˵����һ����������
			if(sym->symbolType != FUNCSYM)
			{
				//����һ����������ô��ʱ���������������ӵķ���
				this->errorHandle(NOTAFUNC);
				return ;
			}
			if(sym->returnType == VOID)
			{
				//����һ���з���ֵ�ĺ������ã���ô��ʱ������
				this->errorHandle(NORETURNVALUE);
			}
			this->inSym();
			this->varParaList(sym);
			if(this->tok.id == RPARENT)
			{
				//ִ����غ�������
				this->pushMidCode(CALLOP, new std::string(), new std::string(), sym->name);
				*operand = std::string("#RET");
				this->inSym();
			}
			else{
				//ȱ����С���ţ���ô��ʱĬ����д�ˣ�������
				this->errorHandle(NOTRPARENT);
			}
		}
		else{
			if(sym->symbolType == SIMPLESYM || sym->symbolType == PARASYM)
			{
				//��ʶ��ֱ����Ϊ����������
				*operand = *sym->name;
			}
			else if(sym->symbolType == FUNCSYM){
				if(sym->feature != 0)
				{
					//���ﶼ���޲κ������ã��������ﲻ����һ���вκ��������ﲻ����
					this->errorHandle(NOTANOPARAFUNC);
				}
				this->pushMidCode(CALLOP, new std::string(), new std::string(), sym->name);
				*operand = std::string("#RET");
			}
			//��Ҫ���ǳ�����ʶ��
			else if(sym->symbolType == CONSTSYM){
				//��ʦ˵�ˣ������±������һ�����γ�������ôҲ��Ҫ��飬��ֻҪ�ܹ�ȷ��ֵ�ģ�����Ҫ��飬
				//����˵�������ǰѳ���ֱ�ӵ���һ��ֵ����ȥ������Ҳ�ü��������±�
				int value = sym->feature;
				std::string constvalue = std::string();
				this->int2string(&constvalue, value);
				*operand = constvalue;
			}
			else{
				//����һ������ȷʹ�õı�ʶ����������
				this->errorHandle(INVALIDID);
			}
		}
	}
	else if(this->tok.id == LPARENT)
	{
		this->inSym();
		this->expression(resulttype, operand);
		if(this->tok.id == RPARENT)
		{
			this->inSym();
		}
		else{
			//ȱ����С���ţ�Ĭ����д������
			this->errorHandle(NOTRPARENT);
		}
	}
	else if(this->isInRange(CONSTANT_BEGIN, CONSTANT_BEGIN_SIZE)){
		//��������ô��ʱֱ�Ӱ�����ֵ��Ϊ������
		int value;
		this->constant(&value, resulttype);
		std::string constvalue = std::string();
		this->int2string(&constvalue, value);
		*operand = constvalue;
	}
	else{
		//����һ����ȷ�����ӣ���ʱ����
		this->errorHandle(NOTFACTOR);
		this->skip(FACTOR_FOLLOW, FACTOR_FOLLOW_SIZE);
	}

	//std::cout<< "����һ�� <����>" << std::endl;
}

void Compiler:: term(eRetType *resulttype, std::string *operand)
{
	//std::cout << "���� <��>" << std::endl;
	//��������term�����շ��ص��м����
	std::string resultoperand = std::string();
	this->factor(resulttype, &resultoperand);
	//��������һ����������#ret ��ô��Ҫһ����ʱ�������нӣ���Ϊ֮��v0���ܻᱻռ��
	if(this->isOperandRet(&resultoperand))
	{
		std::string temp = std::string();
		this->genTemp(&temp);
		this->pushMidCode(ADDOP, &resultoperand, ZEROOPERAND, &temp);
		resultoperand = temp;
	}
	while(this->tok.id == STAR || this->tok.id == DIV)
	{
		//��Ϊһ�����˼��㣬��ô�����������һ����int
		*resulttype = INTRET;

		bool isstar = this->tok.id == STAR;
		eRetType fact = NOTTYPE;
		std::string factoroperand2 = std::string();
		this->inSym();
		this->factor(&fact, &factoroperand2);

		if(this->isOperandNumber(&resultoperand))
		{
			if(this->isOperandNumber(&factoroperand2))
			{
				//��������������֣���ô����ֱ�Ӽ�����
				int op1 = atoi(resultoperand.c_str());
				int op2 = atoi(factoroperand2.c_str());
				if(op2 == 0 && !isstar)
				{
					//���ܳ���0��
					this->errorHandle(DIVZERO);
					//���ﲻ����ʲô,����op2��1���Է�ֹ��Ϊ0
					op2 +=1;
				}
				int result = isstar ? op1 * op2 : op1 / op2;
				std::string constvalue = std::string();
				this->int2string(&constvalue, result);
				resultoperand = constvalue;
			}
			else{
				//��һ�������֣��ڶ����������֣�ͬ���ĵ���������Ҫ������Щ������ʱ�����Ҳ������ֵ����Ӳ���������һ����ʱ����������

				if(!this->isOperandTemp(&factoroperand2))
				{
					//������ʱ��������ô��Ҫ������ʱ����������ԭ���Ĳ�������ֵ�������ʱ�������������ʱ�����������㲢��Ϊ���������
					std::string result = std::string();
					this->genTemp(&result);
					this->pushMidCode(isstar ? MULOP : DIVOP, &resultoperand, &factoroperand2, &result);
					resultoperand = result;
				}
				else{
					//����ʱ��������ôֱ�Ӱ�����Ϊ���Ĳ�����
					this->pushMidCode(isstar ? MULOP : DIVOP, &resultoperand, &factoroperand2, &factoroperand2);
					//Ȼ����Ҫ��resultoperandʼ�մ�Ž��������
					resultoperand = factoroperand2;
				}
			}
		}
		else{
			if(this->isOperandNumber(&factoroperand2))
			{
				int op2 = atoi(factoroperand2.c_str());
				if(op2 == 0 && !isstar)
				{
					//���ܳ���0��
					this->errorHandle(DIVZERO);
				}
			}
			if(this->isOperandTemp(&resultoperand))
			{
				this->pushMidCode(isstar ? MULOP : DIVOP, &resultoperand, &factoroperand2, &resultoperand);
			}
			else{
				//������Ҫ������ʱ������Ϊ���
				std::string result = std::string();
				this->genTemp(&result);
				this->pushMidCode(isstar ? MULOP : DIVOP, &resultoperand, &factoroperand2, &result);
				resultoperand = result;
			}
		}

	}
	*operand = resultoperand;
	//std::cout << "����һ�� <��>" << std::endl;
}

void Compiler:: expression(eRetType *resulttype, std::string *operand)
{
	//std::cout << "���� <���ʽ>" << std::endl;
	//��ʾ����+ - ����У���ôΪtrue
	std::string termoperand1 = std::string();
	bool flag = false;
	bool neg = false;
	if(this->tok.id == PLUS || this->tok.id == MINUS)
	{
		//������Ӧ����Ԫʽ
		flag = true;
		neg = MINUS == this->tok.id;
		this->inSym();
	}
	this->term(resulttype, &termoperand1);
	if(neg)
	{
		//ͬ�����ﻹ����Ҫ�����������һ����������ôֱ�ӾͿ��Լ�����
		if(this->isOperandNumber(&termoperand1))
		{
			//�����һ�����ֳ���
			int value = atoi(termoperand1.c_str());
			value = -1 * value;
			std::string constvalue = std::string();
			//�Ȼ������intֵ��Ȼ��ȡ�෴����Ȼ���ٱ��string
			this->int2string(&constvalue, value);
			//�ѽ�����˵�һ���������
			termoperand1 = constvalue;
		}
		else if(this->isOperandId(&termoperand1))
		{
			//����Ǳ�ʶ������Ҫһ����ʱ���������нӡ���
			std::string temp = std::string();
			this->genTemp(&temp);
			this->pushMidCode(SUBOP, ZEROOPERAND, &termoperand1, &temp);
			termoperand1 = temp;
		}
		else{
			//�������ֳ����ͱ�ʶ������ô�϶�����ʱ������
			this->pushMidCode(SUBOP, ZEROOPERAND, &termoperand1, &termoperand1);
		}
	}
	*resulttype = flag ? INTRET : *resulttype;
	while(this->tok.id ==PLUS || this->tok.id == MINUS)
	{
		bool isplus = this->tok.id == PLUS;
		eRetType result = NOTTYPE;
		std::string termoperand2 = std::string();
		this->inSym();
		this->term(&result, &termoperand2);
		*resulttype = INTRET;
		//������Ҫ�������������ǲ�������
		if(this->isOperandNumber(&termoperand1))
		{
			if(this->isOperandNumber(&termoperand2))
			{
				//�����������������ֳ�������ô���㣬���ѽ����termoperand1
				int op1 = atoi(termoperand1.c_str());
				int op2 = atoi(termoperand2.c_str());
				int result = isplus ? op1 + op2 : op1 - op2;
				std::string constvalue = std::string();
				this->int2string(&constvalue, result);
				termoperand1 = constvalue;
			}
			else{
				//bug:���ﻹ��Ҫ���ڶ���term���ص���һ����ʱ�������Ǳ�ʶ��������Ǳ�ʶ������Ҫ����ʱ�����нӣ�
				if(this->isOperandId(&termoperand2))
				{
					std::string temp = std::string();
					this->genTemp(&temp);
					this->pushMidCode(isplus ? ADDOP : SUBOP, &termoperand1, &termoperand2, &temp);
					termoperand1 = temp;
				}
				else{
					this->pushMidCode(isplus ? ADDOP : SUBOP, &termoperand1, &termoperand2, &termoperand2);
					termoperand1 = termoperand2;
				}
			}
		}
		else{
			if(this->isOperandTemp(&termoperand1))
			{
				//���������1��һ����ʱ����
				this->pushMidCode(isplus ? ADDOP : SUBOP, &termoperand1, &termoperand2, &termoperand1);
			}
			else{
				//���������1��һ����ʶ������Ҫһ����ʱ�������������
				std::string temp = std::string();
				this->genTemp(&temp);
				this->pushMidCode(isplus ? ADDOP : SUBOP, &termoperand1, &termoperand2, &temp);
				termoperand1 = temp;
			}
		}
	}
	*operand = termoperand1;
	//std::cout << "����һ�� <���ʽ>" << std::endl;
}

void Compiler:: varDef(eRetType rettype, std::string *name)
{
	//std::cout << "���� <�������崦��>" << std::endl;
	symbol *sym = 0;
	if(this->find(name, &sym, true))
	{
		//��������Ѿ���������ˣ���ô����
		this->errorHandle(DUPLICATEDEF);
	}
	if(this->tok.id == SEMI)
	{
		//����֮ǰ�ļ򵥱�����ʶ��
		this->push(name, rettype, SIMPLESYM, -1, this->lineCount);
		this->inSym();
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
			//����
			this->errorHandle(NOTUNSIGNEDINT);
		}
		if(this->tok.id == RBRACKET)
		{
			//��������
			this->push(name, rettype, ARRAYSYM, feature, this->lineCount);
			this->inSym();
		}
		else{
			//Ĭ������д�ˣ�������
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
				//�ظ���������������continue
				this->errorHandle(DUPLICATEDEF);
			}
			//�����ڱ�ʶ����Ϣ
			symname = this->tok.val.str; 
			this->inSym();
		}
		else{
			//������continue
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
				//����
				this->errorHandle(NOTUNSIGNEDINT);
			}
			if(this->tok.id == RBRACKET)
			{
				//��������
				this->push(symname, rettype, ARRAYSYM, feature, this->lineCount);
				this->inSym();
			}
			else{
				//Ĭ����д������
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
		//Ĭ����д������
		this->errorHandle(NOTSEMI);
	}
	//std::cout << "����һ�� <����������>" << std::endl;
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
		//����Ĭ��Ϊint��������
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
		//��һ��
		*name = new std::string("#temp");
		this->inSym();
		
	}
	//std::cout << "����һ�� <����ͷ��>" << std::endl;

}

void Compiler:: para(symbol *sym)
{
	//std::cout << "���� <����>" << std::endl;
	std::string *name = 0;
	eRetType rettype = NOTTYPE;
	this->decHead(&rettype, &name);
	if(!name)
	{
		name = new std::string();
		this->genTemp(name);
	}
	sym->paraList[sym->feature++] = rettype;
	symbol *tempsym = 0;
	if(this->find(name, &tempsym, true))
	{
		//���������ֺ�֮ǰ���ظ�
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
		{
			name = new std::string();
			this->genTemp(name);
		}
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

	//std::cout << "����һ�� <����>" << std::endl;
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
		//�ٶ�����д��
		this->errorHandle(NOTLBRACE);
	}
	bool returnflag = false;
	this->pushMidCode(FUNCBEGINOP, new std::string(), new std::string(), sym->name);
	this->comStatement(&returnflag, sym->returnType, sym->name);
	if(this->tok.id == RBRACE)
	{
		//�˳�����
		this->inSym();
		if(!returnflag && sym->returnType != VOIDRET)
		{
			//���û���κ�return�����ҷ����������з���ֵ�����ͣ���ô����
			this->errorHandle(NONERETURN); 
		}
	}
	else{
		//������д
		this->errorHandle(NOTRBRACE);
	}
	//�����ɺ��������ı��
	std::stringstream ss = std::stringstream();
	ss << *(sym->name) << "$end";
	this->pushMidCode(LABOP, new std::string(), new std::string(), &(ss.str()));
	this->pushMidCode(RETOP, new std::string(), new std::string(), sym->name);
	//std::cout << "����һ�� <�޲κ������崦��>" << std::endl;
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
		//������д
		this->errorHandle(NOTRPARENT);
	}
	this->noParaFuncDef(sym);
	//std::cout << "����һ�� <�вκ������崦��>" << std::endl;
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
	//std::cout << "����һ�� <��ͨ�޷���ֵ��������>" << std::endl;
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
		this->inSym();
	}
	//��main����������ű�
	this->push(name, VOIDRET, FUNCSYM, 0, this->lineCount);
	if(this->tok.id == LPARENT)
	{
		this->inSym();
	}
	else{
		//������д
		this->errorHandle(NOTLPARENT);
	}
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		//������д
		this->errorHandle(NOTRPARENT);
	}
	if(this->tok.id == LBRACE)
	{
		this->inFunc();
		this->inSym();
	}
	else{
		//������д
		this->errorHandle(NOTLBRACE);
	}
	bool returnflag = false;
	this->pushMidCode(FUNCBEGINOP, new std::string(), new std::string(), new std::string("main"));
	this->comStatement(&returnflag, VOIDRET, name);
	//����������void������Ҫ�����û��return
	if(this->tok.id == RBRACE)
	{
		this->pop();
		//std::cout << "����һ�� <����������>" << std::endl;
		this->pushMidCode(EXITOP, new std::string(), new std::string(), new std::string());
		return ;
	}
	else{
		//������д
		this->errorHandle(NOTRBRACE);
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
			name = new std::string();
			this->genTemp(name);
		}
		if(this->find(name, &sym, true))
		{
			this->errorHandle(DUPLICATEDEF);
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

	//std::cout << "����һ��  <�����Ժ������忪ʼ�ĳ���>" << std::endl;
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
		{
			name = new std::string();
			this->genTemp(name);
		}
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
	//std::cout << "����һ�� <�����Ա������忪ʼ�ĳ���>" << std::endl;

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
	std::cout << "�﷨����������" << std::endl;
	//std::cout << "����һ�� <����>" << std::endl;

}

void Compiler:: condition(std::string *label)
{
	//std::cout << "���� <����>" << std::endl;
	eRetType rettype = NOTTYPE;
	std::string tempoperand1 = std::string();
	this->expression(&rettype, &tempoperand1);
	if(this->isInRange(RELATION_OPERATOR, RELATION_OPERATOR_SIZE))
	{
		//�����ϵ�����
		int token = this->tok.id ;

		eRetType rettype2 = NOTTYPE;
		std::string tempoperand2 = std::string();
		this->inSym();
		this->expression(&rettype2, &tempoperand2);
		//������Ͳ�һ������ô����ͳһת��Ϊint����
		//�������
		//����ͳһ�ò�����1��ȥ������2
		switch(token)
		{
		case EQU:
			this->pushMidCode(NEQUOP, &tempoperand1, &tempoperand2, label);
			break;
		case NEQU:
			this->pushMidCode(EQUOP, &tempoperand1, &tempoperand2, label);
			break;
		case LESSEQU:
			this->pushMidCode(MOREOP, &tempoperand1, &tempoperand2, label);
			break;
		case LESS:
			this->pushMidCode(MOREEQUOP, &tempoperand1, &tempoperand2, label);
			break;
		case MORE:
			this->pushMidCode(LESSEQUOP, &tempoperand1, &tempoperand2, label);
			break;
		case MOREEQU:
			this->pushMidCode(LESSOP, &tempoperand1, &tempoperand2, label);
			break;

		}
	}
	else{
		this->pushMidCode(EQUOP, &tempoperand1, ZEROOPERAND, label);
	}
	
	//std::cout << "����һ�� <����>" << std::endl;
}

void Compiler:: ifStatement(bool *returnflag, eRetType returntype, std::string *name)
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
		this->skip(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype, name);
	}
	else{
		//����һ�����
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), endlabel);
	this->pushMidCode(LABOP, new std::string(), new std::string(), elselabel);
	if(this->tok.id == ELSE)
	{
		this->inSym();
	}
	else{

		//Ĭ����û��дelse�����ﲻ������ֱ�ӽ���
		this->errorHandle(NOTELSE);
		this->skip(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype, name);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
		this->skip(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE);
	}
	this->pushMidCode(LABOP, new std::string(), new std::string(), endlabel);
	//std::cout << "����һ�� <�������>" << std::endl;
}

void Compiler:: caseStatement(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *nextlab, int *caseconst, std::string *name)
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
			//�������Ͳ�һ����������
			this->errorHandle(CASESWITCHDISMATCH);
			this->inSym();
		}
		//���case��ĳ�����ֵ
		*caseconst = value;
		std::string *constoperand = new std::string();
		this->genTemp(constoperand);
		std::string *constvalue = new std::string();
		this->int2string(constvalue, value);
		this->pushMidCode(ADDOP, constvalue, new std::string("0"), constoperand);
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
		//Ĭ����д
		this->errorHandle(NOTCOLON);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype, name);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), donelab);
	//std::cout << "����һ�� <��������>" << std::endl;
}

void Compiler:: caseTab(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *name)
{
	//std::cout << "���� <�����>" << std::endl;
	if(this->tok.id == CASE)
	{
		int casevalue[kMaxCaseNum];
		int count = 0;
		do{
			int caseconst = 0;
			std::string *nextlab = new std::string();
			this->genLabel(nextlab);
			this->caseStatement(switchtype, switchtemp, returnflag, returntype, donelab, nextlab, &caseconst, name);
			this->pushMidCode(LABOP, new std::string(), new std::string(), nextlab);

			//����ϸ�case�����Ƿ���֮ǰĳ��case�ĳ������
			for(int i = 0 ; i < count ; ++i)
			{
				if(casevalue[i] == caseconst)
				{
					//������ֵ�ظ���  ������
					this->errorHandle(CASEVALUEDUPLICATE);
				}
			}
			casevalue[count++] = caseconst;
			if(count == kMaxCaseNum)
				this->warningHandle(TOOMANYCASE);
		}while(this->tok.id == CASE);
	}
	else{
		this->errorHandle(NOTCASE);
		this->skip(RBRACE);
	}
	//std::cout << "����һ�� <�����>" << std::endl;
}

void Compiler:: switchStatement(bool *returnflag, eRetType returntype, std::string *name)
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
	std::string switchtemp = std::string();
	this->expression(&switchtype, &switchtemp);
	
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
	this->caseTab(switchtype, &switchtemp, returnflag, returntype, done, name);
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
			this->statement(returnflag, returntype, name);
		}
		else{
			this->errorHandle(NOTSTATEMENT);
		}
	}
	this->pushMidCode(LABOP, &(std::string()), &(std::string()), done);
	if(this->tok.id == RBRACE){
		this->inSym();
	}
	else{
		this->errorHandle(NOTRBRACE);
	}
	//std::cout << "����һ�� <������>" << std::endl;
}

void Compiler:: whileStatement(bool *returnflag, eRetType returntype, std::string *name)
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
		this->skip(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype, name);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), whilelab);
	this->pushMidCode(LABOP, new std::string(), new std::string(), endlab);
	//std::cout << "����һ�� <ѭ�����>" << std::endl;
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
			//ֱ��return��������
			this->skip(SEMI);
			return ;
		}
		//ע��ֻ�в������ͺͱ�ʶ�����Ϳ��Ա��������ı�
		if(sym->symbolType != SIMPLESYM && sym->symbolType != PARASYM)
		{
			//������ʾ��������
			this->errorHandle(NOTASIMPLE);
		}
		//���ݱ�ʶ�������ͣ��ж��������ַ�������������
		switch(sym->returnType)
		{
		case INTRET:
			this->pushMidCode(SCANFOP, sym->name, new std::string("int"), sym->name);
			break;
		case CHARRET:
			this->pushMidCode(SCANFOP, sym->name, new std::string("char"), sym->name);
			break;
		}
		this->inSym();
	}
	else{
		this->errorHandle(NOTID);
		this->skip(SEMI);
		return ;
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
				this->skip(END, END_SIZE);
				continue;
			}
			if(sym->symbolType != SIMPLESYM && sym->symbolType != PARASYM)
			{
				this->errorHandle(NOTASIMPLE);
			}
			switch(sym->returnType)
			{
			case INTRET:
				this->pushMidCode(SCANFOP, sym->name, new std::string("int"), sym->name);
				break;
			case CHARRET:
				this->pushMidCode(SCANFOP, sym->name, new std::string("char"), sym->name);
				break;
			}
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
			this->skip(END, END_SIZE);
			continue;
		}
	}
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	//std::cout << "����һ�� <�����>" << std::endl;
}

void Compiler:: printfStatement()
{
	//std::cout << "���� <д���>" << std::endl;
	std::string *num = 0;
	//num�ȱ���Ҫ������ַ������±꣬�������ǲ������ַ������
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
		int strindex = -1;
		this->pushString(this->tok.val.str, &strindex);
		num = new std::string();
		this->int2string(num, strindex);
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
			//��ȷ�Ϻ���û�б��ʽ����󣬲�����ַ���
			this->pushMidCode(PRINTFOP, num, new std::string("0"), num);
			//std::cout << "����һ�� <д���>" << std::endl;
			return ;
		}
	}
	eRetType rettype = NOTTYPE;
	std::string temp = std::string();
	this->expression(&rettype, &temp);
	//��ʱ�������ʽ����Ԫʽ�Ѿ����ɣ����а������ܵĺ�������
	if(num)
	{
		//���num����0����ô˵����Ҫ����ַ���
		this->pushMidCode(PRINTFOP, num, ZEROOPERAND, num);
	}
	switch(rettype)
	{
	case INTRET:
		this->pushMidCode(PRINTFOP, &temp, new std::string("int"), &temp);
		break;
	case CHARRET:
		this->pushMidCode(PRINTFOP, &temp, new std::string("char"), &temp);
		break;
	}
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
		this->skip(SEMI);
	}
	//std::cout << "����һ�� <д���>" << std::endl;
}

void Compiler:: returnStatement(bool *returnflag, eRetType returntype, std::string *name)
{
	//std::cout << "���� <�������>" << std::endl;
	this->inSym();
	if(this->tok.id == LPARENT)
	{
		this->inSym();
		eRetType rettype = NOTTYPE;
		std::string temp = std::string();
		this->expression(&rettype, &temp);
		if(returntype == VOIDRET)
		{
			//��void���͵ģ�ȴ��return()��������䣬��ô��ʾ��������
			this->errorHandle(CANNOTRETURN);
		}
		else 
		{
			//int / char
			//����͸�ֵһ����Ҳ��������ֱ��ʽ���ص���һ����ʱ��������ôֱ�Ӱ������������#RET
			if(this->isOperandTemp(&temp))
			{
				midcode *code = this->codes[this->midindex - 1];
				*code->rstname = std::string("#RET");
			}
			else{
				this->pushMidCode(ADDOP, &temp, ZEROOPERAND, new std::string("#RET"));	
			}
			if(returntype != rettype)
			{
				//return���Ͳ�ƥ�䣬��ʾ��������
				this->errorHandle(RETURNTYPEDISMATCH);
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
	}
	//bug���������Ӧ��ͳһ������������Ľ����Σ�����֮ǰȴû������趨
	//ͳһ������Ľ�����Ϊ ������$end
	std::stringstream ss = std::stringstream();
	ss << *name << "$end";
	//bug:ע������main��������Ҫ���أ���������������return����Ч��main������Ϊ��������Ҫmain�Ľ������
	if(!this->isIdEqual(std::string("main"), *name))
		this->pushMidCode(GOTOOP, new std::string(), new std::string(), &(ss.str()));
	else{
		//bug:�����main��������ôֱ������EXITOP
		this->pushMidCode(EXITOP, new std::string(), new std::string(), new std::string());
	}
	//std::cout << "����һ�� <�������>" << std::endl;
}

void Compiler:: statement(bool *returnflag, eRetType returntype, std::string *funcname)
{
	//std::cout << "���� <���>" << std::endl;
	std::string *name = this->tok.val.str;
	symbol *sym = 0;
	switch(this->tok.id)
	{
	case IF:
		this->ifStatement(returnflag, returntype, funcname);
		break;
	case WHILE:
		this->whileStatement(returnflag, returntype, funcname);
		break;
	case LBRACE:
		this->inSym();
		this->statementList(returnflag, returntype, funcname);
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
		this->switchStatement(returnflag, returntype, funcname);
		break;
	case RETURN:
		this->returnStatement(returnflag, returntype, funcname);
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
			this->skip(SEMI);
			return ;
		}
		this->inSym();
		if(this->tok.id == LPARENT)
		{
			//˵����һ���вκ������ã���Ҫ������ǲ���һ������
			if(sym->symbolType != FUNCSYM)
			{
				this->errorHandle(NOTAFUNC);
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
			//˵���Ǹ��򵥱������߲���������������Ҫ����ǲ��Ǽ򵥱������������
			if(sym->symbolType != SIMPLESYM && sym->symbolType != PARASYM)
			{
				this->errorHandle(NOTASIMPLE);
			}
			this->inSym();
			eRetType rettype = NOTTYPE;
			std::string expressoperand = std::string();
			this->expression(&rettype, &expressoperand);
			//����ֵ

			//int-> char ��int��ֵ��char ����ǲ�������ģ�
			if(sym->returnType == CHARRET && rettype == INTRET)
			{
				this->errorHandle(INTTOCHARNOTALLOW);
			}
			//���ʽֻ�ܷ������ֲ����������֣���ʶ��������ʱ������������ص�����ʱ����
			//��ô����ֱ�Ӱ��������ʱ����Ϊ������������Ǹ���Ԫʽ��Ϊ����Ҫ����ֵ�������ʶ��
			if(this->isOperandTemp(&expressoperand))
			{
				midcode *code = this->codes[this->midindex - 1];
				*code->rstname = *sym->name;
			}
			else{
				this->pushMidCode(ADDOP, &expressoperand, ZEROOPERAND, sym->name);
			}
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
			std::string indexoperand = std::string();
			this->expression(&rettype, &indexoperand);
			//���￴indexoperand�ǲ���һ����������
			if(this->isOperandNumber(&indexoperand))
			{
				//�����һ������ֱ�ӻ��ֵ�����֣���ô��Ҫ���
				int index = atoi(indexoperand.c_str());
				if(index >= sym->feature)
				{
					this->errorHandle(ARRAYINDEXOUTOFRANGE);
				}
			}
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
			std::string tempoperand = std::string();
			this->expression(&righttype, &tempoperand);
			//bug:�����int��char���͸�ֵ����ô����������һ��ʼ��ôû���жϼ���
			if(sym->returnType == CHARRET && righttype == INTRET)
			{
				this->errorHandle(INTTOCHARNOTALLOW);
			}
			this->pushMidCode(LARRAYOP, &tempoperand, &indexoperand, name);
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
			}
			this->pushMidCode(CALLOP, new std::string(), new std::string(), name);
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
		break;
	case SEMI:
		//std::cout << "����һ�� <��>���" << std::endl;
		this->inSym();
		break;

	}
	//std::cout << "����һ�� <���>" << std::endl;
}

void Compiler:: statementList(bool *returnflag, eRetType returntype, std::string *name)
{
	//std::cout << "���� <�����>" << std::endl;
	while(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype, name);
	}
	//std::cout << "����һ�� <�����>" << std::endl;
}

void Compiler:: varState()
{
	//std::cout << "���� <����˵��>" << std::endl;
	eRetType rettype = NOTTYPE;
	std::string *name = 0;
	this->decHead(&rettype, &name);
	if(!name)
	{
		name = new std::string();
		this->genTemp(name);
	}
	if(this->isInRange(VARDEF_BEGIN, VARDEF_BEGIN_SIZE))
	{
		this->varDef(rettype, name);
	}
	else{
		this->errorHandle(NOTVARDEF);
		this->skip(VARSTATE_BEGIN, VARSTATE_BEGIN_SIZE);
		return ;
	}
	while(this->isInRange(DECHEAD_BEGIN, DECHEAD_BEGIN_SIZE))
	{
		eRetType rettype = NOTTYPE;
		std::string *name = 0;
		this->decHead(&rettype, &name);
		if(!name)
		{
			name = new std::string();
			this->genTemp(name);
		}
		if(this->isInRange(VARDEF_BEGIN, VARDEF_BEGIN_SIZE))
		{
			this->varDef(rettype, name);
		}
		else{
			this->errorHandle(NOTVARDEF);
			this->skip(SEMI);
			return ;
		}
	}
	//std::cout << "����һ�� <����˵��>" << std::endl;
}

void Compiler:: comStatement(bool *returnflag, eRetType returntype, std::string *name)
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
	this->statementList(returnflag, returntype, name);

	//std::cout << "����һ�� <�������>" << std::endl;
}