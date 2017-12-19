#include "Compiler.h"

const int baseAddress = 0x10000000 / 4;

//mips保留字
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

//t9统一作为临时寄存器

const char *T9 = "$t9";

//t8专门作为全局变量的存取运算寄存器

const char *T8 = "$t8";

const char *T1 = "$t1";

const char *V0 = "$v0";

const char *A0 = "$a0";

const char *R0 = "$zero";


//一些限制

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
	//寄存器栈恢复
	//恢复之前同样需要做的就是，把之前全局变量的改变情况写回内存里，并写回原来会用到它的寄存器里

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
				//是一个全局变量，那么此时需要把它写回内存,并把它写回到最新寄存器里
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
	this->objectFile << "#初始化字符串\n";
	this->generateOrder(new std::string(".data"));

	for(int i = 0 ; i < this->stringNum ; i++)
	{
		std::string *str = this->stringTab[i];
		std::stringstream ss = std::stringstream();
		ss << "$Message" << i << ":" << ".asciiz" << "\"" << *str << "\"";
		this->generateOrder(&(ss.str()));
	}
	this->strAddress = baseAddress * 4;
	//统一提供400的空间，即可以存400个字符的字符串
	this->strAddress = this->strAddress + 400;
	//当前mipsAddress 就是当前字符串存好后的地址
	this->mipsAddress = this->strAddress;
}

/*void Compiler::initAscii()
{
	this->objectFile << "#初始化字符串\n";
	//strAddress 是当前的字符串地址  按字节记的
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
	//最后怕strAddress不是4的倍数，需要向上取整
	this->strAddress = this->strAddress % 4 == 0 ? this->strAddress : (this->strAddress / 4 + 1) * 4;
	//当前mipsAddress 就是当前字符串存好后的地址
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
	//表示是全局的常量
	if(sym == 0)
	{
		for(int i = 0 ; i < this->top ; i++)
		{
			symbol *sym = this->symTab[i];
			switch(sym->symbolType)
			{
			case CONSTSYM:
				this->generateOrder(new std::string(LI), new std::string(T9), sym->feature);
				//这里需要相对于第一个常量的起始地址偏移
				this->generateOrder(new std::string(SW), new std::string(T9), sym->address * 4 + this->strAddress, new std::string(R0));
				break;
			}
		}
		//std::cout << this->address;
	}
	//表示是局部的常量和变量,此时传入的初始地址为0，需要使用当前的栈指针来寻址
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
	//进入时 sp已经存好了实参，所以sp的地址已经改变，为了方便处理，这里把sp的指针变回放入形参之前的位置
	symbol *sym = 0;
	this->find(name, &sym, false);
	//生成label,就是函数名
	this->genMipsLabel(sym->name);
	//空间分配 参数 常量 变量 t寄存器和s寄存器 上一次的帧指针 上一次的返回地址 当前帧指针等于之前的栈指针，  当前栈指针修改以分配空间
	//currentaddress 存储需要分配的空间大小
	int currentaddress = this->funcMaxAddress[sym->ref];
	int paranum = sym->feature;
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), paranum * 4);

	/*//寄存器压栈

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

	//先保存帧指针
	this->generateOrder(new std::string(SW), new std::string(FP), - currentaddress * 4, new std::string(SP));
	//保存返回地址
	currentaddress += 1;
	this->generateOrder(new std::string(SW), new std::string(RA), - currentaddress * 4, new std::string(SP));
	currentaddress += 1;
	//保存常量
	this->initConstAndVar(sym, 0);
	//当前帧指针等于之前栈指针
	this->generateOrder(new std::string(ADD), new std::string(FP), new std::string(SP), new std::string(R0));
	//当前栈指针修改
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP) , - currentaddress * 4);

}

