#include "Compiler.h"
//�����ҵ�hash����
unsigned int Hash(const char *str)
{
	//����Ѵ�Сдת����,ͳһ��Сд������hashֵ�������Ϳ��� ����ͻ��
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
	sym->name =name;
	sym->returnType = returntype;
	sym->symbolType = symboltype;
	sym->feature = feature;
	sym->decLine = decline;
	sym->useLine = new std::vector<int>();
	sym->link = link;
	sym->address = this->address;
	switch(symboltype)
	{
	case CONSTSYM :
	case SIMPLESYM:
	case PARASYM:
		this->address ++;
		break;
	case ARRAYSYM:
		this->address += sym->feature;
		break;
	}

	this->symTab[this->top++] = sym;

	this->printSymTab();
	return sym;
}


//pop�ǴӺ����г���ʱ�����ű���ά������,ͬʱҪ�������Ѿ�������ɵĺ���������Ϣ
void Compiler:: pop()
{
	//��¼����
	this->funcSymNum[this->funcNum] = this->top - this->index;
	//��ʼ������ֳ�����ű�
	this->funcSymTab[this->funcNum] = new symbol*[500];
	//�ڷֳ���ķ��ű����±�
	int symindex = 0;
	while(this->top > this->index)
	{
		this->top--;
		//ά��hash��
		symbol *sym = this->symTab[this->top];
		int hashindex = Hash(sym->name->c_str());
		this->symHash[hashindex] = sym->link;
		//�Ѵ�ԭ���ķ��ű���ɾ���ķ�����Ϣ���浽�ֺ������ű���
		this->funcSymTab[this->funcNum][symindex ++] = sym;
	}
	//˵��this->top-1��һ����һ����������������ref��Ϊ�ں������е�λ��
	this->symTab[this->top - 1]->ref = this->funcNum;
	this->index = 0;
	this->address = this->globalAddress;
	this->currentFuncSymNum = 0;
	this->funcNum ++;
}

//����һ������ʱ����Ҫά����

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
	//���ﻹҪ��һ�������˵�ֲ�Ѱ�ң����ҷ����Լ���һ�������ڣ���ô��ʱ����Ҫ�������ʶ���뺯�����Ƿ�һ�£����һ�£�Ҳ�ǲ�������
	if(this->index != 0 && local)
	{
		//�Ȼ�ȡ�������������
		symbol *funcsym = this->symTab[this->index - 1];
		if(this->isIdEqual(*(funcsym->name), *name))
		{
			*sym = funcsym;
			return true;
		}
	}
	return false;
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
	std::cout << "���" << " ";
	std::cout.width(15);
	std::cout << "��ʶ������" << " ";
	std::cout.width(15);
	std::cout << "��ʶ����������" << " ";
	std::cout.width(15);
	std::cout << "��ʶ������" << " ";
	std::cout.width(15);
	std::cout << "��ʶ������" << " ";
	std::cout.width(15);
	std::cout << "���鳤�Ȼ���������������ֵ" << " ";
	std::cout.width(15);
	std::cout << "������ַ" << " ";
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
	std::cout << "topָ��λ��:" << this->top << std::endl;
	std::cout << "indexָ��λ��:" << this->index << std::endl;

	std::cout << "��������ӡ����main�����������������ķ��ű���Ϣ" << std::endl;

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

	std::cout << "�����ܵ�ַΪ��" << this->address << std::endl;
	std::cout << "���ű���ӡ���" << std::endl;
}