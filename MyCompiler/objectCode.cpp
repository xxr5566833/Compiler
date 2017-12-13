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


const char *SP = "$sp";

const char *FP = "$fp";

const char *RA = "$ra";

const char *T0 = "$t0";

const char *T1 = "$t1";

const char *V0 = "$v0";

const char *A0 = "$a0";

const char *R0 = "$zero";

void Compiler::initAscii()
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
			this->generateOrder(new std::string(LI), new std::string(T0), c);
			this->generateOrder(new std::string(SB), new std::string(T0), this->strAddress, new std::string(R0));
			this->strAddress ++;
		}
		this->generateOrder(new std::string(SB), new std::string(R0), this->strAddress, new std::string(R0));
		this->strAddress ++;
	}
	//最后怕strAddress不是4的倍数，需要向上取整
	this->strAddress = this->strAddress % 4 == 0 ? this->strAddress : (this->strAddress / 4 + 1) * 4;
	//当前mipsAddress 就是当前字符串存好后的地址
	this->mipsAddress = this->strAddress;
}

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
				this->generateOrder(new std::string(LI), new std::string(T0), sym->feature);
				//这里需要相对于第一个常量的起始地址偏移
				this->generateOrder(new std::string(SW), new std::string(T0), sym->address * 4 + this->strAddress, new std::string(R0));
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
				this->generateOrder(new std::string(LI), new std::string(T0), sym->feature);
				this->generateOrder(new std::string(SW), new std::string(T0), initaddress - sym->address * 4, new std::string(SP));
			}
		}
		
	}
}

void Compiler::genMipsLabel(std::string *label)
{
	//std::cout << *label << ":" << std::endl;
	this->objectFile << *label << ":" << std::endl;
}

void Compiler::funcBegin(std::string *name)
{
	//进入时 sp已经存好了实参，所以sp的地址已经改变，为了方便处理，这里把sp的指针变回放入形参之前的位置
	symbol *sym = 0;
	this->find(name, &sym, false);
	//生成label,就是函数名
	this->genMipsLabel(sym->name);
	//空间分配 参数 常量 变量 上一次的帧指针 上一次的返回地址 当前帧指针等于之前的栈指针，  当前栈指针修改以分配空间
	int currentaddress = this->funcMaxAddress[sym->ref];
	int paranum = sym->feature;
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), paranum * 4);

	//先保存帧指针
	this->generateOrder(new std::string(SW), new std::string(FP), - currentaddress * 4, new std::string(SP));
	//保存返回地址
	this->generateOrder(new std::string(SW), new std::string(RA), - (currentaddress + 1) * 4, new std::string(SP));
	//保存常量
	this->initConstAndVar(sym, 0);
	//当前帧指针等于之前栈指针
	this->generateOrder(new std::string(ADD), new std::string(FP), new std::string(SP), new std::string(R0));
	//当前栈指针修改
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP) , -(currentaddress + 2) * 4);

}

void Compiler::handleRet(std::string *name)
{
	//函数结束运行时需要做
	symbol *sym = 0;
	this->find(name, &sym, false);
	//如果有返回值已经在赋值中考虑过了， 这里就只考虑运行栈的维护
	//更新返回地址
	this->generateOrder(new std::string(LW), new std::string(RA), 4, new std::string(SP));
	//更新当前帧指针
	this->generateOrder(new std::string(LW), new std::string(FP), 8, new std::string(SP));
	//更新栈指针
	int currentaddress = this->funcMaxAddress[sym->ref];
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), (currentaddress + 2) * 4);
	//跳转回去
	this->generateOrder(new std::string(JR), new std::string(RA));
	this->generateOrder(new std::string(NOP));
}

//offset是相对于字符串区的偏移地址  或者是相对于fp的减少地址  注意这里是按字记的
void Compiler::findAddress(std::string *name, int *offset, bool *global)
{
	symbol **symtab = this->funcSymTab[this->currentRef];
	int length = this->funcSymNum[this->currentRef];
	for(int i = 0 ; i < length ; i++)
	{
		symbol *sym = symtab[i];
		if(sym->name->compare(*name) == 0)
		{
			*offset = sym->address;
			*global = false;
			return ;
		}
	}
	for(int i = 0 ; i < this->top ; i++)
	{
		symbol *sym = this->symTab[i];
		if(sym->name->compare(*name) == 0)
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

void Compiler::handleAssign(midcode *code)
{
	std::string *rs = code->op1name;
	std::string *rt = code->rstname;

	this->loadWord(rs, new std::string(T0));
	this->storeWord(rt);
}



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
	this->generateOrder(new std::string(J), label);
	this->generateOrder(new std::string(NOP));
}

void Compiler::handleRealPara(std::string *para)
{
	this->loadWord(para, new std::string(T0));
	this->generateOrder(new std::string(SW), new std::string(T0), 0, new std::string(SP));
	this->generateOrder(new std::string(ADDI), new std::string(SP), new std::string(SP), -4);
}

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
	this->generateOrder(new std::string(JAL), name);
	this->generateOrder(new std::string(NOP));;
}

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
		//存到标识符中
	this->generateOrder(new std::string(ADD), new std::string(T0), new std::string(V0), new std::string(R0));
	this->storeWord(code->rstname);
}

void Compiler::handlePrintf(midcode *code)
{
	if(code->op1name->length() == 0)
	{
		//说明是字符串
		int index = atoi(code->rstname->c_str());
		int address = this->stringAddress[index];
		this->generateOrder(new std::string(LI), new std::string(V0), 4);
		this->generateOrder(new std::string(LA), new std::string(A0), address);
		this->generateOrder(new std::string(SYSCALL));
	}
	else{
		//说明是表达式
		if ((*code->op1name)[0] == 'i')
		{
			this->generateOrder(new std::string(LI), new std::string(V0), 1);
			this->loadWord(code->rstname, new std::string(A0));
			this->generateOrder(new std::string(SYSCALL));
		}
		else{
			this->generateOrder(new std::string(LI), new std::string(V0), 11);
			this->loadWord(code->rstname, new std::string(A0));
			this->generateOrder(new std::string(SYSCALL));
		}
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
	this->generateOrder(new std::string(".text"));
	this->initAscii();
	//存储全局常量
	this->initConstAndVar(0, this->mipsAddress);
	
	//开始读中间代码了
	//加个gotomain
	this->generateOrder(new std::string(ADD), new std::string(FP), new std::string(SP), new std::string(R0));
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
		case ASSIGNOP:
			this->handleAssign(code);
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