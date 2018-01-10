#include "Compiler.h"
#include "grammar.h"

//一些限制
const int kMaxCaseNum = 11;

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

void Compiler:: int_(int *value)
{
	//std::cout << "进入 <整数>" <<std::endl;
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
		//说明现在是无符号整数
		result = this->tok.val.number;
		this->inSym();
	}
	*value = flag ? result : - result;
	//std::cout << "这是一个 <整数>" <<std::endl;
}

void Compiler:: constDef()
{
	//std::cout << "进入 <常量定义>" << std::endl;
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
				//不是标识符，那么就什么也不做
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
				//报存标识符信息
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
						//TODO 跳读
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
	//std::cout << "这是一个 <常量定义>" << std::endl;
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

	//std::cout << "这是一个 <常量说明>" << std::endl;
}

void Compiler:: constant(int *value, eRetType *rettype)
{
	//std::cout << "进入 <常量>" << std::endl;
	if(this->tok.id == SINGLECHAR)
	{
		//处理字符
		*rettype = CHARRET;
		*value = this->tok.val.c;
		this->inSym();

	}
	else{
		//那么一定是整数的开始单词
		*rettype = INTRET;
		this->int_(value);
	}

	//std::cout << "这是一个 <常量>" << std::endl;
}

void Compiler:: varParaList(symbol *sym)
{
	//std::cout << "进入 <值参数表>" << std::endl;
	eRetType type = NOTTYPE;
	int paraindex = 0;
	std::string *temppara = new std::string();
	this->expression(&type, temppara);
	this->pushMidCode(REALPARAOP, new std::string(), new std::string(), temppara, false);
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
		this->pushMidCode(REALPARAOP, new std::string(), new std::string(), temppara, false);
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
	//std::cout << "这是一个 <值参数表>" << std::endl;
}

void Compiler::factor(eRetType *resulttype, std::string *operand)
{
	//std::cout<< "进入 <因子>" << std::endl;
	//保存名称，最后赋给 *operand
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
			//说明是数组元素值
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
				//TODO跳读处理
				return ;
			}
			if(this->isOperandNumber(temp))
			{
				//如果表达式返回的临时变量是一个常数，那么这里就需要检查数组下标是否越界
				int constvalue = atoi(temp->c_str());
				//注意还要和0比较
				if(constvalue >= sym->feature || constvalue < 0)
				{
					this->errorHandle(ARRAYINDEXOUTOFRANGE);
					//跳读
					return ;
				}
			}
			this->genTemp(resultoperand);
			this->pushMidCode(RARRAYOP, sym->name, temp, resultoperand, false);
			if(this->tok.id == RBRACKET)
			{
				this->inSym();

			}
			else{
				this->errorHandle(NOTRBRACKET);

			}
		}
		else if(this->tok.id == LPARENT){
			//说明是一个函数调用
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
				//执行相关函数调用
				this->pushMidCode(CALLOP, new std::string(), new std::string(), sym->name, false);
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
				//标识符直接作为操作数返回
				*resultoperand = *sym->name;
			}
			else if(sym->symbolType == FUNCSYM){
				if(sym->feature != 0)
				{
					//这里都是无参函数调用，所以这里不能是一个有参函数
					this->errorHandle(NOTANOPARAFUNC);
					return ;
				}
				this->pushMidCode(CALLOP, new std::string(), new std::string(), sym->name, false);
				resultoperand = new std::string("#RET");
			}
			//不要忘记常量标识符
			else if(sym->symbolType == CONSTSYM){
				//老师说了，数组下标如果是一个整形常量，那么也需要检查，即只要能够确定值的，都需要检查，
				//所以说这里我们把常量直接当做一个值传出去，这样也好计算最后的下标
				int value = sym->feature;
				std::string *constvalue = new std::string();
				this->int2string(constvalue, value);
				*resultoperand = *constvalue;
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
		//常数，那么此时直接把它的值作为操作数
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

	//std::cout<< "这是一个 <因子>" << std::endl;
}

