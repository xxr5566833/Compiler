// main.cpp: 定义控制台应用程序的入口点。
//
#include "Compiler.h"
#include "stdafx.h"




unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    return (hash & 0x00000FFF);
}


int main(int argc, char *argv[])
{
	/*const tokenType s[] = {INT, CHAR};
	const tokenType INT_BEGIN[] = {PLUS, MINUS, ZERO, UNSIGNEDINT};
	std::cout << sizeof(INT_BEGIN) << std::endl;*/
	//char path[50] ;
	char path[50];
	std::cin >> path;

	Compiler *c = new Compiler(path);
	c->begin();
}
