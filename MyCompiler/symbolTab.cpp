#include "Compiler.h"
//网上找的hash函数
unsigned int Hash(const char *str)
{
	//这里把大小写转换了,统一用小写来计算hash值，这样就可以 检查冲突了
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
	 

    while (*str)
    {
		char c = tolower(*str);
        hash = hash * seed + (c);
		str ++;
    }
 
    return (hash & 0x00000FFF);
}

void Compiler:: initSymTab()
{
	this->index = 0;
	this->top = 0;
	this->address = 0;
	this->funcNum = 0;
	this->currentFuncSymNum = 0;
	for(int i=0;i<kMaxHash;i++)
	{
		this->symHash[i] = -1;
	}
}

symbol* Compiler:: push(std::string *name, eRetType returntype, eSymType symboltype, int feature, int decline)
{
	int hashindex = Hash(name->c_str());
	int link = this->symHash[hashindex];
	this->symHash[hashindex] = this->top;

	symbol *sym = new symbol();
	sym->name = new std::string();
	*sym->name = *name;
	sym->returnType = returntype;
	sym->symbolType = symboltype;
	sym->feature = feature;
	sym->decLine = decline;
	sym->useLine = new std::vector<int>();
	sym->link = link;
	sym->address = this->address;
	//-1 表示尚未分配
	sym->regIndex = -1;
	switch(symboltype)
	{
	case CONSTSYM :
		this->address ++;
		break;
	case SIMPLESYM:
	case PARASYM:
		//简单变量和参数变量还需要初始化使用情况
		{
			this->address ++;
			for(int i = 0 ; i < kMaxBasicBlock ; i++)
			{
				//预先初始化为false，表示未被使用
				sym->flag[i] = false;
			}
		}
		
		break;
	case ARRAYSYM:
		this->address += sym->feature;
		break;
	}

	this->symTab[this->top++] = sym;

	//this->printSymTab();
	return sym;
}


//pop是从函数中出来时，符号表的维护工作,同时要保存下已经编译完成的函数符号信息
void Compiler:: pop()
{
	//记录长度
	this->funcSymNum[this->funcNum] = this->top - this->index;
	//初始化这个分程序符号表
	this->funcSymTab[this->funcNum] = new symbol*[500];
	//在分程序的符号表中下标
	int symindex = 0;
	while(this->top > this->index)
	{
		this->top--;
		//维护hash表
		symbol *sym = this->symTab[this->top];
		int hashindex = Hash(sym->name->c_str());
		this->symHash[hashindex] = sym->link;
		//把从原来的符号表中删除的符号信息保存到分函数符号表中
		this->funcSymTab[this->funcNum][this->top - this->index] = sym;
	}
	//说明this->top-1处一定是一个函数，设置它的ref域为在函数表中的位置
	this->symTab[this->top - 1]->ref = this->funcNum;
	this->funcMaxAddress[this->funcNum] = this->address;
	this->index = 0;
	this->address = this->globalAddress;
	this->currentFuncSymNum = 0;
	this->funcNum ++;
}

//进入一个函数时，需要维护的

void Compiler :: inFunc()
{
	this->index = this->top;
	this->globalAddress = this->address;
	this->address = 0;
}


bool Compiler:: find(std::string *name, symbol **sym, bool local)
{
	int hashindex = Hash(name->c_str());
	int symindex = this->symHash[hashindex];
	while((local && symindex >= this->index)||(!local && symindex >= 0))
	{
		symbol *tempsym = this->symTab[symindex];

		if(this->isIdEqual(*(tempsym->name), *name ))
		{
			*sym = tempsym;
			return true;
		}
		symindex = tempsym->link;
	}
	//这里还要加一条，如果说局部寻找，而且发现自己在一个函数内，那么此时还需要看这个标识符与函数名是否一致，如果一致，也是不允许的
	if(this->index != 0 && local)
	{
		//先获取这个函数的名字
		symbol *funcsym = this->symTab[this->index - 1];
		if(this->isIdEqual(*(funcsym->name), *name))
		{
			*sym = funcsym;
			return true;
		}
	}
	return false;
}

