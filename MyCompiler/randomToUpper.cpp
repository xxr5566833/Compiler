#include "Compiler.h"

//��Ҫ�ǰ�֮ǰ�Ĳ����ļ��е��ַ������ת��Ϊ��д�����Ľ��Ӧ���ǲ����

void toUpperRandom(char *path)
{

	std::fstream in = std::fstream(path, std::ios::in);
	std::fstream out = std::fstream("randomtest.txt", std::ios::out);
	srand(time(0));
	while(in.peek() != EOF)
	{
		char c = in.get();
		int pro = rand() % 100;
		char outc = (pro >= 50 ? toupper(c) : c);
		out << outc; 
	}
}
/*int main(int argc, char *argv[])
{

	char path[50];
	std::cout << "�������ļ�·�� :" << std::endl;
	std::cin >> path;
	toUpperRandom(path);
	
}*/