void Compiler:: term(eRetType *resulttype, std::string *operand)
{
	//std::cout << "进入 <项>" << std::endl;
	//这个是这个term的最终返回的中间代码
	std::string *factoroperand = new std::string();
	this->factor(resulttype, factoroperand);
	std::string *resultoperand = new std::string();
	*resultoperand = *factoroperand;
	if(!this->isOperandTemp(resultoperand) && !this->isOperandNumber(resultoperand))
	{
		//如果不是一个临时变量且不是一个数字，那么需要产生一个临时变量来接受这个操作数
		//因为除了这两种情况以外，就只剩下 标识符 或者 v0寄存器，这两个都是不能作为中间结果的
		std::string *temp = new std::string();
		this->genTemp(temp);
		this->pushMidCode(ADDOP, resultoperand, new std::string("0"), temp, false);
		*resultoperand = *temp;
	}
	//所以第一个操作数，要么是一个临时变量，要么是一个数字

	while(this->tok.id == STAR || this->tok.id == DIV)
	{
		//因为一旦有了计算，那么最后的项的类型一定是int
		*resulttype = INTRET;

		bool isstar = this->tok.id == STAR;
		eRetType fact = NOTTYPE;
		std::string *factoroperand2 = new std::string();
		this->inSym();
		this->factor(&fact, factoroperand2);

		if(this->isOperandNumber(resultoperand))
		{
			if(this->isOperandNumber(factoroperand2))
			{
				//如果两个都是数字，那么可以直接计算结果
				int op1 = atoi(resultoperand->c_str());
				int op2 = atoi(factoroperand2->c_str());
				if(op2 == 0 && !isstar)
				{
					//不能除以0！
					this->errorHandle(DIVZERO);
					//这里不跳读什么,并把op2加1，以防止它为0
					op2 +=1;
				}
				int result = isstar ? op1 * op2 : op1 / op2;
				std::string *constvalue = new std::string();
				this->int2string(constvalue, result);
				*resultoperand = *constvalue;
			}
			else{
				//第一个是数字，第二个不是数字，同样的道理，这里需要对于那些不是临时变量且不是数字的因子操作数赋给一个临时变量操作数

				if(!this->isOperandTemp(factoroperand2))
				{
					//不是临时变量，那么需要生成临时变量，并把原来的操作数的值给这个临时变量，让这个临时变量参与运算并作为结果操作数
					std::string *result = new std::string();
					this->genTemp(result);
					this->pushMidCode(ADDOP, factoroperand2, new std::string("0"), result, false);
					this->pushMidCode(isstar ? MULOP : DIVOP, resultoperand, result, result, false);
					*resultoperand = *result;
				}
				else{
					//是临时变量，那么直接把它作为最后的操作数
					this->pushMidCode(isstar ? MULOP : DIVOP, resultoperand, factoroperand2, factoroperand2, false);
					//然后需要让resultoperand始终存放结果操作数
					*resultoperand = *factoroperand2;
				}
			}
		}
		else{
			//第一个不是数字，那么只有可能是临时变量了，因为首先第一个之前的限制就是临时变量或者数字，之后如果参与了与第二个因子
			//的运算，那么最后的结果也要么是临时变量，要么是数字
			this->pushMidCode(isstar ? MULOP : DIVOP, resultoperand, factoroperand2, resultoperand, false);
		}

	}
	*operand = *resultoperand;
	//std::cout << "这是一个 <项>" << std::endl;
}

