#include "Compiler.h"

//主要是把之前的测试文件中的字符随机的转化为大写，最后的结果应该是不变的

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
	std::cout << "请输入文件路径 :" << std::endl;
	std::cin >> path;
	toUpperRandom(path);
	
}*/