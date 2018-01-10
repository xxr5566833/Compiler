#include "Compiler.h"

const int baseAddress = 0;

//mips保留字
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

//t9统一作为操作数1使用的默认寄存器

std::string *T9 = new std::string("$t9");

//t8专门作为操作数2使用的默认寄存器

std::string *T8 = new std::string("$t8");

//t7统一作为操作数3使用的默认寄存器

std::string *T7 = new std::string("$t7");

std::string *V0 = new std::string("$v0");

std::string *A0 = new std::string("$a0");

std::string *R0 = new std::string("$zero");


const int kMaxTempReg = 10;

const int kMaxSymReg = 8;


void Compiler::objectInit()
{
	this->mipsIndex = 0;
	this->mipsAddress = 0;
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
	this->generateOrder(new std::string(".data"));

	for(int i = 0 ; i < this->stringNum ; i++)
	{
		std::string *str = this->stringTab[i];
		std::stringstream ss = std::stringstream();
		ss << "$Message" << i << ":" << ".asciiz" << "\"" << *str << "\"" ;
		this->generateOrder(&(ss.str()));
	}
	this->strAddress = baseAddress * 4;
	//统一提供400的空间，即可以存400个字符的字符串
	this->strAddress = this->strAddress + 400;
	//当前mipsAddress 就是当前字符串存好后的地址
	this->mipsAddress = this->strAddress;
}

void Compiler::pushOrder(std::string *order)
{
	std::cout << *order;
	std::string *save = new std::string();
	*save = *order;
	this->mipsCodes[this->mipsIndex++] = save;
}

void Compiler::writeMipsOrderToFile(std::fstream &tofile)
{
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
	this->generateOrder(ADDI, SP, SP, paranum * 4);

	//寄存器压栈

	for(int i = 0 ; i < kMaxRegAvailable ; i ++)
	{
		std::stringstream ss = std::stringstream();
		int index = i % (kMaxRegAvailable / 2);
		char *sym = i >= (kMaxRegAvailable / 2) ? "$s" : "$t"; 
		ss << sym << index;
		this->generateOrder(SW, &(ss.str()), - currentaddress * 4, SP);
		currentaddress += 1;
	}

	//先保存帧指针
	this->generateOrder(SW, FP, - currentaddress * 4, SP);
	//保存返回地址
	currentaddress += 1;
	this->generateOrder(SW, RA, - currentaddress * 4, SP);
	currentaddress += 1;
	//当前帧指针等于之前栈指针
	this->generateOrder(ADD, FP, SP, R0);
	//当前栈指针修改
	this->generateOrder(ADDI, SP, SP , - currentaddress * 4);

}

void Compiler::handleRet(std::string *name)
{
	//函数结束运行时需要做
	symbol *sym = 0;
	this->find(name, &sym, false);
	//如果有返回值已经在赋值中考虑过了， 这里就只考虑运行栈的维护
	//更新返回地址
	int currentaddress = 1;
	this->generateOrder(LW, RA, currentaddress * 4, SP);
	//更新当前帧指针
	currentaddress += 1;
	this->generateOrder(LW, FP, currentaddress * 4, SP);
	currentaddress += 1;

	this->regInit();
	//更新每一个寄存器
	for(int i = kMaxRegAvailable - 1 ; i >= 0 ; i--)
	{
		std::stringstream ss = std::stringstream();
		int index = i % (kMaxRegAvailable / 2);
		char *sym = i >= (kMaxRegAvailable / 2) ? "$s" : "$t"; 
		ss << sym << index;
		this->generateOrder(LW, &(ss.str()), currentaddress * 4, SP);
		currentaddress += 1;
	}

	//更新栈指针
	currentaddress += (this->funcMaxAddress[sym->ref] - 1);
	this->generateOrder(ADDI, SP, SP, currentaddress * 4);
	//跳转回去
	this->generateOrder(JR, RA);
	this->generateOrder(NOP);
}