void Compiler:: expression(eRetType *resulttype, std::string *operand)
{
	//std::cout << "进入 <表达式>" << std::endl;
	//表示有无+ - 如果有，那么为true
	std::string *termoperand1 = new std::string();
	bool flag = false;
	bool neg = false;
	if(this->tok.id == PLUS || this->tok.id == MINUS)
	{
		//生成相应的四元式
		flag = true;
		neg = MINUS == this->tok.id;
		this->inSym();
	}
	this->term(resulttype, termoperand1);
	if(neg)
	{
		//同样这里还是需要看，如果项是一个常量，那么直接就可以计算结果
		if(this->isOperandNumber(termoperand1))
		{
			//项返回了一个数字常量
			int value = atoi(termoperand1->c_str());
			value = -1 * value;
			std::string *constvalue = new std::string();
			//先获得它的int值，然后取相反数，然后再变成string
			this->int2string(constvalue, value);
			//把结果给了第一个项操作数
			*termoperand1 = *constvalue;
		}
		else{
			//不是数字常量，那么肯定是临时变量了
			this->pushMidCode(SUBOP, new std::string("0"), termoperand1, termoperand1, false);
		}
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
		//还是需要看两个操作数是不是数字
		if(this->isOperandNumber(termoperand1))
		{
			if(this->isOperandNumber(termoperand2))
			{
				//两个操作数都是数字常量，那么计算，并把结果给termoperand1
				int op1 = atoi(termoperand1->c_str());
				int op2 = atoi(termoperand2->c_str());
				int result = isplus ? op1 + op2 : op1 - op2;
				std::string *constvalue = new std::string();
				this->int2string(constvalue, result);
				*termoperand1 = *constvalue;
			}
			else{
				this->pushMidCode(isplus ? ADDOP : SUBOP, termoperand1, termoperand2, termoperand2, false);
				*termoperand1 = *termoperand2;
			}
		}
		else{
			this->pushMidCode(isplus ? ADDOP : SUBOP, termoperand1, termoperand2, termoperand1, false);
		}
	}
	*operand = *termoperand1;
	//std::cout << "这是一个 <表达式>" << std::endl;
}

void Compiler:: varDef(eRetType rettype, std::string *name)
{
	//std::cout << "进入 <变量定义处理>" << std::endl;
	symbol *sym = 0;
	if(this->find(name, &sym, true))
	{
		this->errorHandle(DUPLICATEDEF);
		//这里暂定出错为直接return
		return ;
	}
	if(this->tok.id == SEMI)
	{
		//处理之前的简单变量标识符
		this->push(name, rettype, SIMPLESYM, -1, this->lineCount);
		this->inSym();
		//std::cout << "这是一个 <变量定义处理>" << std::endl; ;
		return ;
	}
	else if(this->tok.id == LBRACKET)
	{
		//是以[开头，那么是个数组
		int feature = -1;
		this->inSym();
		if(this->tok.id == UNSIGNEDINT)
		{
			//处理数字
			feature = this->tok.val.number;
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
		}
		if(this->tok.id == RBRACKET)
		{
			//处理数组
			this->push(name, rettype, ARRAYSYM, feature, this->lineCount);
			this->inSym();
		}
		else{
			this->errorHandle(NOTRBRACKET);
		}
	}
	else
	{
		//说明这时是一个逗号，那么这里需要处理逗号之前的简单变量标识符，注意这里不需要inSym了，直接进入下面的循环
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
				//这里出错直接return
				return ;
			}
			//保存在标识符信息
			symname = this->tok.val.str; 
			this->inSym();
		}
		else{
			this->errorHandle(NOTID);
		}
		int feature = -1;
		if(this->tok.id == LBRACKET)
		{
			//说明是一个数组
			this->inSym();
			if(this->tok.id == UNSIGNEDINT)
			{
				//处理数字
				feature = this->tok.val.number;
				this->inSym();
			}
			else{
				this->errorHandle(NOTUNSIGNEDINT);
			}
			if(this->tok.id == RBRACKET)
			{
				//处理数组
				this->push(symname, rettype, ARRAYSYM, feature, this->lineCount);
				this->inSym();
			}
			else{
				this->errorHandle(NOTRBRACKET);
			}
		}
		else{
			//处理简单变量
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
	//std::cout << "这是一个 <变量处理定义>" << std::endl;
}

void Compiler:: decHead(eRetType *rettype, std::string **name)
{
	//std::cout << "进入 <声明头部>" << std::endl;
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
		//处理标识符
		*name = this->tok.val.str;
		this->inSym();
	}
	else{
		this->errorHandle(NOTID);
	}
	//std::cout << "这是一个 <声明头部>" << std::endl;

}

void Compiler:: para(symbol *sym)
{
	//std::cout << "进入 <参数>" << std::endl;
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

	//std::cout << "这是一个 <参数>" << std::endl;
}

