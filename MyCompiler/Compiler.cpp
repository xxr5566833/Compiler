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
	ss << path << "_block.txt";
	this->blockFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << path << "_midcode_before.txt";
	this->midFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << path << "_midcode_after.txt";
	this->optimizeFile = std::fstream(ss.str(), std::ios::out);
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
	this->writeMidCodetoFile(this->midFile);
	this->initOptimize();
	this->smallOptimize();
	this->divideToBlock();
	this->printBlock();
	this->initBlockConnect();
//	this->printBlockConnect();

	this->dataFlowAnalysis();

//	this->DAG();

	this->writeMidCodetoFile(this->optimizeFile);
	this->objectInit();
	this->generate();
	this->warningPrint();
	this->errorPrint();
}

//一些所有模块都可能用到的方法加在这里吧

void Compiler::str2Lower(std::string *oldstr, std::string *newstr)
{
	if(!newstr)
	{
		newstr = new std::string();
	}
	for(int i = 0; i < oldstr->length() ; i++)
	{
		char c = tolower((*oldstr)[i]);
		newstr->append(1, c);
	}
}
