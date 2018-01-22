#include "Compiler.h"

////////////////////////////////////////////////
//Ŀ������������							  //
//											  //
////////////////////////////////////////////////
//mips������
std::string *SW = new std::string("sw");

std::string *LW = new std::string("lw");

std::string *LI = new std::string("li");

std::string *ADD = new std::string("add");

std::string *ADDI = new std::string("addi");

std::string *SUBI = new std::string("subi");

std::string *SUB = new std::string("sub");

std::string *BEQ = new std::string("beq");

std::string *BNE = new std::string("bne");

std::string *BGEZ = new std::string("bgez");

std::string *BGTZ = new std::string("bgtz");

std::string *BLEZ = new std::string("blez");

std::string *BLTZ = new std::string("bltz");

std::string *J = new std::string("j");

std::string *JAL = new std::string("jal");

std::string *JR = new std::string("jr");

std::string *MULOBJ = new std::string("mul");

std::string *DIVOBJ = new std::string("div");

std::string *MFLO = new std::string("mflo");

std::string *SYSCALL = new std::string("syscall");

std::string *LA = new std::string("la");

std::string *NOP = new std::string("nop");

std::string *SLL = new std::string("sll");

std::string *MOVE = new std::string("move");

std::string *ADDU = new std::string("addu");


std::string *SP = new std::string("$sp");

std::string *FP = new std::string("$fp");

std::string *RA = new std::string("$ra");

std::string *GP = new std::string("$gp");

//t9ͳһ��Ϊ������1ʹ�õ�Ĭ�ϼĴ���

std::string *T9 = new std::string("$t9");

//t8ר����Ϊ������2ʹ�õ�Ĭ�ϼĴ���

std::string *T8 = new std::string("$t8");

//t7ͳһ��Ϊ������3ʹ�õ�Ĭ�ϼĴ���

std::string *T7 = new std::string("$t7");

std::string *V0 = new std::string("$v0");

std::string *A0 = new std::string("$a0");

std::string *R0 = new std::string("$zero");



void Compiler::objectInit()
{
	this->mipsIndex = 0;
	this->currentRef = -1;
	this->regInit();
}

void Compiler::regInit()
{
	for(int i = 0 ; i < kMaxRegAvailable ; i++)
	{
		this->allReg[i] = 0;
	}
}

void Compiler::initAscii()
{
	//��Ϊ����mars��defaultģʽ�£�.asciiz �洢�ĵ�ַ���Ǵ�0x10000000��ʼ�ģ���֮��ȫ�ֱ�����Ѱֱַ�Ӵ�$gp��ʼ���ɣ��������ﲻ��Ҫ��¼strAddress��
	this->generateOrder(new std::string(".data"));

	for(int i = 0 ; i < this->stringNum ; i++)
	{
		std::string *str = this->stringTab[i];
		std::stringstream ss = std::stringstream();
		ss << "$Message" << i << ":" << ".asciiz" << "\"" << *str << "\"" ;
		this->generateOrder(&(ss.str()));
	}
}
//���ָ��
void Compiler::pushOrder(std::string *order)
{
	//std::cout << *order;
	std::string *save = new std::string();
	*save = *order;
	this->mipsCodes[this->mipsIndex++] = save;
}

void Compiler::writeMipsOrderToFile(std::fstream &tofile)
{
	std::cout << "һ����" << this->mipsIndex << "��Ŀ�����" << std::endl ;
	tofile << "#һ����" << this->mipsIndex << "��Ŀ�����" << std::endl << std::endl;
	for(int i = 0 ; i < this->mipsIndex ; i++)
	{
		tofile << *(this->mipsCodes[i]);
	}
}

