#include "Compiler.h"

const int baseAddress = 0x10000000 / 4;

//mips������
const char *SW = "sw";

const char *LW = "lw";

const char *LI = "li";

const char *ADD = "add";

const char *ADDI = "addi";

const char *SUB = "sub";

const char *BEQ = "beq";

const char *BNE = "bne";

const char *BGEZ = "bgez";

const char *BGTZ = "bgtz";

const char *BLEZ = "blez";

const char *BLTZ = "bltz";

const char *J = "j";

const char *JAL = "jal";

const char *JR = "jr";

const char *MUL ="mul";

const char *DIVIDE = "div";

const char *MFLO = "mflo";

const char *SYSCALL = "syscall";

const char *LA = "la";

const char *NOP = "nop";

const char *SB = "sb";

const char *SLL = "sll";


const char *SP = "$sp";

const char *FP = "$fp";

const char *RA = "$ra";

const char *T0 = "$t0";

//t9ͳһ��Ϊ��ʱ�Ĵ���

const char *T9 = "$t9";

//t8ר����Ϊȫ�ֱ����Ĵ�ȡ����Ĵ���

const char *T8 = "$t8";

const char *T1 = "$t1";

const char *V0 = "$v0";

const char *A0 = "$a0";

const char *R0 = "$zero";


//һЩ����

const int maxTempReg = 8;

const int maxSymReg = 8;

void Compiler::objectInit()
{

	for(int i = 0 ; i < maxTempReg ; i ++)
	{
		this->tempReg[i] = -1;
	}
	for(int i = 0 ; i < maxSymReg ; i++)
	{
		this->symReg[i] = 0;
	}
	this->tempRegIndex = 0;
	this->symRegIndex = 0;
}

void Compiler::stackPop()
{
	//�Ĵ���ջ�ָ�
	//�ָ�֮ǰͬ����Ҫ���ľ��ǣ���֮ǰȫ�ֱ����ĸı����д���ڴ����д��ԭ�����õ����ļĴ�����

	for(int i = 0 ; i < maxSymReg ; i++)
	{
		std::string *name = this->symReg[i];
		if(name)
		{
			bool global = false;
			int offset = 0;
			std::stringstream ss = std::stringstream();
			ss << "$s" << i;
			this->findAddress(name, &offset, &global);
			if(global)
			{
				//��һ��ȫ�ֱ�������ô��ʱ��Ҫ����д���ڴ�,������д�ص����¼Ĵ�����
				this->generateOrder(new std::string(SW), &(ss.str()), this->strAddress + offset * 4, new std::string(R0));
				int address = 2 + maxSymReg - i;
				this->generateOrder(new std::string(SW), &(ss.str()), address * 4, new std::string(SP));
			}
		}
	}

	this->objectInit();
}

void Compiler::initAscii()
{
	this->objectFile << "#��ʼ���ַ���\n";
	this->generateOrder(new std::string(".data"));

	for(int i = 0 ; i < this->stringNum ; i++)
	{
		std::string *str = this->stringTab[i];
		std::stringstream ss = std::stringstream();
		ss << "$Message" << i << ":" << ".asciiz" << "\"" << *str << "\"";
		this->generateOrder(&(ss.str()));
	}
	this->strAddress = baseAddress * 4;
	//ͳһ�ṩ400�Ŀռ䣬�����Դ�400���ַ����ַ���
	this->strAddress = this->strAddress + 400;
	//��ǰmipsAddress ���ǵ�ǰ�ַ�����ú�ĵ�ַ
	this->mipsAddress = this->strAddress;
}

/*void Compiler::initAscii()
{
	this->objectFile << "#��ʼ���ַ���\n";
	//strAddress �ǵ�ǰ���ַ�����ַ  ���ֽڼǵ�
	this->strAddress = baseAddress * 4;
	for(int i = 0 ; i < this->stringNum ; i++)
	{
		std::string *str = this->stringTab[i];
		this->stringAddress[i] = this->strAddress; 
		for(int j = 0 ; j < str->length() ; j++)
		{
			char c = (*str)[j];
			this->generateOrder(new std::string(LI), new std::string(T9), c);
			this->generateOrder(new std::string(SB), new std::string(T9), this->strAddress, new std::string(R0));
			this->strAddress ++;
		}
		this->generateOrder(new std::string(SB), new std::string(R0), this->strAddress, new std::string(R0));
		this->strAddress ++;
	}
	//�����strAddress����4�ı�������Ҫ����ȡ��
	this->strAddress = this->strAddress % 4 == 0 ? this->strAddress : (this->strAddress / 4 + 1) * 4;
	//��ǰmipsAddress ���ǵ�ǰ�ַ�����ú�ĵ�ַ
	this->mipsAddress = this->strAddress;
}*/

