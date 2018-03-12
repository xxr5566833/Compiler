#include "stdafx.h"
#include "Compiler.h"

////////////////////////////////////////////////
//Compiler��Ĺ��췽���ͱ���������������	  //
//											  //
////////////////////////////////////////////////

Compiler::Compiler(char *path)
{
	this->file = std::fstream(path, std::ios::in);
	if(!this->file)
	{
		std::cout << "�ļ�·�������ڣ�" << std::endl;
		exit(0);
	}
	std::stringstream ss = std::stringstream();
	ss << "_�����黮�����.txt";
	this->blockFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_�Ż�ǰ�м����.txt";
	this->midFileBefore = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_�Ż����м����.txt";
	this->midFileAfter = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_�Ż�ǰĿ�����.asm";
	this->objectFileBefore = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_�Ż���Ŀ�����.asm";
	this->objectFileAfter = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_���ű���Ϣ.txt";
	this->symtabFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_������������Ϣ.txt";
	this->dataAnalysisFile = std::fstream(ss.str(), std::ios::out);
	ss.str("");
	ss << "_dagͼ�Լ�С�Ż�������Ϣ.txt";
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
//��������к���
void Compiler:: begin()
{
	//���ű��ʼ��
	this->initSymTab();
	//���������ֱ����ڵõ���ǰ�����ǲ���һ��������
	this->setup();
	//�﷨����ʱ�����м�����ʼ��
	this->initMidCode();
	//�����﷨�Ƶ�����
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
	std::cout << "�Ż�ǰ" << std::endl;
	this->writeMidCodetoFile(this->midFileBefore);
	this->objectInit();
	this->generate();
	this->writeMipsOrderToFile(this->objectFileBefore);
	//Ȼ��ʼ�Ż����������Ż�����м�����Ŀ�����
	std::cout << "��ʼ�Ż�" << std::endl;
	this->initOptimize();
	//������label��goto���Ż�
	this->smallOptimize();
	//�����黮��
	this->divideToBlock();
	//��ͼ����
	this->initBlockConnect();
	//��ͼ��Ϣд���ļ�
	this->writeBlockToFile();
	//��Ծ��������
	this->dataFlowAnalysis();
	//dagͼ�Ż�
	this->DAG();
	//���ű���Ϣд���ļ���
	this->writeSymtoFile();
	std::cout << "�Ż���" << std::endl;
	this->writeMidCodetoFile(this->midFileAfter);
	this->objectInit();
	//����Ŀ�����
	this->generate();
	this->writeMipsOrderToFile(this->objectFileAfter);
}


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