void Compiler:: noParaFuncDef(symbol *sym)
{
	//std::cout << "进入 <无参函数定义处理>" << std::endl;
	
	//同时注意维护符号表index
	if(this->tok.id == LBRACE)
	{
		//index 指向函数的第一个标识符
		this->inSym();
	}
	else{
		this->errorHandle(NOTLBRACE);
	}
	bool returnflag = false;
	this->pushMidCode(FUNCBEGINOP, new std::string(), new std::string(), sym->name, false);
	this->comStatement(&returnflag, sym->returnType, sym->name);
	if(this->tok.id == RBRACE)
	{
		//退出函数
		this->inSym();
		if(!returnflag && sym->returnType != VOIDRET)
		{
			//如果没有任何return语句而且返回类型是有返回值的类型，那么报错
			this->errorHandle(NONERETURN);
			return ;
		}
	}
	else{
		this->errorHandle(NOTRBRACKET);
	}
	//先生成函数结束的标号
	std::stringstream ss = std::stringstream();
	ss << *(sym->name) << "$end";
	this->pushMidCode(LABOP, new std::string(), new std::string(), &(ss.str()), false);
	this->pushMidCode(RETOP, new std::string(), new std::string(), sym->name, false);
	//std::cout << "这是一个 <无参函数定义处理>" << std::endl;
}

void Compiler:: haveParaFuncDef(symbol *sym)
{
	//std::cout << "进入 <有参函数定义处理>" << std::endl;
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
	//std::cout << "这是一个 <有参函数定义处理>" << std::endl;
}


void Compiler:: notMainVoidFuncDef()
{
	//std::cout << "进入 <普通无返回值函数定义>" << std::endl;
	eRetType rettype = VOIDRET;
	std::string *name = this->tok.val.str;
	symbol *sym = 0;;
	//处理标识符
	if(this->find(name, &sym, true))
	{
		this->errorHandle(DUPLICATEDEF);
		return ;
	}
	else{
		sym = this->push(name, rettype, FUNCSYM, 0, this->lineCount);
	}
	this->inSym();
	//调整index，调整address，因为进入一个新的函数，需要分配这个函数的局部变量的地址
	this->inFunc();
	if(this->tok.id == LPARENT)
	{
		this->haveParaFuncDef(sym);
	}
	else{
		this->noParaFuncDef(sym);
	}
	this->pop();
	//std::cout << "这是一个 <普通无返回值函数定义>" << std::endl;
}