void Compiler::generateOrder(std::string *order, std::string *rs, int num)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << num << std::endl;
	//std::cout << ss.str();
	this->objectFile << ss.str();
}

void Compiler::generateOrder(std::string *order, std::string *rs, int num, std::string *rt)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << num << "(" << *rt << ")" << std::endl;
	//std::cout << ss.str();
	this->objectFile << ss.str();
}

void Compiler::generateOrder(std::string *order, std::string *rd, std::string *rt, int imme)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rd << "\t,\t" << *rt << "\t,\t" << imme << std::endl;
	//std::cout << ss.str();
	this->objectFile << ss.str();
}

void Compiler::generateOrder(std::string *order, std::string *rd, std::string *rs, std::string *rt)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rd << "\t,\t" << *rs << "\t,\t" << *rt << std::endl;
	//std::cout << ss.str();
	this->objectFile << ss.str();
}

void Compiler:: generateOrder(std::string *order, std::string *rs, std::string *label)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *rs << "\t,\t" << *label << std::endl;
	//std::cout << ss.str();
	this->objectFile << ss.str();
}

void Compiler::generateOrder(std::string *order, std::string *target)
{
	std::stringstream ss = std::stringstream();
	ss << "\t" << *order << "\t" << *target << std::endl;
	//std::cout << ss.str();
	this->objectFile << ss.str();
}

void Compiler::generateOrder(std::string *order)
{
	//std::cout << "\t" << *order << std::endl;;
	this->objectFile << "\t" << *order << std::endl;
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
				this->generateOrder(new std::string(LI), new std::string(T9), sym->feature);
				//������Ҫ����ڵ�һ����������ʼ��ַƫ��
				this->generateOrder(new std::string(SW), new std::string(T9), sym->address * 4 + this->strAddress, new std::string(R0));
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
				this->generateOrder(new std::string(LI), new std::string(T9), sym->feature);
				this->generateOrder(new std::string(SW), new std::string(T9), initaddress - sym->address * 4, new std::string(SP));
			}
		}
		
	}
}

void Compiler::genMipsLabel(std::string *label)
{
	std::string *newlab = new std::string();
	this->str2Lower(label, newlab);
	//std::cout << *newlab << ":" << std::endl;
	this->objectFile << *newlab << ":" << std::endl;
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
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), paranum * 4);

	/*//�Ĵ���ѹջ

	for(int i = 0 ; i < maxTempReg ; i ++)
	{
		std::stringstream ss = std::stringstream();
		ss << "$t" << i;
		this->generateOrder(new std::string(SW), &(ss.str()), - currentaddress * 4, new std::string(SP));
		currentaddress += 1;
	}
	for(int i = 0 ; i < maxSymReg ; i ++)
	{
		std::stringstream ss = std::stringstream();
		ss << "$s" << i;
		this->generateOrder(new std::string(SW), &(ss.str()), -currentaddress * 4 , new std::string(SP));
		currentaddress += 1;
	}*/

	//�ȱ���ָ֡��
	this->generateOrder(new std::string(SW), new std::string(FP), - currentaddress * 4, new std::string(SP));
	//���淵�ص�ַ
	currentaddress += 1;
	this->generateOrder(new std::string(SW), new std::string(RA), - currentaddress * 4, new std::string(SP));
	currentaddress += 1;
	//���泣��
	this->initConstAndVar(sym, 0);
	//��ǰָ֡�����֮ǰջָ��
	this->generateOrder(new std::string(ADD), new std::string(FP), new std::string(SP), new std::string(R0));
	//��ǰջָ���޸�
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP) , - currentaddress * 4);

}