void Compiler::generateOrder(std::string *order, std::string *rs, int num)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << num << std::endl;
	this->pushOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order, std::string *rs, int num, std::string *rt)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << num << "(" << *rt << ")" << std::endl;
	this->pushOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order, std::string *rd, std::string *rt, int imme)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rd << "\t,\t" << *rt << "\t,\t" << imme << std::endl;
	this->pushOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order, std::string *rd, std::string *rs, std::string *rt)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rd << "\t,\t" << *rs << "\t,\t" << *rt << std::endl;
	this->pushOrder(&ss.str());
}

void Compiler:: generateOrder(std::string *order, std::string *rs, std::string *label)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << *label << std::endl;
	this->pushOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order, std::string *target)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *target << std::endl;
	this->pushOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << std::endl;
	this->pushOrder(&ss.str());
}

void Compiler::genMipsLabel(std::string *label)
{
	std::string *newlab = new std::string();
	this->str2Lower(label, newlab);
	*newlab = *newlab + ":\n";
	this->pushOrder(newlab);
	delete newlab;
}
//init ������ ��Ԫʽת��ΪĿ�����
void Compiler::funcBegin(std::string *name)
{
	//����ʱ sp�Ѿ������ʵ�Σ�����sp�ĵ�ַ�Ѿ��ı䣬Ϊ�˷��㴦�������sp��ָ���ط����β�֮ǰ��λ��
	symbol *sym = 0;
	this->find(name, &sym, false);
	//����label,���Ǻ�����
	this->genMipsLabel(sym->name);
	//�ռ���� ���� ���� ���� t�Ĵ�����s�Ĵ��� ��һ�ε�ָ֡�� ��һ�εķ��ص�ַ ��ǰָ֡�����֮ǰ��ջָ�룬  ��ǰջָ���޸��Է���ռ�
	//currentaddress �洢��Ҫ����Ŀռ��С
	int currentaddress = this->funcMaxAddress[sym->ref];
	int paranum = sym->feature;
	if(paranum != 0)
		this->generateOrder(ADDI, SP, SP, paranum * 4);

	//�Ĵ���ѹջ

	for(int i = 0 ; i < kMaxRegAvailable ; i ++)
	{
		std::stringstream ss = std::stringstream();
		int index = i % (kMaxRegAvailable / 2);
		char *sym = i >= (kMaxRegAvailable / 2) ? "$s" : "$t"; 
		ss << sym << index;
		this->generateOrder(SW, &(ss.str()), - currentaddress * 4, SP);
		currentaddress += 1;
	}

	//�ȱ���ָ֡��
	this->generateOrder(SW, FP, - currentaddress * 4, SP);
	//���淵�ص�ַ
	currentaddress += 1;
	this->generateOrder(SW, RA, - currentaddress * 4, SP);
	currentaddress += 1;
	//��ǰָ֡�����֮ǰջָ��
	this->generateOrder(ADD, FP, SP, R0);
	//��ǰջָ���޸�
	this->generateOrder(ADDI, SP, SP , - currentaddress * 4);

}
//ret ������ ��Ԫʽת��ΪĿ�����
void Compiler::handleRet(std::string *name)
{
	//������������ʱ��Ҫ��
	symbol *sym = 0;
	this->find(name, &sym, false);
	//����з���ֵ�Ѿ��ڸ�ֵ�п��ǹ��ˣ� �����ֻ��������ջ��ά��
	//���·��ص�ַ
	int currentaddress = 1;
	this->generateOrder(LW, RA, currentaddress * 4, SP);
	//���µ�ǰָ֡��
	currentaddress += 1;
	this->generateOrder(LW, FP, currentaddress * 4, SP);
	currentaddress += 1;

	this->regInit();
	//����ÿһ���Ĵ���
	for(int i = kMaxRegAvailable - 1 ; i >= 0 ; i--)
	{
		std::stringstream ss = std::stringstream();
		int index = i % (kMaxRegAvailable / 2);
		char *sym = i >= (kMaxRegAvailable / 2) ? "$s" : "$t"; 
		ss << sym << index;
		this->generateOrder(LW, &(ss.str()), currentaddress * 4, SP);
		currentaddress += 1;
	}

	//����ջָ��
	currentaddress += (this->funcMaxAddress[sym->ref] - 1);
	this->generateOrder(ADDI, SP, SP, currentaddress * 4);
	//��ת��ȥ
	this->generateOrder(JR, RA);
	this->generateOrder(NOP);
}