void Compiler:: mainDef()
{
	//std::cout << "进入 <主函数定义>" << std::endl;
	std::string *name = new std::string("main");
	if(this->tok.id == MAIN)
	{
		//处理main
		this->inSym();
	}
	else{
		this->errorHandle(NOTMAIN);
	}
	//把main函数插入符号表
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
	this->pushMidCode(FUNCBEGINOP, new std::string(), new std::string(), new std::string("main"), false);
	this->comStatement(&returnflag, VOIDRET, name);
	//这里类型是void，不需要检查有没有return
	if(this->tok.id == RBRACE)
	{
		this->pop();
		//std::cout << "这是一个 <主函数定义>" << std::endl;

		this->pushMidCode(EXITOP, new std::string(), new std::string(), new std::string(), false);
		return ;
	}
	else{
		this->errorHandle(NOTRBRACE);
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
		std::string *name = 0;
		eRetType rettype = NOTTYPE;
		symbol *sym = 0;
		this->decHead(&rettype, &name);
		//保存这个函数标识符
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

	//std::cout << "这是一个  <可能以函数定义开始的程序>" << std::endl;
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
	//std::cout << "这是一个 <可能以变量定义开始的程序>" << std::endl;

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

	//std::cout << "这是一个 <程序>" << std::endl;

}

void Compiler:: condition(std::string *label)
{
	//std::cout << "进入 <条件>" << std::endl;
	eRetType rettype = NOTTYPE;
	std::string *tempoperand1 = new std::string();
	this->expression(&rettype, tempoperand1);
	if(this->isInRange(RELATION_OPERATOR, RELATION_OPERATOR_SIZE))
	{
		//处理关系运算符
		int token = this->tok.id ;

		eRetType rettype2 = NOTTYPE;
		std::string *tempoperand2 = new std::string();
		this->inSym();
		this->expression(&rettype2, tempoperand2);
		//如果类型不一样，那么可以统一转换为int计算
		//生成语句
		//这里统一让操作数1减去操作数2
		switch(token)
		{
		case EQU:
			this->pushMidCode(NEQUOP, tempoperand1, tempoperand2, label, false);
			break;
		case NEQU:
			this->pushMidCode(EQUOP, tempoperand1, tempoperand2, label, false);
			break;
		case LESSEQU:
			this->pushMidCode(MOREOP, tempoperand1, tempoperand2, label, false);
			break;
		case LESS:
			this->pushMidCode(MOREEQUOP, tempoperand1, tempoperand2, label, false);
			break;
		case MORE:
			this->pushMidCode(LESSEQUOP, tempoperand1, tempoperand2, label, false);
			break;
		case MOREEQU:
			this->pushMidCode(LESSOP, tempoperand1, tempoperand2, label, false);
			break;

		}
	}
	else{
		this->pushMidCode(EQUOP, tempoperand1, new std::string("0"), label, false);
	}
	
	//std::cout << "这是一个 <条件>" << std::endl;
}

void Compiler:: ifStatement(bool *returnflag, eRetType returntype, std::string *name)
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
		this->statement(returnflag, returntype, name);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), endlabel, false);
	this->pushMidCode(LABOP, new std::string(), new std::string(), elselabel, false);
	if(this->tok.id == ELSE)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTELSE);
	}
	if(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype, name);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(LABOP, new std::string(), new std::string(), endlabel, false);
	//std::cout << "这是一个 <条件语句>" << std::endl;
}

void Compiler:: caseStatement(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *nextlab, int *caseconst, std::string *name)
{
	//std::cout << "进入 <情况子语句>" << std::endl;
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
		//获得case后的常量的值
		*caseconst = value;
		std::string *constoperand = new std::string();
		this->genTemp(constoperand);
		std::string *constvalue = new std::string();
		this->int2string(constvalue, value);
		this->pushMidCode(ADDOP, constvalue, new std::string("0"), constoperand, false);
		this->pushMidCode(NEQUOP, constoperand, switchtemp, nextlab, false);
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
		this->statement(returnflag, returntype, name);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), donelab, false);
	//std::cout << "这是一个 <情况子语句>" << std::endl;
}