void Compiler::handleRet(std::string *name)
{
	//������������ʱ��Ҫ��
	symbol *sym = 0;
	this->find(name, &sym, false);
	//����з���ֵ�Ѿ��ڸ�ֵ�п��ǹ��ˣ� �����ֻ��������ջ��ά��
	//���·��ص�ַ
	int currentaddress = 1;
	this->generateOrder(new std::string(LW), new std::string(RA), currentaddress * 4, new std::string(SP));
	//���µ�ǰָ֡��
	currentaddress += 1;
	this->generateOrder(new std::string(LW), new std::string(FP), currentaddress * 4, new std::string(SP));
	currentaddress += 1;

	/*//�Ĵ���ʹ��������Իָ���
	this->stackPop();
	//����ÿһ���Ĵ���
	for(int i = maxSymReg - 1 ; i >= 0 ; i--)
	{
		std::stringstream ss = std::stringstream();
		ss << "$s" << i;
		this->generateOrder(new std::string(LW), &(ss.str()), currentaddress * 4, new std::string(SP));
		currentaddress += 1;
	}
	for(int i = maxTempReg - 1 ; i >= 0 ; i--)
	{
		std::stringstream ss = std::stringstream();
		ss << "$t" << i;
		this->generateOrder(new std::string(LW), &(ss.str()), currentaddress * 4, new std::string(SP));
		currentaddress += 1;
	}*/

	//����ջָ��
	currentaddress += (this->funcMaxAddress[sym->ref] - 1);
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), currentaddress * 4);
	//��ת��ȥ
	this->generateOrder(new std::string(JR), new std::string(RA));
	this->generateOrder(new std::string(NOP));
}

//offset��������ַ�������ƫ�Ƶ�ַ  �����������fp�ļ��ٵ�ַ  ע�������ǰ��ּǵ�
//������Ϊ����ֲ�������ȫ�ֱ�����������ô���Ǿֲ�����
void Compiler::findAddress(std::string *name, int *offset, bool *global)
{
	symbol **symtab = this->funcSymTab[this->currentRef];
	int length = this->funcSymNum[this->currentRef];
	for(int i = 0 ; i < length ; i++)
	{
		symbol *sym = symtab[i];
		//bug������һ��ʼΪʲôû����isIdEqual()?
		if(this->isIdEqual(*name, *(sym->name)))
		{
			*offset = sym->address;
			*global = false;
			return ;
		}
	}
	for(int i = 0 ; i < this->top ; i++)
	{
		symbol *sym = this->symTab[i];
		if(this->isIdEqual(*name, *(sym->name)))
		{
			*offset = sym->address;
			*global = true;
			return ;
		}
	}

}


//������Ԫʽ������ -> �Ĵ���
void Compiler::loadWord(std::string *rs, std::string *reg)
{
	//ע������Ҳ���ܷ��� �Ը��ſ�ʼ������
	if((*rs)[0] >= '0' && (*rs)[0] <= '9' || (*rs)[0] == '-')
	{
		this->generateOrder(new std::string(LI), reg, atoi(rs->c_str()));
	}
	else if((*rs)[0] == '$')
	{
		//����offset���������ȫ�ֱ�������ƫ��
		int offset = atoi(rs->substr(2).c_str());
		//��ʱ����Ҳ����ȫ�������������ĵ�ַ��Ҫƫ�� �ַ��� ȫ�ֱ����ͳ����ĵ�ַ
		this->generateOrder(new std::string(LW), reg, this->strAddress + (this->address + offset) * 4, new std::string(R0));
	}
	else if((*rs)[0] == '#')
	{
		this->generateOrder(new std::string(ADD), reg, new std::string(V0), new std::string(R0));
	}
	else{
		bool global = false;
		int offset = 0;
		this->findAddress(rs, &offset, &global);
		if(global)
		{
			//ȫ�ֱ�������Ҫ������ַ�����ƫ�Ƶ�
			this->generateOrder(new std::string(LW), reg, this->strAddress + 4 * offset, new std::string(R0));		
		}
		else{
			this->generateOrder(new std::string(LW), reg, - offset * 4, new std::string(FP));
		}
	}
}
//������ʱ�Ĵ��� -> ��Ԫʽ��������Ӧ�Ĵ洢�ռ��ϣ�Ĭ�ϼĴ���Ϊt0
void Compiler::storeWord(std::string *rd)
{
	int offset = 0;
	switch((*rd)[0])
	{
	case '$':
		offset = atoi(rd->substr(2).c_str());
		this->generateOrder(new std::string(SW), new std::string(T0), this->strAddress + (offset + this->address) * 4, new std::string(R0));
		break;
	case '#':
		this->generateOrder(new std::string(ADD), new std::string(V0), new std::string(T0), new std::string(R0));
		break;
	default:
		bool global = false;
		offset = 0;
		this->findAddress(rd, &offset, &global);
		if(global)
		{
			this->generateOrder(new std::string(SW), new std::string(T0), this->strAddress + offset * 4, new std::string(R0));

		}
		else{
			this->generateOrder(new std::string(SW), new std::string(T0), - offset * 4, new std::string(FP));
		}

	}
}