//offset��������ַ�������ƫ�Ƶ�ַ  �����������fp�ļ��ٵ�ַ  ע�������ǰ��ּǵ�
//������Ϊ����ֲ�������ȫ�ֱ�����������ô���Ǿֲ�����
void Compiler::findSym(std::string *name, symbol **resultsym, bool *global)
{
	symbol **symtab = this->funcSymTab[this->currentRef];
	int length = this->funcSymNum[this->currentRef];
	for(int i = 0 ; i < length ; i++)
	{
		symbol *sym = symtab[i];
		//bug������һ��ʼΪʲôû����isIdEqual()?
		if(this->isIdEqual(*name, *(sym->name)))
		{
			*resultsym = sym;
			*global = false;
			return ;
		}
	}
	for(int i = 0 ; i < this->top ; i++)
	{
		symbol *sym = this->symTab[i];
		if(this->isIdEqual(*name, *(sym->name)))
		{
			*resultsym = sym;
			*global = true;
			return ;
		}
	}

}


//ת��Ҫʹ�õĲ�����Ϊ��Ӧ�ļĴ���
void Compiler::getUseReg(std::string *rs, std::string *reg)
{
	//bug : ��ʱ����������Ϊȫ�ֵ���ʹ�ã�ֻ����Ϊ�ֲ��ģ�ֱ�Ӱ�������һ����ʶ��
	//reg ������ǣ�����������û����Ӧ�ļĴ�������ô�ñ�����Ӧ��Ĭ�ϼĴ�����ʲô
	if(this->isOperandRet(rs))
	{
		*reg = *V0;
	}
	else if(this->isOperandNumber(rs))
	{
		//�����0����ôֱ�ӷ���$zero
		if((*rs)[0] == '0')
		{
			*reg = *R0;
		}
		else{
			this->generateOrder(LI, reg, rs);
		}
	}
	else{
		//�����Ǳ�ʶ����������ʱ����
		bool global = false;
		symbol *sym = 0;
		this->findSym(rs, &sym, &global);
		int regindex = sym->regIndex;
		if(regindex == -1)
		{
			//˵��û����Ӧ�ļĴ���������ֱ�Ӵ����ĵ�ַ�ϵ�ֵload����Ӧ��reg�Ĵ�����
			int offset = sym->address;
			if(global)
			{
				this->generateOrder(LW, reg, 4 * offset, GP);		
			}
			else{
				this->generateOrder(LW, reg, - offset * 4, FP);
			}
		}
		else{
			//˵������Ӧ�ļĴ�����������ô��ʱ�ȼ�鵱ǰ��Ӧ�ļĴ�����û�б�ʹ��
			std::stringstream ss = std::stringstream();
			ss << (regindex < (kMaxRegAvailable / 2) ? "$t" : "$s") << regindex % (kMaxRegAvailable / 2);
			*reg = ss.str();
			//����ǲ�������ʱ�����Ӧ��reg��û�м�¼�����Ǻ������¼���Ǹò�����˵���ò�����û�б�load���Ĵ�������Ҫ�Ȱ������ڴ�load����Ӧ�ļĴ�����
			if(sym->symbolType == PARASYM &&(!this->allReg[regindex] || !this->isIdEqual(*(this->allReg[regindex]), *sym->name)))
			{
				this->generateOrder(LW, reg, - sym->address * 4, FP);
			}
			this->allReg[regindex] = sym->name;
		}
	}
}
//�ѽ��������ת��Ϊ��Ӧ�ļĴ���
void Compiler:: getResultReg(std::string *rd, std::string *reg){

	//��ʱrdֻ�������������ʶ�� ��ʱ���� #RET
	if(this->isOperandRet(rd))
	{
		//��ʱֱ����regΪv0
		*reg = *V0;
	}
	else{
		//�����Ǳ�ʶ����������ʱ����
		bool global = false;
		symbol *sym = 0;
		this->findSym(rd, &sym, &global);
		int regindex = sym->regIndex;
		if(regindex == -1)
		{
			//˵��û����Ӧ�ļĴ�������
			//��ʱʲô��������ֱ����reg��Ĭ����Ϊ��Ž���ļĴ�����Ȼ���õ����ߵ���writeBack�ٰɽ����ص�ַ��
		}
		else{
			//˵������Ӧ�ļĴ�����������ô��ʱ�ȼ�鵱ǰ��Ӧ�ļĴ�����û�б�ʹ��
			std::stringstream ss = std::stringstream();
			ss << (regindex < (kMaxRegAvailable / 2) ? "$t" : "$s") << regindex % (kMaxRegAvailable / 2);
			*reg = ss.str();
			this->allReg[regindex] = sym->name;
		}
	}

}