void Compiler::handleRet(std::string *name)
{
	//函数结束运行时需要做
	symbol *sym = 0;
	this->find(name, &sym, false);
	//如果有返回值已经在赋值中考虑过了， 这里就只考虑运行栈的维护
	//更新返回地址
	int currentaddress = 1;
	this->generateOrder(new std::string(LW), new std::string(RA), currentaddress * 4, new std::string(SP));
	//更新当前帧指针
	currentaddress += 1;
	this->generateOrder(new std::string(LW), new std::string(FP), currentaddress * 4, new std::string(SP));
	currentaddress += 1;

	/*//寄存器使用情况可以恢复了
	this->stackPop();
	//更新每一个寄存器
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

	//更新栈指针
	currentaddress += (this->funcMaxAddress[sym->ref] - 1);
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), currentaddress * 4);
	//跳转回去
	this->generateOrder(new std::string(JR), new std::string(RA));
	this->generateOrder(new std::string(NOP));
}

//offset是相对于字符串区的偏移地址  或者是相对于fp的减少地址  注意这里是按字记的
//而且因为如果局部变量和全局变量重名，那么就是局部变量
void Compiler::findAddress(std::string *name, int *offset, bool *global)
{
	symbol **symtab = this->funcSymTab[this->currentRef];
	int length = this->funcSymNum[this->currentRef];
	for(int i = 0 ; i < length ; i++)
	{
		symbol *sym = symtab[i];
		//bug：这里一开始为什么没有用isIdEqual()?
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


//控制四元式操作数 -> 寄存器
void Compiler::loadWord(std::string *rs, std::string *reg)
{
	//注意整数也可能返回 以负号开始的数字
	if((*rs)[0] >= '0' && (*rs)[0] <= '9' || (*rs)[0] == '-')
	{
		this->generateOrder(new std::string(LI), reg, atoi(rs->c_str()));
	}
	else if((*rs)[0] == '$')
	{
		//这里offset就是相对于全局变量区的偏移
		int offset = atoi(rs->substr(2).c_str());
		//临时变量也存在全局区，所以它的地址需要偏移 字符串 全局变量和常量的地址
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
			//全局变量是需要相对于字符串区偏移的
			this->generateOrder(new std::string(LW), reg, this->strAddress + 4 * offset, new std::string(R0));		
		}
		else{
			this->generateOrder(new std::string(LW), reg, - offset * 4, new std::string(FP));
		}
	}
}
//控制临时寄存器 -> 四元式操作数对应的存储空间上，默认寄存器为t0
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
	//根据operand的性质分配寄存器，可能有三种情况：v0，标识符或者是临时变量
	if(this->isOperandRet(operand))
	{
		*reg = std::string(V0);
	}
	else if(this->isOperandTemp(operand))
	{
		//是一个临时变量
		int temp = atoi(operand->substr(2).c_str());
		//先扫描一遍看是不是已经被分配好了
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
		//再扫描一遍，看有没有可以用的寄存器
		for(int i = 0 ; i < maxTempReg ; i ++)
		{
			if(this->tempReg[i] == -1)
			{
				std::stringstream ss = std::stringstream();
				ss << "$t" << i ;
				*reg = ss.str();
				//然后需要把相应地址上的值取好放在这个寄存器里
				//这里offset就是相对于全局变量区的偏移
				int offset = temp;
				//临时变量也存在全局区，所以它的地址需要偏移 字符串 全局变量和常量的地址
				this->generateOrder(new std::string(LW), reg, this->strAddress + (this->address + offset) * 4, new std::string(R0));
				this->tempReg[i] = temp;
				return ;
			}
		}
		//然后就得把原来被使用的给存好，然后把新的加进来，不如采用最近最长时间未被使用的原则。。
		//首先存好要被取代的
		int oldtemp = this->tempReg[this->tempRegIndex];
		int offset = oldtemp;
		std::stringstream regss = std::stringstream();
		regss << "$t" << this->tempRegIndex;
		this->generateOrder(new std::string(SW), &(regss.str()), this->strAddress + (this->address + offset) * 4, new std::string(R0));
		//然后取出要用的
		offset = temp;
		this->tempReg[this->tempRegIndex] = temp;
		this->generateOrder(new std::string(LW), &(regss.str()), this->strAddress + (this->address + offset) * 4, new std::string(R0));
		*reg = regss.str();
		this->tempRegIndex = (this->tempRegIndex + 1) % maxTempReg;


	}
	else{
		//说明是一个标识符了


		bool global = false;
		int offset = 0;
		this->findAddress(operand, &offset, &global);
		//先扫描一遍看是否被分配好
		for(int i = 0 ; i < maxSymReg ; i++)
		{
			//bug：这里一开始没有判断symReg的这个元素是不是有效
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
				//bug: 全局变量不分配寄存器，直接lw sw，不在这里处理，在这里处理的都是局部变量
				this->generateOrder(new std::string(LW), &(ss.str()), -offset * 4, new std::string(FP));
				return ;
			}
		}
		//接下来就需要先存好原来的，再取出最新的
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

//尚未修改完
/*void Compiler::handleAssign(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *rt = code->rstname;

	if(this->isOperandNumber(rs))
	{
		//整数的赋值对象可能有三种，标识符，临时变量和v0
		std::string *reg = new std::string();
		//所以allocReg这里需要把v0也考虑进去
		if(this->isOperandId(rt))
		{
			bool global = false;
			int offset = 0;
			this->findAddress(rt, &offset, &global);
			if(global)
			{
				//如果是一个全局标识符，那么直接sw就行
				this->generateOrder(new std::string(LI), new std::string(T8), atoi(rs->c_str()));
				this->generateOrder(new std::string(SW), new std::string(T8), this->strAddress + offset * 4, new std::string(R0));
			}
		}
		else{
			//非全局的标识符/v0/临时变量
			this->allocReg(rt, reg);
			//生成LI  表示整数赋值,注意这里LI的参数是数字
			this->generateOrder(new std::string(LI), reg, atoi(rs->c_str()));
		}
	}
	else 
	{
		std::string *rsreg = new std::string();
		std::string *rtreg = new std::string();
		//右操作数除了可能是整数，还可能是标识符/临时变量/v0 
		if(this->isOperandId(rs))
		{
			bool global = false;
			int offset = 0;
			this->findAddress(rs, &offset, &global);
			if(global)
			{
				//如果是一个全局标识符，那么load到t8
				this->generateOrder(new std::string(LW), new std::string(T8), this->strAddress + offset * 4, new std::string(R0));
				*rsreg = std::string(T8);

			}
		}

		this->allocReg(rs, rsreg);
		this->allocReg(rt, rtreg);
		//生成move 指令，这里直接用add zero
		this->generateOrder(new std::string(ADD), rtreg, rsreg, new std::string(R0));
	}
}*/

/*void Compiler::handleAssign(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *rt = code->rstname;

	this->loadWord(rs, new std::string(T0));
	//然后分配存储rt的是哪一个，
	this->storeWord(rt);
}*/


/*void Compiler::handleBranch(midcode *code)
{
	std::string *op1reg = new std::string();
	if(this->isOperandNumber(code->op1name))
	{
		//表达式返回的是一个数字操作数，那么此时使用LI
		this->generateOrder(new std::string(LI), new std::string(T9), atoi(code->op1name->c_str()));
		//第一个操作数就是$t9了
		*op1reg = std::string(T9);
	}
	else{
		//只有可能是临时变量了
		this->allocReg(code->op1name, op1reg);
	}
	//上面就让op1reg保存了第一个操作数
	std::string *op2reg = new std::string();
	if(this->isOperandNumber(code->op2name))
	{
		//如果操作数2是一个数字，那么此时直接用addi即可，结果放在$t9中
		//注意这里需要先把第二个操作数的数值取反
		int value = atoi(code->op2name->c_str());
		value = -1 * value;
		this->generateOrder(new std::string(ADDI), new std::string(T9), op1reg, value);
	}
	else{
		//操作数2不是一个数字，那么就是一个临时变量了，此时需要获得它的寄存器
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
	//一开始忘了加nop..
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
	//一开始忘了加nop..
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
	//para也是从表达式得到的值，此时还是分为数字和临时变量
	//reg保存这个参数最后的所使用的寄存器
	std::string *reg = new std::string();
	if(this->isOperandNumber(para))
	{
		//是个数字，这里使用临时寄存器t9
		this->generateOrder(new std::string(LI), new std::string(T9), atoi(para->c_str()));
		*reg = std::string(T9);
	}
	else{
		//因为参数列表还是由<表达式>得到的，所以这里只有可能是临时变量，得到它对应的寄存器
		this->allocReg(para, reg);
	}

	this->generateOrder(new std::string(SW), reg, 0, new std::string(SP));
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), -4);
}*/

void Compiler::handleRealPara(std::string *para)
{
	//para也是从表达式得到的值，此时还是分为数字和临时变量
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
		//计算好偏移后相对于第一个常量寻址
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
		//计算好偏移后相对于第一个常量寻址
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
		//第一个是数字，那么第二个肯定不是数字
		this->allocReg(rt, rtreg);
		//先把数字放在$t9
		this->generateOrder(new std::string(LI), new std::string(T9), atoi(code->op1name->c_str()));
		*rsreg = std::string(T9);
	}
	else{
		//第一个不是数字，那么第二个可能是数字，也可能是临时变量
		if(this->isOperandNumber(rt))
		{
			this->allocReg(rs, rsreg);
			this->generateOrder(new std::string(LI), new std::string(T9), atoi(code->op2name->c_str()));
			*rtreg = std::string(T9);
		}
		else{
			//第一个第二个都不是数字
			this->allocReg(rs, rsreg);
			this->allocReg(rt, rtreg);
		}
	}

	this->allocReg(rd, rdreg);
	switch(code->op)
	{
		//一开始这里操作数的顺序错了，应该先t0后t1的，对于加法，乘法，除法都对，就是减法顺序颠倒会出错。。
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
		//一开始这里操作数的顺序错了，应该先t0后t1的，对于加法，乘法，除法都对，就是减法顺序颠倒会出错。。
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
	//同样的 $t9这里作为数组变量地址索引的临时寄存器
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
		//读入一个整数
		this->generateOrder(new std::string(LI), new std::string(V0), 5);
	}
	else {
		//读入一个字符
		this->generateOrder(new std::string(LI), new std::string(V0), 12);
	}
	this->generateOrder(new std::string(SYSCALL));
	//结果操作数只能是一个标识符
	std::string *rstreg = new std::string();
	this->allocReg(code->rstname, rstreg);
	//把读到的结果给这个结果寄存器
	this->generateOrder(new std::string(ADD), rstreg, new std::string(V0), new std::string(R0));
}*/