void Compiler::allocReg(std::string *operand, std::string *reg)
{
	//����operand�����ʷ���Ĵ��������������������v0����ʶ����������ʱ����
	if(this->isOperandRet(operand))
	{
		*reg = std::string(V0);
	}
	else if(this->isOperandTemp(operand))
	{
		//��һ����ʱ����
		int temp = atoi(operand->substr(2).c_str());
		//��ɨ��һ�鿴�ǲ����Ѿ����������
		for(int i = 0 ; i < maxTempReg ; i++)
		{
			if(this->tempReg[i] == temp)
			{
				std::stringstream ss = std::stringstream();
				ss << "$t" << i;
				*reg = ss.str();
				return ;
			}
		}
		//��ɨ��һ�飬����û�п����õļĴ���
		for(int i = 0 ; i < maxTempReg ; i ++)
		{
			if(this->tempReg[i] == -1)
			{
				std::stringstream ss = std::stringstream();
				ss << "$t" << i ;
				*reg = ss.str();
				//Ȼ����Ҫ����Ӧ��ַ�ϵ�ֵȡ�÷�������Ĵ�����
				//����offset���������ȫ�ֱ�������ƫ��
				int offset = temp;
				//��ʱ����Ҳ����ȫ�������������ĵ�ַ��Ҫƫ�� �ַ��� ȫ�ֱ����ͳ����ĵ�ַ
				this->generateOrder(new std::string(LW), reg, this->strAddress + (this->address + offset) * 4, new std::string(R0));
				this->tempReg[i] = temp;
				return ;
			}
		}
		//Ȼ��͵ð�ԭ����ʹ�õĸ���ã�Ȼ����µļӽ����������������ʱ��δ��ʹ�õ�ԭ�򡣡�
		//���ȴ��Ҫ��ȡ����
		int oldtemp = this->tempReg[this->tempRegIndex];
		int offset = oldtemp;
		std::stringstream regss = std::stringstream();
		regss << "$t" << this->tempRegIndex;
		this->generateOrder(new std::string(SW), &(regss.str()), this->strAddress + (this->address + offset) * 4, new std::string(R0));
		//Ȼ��ȡ��Ҫ�õ�
		offset = temp;
		this->tempReg[this->tempRegIndex] = temp;
		this->generateOrder(new std::string(LW), &(regss.str()), this->strAddress + (this->address + offset) * 4, new std::string(R0));
		*reg = regss.str();
		this->tempRegIndex = (this->tempRegIndex + 1) % maxTempReg;


	}
	else{
		//˵����һ����ʶ����


		bool global = false;
		int offset = 0;
		this->findAddress(operand, &offset, &global);
		//��ɨ��һ�鿴�Ƿ񱻷����
		for(int i = 0 ; i < maxSymReg ; i++)
		{
			//bug������һ��ʼû���ж�symReg�����Ԫ���ǲ�����Ч
			if(this->symReg[i] && this->isIdEqual(*(this->symReg[i]), *operand))
			{
				std::stringstream ss = std::stringstream();
				ss << "$s" << i;
				*reg = ss.str();
				return ;
			}
		}
		for(int i = 0 ; i < maxSymReg ; i++)
		{
			if(!this->symReg[i])
			{
				std::stringstream ss = std::stringstream();
				ss << "$s" << i;
				*reg = ss.str();
				this->symReg[i] = operand;
				//bug: ȫ�ֱ���������Ĵ�����ֱ��lw sw���������ﴦ�������ﴦ��Ķ��Ǿֲ�����
				this->generateOrder(new std::string(LW), &(ss.str()), -offset * 4, new std::string(FP));
				return ;
			}
		}
		//����������Ҫ�ȴ��ԭ���ģ���ȡ�����µ�
		std::string *oldname = this->symReg[this->symRegIndex];
		this->findAddress(oldname, &offset, &global);
		std::stringstream ss = std::stringstream();
		ss << "$s" << this->symRegIndex;
		this->generateOrder(new std::string(SW), &(ss.str()), -offset * 4, new std::string(FP));

		this->findAddress(operand, &offset, &global);
		this->symReg[this->symRegIndex] = operand;
		this->generateOrder(new std::string(LW), &(ss.str()), -offset * 4, new std::string(FP));
		*reg = ss.str();
		this->tempRegIndex = (this->tempRegIndex + 1) % maxTempReg;

	}

}