//offset是相对于字符串区的偏移地址  或者是相对于fp的减少地址  注意这里是按字记的
//而且因为如果局部变量和全局变量重名，那么就是局部变量
void Compiler::findSym(std::string *name, symbol **resultsym, bool *global)
{
	symbol **symtab = this->funcSymTab[this->currentRef];
	int length = this->funcSymNum[this->currentRef];
	for(int i = 0 ; i < length ; i++)
	{
		symbol *sym = symtab[i];
		//bug：这里一开始为什么没有用isIdEqual()?
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


//转化要使用的操作数为对应的寄存器
void Compiler::loadReg(std::string *rs, std::string *reg)
{
	//bug : 临时变量不能作为全局的来使用，只能作为局部的！直接把他当做一个标识符
	//reg 传入的是，如果这个变量没有相应的寄存器，那么该变量对应的默认寄存器是什么
	if(this->isOperandRet(rs))
	{
		*reg = *V0;
	}
	else if(this->isOperandNumber(rs))
	{
		this->generateOrder(LI, reg, rs);
	}
	else{
		//这里是标识符或者是临时变量
		bool global = false;
		symbol *sym = 0;
		this->findSym(rs, &sym, &global);
		int regindex = sym->regIndex;
		if(regindex == -1)
		{
			//说明没有相应的寄存器给它，直接从它的地址上的值load到相应的reg寄存器里
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
			//说明有相应的寄存器给它，那么此时先检查当前相应的寄存器有没有被使用
			std::string *old = this->allReg[regindex];
			std::stringstream ss = std::stringstream();
			ss << (regindex < (kMaxRegAvailable / 2) ? "$t" : "$s") << regindex % (kMaxRegAvailable / 2);
			*reg = ss.str();
			//如果是参数，此时如果对应的reg上没有记录或者是和这个记录不是该参数，说明该参数还没有被load进寄存器，需要先把它从内存load到相应的寄存器里
			if(sym->symbolType == PARASYM &&(!this->allReg[regindex] || !this->isIdEqual(*(this->allReg[regindex]), *sym->name)))
			{
				this->generateOrder(LW, reg, - sym->address * 4, FP);
			}
			this->allReg[regindex] = sym->name;
		}
	}
}
//把结果操作数转化为相应的寄存器
void Compiler:: storeReg(std::string *rd, std::string *reg){

	//此时rd只有三种情况：标识符 临时变量 #RET
	if(this->isOperandRet(rd))
	{
		//此时直接让reg为v0
		*reg = *V0;
	}
	else{
		//这里是标识符或者是临时变量
		bool global = false;
		symbol *sym = 0;
		this->findSym(rd, &sym, &global);
		int regindex = sym->regIndex;
		if(regindex == -1)
		{
			//说明没有相应的寄存器给它
			//此时什么都不做，直接用reg的默认作为存放结果的寄存器，然后让调用者调用writeBack再吧结果存回地址上
		}
		else{
			//说明有相应的寄存器给它，那么此时先检查当前相应的寄存器有没有被使用
			std::string *old = this->allReg[regindex];
			std::stringstream ss = std::stringstream();
			ss << (regindex < (kMaxRegAvailable / 2) ? "$t" : "$s") << regindex % (kMaxRegAvailable / 2);
			*reg = ss.str();
			this->allReg[regindex] = sym->name;
		}
	}

}

//根据情况看是否要写回到内存里
void Compiler::writeBack(std::string *rd, std::string *reg)
{
	if(!this->isOperandRet(rd))
	{
		symbol *sym = 0;
		bool global = false;
		this->findSym(rd, &sym, &global);
		if(sym && sym->regIndex == -1)
		{
			//如果是不分配寄存器的标识符，那么此时还需要写回相应的地址里去
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
	if(this->isOperandTemp(op1))
	{
		//如果op1是一个临时变量
		//获得这个临时变量对应的寄存器
		this->loadReg(op1, reg1);
		if(this->isOperandNumber(op2))
		{
			//如果第二个操作数是一个数字，那么就把他俩减了以后的结果作为结果操作数
			this->generateOrder(SUBI, rstreg, reg1, op2);
		}
		else{
			//第二个操作数是一个临时变量
			this->loadReg(op2, reg2);
			//两个操作数都是临时变量，那么就把他俩减了后的结果放在t9，作为最后的判断
			this->generateOrder(SUB, rstreg, reg1, reg2);
			//释放空间
		}
		//释放空间
	}
	else{
		//第一个操作数是一个数字
		if(this->isOperandNumber(op2))
		{
			//两个操作数都是数字，把他俩减了之后的结果给t9
			int value1 = atoi(op1->c_str());
			int value2 = atoi(op2->c_str());
			value2 = value1 - value2;
			this->generateOrder(LI, rstreg, value2);
		}
		else{
			//第二个操作数是一个临时变量
			this->loadReg(op2, reg2);
			//需要先把操作数1数字li到t9，
			this->generateOrder(LI, T9, op1);
			this->generateOrder(SUB, rstreg, T9, reg2);
			//释放空间
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
	//一开始忘了加nop..
	this->generateOrder(NOP);
	//释放空间：
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
	//para也是从表达式得到的值，此时还是分为数字和临时变量
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
			//操作数1是一个数字，那么此时操作数2如果是临时变量，那么结果操作数也是临时变量
			this->loadReg(op2, reg2);
			this->storeReg(rst, rstreg);
			this->generateOrder(ADDI, rstreg, reg2, op1);
		}
		else{
			//操作数2只能是0了
			this->storeReg(rst, rstreg);
			this->generateOrder(LI, rstreg, op1);
		}
	}
	else{
		//操作数1是一个临时变量/#RET/标识符
		this->loadReg(op1, reg1);
		if(this->isOperandNumber(op2))
		{
			//操作数2是一个数字
			this->storeReg(rst, rstreg);
			//获得了结果操作数对应的寄存器
			this->generateOrder(ADDI, rstreg, reg1, op2);
			//此时还需要看结果操作数是不是需要写回地址
		}
		else{
			//操作数2是一个临时变量
			//结果操作数是一个临时变量/#RET/标识符
			this->loadReg(op2, reg2);
			this->storeReg(rst, rstreg);
			this->generateOrder(ADD, rstreg, reg1, reg2);
		}
	}
	this->writeBack(rst, rstreg);
	//释放空间
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
		//操作数1是一个数字，那么此时操作数2和结果操作数都是临时变量
		if((*op1)[0] == '0')
		{
			//表示操作数1是0，那么此时直接用$zero就可以
			*reg1 = *R0;
		}
		else{
			//操作数1不是0，先LI
			this->generateOrder(LI, reg1, op1);
		}
		this->loadReg(op2, reg2);
		this->storeReg(rst, rstreg);
		this->generateOrder(SUB, rstreg, reg1, reg2);
	}
	else{
		//操作数1是一个临时变量
		this->loadReg(op1, reg1);
		if(this->isOperandTemp(op2))
		{
			//操作数2也是一个临时变量
			this->loadReg(op2, reg2);

			//结果操作数也是一个临时变量
			this->storeReg(rst, rstreg);

			//获得了结果操作数对应的寄存器
			this->generateOrder(SUB, rstreg, reg1, reg2);
		}
		else{
			//操作数2是一个数字
			//结果操作数是一个临时变量
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
		this->generateOrder(ADDU, T9, T9, GP);
		this->generateOrder(LW, rstreg, 0, T9);
	}
	else{
		this->generateOrder(SUB, T9, FP, T9);
		this->generateOrder(LW, rstreg, 0, T9);
	}
	this->writeBack(code->rstname, rstreg);

	//释放空间
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
	//获得下标
	this->loadReg(index, reg2);
	this->generateOrder(ADDI, T7, reg2, sym->address);
	this->generateOrder(SLL, T7, T7, 2);
	this->loadReg(rs, reg1);
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
		//读入一个整数
		this->generateOrder(LI, V0, 5);
	}
	else {
		//读入一个字符
		this->generateOrder(LI, V0, 12);
	}
	this->generateOrder(SYSCALL);
	//结果操作数只能是一个标识符
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
		//说明是字符串
		this->generateOrder(LI, V0, 4);
		std::stringstream ss = std::stringstream();
		ss << "$Message" << *(code->rstname);
		this->generateOrder(LA, A0, &(ss.str()));
		this->generateOrder(SYSCALL);
	}
	else{
		//说明是表达式,根据op1name的第一个字符是什么字母来判断是输出整数还是字母
		this->generateOrder(LI, V0, (*code->op1name)[0] == 'i' ? 1 : 11);
		//这里需要把要输出的数字/字符给到a0寄存器
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

//统一规定sp先用后改变
void Compiler::generate()
{
	this->initAscii();
	this->generateOrder(new std::string(".text"));
	
	//开始读中间代码了
	//加个gotomain
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