void Compiler:: handleScanf(midcode *code)
{
	if((*code->op1name)[0] == 'i')
	{
		//读入一个整数
		this->generateOrder(new std::string(LI), new std::string(V0), 5);
	}
	else {
		//读入一个字符
		this->generateOrder(new std::string(LI), new std::string(V0), 12);
	}
	this->generateOrder(new std::string(SYSCALL));
	//结果操作数只能是一个标识符
	this->generateOrder(new std::string(ADD), new std::string(T0), new std::string(V0), new std::string(R0));
	this->storeWord(code->rstname);
}

/*void Compiler::handlePrintf(midcode *code)
{
	if(code->op1name->length() == 0)
	{
		//说明是字符串
		this->generateOrder(new std::string(LI), new std::string(V0), 4);
		std::stringstream ss = std::stringstream();
		ss << "$Message" << *(code->rstname);
		this->generateOrder(new std::string(LA), new std::string(A0), &(ss.str()));
		this->generateOrder(new std::string(SYSCALL));
	}
	else{
		//说明是表达式,根据op1name的第一个字符是什么字母来判断是输出整数还是字母
		this->generateOrder(new std::string(LI), new std::string(V0),(*code->op1name)[0] == 'i' ? 1 : 11);
			//这里需要把要输出的数字/字符给到a0寄存器
		if(this->isOperandNumber(code->rstname))
		{
				//如果是数字，那么直接给
			this->generateOrder(new std::string(LI), new std::string(A0), atoi(code->rstname->c_str()));
		}
		else{
				//说明是临时变量，那么先获得它所在的寄存器
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
		//说明是字符串
		this->generateOrder(new std::string(LI), new std::string(V0), 4);
		std::stringstream ss = std::stringstream();
		ss << "$Message" << *(code->rstname);
		this->generateOrder(new std::string(LA), new std::string(A0), &(ss.str()));
		this->generateOrder(new std::string(SYSCALL));
	}
	else{
		//说明是表达式,根据op1name的第一个字符是什么字母来判断是输出整数还是字母
		this->generateOrder(new std::string(LI), new std::string(V0),(*code->op1name)[0] == 'i' ? 1 : 11);
		//这里需要把要输出的数字/字符给到a0寄存器
		this->loadWord(code->rstname, new std::string(A0));
		this->generateOrder(new std::string(SYSCALL));
	}
}

void Compiler::handleExit()
{
	this->generateOrder(new std::string(LI), new std::string(V0), 10);
	this->generateOrder(new std::string(SYSCALL));
}

//统一规定sp先用后改变
void Compiler::generate()
{
	this->mipsAddress = 0;
	this->currentRef = -1;
	this->initAscii();
	this->generateOrder(new std::string(".text"));
	//存储全局常量
	this->initConstAndVar(0, this->mipsAddress);
	
	//开始读中间代码了
	//加个gotomain
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