//��δ�޸���
/*void Compiler::handleAssign(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *rt = code->rstname;

	if(this->isOperandNumber(rs))
	{
		//�����ĸ�ֵ������������֣���ʶ������ʱ������v0
		std::string *reg = new std::string();
		//����allocReg������Ҫ��v0Ҳ���ǽ�ȥ
		if(this->isOperandId(rt))
		{
			bool global = false;
			int offset = 0;
			this->findAddress(rt, &offset, &global);
			if(global)
			{
				//�����һ��ȫ�ֱ�ʶ������ôֱ��sw����
				this->generateOrder(new std::string(LI), new std::string(T8), atoi(rs->c_str()));
				this->generateOrder(new std::string(SW), new std::string(T8), this->strAddress + offset * 4, new std::string(R0));
			}
		}
		else{
			//��ȫ�ֵı�ʶ��/v0/��ʱ����
			this->allocReg(rt, reg);
			//����LI  ��ʾ������ֵ,ע������LI�Ĳ���������
			this->generateOrder(new std::string(LI), reg, atoi(rs->c_str()));
		}
	}
	else 
	{
		std::string *rsreg = new std::string();
		std::string *rtreg = new std::string();
		//�Ҳ��������˿������������������Ǳ�ʶ��/��ʱ����/v0 
		if(this->isOperandId(rs))
		{
			bool global = false;
			int offset = 0;
			this->findAddress(rs, &offset, &global);
			if(global)
			{
				//�����һ��ȫ�ֱ�ʶ������ôload��t8
				this->generateOrder(new std::string(LW), new std::string(T8), this->strAddress + offset * 4, new std::string(R0));
				*rsreg = std::string(T8);

			}
		}

		this->allocReg(rs, rsreg);
		this->allocReg(rt, rtreg);
		//����move ָ�����ֱ����add zero
		this->generateOrder(new std::string(ADD), rtreg, rsreg, new std::string(R0));
	}
}*/

/*void Compiler::handleAssign(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *rt = code->rstname;

	this->loadWord(rs, new std::string(T0));
	//Ȼ�����洢rt������һ����
	this->storeWord(rt);
}*/


/*void Compiler::handleBranch(midcode *code)
{
	std::string *op1reg = new std::string();
	if(this->isOperandNumber(code->op1name))
	{
		//���ʽ���ص���һ�����ֲ���������ô��ʱʹ��LI
		this->generateOrder(new std::string(LI), new std::string(T9), atoi(code->op1name->c_str()));
		//��һ������������$t9��
		*op1reg = std::string(T9);
	}
	else{
		//ֻ�п�������ʱ������
		this->allocReg(code->op1name, op1reg);
	}
	//�������op1reg�����˵�һ��������
	std::string *op2reg = new std::string();
	if(this->isOperandNumber(code->op2name))
	{
		//���������2��һ�����֣���ô��ʱֱ����addi���ɣ��������$t9��
		//ע��������Ҫ�Ȱѵڶ�������������ֵȡ��
		int value = atoi(code->op2name->c_str());
		value = -1 * value;
		this->generateOrder(new std::string(ADDI), new std::string(T9), op1reg, value);
	}
	else{
		//������2����һ�����֣���ô����һ����ʱ�����ˣ���ʱ��Ҫ������ļĴ���
		this->allocReg(code->op2name, op2reg);
		this->generateOrder(new std::string(SUB), new std::string(T9), op1reg, op2reg);
	}
	
	switch(code->op)
	{
	case EQUOP:
		this->generateOrder(new std::string(BEQ), new std::string(T9), new std::string(R0), code->rstname);
		break;
	case NEQUOP:
		this->generateOrder(new std::string(BNE), new std::string(T9), new std::string(R0), code->rstname);
		break;
	case MOREEQUOP:
		this->generateOrder(new std::string(BGEZ), new std::string(T9), code->rstname);
		break;
	case MOREOP:
		this->generateOrder(new std::string(BGTZ), new std::string(T9), code->rstname);
		break;
	case LESSEQUOP:
		this->generateOrder(new std::string(BLEZ), new std::string(T9), code->rstname);
		break;
	case LESSOP:
		this->generateOrder(new std::string(BLTZ), new std::string(T9), code->rstname);
		break;
	}
	//һ��ʼ���˼�nop..
	this->generateOrder(new std::string(NOP));
}*/

