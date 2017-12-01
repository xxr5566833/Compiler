#include "stdafx.h"
#include "Compiler.h"

Compiler::Compiler(char *path)
{
	std::cout << path << std::endl;
	this->file = std::fstream(path, std::ios::in);
	std::cout << path << std::endl;
	if(!this->file)
	{
		std::cout << "文件路径不存在！" << std::endl;
		exit(0);
	}
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
	this->setup();
	this->initWordArray();
	int i = 0;
	this->program();
	this->warningPrint();
	this->errorPrint();
}

void Compiler:: to()

{
	this->setup();
	this->initWordArray();
	int i = 0;
	while(!this->file.eof())
	{
		this->inSym();
		std::cout << this->sym << " ";
		std::cout << *(this->tok.output) << std::endl;
	}
	this->warningPrint();
	this->errorPrint();
}