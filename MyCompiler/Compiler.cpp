#include "stdafx.h"
#include "Compiler.h"

Compiler::Compiler(char *path)
{
	this->file = std::fstream(path, std::ios::in);
	this->sym = std::string();
	this->lineCount = 0;
	this->warningList = std::vector<warning*>();
	this->errorList = std::vector<error*>();
}


Compiler::~Compiler()
{
	this->file.close();
	this->sym.clear();
	
}

void Compiler:: begin()
{
	this->setup();
	this->initWordArray();
	int i = 0;
	while(1)
	{
		this->inSym();
		if(this->isEof())
		{
			break ;
		}
		++i;
		std::cout.setf(std::ios::left);
		std::cout <<  i << " ";
		std::cout.width(15);
		std::cout << this->wordOutput[this->tok.id] << " ";
		std::cout.width(10);
		std::cout << this->sym << std::endl;
	}
	this->warningPrint();
	this->errorPrint();
}