//����������Ƿ�Ҫд�ص��ڴ���
void Compiler::writeBack(std::string *rd, std::string *reg)
{
	if(!this->isOperandRet(rd))
	{
		symbol *sym = 0;
		bool global = false;
		this->findSym(rd, &sym, &global);
		if(sym && sym->regIndex == -1)
		{
			//����ǲ�����Ĵ����ı�ʶ������ô��ʱ����Ҫд����Ӧ�ĵ�ַ��ȥ
			if(global)
			{
				this->generateOrder(SW, reg, 4 * sym->address, GP);		
			}
			else{
				this->generateOrder(SW, reg, - sym->address * 4, FP);
			}
		}
	}
}

void Compiler::handleBranch(midcode *code)
{
	std::string *op1 = code->op1name;
	std::string *op2 = code->op2name;

	std::string *reg1 = new std::string();
	*reg1 = *T9;
	std::string *reg2 = new std::string();
	*reg2 = *T8;
	std::string *rstreg = new std::string();
	*rstreg = *T7;
	//���ȿ���beq��bne����Ϊ��������Ҫ������������
	if(code->op == EQUOP || code->op == NEQUOP)
	{
		if(this->isOperandNumber(op1))
		{
			if(this->isOperandNumber(op2))
			{
				//�����������֣����Ľ������reg1��zero����Ϊreg2
				int value1 = atoi(op1->c_str());
				int value2 = atoi(op2->c_str());
				value2 = value1 - value2;
				std::string constvalue = std::string();
				this->int2string(&constvalue, value2);
				this->getUseReg(&constvalue, reg1);
				*reg2 = *R0;
			}
			else{
				//��һ�������֣��ڶ�����������
				this->getUseReg(op1, reg1);
				this->getUseReg(op2, reg2);
			}
		}
		else{
			this->getUseReg(op1, reg1);
			this->getUseReg(op2, reg2);
		}
		//��ʵ�����������ֵ�������⣬ʣ�µĶ���һ����
		this->generateOrder(code->op == EQUOP ? BEQ : BNE, reg1, reg2, code->rstname);
	}
	else{
		if(!this->isOperandNumber(op1))
		{
			//���op1��һ����ʱ�������߱�ʶ��
			//��ö�Ӧ�ļĴ���
			this->getUseReg(op1, reg1);
			if(this->isOperandNumber(op2))
			{
				//����ڶ�����������һ�����֣���ô�Ͱ����������Ժ�Ľ����Ϊ���������
				this->generateOrder(SUBI, rstreg, reg1, op2);
			}
			else{
				//�ڶ�����������һ����ʱ�������߱�ʶ��
				this->getUseReg(op2, reg2);
				//�������������������֣���ô�Ͱ��������˺�Ľ������t9����Ϊ�����ж�
				this->generateOrder(SUB, rstreg, reg1, reg2);
			}
		}
		else{
			//��һ����������һ������
			if(this->isOperandNumber(op2))
			{
				//������������������
				int value1 = atoi(op1->c_str());
				int value2 = atoi(op2->c_str());
				value2 = value1 - value2;
				std::string constvalue = std::string();
				this->int2string(&constvalue, value2);
				this->getUseReg(&constvalue, rstreg);
			}
			else{
				//�ڶ�����������������
				this->getUseReg(op2, reg2);
				this->getUseReg(op1, reg1);
				this->generateOrder(SUB, rstreg, reg1, reg2);
				//�ͷſռ�
			}
		}
		switch(code->op)
		{
		case MOREEQUOP:
			this->generateOrder(BGEZ, rstreg, code->rstname);
			break;
		case MOREOP:
			this->generateOrder(BGTZ, rstreg, code->rstname);
			break;
		case LESSEQUOP:
			this->generateOrder(BLEZ, rstreg, code->rstname);
			break;
		case LESSOP:
			this->generateOrder(BLTZ, rstreg, code->rstname);
			break;
		}
	}
	//һ��ʼ���˼�nop..
	this->generateOrder(NOP);
	//�ͷſռ䣺
	delete rstreg;
	delete reg1;
	delete reg2;
}