void Compiler::writeSymtoFile()
{
	this->symtabFile << "对于常量，特征值为常量值，对于函数，特征值为参数个数，对于数组，特征值为数组长度" << std::endl;
	this->symtabFile << "序号" << "\t\t" << "名称" << "\t\t" << "行数" << "\t\t" << "种类" << "\t\t" << "类型" << "\t\t" << "特征值" << "\t\t"
		<< "地址" << "\t\t" << "寄存器" << "\t\t" << std::endl;
	std::stringstream ss = std::stringstream();
	for(int i = 0 ; i < this->funcNum ; i++)
	{
		symbol **tab = this->funcSymTab[i];
		int length = this->funcSymNum[i];
		for(int j = 0 ; j < length ; j++)
		{
			symbol *sym = tab[j];
			ss << j << "\t\t";
			ss << *(sym->name) << "\t\t";
			ss << sym->decLine + 1 << "\t\t";
			switch(sym->symbolType)
			{
			case CONSTSYM:
				ss << "常量" ;
				break;
			case SIMPLESYM:
				ss << "简单" ;
				break;
			case ARRAYSYM:
				ss << "数组" ;
				break;
			case PARASYM:
				ss << "参数" ;
				break;
			case FUNCSYM:
				ss << "函数";
				break;
			}
			ss << "\t\t";
			switch(sym->returnType)
			{
			case INTRET:
				ss << "int";
				break;
			case CHARRET:
				ss << "char";
				break;
			case VOIDRET:
				ss << "void";
				break;
			}
			ss << "\t\t";
			ss << sym->feature << "\t\t";
			ss << sym->address << "\t\t";
			if(sym->regIndex == -1)
			{
				ss << "无" << "\t\t";
			}
			else{
				ss << (sym->regIndex < (kMaxRegAvailable / 2) ? "$t" : "$s") << sym->regIndex % (kMaxRegAvailable / 2) << "\t\t";
			}
			ss << std::endl;
		}
		ss << "该函数表打印完毕" << std::endl;
	}
	ss << "接下来打印全局函数表" << std::endl;
	for(int j = 0 ; j < this->top ; j++)
	{
		symbol *sym = this->symTab[j];
		ss << j << "\t\t";
			ss << *(sym->name) << "\t\t";
			ss << sym->decLine + 1 << "\t\t";
			switch(sym->symbolType)
			{
			case CONSTSYM:
				ss << "常量" ;
				break;
			case SIMPLESYM:
				ss << "简单" ;
				break;
			case ARRAYSYM:
				ss << "数组" ;
				break;
			case PARASYM:
				ss << "参数" ;
				break;
			case FUNCSYM:
				ss << "函数";
				break;
			}
			ss << "\t\t";
			switch(sym->returnType)
			{
			case INTRET:
				ss << "int";
				break;
			case CHARRET:
				ss << "char";
				break;
			case VOIDRET:
				ss << "void";
				break;
			}
			ss << "\t\t";
			ss << sym->feature << "\t\t";
			ss << sym->address << "\t\t";
			if(sym->regIndex == -1)
			{
				ss << "无" << "\t\t";
			}
			else{
				ss << (sym->regIndex < (kMaxRegAvailable / 2) ? "$t" : "$s") << sym->regIndex % (kMaxRegAvailable / 2) << "\t\t";
			}
			ss << std::endl;
	}
	ss << "符号表打印完毕" << std::endl;
	this->symtabFile << ss.str();
	
}

void Compiler:: printSym(symbol *sym)
{
	std::cout.setf(std::ios::left);
	std::cout.width(15);
	std::cout << *(sym->name) << " ";
	std::cout.width(15);
	std::cout << sym->decLine + 1 << " ";
	std::cout.width(15);
	std::cout << sym->symbolType << " ";
	std::cout.width(15);
	std::cout << sym->returnType << " ";
	std::cout.width(15);
	std::cout << sym->feature << " ";
	std::cout.width(15);
	std::cout << sym->address << " ";
	std::cout << "\n";
}

void Compiler:: printSymTab()
{
	int symindex = this->top;

	std::cout.setf(std::ios::left);
	std::cout.width(15);
	std::cout << "序号" << " ";
	std::cout.width(15);
	std::cout << "标识符名称" << " ";
	std::cout.width(15);
	std::cout << "标识符声明行数" << " ";
	std::cout.width(15);
	std::cout << "标识符种类" << " ";
	std::cout.width(15);
	std::cout << "标识符类型" << " ";
	std::cout.width(15);
	std::cout << "数组长度或函数参数个数或常量值" << " ";
	std::cout.width(15);
	std::cout << "所处地址" << " ";
	std::cout << "\n";

	while(symindex>0)
	{
		symindex --;
		std::cout.setf(std::ios::left);
		std::cout.width(15);
		std::cout << symindex << " ";
		symbol *tempsym = this->symTab[symindex];
		this->printSym(tempsym);
	}
	std::cout << "top指针位于:" << this->top << std::endl;
	std::cout << "index指针位于:" << this->index << std::endl;

	std::cout << "接下来打印除了main函数以外其他函数的符号表信息" << std::endl;

	for(int i=0;i<this->funcNum;i++)
	{
		symbol **functab = this->funcSymTab[i];
		int length = this->funcSymNum[i];
		for(int j = 0;j < length ; j++)
		{
			symbol *sym = functab[j];
			std::cout.setf(std::ios::left);
			std::cout.width(15);
			std::cout << j << " ";
			this->printSym(sym);

		}
	}

	std::cout << "所需总地址为：" << this->address << std::endl;
	std::cout << "符号表打印完毕" << std::endl;
}