void Compiler::handleBranch(midcode *code)
{
	this->loadWord(code->op1name, new std::string(T0));
	this->loadWord(code->op2name, new std::string(T1));
	this->generateOrder(new std::string(SUB), new std::string(T0), new std::string(T0), new std::string(T1));
	switch(code->op)
	{
	case EQUOP:
		this->generateOrder(new std::string(BEQ), new std::string(T0), new std::string(R0), code->rstname);
		break;
	case NEQUOP:
		this->generateOrder(new std::string(BNE), new std::string(T0), new std::string(R0), code->rstname);
		break;
	case MOREEQUOP:
		this->generateOrder(new std::string(BGEZ), new std::string(T0), code->rstname);
		break;
	case MOREOP:
		this->generateOrder(new std::string(BGTZ), new std::string(T0), code->rstname);
		break;
	case LESSEQUOP:
		this->generateOrder(new std::string(BLEZ), new std::string(T0), code->rstname);
		break;
	case LESSOP:
		this->generateOrder(new std::string(BLTZ), new std::string(T0), code->rstname);
		break;
	}
	//һ��ʼ���˼�nop..
	this->generateOrder(new std::string(NOP));
}


void Compiler::handleGoto(std::string *label)
{
	std::string *newlab = new std::string();
	this->str2Lower(label, newlab);
	this->generateOrder(new std::string(J), newlab);
	this->generateOrder(new std::string(NOP));
}

/*void Compiler::handleRealPara(std::string *para)
{
	//paraҲ�Ǵӱ��ʽ�õ���ֵ����ʱ���Ƿ�Ϊ���ֺ���ʱ����
	//reg�����������������ʹ�õļĴ���
	std::string *reg = new std::string();
	if(this->isOperandNumber(para))
	{
		//�Ǹ����֣�����ʹ����ʱ�Ĵ���t9
		this->generateOrder(new std::string(LI), new std::string(T9), atoi(para->c_str()));
		*reg = std::string(T9);
	}
	else{
		//��Ϊ�����б�����<���ʽ>�õ��ģ���������ֻ�п�������ʱ�������õ�����Ӧ�ļĴ���
		this->allocReg(para, reg);
	}

	this->generateOrder(new std::string(SW), reg, 0, new std::string(SP));
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), -4);
}*/

void Compiler::handleRealPara(std::string *para)
{
	//paraҲ�Ǵӱ��ʽ�õ���ֵ����ʱ���Ƿ�Ϊ���ֺ���ʱ����
	this->loadWord(para, new std::string(T0));
	this->generateOrder(new std::string(SW), new std::string(T0), 0, new std::string(SP));
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), -4);
}


/*void Compiler::handleRarray(midcode *code)
{
	bool global;
	int offset;
	this->findAddress(code->op1name, &offset, &global);
	std::string *indexreg = new std::string();
	if(this->isOperandNumber(code->op2name))
	{
		this->generateOrder(new std::string(LI), new std::string(T9), atoi(code->op2name->c_str()));
		*indexreg = std::string(T9);
	}
	else{
		this->allocReg(code->op2name, indexreg);
	}


	this->generateOrder(new std::string(ADDI), new std::string(T9), indexreg, offset);
	this->generateOrder(new std::string(SLL), new std::string(T9), new std::string(T9), 2);
	if(global)
	{
		//�����ƫ�ƺ�����ڵ�һ������Ѱַ
		this->generateOrder(new std::string(LW), new std::string(T9), this->strAddress, new std::string(T9));
	}
	else{
		this->generateOrder(new std::string(SUB), new std::string(T9), new std::string(FP), new std::string(T9));
		this->generateOrder(new std::string(LW), new std::string(T9), 0, new std::string(T9));
	}
	std::string *rstreg = new std::string();
	this->allocReg(code->rstname, rstreg);
	this->generateOrder(new std::string(ADD), rstreg, new std::string(T9), new std::string(R0));
}*/

void Compiler::handleRarray(midcode *code)
{
	bool global;
	int offset;
	this->findAddress(code->op1name, &offset, &global);
	this->loadWord(code->op2name, new std::string(T0));
	this->generateOrder(new std::string(ADDI), new std::string(T0), new std::string(T0), offset);
	this->generateOrder(new std::string(LI), new std::string(T1), 4);
	this->generateOrder(new std::string(MUL), new std::string(T0), new std::string(T0),new std::string(T1));
	if(global)
	{
		//�����ƫ�ƺ�����ڵ�һ������Ѱַ
		this->generateOrder(new std::string(LW), new std::string(T0), this->strAddress, new std::string(T0));
	}
	else{
		this->generateOrder(new std::string(SUB), new std::string(T0), new std::string(FP), new std::string(T0));
		this->generateOrder(new std::string(LW), new std::string(T0), 0, new std::string(T0));
	}
	this->storeWord(code->rstname);
}

void Compiler::handleCall(std::string *name)
{
	std::string *newlab = new std::string();
	this->str2Lower(name, newlab);
	this->generateOrder(new std::string(JAL), newlab);
	this->generateOrder(new std::string(NOP));;
}