void Compiler::handleGoto(std::string *label)
{
	std::string *newlab = new std::string();
	this->str2Lower(label, newlab);
	this->generateOrder(J, newlab);
	this->generateOrder(NOP);
}
//pushת��ΪĿ�����
void Compiler::handleRealPara(std::string *para)
{
	//paraҲ�Ǵӱ��ʽ�õ���ֵ
	std::string *rstreg = new std::string();
	*rstreg = *T7;
	this->getUseReg(para, rstreg);
	this->generateOrder(SW, rstreg, 0, SP);
	this->generateOrder(ADDI, SP, SP, -4);
	delete rstreg;
}
//call ת��ΪĿ�����
void Compiler::handleCall(std::string *name)
{
	std::string *newlab = new std::string();
	this->str2Lower(name, newlab);
	this->generateOrder(JAL, newlab);
	this->generateOrder(NOP);
	delete newlab;
}

void Compiler::handleAdd(midcode *code)
{
	std::string *op1 = code->op1name;
	std::string *op2 = code->op2name;
	std::string *rst = code->rstname;

	std::string *reg1 = new std::string();
	*reg1 = *T9;
	std::string *reg2 = new std::string();
	*reg2 = *T8;
	std::string *rstreg = new std::string();
	*rstreg = *T7;
	if(this->isOperandNumber(op1))
	{
		if(!this->isOperandNumber(op2))
		{
			
			this->getUseReg(op2, reg2);
			this->getResultReg(rst, rstreg);
			this->generateOrder(ADDI, rstreg, reg2, op1);
		}
		else{
			//������2Ҳ����������������
			int value1 = atoi(op1->c_str());
			int value2 = atoi(op2->c_str());
			value2 = value1 + value2;
			this->getResultReg(rst, rstreg);
			this->generateOrder(LI, rstreg, value2);
		}
	}
	else{
		//������1��һ����ʱ����/#RET/��ʶ��
		this->getUseReg(op1, reg1);
		if(this->isOperandNumber(op2))
		{
			//������2��һ������
			this->getResultReg(rst, rstreg);
			//����˽����������Ӧ�ļĴ���
			this->generateOrder(ADDI, rstreg, reg1, op2);
			//��ʱ����Ҫ������������ǲ�����Ҫд�ص�ַ
		}
		else{
			//�����������һ����ʱ����/#RET/��ʶ��
			this->getUseReg(op2, reg2);
			this->getResultReg(rst, rstreg);
			this->generateOrder(ADD, rstreg, reg1, reg2);
		}
	}
	this->writeBack(rst, rstreg);
	//�ͷſռ�
	delete reg1;
	delete reg2;
	delete rstreg;
}

