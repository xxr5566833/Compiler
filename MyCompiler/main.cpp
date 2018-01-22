#include "stdafx.h"
#include "Compiler.h"
////////////////////////////////////////////////
//主函数									  //
//											  //
////////////////////////////////////////////////



int main(int argc, char *argv[])
{

	char path[50];
	std::cout << "请输入文件路径 :" << std::endl;
	std::cin >> path;
	Compiler *c = new Compiler(path);
	c->begin();

}
