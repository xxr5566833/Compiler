// main.cpp: 定义控制台应用程序的入口点。
//
#include "Compiler.h"
#include "stdafx.h"
/*//程序部分开始
const char _ = '_', p_ = '+', m__ = '-', s0 = '*', d_0 = '/', a0a = 'a', _00 = '0'; 	//7种代表的标识符全了
const int _zero = 0, _num = 4, _pnum = +3, _mnum = -9;
const int __num = 20, __pnum = +56, __mnum = -78;
const int ___num = 5783, ___pnum = +326, ___mnum = -111;								//
//常量说明
const int _k1 = 0, _k2 = +100, _k3 = -1000;
const char _k4 = 'a', _k5 = '_', _k6 = 'A', _k7 = '-', _k8 = '*', _k9 = '0';
//变量说明
int v1, fibarray[1000];
char c1, arrayc[1000];
//函数定义
//有返回值函数定义,有返回值的函数递归调用，
//声明头部 int
//(参数)
//条件语句
// (条件)实现了表达式作为判断依据
//循环语句
// (条件)实现了表达式 + 关系运算符 + 表达式作为判断依据
//语句中还实现了
//①语句列
//②赋值语句 中实现了<标识符> = <表达式>
//③写语句的三种情况
//
//⑤返回语句
//因子中实现了标识符

//有返回值有参数函数定义
int _4fib(int num)
{
	const char m = '_';
	int temp, fib1, fib2;
	if (- num < -1)
	{
		if (fibarray[num - 1] <= -1)
		{
			fib1 = _4fib(num - 1);
		}
		else {
			fib1 = fibarray[num - 1];
		}
		fib2 = fibarray[num - 2];
		temp = fib1 + fib2;
		fibarray[num] = temp;					//两种赋值语句
		return temp;
	}
	else {
		if (num)
		{
			fibarray[1] = 1;
			return 1;
		}
		else {
			fibarray[0] = 0;
			return 0;
		}
	}
	;
}
//无返回值无参数的函数定义
void printStar()
{
	std::cout << "*";
	return;
}
//无返回值有参数的函数定义
void printChar(char c, int num)
{
	if (num == 0)
	{
		return;
	}
	else {
		std::cout << c;
		printChar(c, num - 1);
	}
}
//有返回值无参数函数定义
char returnStar()
{
	return '*';
}
//主函数
void main()
{
	const char a = '_';
	int testarray[10], max, i, num, _no;
	char c;

	for (i = 0; i <= 999; i++)
	{
		fibarray[i] = - i;
	}
	//输出全局常数，确认常数定义的正确性
	printf("%c", _);							//<表达式> => <标识符>
	printf(" ");
	printf("%d", - fibarray[+ _zero]);			//<表达式> => [+|-]<标识符>'['[+|-]<标识符>']' 
	printf(" ");
	printf("%d", + fibarray[- - 9]);			//<表达式> => [+|-]<标识符>'['[+|-]<整数>']'
	printf(" ");
	printf("%d", fibarray['a']);				//<表达式> => [+|-]<标识符>'['[+|-]<字符>']'
	printf(" ");
	printf("%d", + (- ___num));					//<表达式> => [+|-]([+|-]<标识符>)		
	printf(" ");
	printf("%d", - (100));						//<表达式> => [+|-]([+|-]<整数>)
	printf(" ");
	printf("%d", - + 23);						//<表达式> => [+|-][+|-]<无符号整数>
	printf(" ");
	printf("%d", - 'a');						//<表达式> => [+|-]<字符>
	printf(" ");
	printf("%d", - _4fib(_4fib(_num)));			//<表达式> => [+|-]<标识符> '('( [+|-] (<标识符> '('<标识符>')')')'
	printf(" ");
												
	printf("%d", +(- 'a') * (+ 'b'));			//<表达式> => [+|-]([+|-]<字符>) * ([+|-]<字符>)
	printf(" ");
	printf("%d", _4fib(__num) / _4fib(6));		//<表达式> => [+|-](<标识符>'('<标识符>')') / (<标识符>'('<整数>')')
	printf(" ");
	printf("%d",_k1 * _k2);						//<表达式> => [+|-](<标识符>) * (<标识符>)
	printf(" ");
	printf("%d", _k1 / _k2);					//<表达式> => [+|-](<标识符>) / (<标识符>)
	printf(" ");

	printf("%d",+ (-'a') * (+'b') + _4fib(__num) / _4fib(6));
	printf(" ");
	printf("%d", _k1 * _k2 - _k1 / _k2);
	printf(" ");
	printf("%d",-_k2 + (_k3 + _k3));
	printf(" ");
	printf("%d", _k3 * (_k1 + fibarray[- - 9]));
	printf(" ");

	printf("%c", _k4);
	printf("%c", _k5);
	printf("%c", _k6);
	printf("%c", _k7);
	printf("%c", _k8);
	printf("%c", _k9);

	printf("  ");
	max = 3;
	i = max;

	while (i)
	{
		printStar();						//无返回值无参数的函数调用
		i = i - 1;
	}
	std::cout << "  ";

	std::cin >> num >> c;
	printChar(c, max);					//无返回值有参数的函数调用

	printf("  ");


	if (num < 2)
	{
		printf("num is less than 2!");
	}
	else {
		if (num > 45)
		{
			printf("num is more than 45!");
		}
		else {
			_4fib(num);					//有返回值有参数的函数调用语句
			printf("the fib array is : ");
			while (num >= 0) {
				std::cout << "no." << num;
				std::cout << " is " ;
				printf("%d", - - fibarray[num]);		//标识符[表达式]
				printf(" ");
				num = num - 1;
			}
		}
	}



	printf("  ");
	;
	returnStar();						//有返回值无参数的函数调用语句
	std::cout << returnStar();

	printf("  ");

	printf("please input a number from 0 to 4: ");
	std::cin >> num;
	switch (num)
	{
	case 0: printf("%d", 0); break;
	case 1: printf("%d", 1);  break;
	case 2: printf("%d", 2);  break;
	case 3: printf("%d", 3);  break;
	case 4: printf("%d", 4);  break;
	default: printf("out of range!");
	}

}*/

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
	Compiler *c = new Compiler("15061129_test.txt");
	c->begin();
}