/*void Compiler::handleCompute(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *rt = code->op2name;
	std::string *rd = code->rstname;

	std::string *rsreg = new std::string();
	std::string *rtreg = new std::string();
	std::string *rdreg = new std::string();
	
	if(this->isOperandNumber(rs))
	{
		//��һ�������֣���ô�ڶ����϶���������
		this->allocReg(rt, rtreg);
		//�Ȱ����ַ���$t9
		this->generateOrder(new std::string(LI), new std::string(T9), atoi(code->op1name->c_str()));
		*rsreg = std::string(T9);
	}
	else{
		//��һ���������֣���ô�ڶ������������֣�Ҳ��������ʱ����
		if(this->isOperandNumber(rt))
		{
			this->allocReg(rs, rsreg);
			this->generateOrder(new std::string(LI), new std::string(T9), atoi(code->op2name->c_str()));
			*rtreg = std::string(T9);
		}
		else{
			//��һ���ڶ�������������
			this->allocReg(rs, rsreg);
			this->allocReg(rt, rtreg);
		}
	}

	this->allocReg(rd, rdreg);
	switch(code->op)
	{
		//һ��ʼ�����������˳����ˣ�Ӧ����t0��t1�ģ����ڼӷ����˷����������ԣ����Ǽ���˳��ߵ��������
	case ADDOP:
		this->generateOrder(new std::string(ADD), rdreg, rsreg, rtreg);
		break;
	case SUBOP:
		this->generateOrder(new std::string(SUB), rdreg, rsreg, rtreg);
		break;
	case MULOP:
		this->generateOrder(new std::string(MUL), rdreg, rsreg, rtreg);
		break;
	case DIVOP:
		this->generateOrder(new std::string(DIVIDE), rsreg, rtreg);
		this->generateOrder(new std::string(MFLO), rdreg);
		break;
	}
}*/

void Compiler::handleCompute(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *rt = code->op2name;
	std::string *rd = code->rstname;

	this->loadWord(rs, new std::string(T0));
	this->loadWord(rt, new std::string(T1));
	switch(code->op)
	{
		//һ��ʼ�����������˳����ˣ�Ӧ����t0��t1�ģ����ڼӷ����˷����������ԣ����Ǽ���˳��ߵ��������
	case ADDOP:
		this->generateOrder(new std::string(ADD), new std::string(T0), new std::string(T0), new std::string(T1));
		break;
	case SUBOP:
		this->generateOrder(new std::string(SUB), new std::string(T0), new std::string(T0), new std::string(T1));
		break;
	case MULOP:
		this->generateOrder(new std::string(MUL), new std::string(T0), new std::string(T0), new std::string(T1));
		break;
	case DIVOP:
		this->generateOrder(new std::string(DIVIDE), new std::string(T0), new std::string(T1));
		this->generateOrder(new std::string(MFLO), new std::string(T0));
		break;
	}
	this->storeWord(rd);
}

/*void Compiler:: handleLarray(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *index = code->op2name;
	std::string *name = code->rstname;

	std::string *rsreg = new std::string();
	std::string *indexreg = new std::string();

	bool global = false;
	int offset = 0;
	this->findAddress(name, &offset, &global);
	
	if(this->isOperandNumber(index))
	{
		this->generateOrder(new std::string(LI), new std::string(T9), atoi(index->c_str()));
		*indexreg = std::string(T9);
	}
	else{
		this->allocReg(index, indexreg);
	}
	//ͬ���� $t9������Ϊ���������ַ��������ʱ�Ĵ���
	this->generateOrder(new std::string(ADDI), new std::string(T9), indexreg, offset);
	this->generateOrder(new std::string(SLL), new std::string(T9), new std::string(T9), 2);
	
	this->allocReg(rs, rsreg);
	if(global)
	{
		this->generateOrder(new std::string(SW), rsreg, this->strAddress, new std::string(T9));
	}
	else{
		this->generateOrder(new std::string(SUB), new std::string(T9), new std::string(FP), new std::string(T9));
		this->generateOrder(new std::string(SW), rsreg, 0, new std::string(T9));
	}
}*/

void Compiler:: handleLarray(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *index = code->op2name;
	std::string *name = code->rstname;
	bool global = false;
	int offset = 0;
	this->findAddress(name, &offset, &global);
	this->loadWord(index, new std::string(T1));
	this->generateOrder(new std::string(ADDI), new std::string(T1), new std::string(T1), offset);
	this->generateOrder(new std::string(LI), new std::string(T0), 4);
	this->generateOrder(new std::string(MUL), new std::string(T0), new std::string(T0),new std::string(T1));
	this->loadWord(rs, new std::string(T1));
	if(global)
	{
		this->generateOrder(new std::string(SW), new std::string(T1), this->strAddress, new std::string(T0));
	}
	else{
		this->generateOrder(new std::string(SUB), new std::string(T0), new std::string(FP), new std::string(T0));
		this->generateOrder(new std::string(SW), new std::string(T1), 0, new std::string(T0));
	}
}

