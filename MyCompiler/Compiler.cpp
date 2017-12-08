#include "stdafx.h"
#include "Compiler.h"

Compiler::Compiler(char *path)
{
	this->file = std::fstream(path, std::ios::in);
	if(!this->file)
	{
		std::cout << "文件路径不存在！" << std::endl;
		exit(0);
	}
	std::stringstream ss = std::stringstream();
	ss << path << "_midcode.txt";
	this->midFile = std::fstream(ss.str(),std::ios::out);
	ss.str("");
	ss << path << "_mipscode.asm";
	this->objectFile = std::fstream(ss.str(), std::ios::out);
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
	//符号表初始化
	this->initSymTab();
	this->initMidCode();
	this->setup();
	this->initWordArray();
	int i = 0;
	this->program();
	this->generate();
	this->warningPrint();
	this->errorPrint();
}
