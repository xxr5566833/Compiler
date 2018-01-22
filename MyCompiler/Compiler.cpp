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
	ss << "_基本块划分情况.txt";
	this->blockFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_优化前中间代码.txt";
	this->midFileBefore = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_优化后中间代码.txt";
	this->midFileAfter = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_优化前目标代码.asm";
	this->objectFileBefore = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_优化后目标代码.asm";
	this->objectFileAfter = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_符号表信息.txt";
	this->symtabFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_数据流分析信息.txt";
	this->dataAnalysisFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_dag图以及小优化调试信息.txt";
	this->dagFile = std::fstream(ss.str(), std::ios::out);

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
	//语法分析时生成中间代码初始化
	this->initMidCode();
	this->setup();
	this->initWordArray();
	int i = 0;
	this->program();
	//注意这里如果有错误，那么直接输出错误并结束
	if(this->errorList.size() > 0)
	{
		//说明有错误，结束程序
		this->warningPrint();
		this->errorPrint();
		return ;
	}
	//先生成优化前的中间代码和目标代码，然后生成优化后的中间代码和目标代码
	std::cout << "优化前" << std::endl;
	this->writeMidCodetoFile(this->midFileBefore);
	this->objectInit();
	this->generate();
	this->writeMipsOrderToFile(this->objectFileBefore);
	//然后开始优化，并生成优化后的中间代码和目标代码
	std::cout << "开始优化" << std::endl;
	this->initOptimize();
	this->smallOptimize();
	this->divideToBlock();
	this->initBlockConnect();
	this->writeBlockToFile();
	this->dataFlowAnalysis();
	this->DAG();
	this->writeSymtoFile();
	std::cout << "优化后" << std::endl;
	this->writeMidCodetoFile(this->midFileAfter);
	this->objectInit();
	this->generate();
	this->writeMipsOrderToFile(this->objectFileAfter);
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