void Compiler:: caseTab(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *name)
{
	//std::cout << "进入 <情况表>" << std::endl;
	if(this->tok.id == CASE)
	{
		int casevalue[kMaxCaseNum];
		int count = 0;
		do{
			int caseconst = 0;
			std::string *nextlab = new std::string();
			this->genLabel(nextlab);
			this->caseStatement(switchtype, switchtemp, returnflag, returntype, donelab, nextlab, &caseconst, name);
			this->pushMidCode(LABOP, new std::string(), new std::string(), nextlab, false);

			//检查上个case常量是否与之前某个case的常量相等
			for(int i = 0 ; i < count ; ++i)
			{
				if(casevalue[i] == caseconst)
				{
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
	}
	//std::cout << "这是一个 <情况表>" << std::endl;
}

void Compiler:: switchStatement(bool *returnflag, eRetType returntype, std::string *name)
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
	eRetType switchtype = NOTTYPE;
	std::string *switchtemp = new std::string();
	this->expression(&switchtype, switchtemp);
	
	//结束时的标号
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
	this->caseTab(switchtype, switchtemp, returnflag, returntype, done, name);
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
	this->pushMidCode(LABOP, new std::string(), new std::string(), done, false);
	if(this->tok.id == RBRACE){
		this->inSym();
	}
	else{
		this->errorHandle(NOTRBRACE);
	}
	//std::cout << "这是一个 <情况语句>" << std::endl;
}

void Compiler:: whileStatement(bool *returnflag, eRetType returntype, std::string *name)
{
	//std::cout << "进入 <循环语句>" << std::endl;
	std::string *whilelab = new std::string();
	this->genLabel(whilelab);
	std::string *endlab = new std::string();
	this->genLabel(endlab);
	this->pushMidCode(LABOP, new std::string(), new std::string(), whilelab, false);
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
		this->statement(returnflag, returntype, name);
	}
	else{
		this->errorHandle(NOTSTATEMENT);
	}
	this->pushMidCode(GOTOOP, new std::string(), new std::string(), whilelab, false);
	this->pushMidCode(LABOP, new std::string(), new std::string(), endlab, false);
	//std::cout << "这是一个 <循环语句>" << std::endl;
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
		//处理这个标识符
		symbol *sym = 0;
		if(!this->find(this->tok.val.str, &sym, false))
		{
			this->errorHandle(IDNOTDEF);
			return ;
		}
		//注意只有参数类型和标识符类型可以被输入所改变
		if(sym->symbolType != SIMPLESYM && sym->symbolType != PARASYM)
		{
			this->errorHandle(NOTASIMPLE);
		}
		//根据标识符的类型，判断是输入字符还是输入整数
		switch(sym->returnType)
		{
		case INTRET:
			this->pushMidCode(SCANFOP, sym->name, new std::string("int"), sym->name, false);
			break;
		case CHARRET:
			this->pushMidCode(SCANFOP, sym->name, new std::string("char"), sym->name, false);
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
			//处理这个标识符
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
				this->pushMidCode(SCANFOP, sym->name, new std::string("int"), sym->name, false);
				break;
			case CHARRET:
				this->pushMidCode(SCANFOP, sym->name, new std::string("char"), sym->name, false);
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
	//std::cout << "这是一个 <读语句>" << std::endl;
}

void Compiler:: printfStatement()
{
	//std::cout << "进入 <写语句>" << std::endl;
	std::string *num = 0;
	//num既保存要输出的字符串的下标，还保存是不是有字符串输出
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
			//当确认后面没有表达式输出后，才输出字符串
			this->pushMidCode(PRINTFOP, new std::string(), new std::string(), num, false);
			//std::cout << "这是一个 <写语句>" << std::endl;
			return ;
		}
	}
	eRetType rettype = NOTTYPE;
	std::string *temp = new std::string();
	this->expression(&rettype, temp);
	//这时产生表达式的四元式已经生成，其中包括可能的函数调用
	if(num)
	{
		//如果num不是0，那么说明需要输出字符串
		this->pushMidCode(PRINTFOP, new std::string(), new std::string(), num, false);
	}
	switch(rettype)
	{
	case INTRET:
		this->pushMidCode(PRINTFOP, new std::string("int"), new std::string(), temp, false);
		break;
	case CHARRET:
		this->pushMidCode(PRINTFOP, new std::string("char"), new std::string(), temp, false);
		break;
	}
	if(this->tok.id == RPARENT)
	{
		this->inSym();
	}
	else{
		this->errorHandle(NOTRPARENT);
	}
	//std::cout << "这是一个 <写语句>" << std::endl;
}

void Compiler:: returnStatement(bool *returnflag, eRetType returntype, std::string *name)
{
	//std::cout << "进入 <返回语句>" << std::endl;
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
			this->pushMidCode(ADDOP, temp, new std::string("0"), new std::string("#RET"), false);
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
		//如果说是int 或者是 char，却什么都不返回，也报错
		this->errorHandle(RETURNTYPEDISMATCH);
		return ;
	}
	//bug：返回语句应该统一跳到这个函数的结束段，但是之前却没有这个设定
	//统一函数体的结束处为 函数名$end
	std::stringstream ss = std::stringstream();
	ss << *name << "$end";
	//bug:注意这里main函数不需要返回！这里其他函数的return才有效，main函数因为根本不需要main的结束标号
	if(!this->isIdEqual(std::string("main"), *name))
		this->pushMidCode(GOTOOP, new std::string(), new std::string(), &(ss.str()), false);
	else{
		//bug:如果是main函数，那么直接生成EXITOP
		this->pushMidCode(EXITOP, new std::string(), new std::string(), new std::string(), false);
	}
	//std::cout << "这是一个 <返回语句>" << std::endl;
}

