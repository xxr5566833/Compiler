#include "Compiler.h"

const int baseAddress = 0x10000000 / 4;

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



std::string *SP = new std::string("$sp");

std::string *FP = new std::string("$fp");

std::string *RA = new std::string("$ra");

//t9ͳһ��Ϊ������1ʹ�õ�Ĭ�ϼĴ���

std::string *T9 = new std::string("$t9");

//t8ר����Ϊ������2ʹ�õ�Ĭ�ϼĴ���

std::string *T8 = new std::string("$t8");

//t7ͳһ��Ϊ������3ʹ�õ�Ĭ�ϼĴ���

std::string *T7 = new std::string("$t7");

std::string *V0 = new std::string("$v0");

std::string *A0 = new std::string("$a0");

std::string *R0 = new std::string("$zero");


const int kMaxTempReg = 10;

const int kMaxSymReg = 8;


void Compiler::objectInit()
{

	for(int i = 0 ; i < kMaxRegAvailable ; i++)
	{
		this->allReg[i] = 0;
	}
}

void Compiler::initAscii()
{
	this->objectFile << "#��ʼ���ַ���\n";
	this->generateOrder(new std::string(".data"));

	for(int i = 0 ; i < this->stringNum ; i++)
	{
		std::string *str = this->stringTab[i];
		std::stringstream ss = std::stringstream();
		ss << "$Message" << i << ":" << ".asciiz" << "\"" << *str << "\"" ;
		this->generateOrder(&(ss.str()));
	}
	this->strAddress = baseAddress * 4;
	//ͳһ�ṩ400�Ŀռ䣬�����Դ�400���ַ����ַ���
	this->strAddress = this->strAddress + 400;
	//��ǰmipsAddress ���ǵ�ǰ�ַ�����ú�ĵ�ַ
	this->mipsAddress = this->strAddress;
}

void Compiler::printOrder(std::string *order)
{
	//std::cout << *order;
	this->objectFile << *order;
}

void Compiler::generateOrder(std::string *order, std::string *rs, int num)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << num << std::endl;
	this->printOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order, std::string *rs, int num, std::string *rt)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << num << "(" << *rt << ")" << std::endl;
	this->printOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order, std::string *rd, std::string *rt, int imme)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rd << "\t,\t" << *rt << "\t,\t" << imme << std::endl;
	this->printOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order, std::string *rd, std::string *rs, std::string *rt)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rd << "\t,\t" << *rs << "\t,\t" << *rt << std::endl;
	this->printOrder(&ss.str());
}

void Compiler:: generateOrder(std::string *order, std::string *rs, std::string *label)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << *label << std::endl;
	this->printOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order, std::string *target)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *target << std::endl;
	this->printOrder(&ss.str());
}

void Compiler::generateOrder(std::string *order)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << std::endl;
	this->printOrder(&ss.str());
}

void Compiler::genMipsLabel(std::string *label)
{
	std::string *newlab = new std::string();
	this->str2Lower(label, newlab);
	*newlab = *newlab + ":\n";
	this->printOrder(newlab);
	delete newlab;
}

