// main.cpp: �������̨Ӧ�ó������ڵ㡣
//
#include "Compiler.h"
#include "stdafx.h"
/*//���򲿷ֿ�ʼ
const char _ = '_', p_ = '+', m__ = '-', s0 = '*', d_0 = '/', a0a = 'a', _00 = '0'; 	//7�ִ���ı�ʶ��ȫ��
const int _zero = 0, _num = 4, _pnum = +3, _mnum = -9;
const int __num = 20, __pnum = +56, __mnum = -78;
const int ___num = 5783, ___pnum = +326, ___mnum = -111;								//
//����˵��
const int _k1 = 0, _k2 = +100, _k3 = -1000;
const char _k4 = 'a', _k5 = '_', _k6 = 'A', _k7 = '-', _k8 = '*', _k9 = '0';
//����˵��
int v1, fibarray[1000];
char c1, arrayc[1000];
//��������
//�з���ֵ��������,�з���ֵ�ĺ����ݹ���ã�
//����ͷ�� int
//(����)
//�������
// (����)ʵ���˱��ʽ��Ϊ�ж�����
//ѭ�����
// (����)ʵ���˱��ʽ + ��ϵ����� + ���ʽ��Ϊ�ж�����
//����л�ʵ����
//�������
//�ڸ�ֵ��� ��ʵ����<��ʶ��> = <���ʽ>
//��д�����������
//
//�ݷ������
//������ʵ���˱�ʶ��

//�з���ֵ�в�����������
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
		fibarray[num] = temp;					//���ָ�ֵ���
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
//�޷���ֵ�޲����ĺ�������
void printStar()
{
	std::cout << "*";
	return;
}
//�޷���ֵ�в����ĺ�������
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
//�з���ֵ�޲�����������
char returnStar()
{
	return '*';
}
//������
void main()
{
	const char a = '_';
	int testarray[10], max, i, num, _no;
	char c;

	for (i = 0; i <= 999; i++)
	{
		fibarray[i] = - i;
	}
	//���ȫ�ֳ�����ȷ�ϳ����������ȷ��
	printf("%c", _);							//<���ʽ> => <��ʶ��>
	printf(" ");
	printf("%d", - fibarray[+ _zero]);			//<���ʽ> => [+|-]<��ʶ��>'['[+|-]<��ʶ��>']' 
	printf(" ");
	printf("%d", + fibarray[- - 9]);			//<���ʽ> => [+|-]<��ʶ��>'['[+|-]<����>']'
	printf(" ");
	printf("%d", fibarray['a']);				//<���ʽ> => [+|-]<��ʶ��>'['[+|-]<�ַ�>']'
	printf(" ");
	printf("%d", + (- ___num));					//<���ʽ> => [+|-]([+|-]<��ʶ��>)		
	printf(" ");
	printf("%d", - (100));						//<���ʽ> => [+|-]([+|-]<����>)
	printf(" ");
	printf("%d", - + 23);						//<���ʽ> => [+|-][+|-]<�޷�������>
	printf(" ");
	printf("%d", - 'a');						//<���ʽ> => [+|-]<�ַ�>
	printf(" ");
	printf("%d", - _4fib(_4fib(_num)));			//<���ʽ> => [+|-]<��ʶ��> '('( [+|-] (<��ʶ��> '('<��ʶ��>')')')'
	printf(" ");
												
	printf("%d", +(- 'a') * (+ 'b'));			//<���ʽ> => [+|-]([+|-]<�ַ�>) * ([+|-]<�ַ�>)
	printf(" ");
	printf("%d", _4fib(__num) / _4fib(6));		//<���ʽ> => [+|-](<��ʶ��>'('<��ʶ��>')') / (<��ʶ��>'('<����>')')
	printf(" ");
	printf("%d",_k1 * _k2);						//<���ʽ> => [+|-](<��ʶ��>) * (<��ʶ��>)
	printf(" ");
	printf("%d", _k1 / _k2);					//<���ʽ> => [+|-](<��ʶ��>) / (<��ʶ��>)
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
		printStar();						//�޷���ֵ�޲����ĺ�������
		i = i - 1;
	}
	std::cout << "  ";

	std::cin >> num >> c;
	printChar(c, max);					//�޷���ֵ�в����ĺ�������

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
			_4fib(num);					//�з���ֵ�в����ĺ����������
			printf("the fib array is : ");
			while (num >= 0) {
				std::cout << "no." << num;
				std::cout << " is " ;
				printf("%d", - - fibarray[num]);		//��ʶ��[���ʽ]
				printf(" ");
				num = num - 1;
			}
		}
	}



	printf("  ");
	;
	returnStar();						//�з���ֵ�޲����ĺ����������
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