void Compiler::handleSub(midcode *code)
{
	std::string *op1 = code->op1name;
	std::string *op2 = code->op2name;
	std::string *rst = code->rstname;

	std::string *reg1 = new std::string();
	*reg1 = *T9;
	std::string *reg2 = new std::string();
	*reg2 = *T8;
	std::string *rstreg = new std::string();
	*rstreg = *T7;
	if(this->isOperandNumber(op1))
	{
		this->getUseReg(op1, reg1);
		this->getUseReg(op2, reg2);
		this->getResultReg(rst, rstreg);
		this->generateOrder(SUB, rstreg, reg1, reg2);
	}
	else{
		//������1��һ��������
		this->getUseReg(op1, reg1);
		if(!this->isOperandNumber(op2))
		{
			this->getUseReg(op2, reg2);

			//���������
			this->getResultReg(rst, rstreg);

			//����˽����������Ӧ�ļĴ���
			this->generateOrder(SUB, rstreg, reg1, reg2);
		}
		else{
			//������2��һ������
			this->getResultReg(rst, rstreg);
			this->generateOrder(SUBI, rstreg, reg1, op2);
		}
	}
	this->writeBack(rst, rstreg);
	delete reg1;
	delete reg2;
	delete rstreg;
}


void Compiler::handleMulOrDiv(midcode *code)
{
	std::string *op1 = code->op1name;
	std::string *op2 = code->op2name;
	std::string *rst = code->rstname;

	std::string *reg1 = new std::string();
	*reg1 = *T9;
	std::string *reg2 = new std::string();
	*reg2 = *T8;
	std::string *rstreg = new std::string();
	*rstreg = *T7;
	this->getUseReg(op1, reg1);
	this->getUseReg(op2, reg2);
	this->getResultReg(rst, rstreg);
	if(code->op == MULOP)
	{
		this->generateOrder(MULOBJ, rstreg, reg1, reg2);
	}
	else{
		this->generateOrder(DIVOBJ, reg1, reg2);
		this->generateOrder(MFLO, rstreg);
	}
	this->writeBack(rst, rstreg);
	delete reg1;
	delete reg2;
	delete rstreg;
}

void Compiler::handleRarray(midcode *code)
{
	std::string *reg2 = new std::string();
	*reg2 = *T8;
	std::string *rstreg = new std::string();
	*rstreg = *T7;

	bool global = false;
	symbol *sym = 0;
	this->findSym(code->op1name, &sym, &global);
	this->getUseReg(code->op2name, reg2);
	this->generateOrder(ADDI, T9, reg2, sym->address);
	this->generateOrder(SLL, T9, T9, 2);
	this->getResultReg(code->rstname, rstreg);
	if(global)
	{
		this->generateOrder(ADDU, T9, T9, GP);
		this->generateOrder(LW, rstreg, 0, T9);
	}
	else{
		this->generateOrder(SUB, T9, FP, T9);
		this->generateOrder(LW, rstreg, 0, T9);
	}
	this->writeBack(code->rstname, rstreg);

	//�ͷſռ�
	delete reg2;
	delete rstreg;
}


void Compiler:: handleLarray(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *index = code->op2name;
	std::string *name = code->rstname;

	std::string *reg1 = new std::string();
	*reg1 = *T9;
	std::string *reg2 = new std::string();
	*reg2 = *T8;

	bool global = false;
	symbol *sym = 0;
	this->findSym(name, &sym, &global);
	//����±�
	this->getUseReg(index, reg2);
	this->generateOrder(ADDI, T7, reg2, sym->address);
	this->generateOrder(SLL, T7, T7, 2);
	this->getUseReg(rs, reg1);
	if(global)
	{
		this->generateOrder(ADDU, T7, T7, GP);
		this->generateOrder(SW, reg1, 0, T7);
	}
	else{
		this->generateOrder(SUB, T7, FP, T7);
		this->generateOrder(SW, reg1, 0, T7);
	}
	delete reg1;
	delete reg2;
}