/*void Compiler:: handleScanf(midcode *code)
{
	if((*code->op1name)[0] == 'i')
	{
		//����һ������
		this->generateOrder(new std::string(LI), new std::string(V0), 5);
	}
	else {
		//����һ���ַ�
		this->generateOrder(new std::string(LI), new std::string(V0), 12);
	}
	this->generateOrder(new std::string(SYSCALL));
	//���������ֻ����һ����ʶ��
	std::string *rstreg = new std::string();
	this->allocReg(code->rstname, rstreg);
	//�Ѷ����Ľ�����������Ĵ���
	this->generateOrder(new std::string(ADD), rstreg, new std::string(V0), new std::string(R0));
}*/

void Compiler:: handleScanf(midcode *code)
{
	if((*code->op1name)[0] == 'i')
	{
		//����һ������
		this->generateOrder(new std::string(LI), new std::string(V0), 5);
	}
	else {
		//����һ���ַ�
		this->generateOrder(new std::string(LI), new std::string(V0), 12);
	}
	this->generateOrder(new std::string(SYSCALL));
	//���������ֻ����һ����ʶ��
	this->generateOrder(new std::string(ADD), new std::string(T0), new std::string(V0), new std::string(R0));
	this->storeWord(code->rstname);
}

/*void Compiler::handlePrintf(midcode *code)
{
	if(code->op1name->length() == 0)
	{
		//˵�����ַ���
		this->generateOrder(new std::string(LI), new std::string(V0), 4);
		std::stringstream ss = std::stringstream();
		ss << "$Message" << *(code->rstname);
		this->generateOrder(new std::string(LA), new std::string(A0), &(ss.str()));
		this->generateOrder(new std::string(SYSCALL));
	}
	else{
		//˵���Ǳ��ʽ,����op1name�ĵ�һ���ַ���ʲô��ĸ���ж����������������ĸ
		this->generateOrder(new std::string(LI), new std::string(V0),(*code->op1name)[0] == 'i' ? 1 : 11);
			//������Ҫ��Ҫ���������/�ַ�����a0�Ĵ���
		if(this->isOperandNumber(code->rstname))
		{
				//��������֣���ôֱ�Ӹ�
			this->generateOrder(new std::string(LI), new std::string(A0), atoi(code->rstname->c_str()));
		}
		else{
				//˵������ʱ��������ô�Ȼ�������ڵļĴ���
			std::string *reg = new std::string();
			this->allocReg(code->rstname, reg);
			this->generateOrder(new std::string(ADD), new std::string(A0), reg, new std::string(R0));
		}
		this->generateOrder(new std::string(SYSCALL));
	}
}*/

void Compiler::handlePrintf(midcode *code)
{
	if(code->op1name->length() == 0)
	{
		//˵�����ַ���
		this->generateOrder(new std::string(LI), new std::string(V0), 4);
		std::stringstream ss = std::stringstream();
		ss << "$Message" << *(code->rstname);
		this->generateOrder(new std::string(LA), new std::string(A0), &(ss.str()));
		this->generateOrder(new std::string(SYSCALL));
	}
	else{
		//˵���Ǳ��ʽ,����op1name�ĵ�һ���ַ���ʲô��ĸ���ж����������������ĸ
		this->generateOrder(new std::string(LI), new std::string(V0),(*code->op1name)[0] == 'i' ? 1 : 11);
		//������Ҫ��Ҫ���������/�ַ�����a0�Ĵ���
		this->loadWord(code->rstname, new std::string(A0));
		this->generateOrder(new std::string(SYSCALL));
	}
}

void Compiler::handleExit()
{
	this->generateOrder(new std::string(LI), new std::string(V0), 10);
	this->generateOrder(new std::string(SYSCALL));
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
	this->generateOrder(new std::string(ADD), new std::string(FP), new std::string(SP), new std::string(R0));
	this->handleGoto(new std::string("main"));
	for(int i = 0 ; i < this->optimizeMidIndex ; i++)
	{
		midcode *code = this->optimizeCodes[i];
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
		case MULOP:
		case ADDOP:
		case SUBOP:
		case DIVOP:
			this->handleCompute(code);
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