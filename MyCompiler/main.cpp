// main.cpp: 定义控制台应用程序的入口点。
//
#include "Compiler.h"
#include "stdafx.h"





int main(int argc, char *argv[])
{

	char path[50];
	std::cout << "请输入文件路径 :" << std::endl;
	std::cin >> path;
	Compiler *c = new Compiler(path);
	c->begin();
}