void Compiler::initConstAndVar(symbol *sym, int initaddress)
{
	//��ʾ��ȫ�ֵĳ���
	if(sym == 0)
	{
		for(int i = 0 ; i < this->top ; i++)
		{
			symbol *sym = this->symTab[i];
			switch(sym->symbolType)
			{
			case CONSTSYM:
				this->generateOrder(LI, T9, sym->feature);
				//������Ҫ����ڵ�һ����������ʼ��ַƫ��
				this->generateOrder(SW, T9, sym->address * 4 + this->strAddress, R0);
				break;
			}
		}
		//std::cout << this->address;
	}
	//��ʾ�Ǿֲ��ĳ����ͱ���,��ʱ����ĳ�ʼ��ַΪ0����Ҫʹ�õ�ǰ��ջָ����Ѱַ
	else{
		symbol **symtab = this->funcSymTab[sym->ref];
		for(int i = 0 ; i < this->funcSymNum[sym->ref] ; i++)
		{
			symbol *sym = symtab[i];
			//std::cout << *sym->name << std::endl;
			switch(sym->symbolType)
			{
			case CONSTSYM:
				this->generateOrder(LI, T9, sym->feature);
				this->generateOrder(LI, T9, initaddress - sym->address * 4, SP);
			}
		}
		
	}
}

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
	//���泣��
	this->initConstAndVar(sym, 0);
	//��ǰָ֡�����֮ǰջָ��
	this->generateOrder(ADD, FP, SP, R0);
	//��ǰջָ���޸�
	this->generateOrder(ADDI, SP, SP , - currentaddress * 4);

}

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

	this->objectInit();
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
void Compiler::loadReg(std::string *rs, std::string *reg)
{
	//bug : ��ʱ����������Ϊȫ�ֵ���ʹ�ã�ֻ����Ϊ�ֲ��ģ�ֱ�Ӱ�������һ����ʶ��
	//reg ������ǣ�����������û����Ӧ�ļĴ�������ô�ñ�����Ӧ��Ĭ�ϼĴ�����ʲô
	if(this->isOperandRet(rs))
	{
		*reg = *V0;
	}
	else if(this->isOperandNumber(rs))
	{
		this->generateOrder(LI, reg, rs);
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
				//ȫ�ֱ�������Ҫ������ַ�����ƫ�Ƶ�
				this->generateOrder(LW, reg, this->strAddress + 4 * offset, R0);		
			}
			else{
				this->generateOrder(LW, reg, - offset * 4, FP);
			}
		}
		else{
			//˵������Ӧ�ļĴ�����������ô��ʱ�ȼ�鵱ǰ��Ӧ�ļĴ�����û�б�ʹ��
			std::string *old = this->allReg[regindex];
			std::stringstream ss = std::stringstream();
			ss << (regindex < (kMaxRegAvailable / 2) ? "$t" : "$s") << regindex % (kMaxRegAvailable / 2);
			*reg = ss.str();
			if(old == 0)
			{
				//��ʾ����Ĵ���δ�����䣬��ô�Ȱ���Ӧ��ַ�ϵ�ֵload������Ĵ���
				int offset = sym->address;
				if(global)
				{
					//ȫ�ֱ�������Ҫ������ַ�����ƫ�Ƶ�
					this->generateOrder(LW, reg, this->strAddress + 4 * offset, R0);		
				}
				else{
					this->generateOrder(LW, reg, - offset * 4, FP);
				}
				//��ά��allReg���� 
				this->allReg[regindex] = sym->name;
			}
			else{
				//����Ĵ����ѱ����䣬��ô����������ǲ��Ǻ͵�ǰ��Ҫ����һ���ģ������һ������ô����ֱ����
				if(this->isIdEqual(*rs, *old))
				{
					//��ôֱ���ü��ɣ�ʲô��������
				}
				else{
					//�����䣬���ұ�����Ĳ��������ʶ������ô�Ȱ�ԭ����д�أ��ٰ����load���Ĵ���
					symbol *oldsym = 0;
					bool oldglobal = false;
					this->findSym(old, &oldsym, &oldglobal);
					//��Ȼ�Ǳ�����Ĵ����ģ���ôһ���Ǿֲ������������ʱ������ͻ����ʱ����Ҫд�أ���Ϊ��һ�β��������������ʱ������ֻ��Ҫ�Ѿֲ�����д�ؼ���
					if(!this->isOperandTemp(oldsym->name))
						this->generateOrder(SW, reg, - oldsym->address * 4, FP);
					//����Ժ��ٰ��µı�ʶ����Ӧ�ĵ�ַ�ϵ�ֵload������Ĵ���
					this->generateOrder(LW, reg, - sym->address * 4, FP);
					//��ά��allreg����
					this->allReg[regindex] = sym->name;
				}
			}
		}
	}
}
//�ѽ��������ת��Ϊ��Ӧ�ļĴ���
void Compiler:: storeReg(std::string *rd, std::string *reg){

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
			std::string *old = this->allReg[regindex];
			std::stringstream ss = std::stringstream();
			ss << (regindex < (kMaxRegAvailable / 2) ? "$t" : "$s") << regindex % (kMaxRegAvailable / 2);
			*reg = ss.str();
			if(old == 0)
			{
				//��ʾ����Ĵ���δ������
				//��ά��allReg���� 
				this->allReg[regindex] = sym->name;
			}
			else{
				//����Ĵ����ѱ����䣬��ô����������ǲ��Ǻ͵�ǰ��Ҫ����һ���ģ������һ������ô����ֱ����
				if(this->isIdEqual(*rd, *old))
				{
					//��ôֱ���ü��ɣ�ʲô��������,ֱ����֮ǰ���õ�reg
				}
				else{
					//�����䣬���ұ�����Ĳ��������ʶ������ô�Ȱ�ԭ����д�أ�
					symbol *oldsym = 0;
					bool oldglobal = false;
					this->findSym(old, &oldsym, &oldglobal);
					//��Ȼ�Ǳ�����Ĵ����ģ���ôһ���Ǿֲ�����
					this->generateOrder(SW, reg, - oldsym->address * 4, FP);
					//��ά��allreg����
					this->allReg[regindex] = sym->name;
				}
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
	if(this->isOperandTemp(op1))
	{
		//���op1��һ����ʱ����
		//��������ʱ������Ӧ�ļĴ���
		this->loadReg(op1, reg1);
		if(this->isOperandNumber(op2))
		{
			//����ڶ�����������һ�����֣���ô�Ͱ����������Ժ�Ľ����Ϊ���������
			this->generateOrder(SUBI, rstreg, reg1, op2);
		}
		else{
			//�ڶ�����������һ����ʱ����
			this->loadReg(op2, reg2);
			//����������������ʱ��������ô�Ͱ��������˺�Ľ������t9����Ϊ�����ж�
			this->generateOrder(SUB, rstreg, reg1, reg2);
			//�ͷſռ�
		}
		//�ͷſռ�
	}
	else{
		//��һ����������һ������
		if(this->isOperandNumber(op2))
		{
			//�����������������֣�����������֮��Ľ����t9
			int value1 = atoi(op1->c_str());
			int value2 = atoi(op2->c_str());
			value2 = value1 - value2;
			this->generateOrder(LI, rstreg, value2);
		}
		else{
			//�ڶ�����������һ����ʱ����
			this->loadReg(op2, reg2);
			//��Ҫ�ȰѲ�����1����li��t9��
			this->generateOrder(LI, T9, op1);
			this->generateOrder(SUB, rstreg, T9, reg2);
			//�ͷſռ�
		}
	}
	switch(code->op)
	{
	case EQUOP:
		this->generateOrder(BEQ, rstreg, R0, code->rstname);
		break;
	case NEQUOP:
		this->generateOrder(BNE, rstreg, R0, code->rstname);
		break;
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

void Compiler::handleRealPara(std::string *para)
{
	//paraҲ�Ǵӱ��ʽ�õ���ֵ����ʱ���Ƿ�Ϊ���ֺ���ʱ����
	std::string *rstreg = new std::string();
	*rstreg = *T7;
	this->loadReg(para, rstreg);
	this->generateOrder(SW, rstreg, 0, SP);
	this->generateOrder(ADDI, SP, SP, -4);
	delete rstreg;
}

void Compiler::handleCall(std::string *name)
{
	std::string *newlab = new std::string();
	this->str2Lower(name, newlab);
	this->generateOrder(JAL, newlab);
	this->generateOrder(NOP);
	delete newlab;
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
				this->generateOrder(SW, reg, this->strAddress + 4 * sym->address, R0);		
			}
			else{
				this->generateOrder(SW, reg, - sym->address * 4, FP);
			}
		}
	}
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
		if(this->isOperandTemp(op2))
		{
			//������1��һ�����֣���ô��ʱ������2�������ʱ��������ô���������Ҳ����ʱ����
			this->loadReg(op2, reg2);
			this->storeReg(rst, rstreg);
			this->generateOrder(ADDI, rstreg, reg2, op1);
		}
		else{
			//������2ֻ����0��
			this->storeReg(rst, rstreg);
			this->generateOrder(LI, rstreg, op1);
		}
	}
	else{
		//������1��һ����ʱ����/#RET/��ʶ��
		this->loadReg(op1, reg1);
		if(this->isOperandNumber(op2))
		{
			//������2��һ������
			this->storeReg(rst, rstreg);
			//����˽����������Ӧ�ļĴ���
			this->generateOrder(ADDI, rstreg, reg1, op2);
			//��ʱ����Ҫ������������ǲ�����Ҫд�ص�ַ
		}
		else{
			//������2��һ����ʱ����
			//�����������һ����ʱ����/#RET/��ʶ��
			this->loadReg(op2, reg2);
			this->storeReg(rst, rstreg);
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
		//������1��һ�����֣���ô��ʱ������2�ͽ��������������ʱ����
		if((*op1)[0] == '0')
		{
			//��ʾ������1��0����ô��ʱֱ����$zero�Ϳ���
			*reg1 = *R0;
		}
		else{
			//������1����0����LI
			this->generateOrder(LI, reg1, op1);
		}
		this->loadReg(op2, reg2);
		this->storeReg(rst, rstreg);
		this->generateOrder(SUB, rstreg, reg1, reg2);
	}
	else{
		//������1��һ����ʱ����
		this->loadReg(op1, reg1);
		if(this->isOperandTemp(op2))
		{
			//������2Ҳ��һ����ʱ����
			this->loadReg(op2, reg2);

			//���������Ҳ��һ����ʱ����
			this->storeReg(rst, rstreg);

			//����˽����������Ӧ�ļĴ���
			this->generateOrder(SUB, rstreg, reg1, reg2);
		}
		else{
			//������2��һ������
			//�����������һ����ʱ����
			this->storeReg(rst, rstreg);
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
	this->loadReg(op1, reg1);
	this->loadReg(op2, reg2);
	this->storeReg(rst, rstreg);
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

	this->loadReg(code->op2name, reg2);
	this->generateOrder(ADDI, T9, reg2, sym->address);
	this->generateOrder(SLL, T9, T9, 2);

	this->storeReg(code->rstname, rstreg);
	if(global)
	{
		//�����ƫ�ƺ�����ڵ�һ������Ѱַ
		this->generateOrder(LW, rstreg, this->strAddress, T9);
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
	this->loadReg(index, reg2);
	this->generateOrder(ADDI, T7, reg2, sym->address);
	this->generateOrder(SLL, T7, T7, 2);
	this->loadReg(rs, reg1);
	if(global)
	{
		this->generateOrder(SW, reg1, this->strAddress, T7);
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
	this->storeReg(code->rstname, rstreg);
	this->generateOrder(ADD, rstreg, V0, R0);
	this->writeBack(code->rstname, rstreg);

	delete rstreg;
}

void Compiler::handlePrintf(midcode *code)
{
	if(code->op1name->length() == 0)
	{
		//˵�����ַ���
		this->generateOrder(LI, V0, 4);
		std::stringstream ss = std::stringstream();
		ss << "$Message" << *(code->rstname);
		this->generateOrder(LA, A0, &(ss.str()));
		this->generateOrder(SYSCALL);
	}
	else{
		//˵���Ǳ��ʽ,����op1name�ĵ�һ���ַ���ʲô��ĸ���ж����������������ĸ
		this->generateOrder(LI, V0, (*code->op1name)[0] == 'i' ? 1 : 11);
		//������Ҫ��Ҫ���������/�ַ�����a0�Ĵ���
		std::string *rstreg = new std::string();
		*rstreg = *T7;
		this->loadReg(code->rstname, rstreg);
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
	this->mipsAddress = 0;
	this->currentRef = -1;
	this->initAscii();
	this->generateOrder(new std::string(".text"));
	//�洢ȫ�ֳ���
	this->initConstAndVar(0, this->mipsAddress);
	
	//��ʼ���м������
	//�Ӹ�gotomain
	this->generateOrder(ADD, FP, SP, R0);
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