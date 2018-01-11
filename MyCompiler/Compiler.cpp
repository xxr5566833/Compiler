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
	std::stringstream ss = std::stringstream();
	ss << "15061129_��С��_�����黮�����.txt";
	this->blockFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "15061129_��С��_�Ż�ǰ�м����.txt";
	this->midFileBefore = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "15061129_��С��_�Ż����м����.txt";
	this->midFileAfter = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "15061129_��С��_�Ż�ǰĿ�����.asm";
	this->objectFileBefore = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "15061129_��С��_�Ż���Ŀ�����.asm";
	this->objectFileAfter = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "15061129_��С��_���ű���Ϣ.txt";
	this->symtabFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "15061129_��С��_������������Ϣ.txt";
	this->dataAnalysisFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "15061129_��С��_dagͼ�Լ�С�Ż���Ϣ.txt";
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
	//���ű��ʼ��
	this->initSymTab();
	//�﷨����ʱ�����м�����ʼ��
	this->initMidCode();
	this->setup();
	this->initWordArray();
	int i = 0;
	this->program();
	//ע����������д�����ôֱ��������󲢽���
	if(this->errorList.size() > 0)
	{
		//˵���д��󣬽�������
		this->warningPrint();
		this->errorPrint();
		return ;
	}
	//�������Ż�ǰ���м�����Ŀ����룬Ȼ�������Ż�����м�����Ŀ�����
	this->writeMidCodetoFile(this->midFileBefore);
	this->objectInit();
	this->generate();
	this->writeMipsOrderToFile(this->objectFileBefore);
	//Ȼ��ʼ�Ż����������Ż�����м�����Ŀ�����
	this->initOptimize();
	this->smallOptimize();
	this->divideToBlock();
	this->initBlockConnect();
	this->writeBlockToFile();

	this->dataFlowAnalysis();

	this->DAG();

	this->writeMidCodetoFile(this->midFileAfter);
	this->writeSymtoFile();
	this->objectInit();
	this->generate();
	this->writeMipsOrderToFile(this->objectFileAfter);
}

//һЩ����ģ�鶼�����õ��ķ������������

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