void Compiler:: statement(bool *returnflag, eRetType returntype, std::string *funcname)
{
	//std::cout << "进入 <语句>" << std::endl;
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
			return ;
		}
		this->inSym();
		if(this->tok.id == LPARENT)
		{
			//说明是一个有参函数调用，需要检查它是不是一个函数
			if(sym->symbolType != FUNCSYM)
			{
				this->errorHandle(NOTAFUNC);
				return ;
			}
			this->inSym();
			this->varParaList(sym);
			this->pushMidCode(CALLOP, new std::string(), new std::string(), sym->name, false);
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
			//说明是个简单变量或者参数变量，首先需要检查是不是简单变量或参数变量
			if(sym->symbolType != SIMPLESYM && sym->symbolType != PARASYM)
			{
				this->errorHandle(NOTASIMPLE);
			}
			this->inSym();
			eRetType rettype = NOTTYPE;
			std::string *expressoperand = new std::string();
			this->expression(&rettype, expressoperand);
			//做赋值

			//int-> char 把int的值给char 这个是不被允许的！
			if(sym->returnType == CHARRET && rettype == INTRET)
			{
				this->errorHandle(INTTOCHARNOTALLOW);
				return ;
			}
			this->pushMidCode(ADDOP, expressoperand, new std::string("0"), sym->name, false);
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
			//说明是一个数组变量，需要检查
			if(sym->symbolType != ARRAYSYM)
			{
				this->errorHandle(NOTANARRAY);
			}
			this->inSym();
			eRetType rettype = NOTTYPE;
			std::string *indexoperand = new std::string();
			this->expression(&rettype, indexoperand);
			//这里看indexoperand是不是一个整数常量
			if(this->isOperandNumber(indexoperand))
			{
				//如果是一个可以直接获得值的数字，那么需要检查
				int index = atoi(indexoperand->c_str());
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
			std::string *tempoperand = new std::string();
			this->expression(&righttype, tempoperand);
			//这里为了之后好处理，把要给数组元素赋值的右边变量统一用临时变量表示
			if(this->isOperandNumber(tempoperand))
			{
				std::string *temp = new std::string();
				this->genTemp(temp);
				this->pushMidCode(ADDOP, tempoperand, new std::string("0"), temp, false);
				*tempoperand = *temp;
			}
			//如果是int给char类型赋值，那么不允许！这里一开始怎么没把判断加上
			if(sym->returnType == CHARRET && righttype == INTRET)
			{
				this->errorHandle(INTTOCHARNOTALLOW);
			}
			this->pushMidCode(LARRAYOP, tempoperand, indexoperand, name, false);
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
			//无参数的函数调用，需要检查这个是不是一个无参函数
			if(sym->symbolType != FUNCSYM || sym->feature != 0)
			{
				this->errorHandle(NOTANOPARAFUNC);
				return ;
			}
			this->pushMidCode(CALLOP, new std::string(), new std::string(), name, false);
			this->inSym();
		}
		else{
			this->errorHandle(NOTSEMI);
		}
		break;
	case SEMI:
		//std::cout << "这是一个 <空>语句" << std::endl;
		this->inSym();
		break;

	}
	//std::cout << "这是一个 <语句>" << std::endl;
}

void Compiler:: statementList(bool *returnflag, eRetType returntype, std::string *name)
{
	//std::cout << "进入 <语句列>" << std::endl;
	while(this->isInRange(STATEMENT_BEGIN, STATEMENT_BEGIN_SIZE))
	{
		this->statement(returnflag, returntype, name);
	}
	//std::cout << "这是一个 <语句列>" << std::endl;
}

void Compiler:: varState()
{
	//std::cout << "进入 <变量说明>" << std::endl;
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
	//std::cout << "这是一个 <变量说明>" << std::endl;
}

void Compiler:: comStatement(bool *returnflag, eRetType returntype, std::string *name)
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
	this->statementList(returnflag, returntype, name);

	//std::cout << "这是一个 <复合语句>" << std::endl;
}