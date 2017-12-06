#include "stdafx.h"
#include "Compiler.h"

Compiler::Compiler(char *path)
{
	this->file = std::fstream(path, std::ios::in);
	if(!this->file)
	{
		std::cout << "�ļ�·�������ڣ�" << std::endl;
		exit(0);
	}
	this->midFile = std::fstream("midcode.txt",std::ios::out);
	this->sym = std::string();
	this->lineCount = 0;
	this->warningList = std::vector<warning*>();
	this->errorList = std::vector<error*>();
}


Compiler::~Compiler()
{
	this->sym.clear();
	
}

void Compiler:: begin()
{
	//���ű��ʼ��
	this->initSymTab();
	this->initMidCode();
	this->setup();
	this->initWordArray();
	int i = 0;
	this->program();
	this->warningPrint();
	this->errorPrint();
}