void Compiler:: handleScanf(midcode *code)
{
	if((*code->op2name)[0] == 'i')
	{
		//����һ������
		this->generateOrder(LI, V0, 5);
	}
	else {
		//����һ���ַ�
		this->generateOrder(LI, V0, 12);
	}
	this->generateOrder(SYSCALL);
	//���������ֻ����һ����ʶ��
	std::string *rstreg = new std::string();
	*rstreg = *T7;
	this->getResultReg(code->rstname, rstreg);
	this->generateOrder(ADD, rstreg, V0, R0);
	this->writeBack(code->rstname, rstreg);

	delete rstreg;
}

void Compiler::handlePrintf(midcode *code)
{
	//Ϊ�˺�֮ǰ����Ԫʽ�Ķ���ƥ�䣬 ������ж�������ַ�������������ʽ�ķ�����Ϊ�жϵڶ����������Ƿ�Ϊ0
	if(this->isIdEqual(*code->op2name, std::string("0")))
	{
		//˵�����ַ���
		this->generateOrder(LI, V0, 4);
		std::stringstream ss = std::stringstream();
		ss << "$Message" << *(code->rstname);
		this->generateOrder(LA, A0, &(ss.str()));
		this->generateOrder(SYSCALL);
	}
	else{
		//˵���Ǳ��ʽ,����op2name�ĵ�һ���ַ���ʲô��ĸ���ж����������������ĸ
		this->generateOrder(LI, V0, (*code->op2name)[0] == 'i' ? 1 : 11);
		//������Ҫ��Ҫ���������/�ַ�����a0�Ĵ���
		std::string *rstreg = new std::string();
		*rstreg = *T7;
		this->getUseReg(code->rstname, rstreg);
		this->generateOrder(ADD, A0, rstreg, R0);
		this->generateOrder(SYSCALL);
		delete rstreg;
	}
}

void Compiler::handleExit()
{
	this->generateOrder(LI, V0, 10);
	this->generateOrder(SYSCALL);
}

//ͳһ�涨sp���ú�ı�
void Compiler::generate()
{
	this->initAscii();
	this->generateOrder(new std::string(".text"));
	
	//��ʼ���м������
	//�Ӹ�gotomain
	this->generateOrder(ADD, FP, SP, R0);
	this->generateOrder(ADDI, GP, GP, 0x10000);
	this->handleGoto(new std::string("main"));
	for(int i = 0 ; i < this->midindex ; i++)
	{
		midcode *code = this->codes[i];
		switch(code->op)
		{
		case FUNCBEGINOP:
			this->currentRef += 1;
			this->funcBegin(code->rstname);
			break;
		case EQUOP:
		case NEQUOP:
		case MOREOP:
		case MOREEQUOP:
		case LESSOP:
		case LESSEQUOP:
			this->handleBranch(code);
			break;
		case GOTOOP:
			this->handleGoto(code->rstname);
			break;
		case LABOP:
			this->genMipsLabel(code->rstname);
			break;
		case REALPARAOP:
			this->handleRealPara(code->rstname);
			break;
		case RARRAYOP:
			this->handleRarray(code);
			break;
		case CALLOP:
			this->handleCall(code->rstname);
			break;
		case RETOP:
			this->handleRet(code->rstname);
			break;
		case DIVOP:
		case MULOP:
			this->handleMulOrDiv(code);
			break;
		case ADDOP:
			this->handleAdd(code);
			break;
		case SUBOP:
			this->handleSub(code);
			break;
		case LARRAYOP:
			this->handleLarray(code);
			break;
		case SCANFOP:
			this->handleScanf(code);
			break;
		case PRINTFOP:
			this->handlePrintf(code);
			break;
		case EXITOP:
			this->handleExit();
			break;


		}
	}
}