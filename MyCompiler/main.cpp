#include "stdafx.h"
#include "Compiler.h"
////////////////////////////////////////////////
//������									  //
//											  //
////////////////////////////////////////////////



int main(int argc, char *argv[])
{

	char path[50];
	std::cout << "�������ļ�·�� :" << std::endl;
	std::cin >> path;
	Compiler *c = new Compiler(path);
	c->begin();

}
