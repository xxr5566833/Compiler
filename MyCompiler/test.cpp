#include "stdafx.h"

const char _char__ = '_', _char_lower_a = 'a', _char_lower_b = 'b', _char_lower_c = 'c', _char_lower_d = 'd';
const char _char_upper_A = 'A', _char_upper_B = 'B', _char_upper_C = 'C', _char_D = 'D';
const char _char_0 = '0', _char_1 = '1', _char_2 = '2', _char_3 = '3', _char_4 = '4', _char_5 = '5', _char_6 = '6', _char_7 = '7', _char_8 = '8', _char_9 = '9';
const char _char_plus = '+', _char_minus = '-', _char_mul = '*', _char_div = '/';

const int _int_0 = 0;
const int _int_1 = 1, _int_256 = 256, _int_34545 = 34545;
const int _int_minus400 = -400, _int_minus888 = -888, _int_minus1563 = -1563;
const int _int_plus567 = +567, _int_plus5 = +5, _int_plus1000 = +1000;
const int _int_temp = 77;
const int _int_i = 56;

char _array_char_a[1000], _array_char_c[1000], _simple_char_t;
int _simple_int_e, _array_int_fibarray[1000], _array_int_fibarray_temp[1000], _simple_int_num, _array_int_a[1000];


int _array_int_quicksort_[100], _simple_int_count;
int _simple_int_length;

int fib(int _simple_int_num)
{

	int _int_temp, fib1, fib2;
	int _array_int_fibarray_temp[50];
	if (- _simple_int_num < - (- (- _int_1)))
	{
		if (_array_int_fibarray[_simple_int_num - 1] <= -1)
		{
			fib1 = fib(_simple_int_num - 1);
		}
		else {
			fib1 = _array_int_fibarray[_simple_int_num - 1];
		}
		fib2 = _array_int_fibarray[_simple_int_num - 2];
		_int_temp = fib1 + fib2;
		_array_int_fibarray[_simple_int_num] = _int_temp;					
		return (_int_temp);
	}
	else {
		if (_simple_int_num * (_simple_int_num + _int_1) / (_simple_int_num + 1))
		{
			_array_int_fibarray[1] = 1;
			_array_int_fibarray_temp[1] = _int_1;
			return (_array_int_fibarray_temp[_array_int_fibarray[_array_int_fibarray_temp[_int_1]]] * (_array_int_fibarray[_array_int_fibarray_temp[1]]) + _int_0);
		}
		else {
			_array_int_fibarray[0] = 0;
			_array_int_fibarray_temp[0] = _int_0;
			return (_array_int_fibarray_temp[_array_int_fibarray[_int_0]] * (_array_int_fibarray[_array_int_fibarray_temp[0]]) + _int_0);
		}
	}
	{
		;
	}
}

void main1(){
	int _int_i;
	_int_i = 0;
	while(_int_i < 46)
	{
		_array_int_fibarray_temp[_int_i] = - 1;
		_array_int_fibarray[_int_i] = -1;
		_array_char_a[_int_i + _int_0 / _char_plus] = _char_0;
		_array_char_c[_int_i] = '0';
		_int_i = _int_i + 1 - _int_0;
	}
	_simple_int_num = 0;
	printf("please give me your max index in range from 2 to 45：");
	scanf("%d",&_simple_int_num);
	if (_simple_int_num < 2)
	{
		printf("num is less than 2!");
	}
	else {
		if (_simple_int_num > 45)
		{
			printf("num is more than 45!");
		}
		else {
			fib(_simple_int_num + fib(_int_0) - fib(_int_1) + fib(_int_1 + _int_1));
			while (_simple_int_num >= 0) {
				printf("%d", - (- _array_int_fibarray[_simple_int_num]));		
				printf(" ");
				if(_array_int_fibarray_temp[_simple_int_num] != -1)
				{
					printf("error");
				}
				_simple_int_num = _simple_int_num - _int_1;
			}
		}
	}
}

int printArray() {
    int A;
    A = 1;
    if(_simple_int_length >= 1){
        printf("%d", _array_int_quicksort_[0]);
    } else {
        return (-1);
    }
    while (A < _simple_int_length) {
		printf(",");
        printf("%d", _array_int_quicksort_[A]);
        A = A + 1;
    }
    return (0);
}

void quickSort(int head, int tail) {
    int a, b, tmp;
    if(head >= tail){
        return;
    }else {}
    a = head + 1;
    b = head;
    while(a <= tail) {
        if(_array_int_quicksort_[a] < _array_int_quicksort_[b]) {
            tmp = _array_int_quicksort_[a];
            _array_int_quicksort_[a] = _array_int_quicksort_[b];
            _array_int_quicksort_[b] = tmp;
            tmp = _array_int_quicksort_[a];
            _array_int_quicksort_[a] = _array_int_quicksort_[b + 1];
            _array_int_quicksort_[b + 1] = tmp;
            b = b + 1;
            _simple_int_count = _simple_int_count + 1;
        } else {;}
        a = a + 1;
    }
    quickSort(head, b - 1);
    quickSort(b + 1, tail);
    return;
}

int Return1()
{
	return (1);
}

int return999()
{
	return (999);
}

int returnminus998()
{
	return (-998);
}

void main2()
{
    int i;
    int return1;
    _simple_int_count = 0;
    i = 0;
    printf("this is a quick sort, input count of numbers in the first line:");
    scanf("%d", &_simple_int_length);
    if(_simple_int_length != 0) {
        _simple_int_length = (_simple_int_length + _simple_int_length * _simple_int_length) / _simple_int_length - 1;
    } else{;}
    printf("input your raw array, split numbers with space:");
    while (i < _simple_int_length) {
        scanf("%d", &return1);
        _array_int_quicksort_[i] = return1;
        i = i + 1;
    }
    switch (_simple_int_length) {
        case 0: printArray();
        case 1: printArray();
        default: {
            if (_simple_int_length < 0) {
                printf("invalid length!");
                return;
            }else {
                quickSort(0, _simple_int_length - 1);
                printArray();
            }
        }
    }
    printf("exchange time of numbers: %d", _simple_int_count);
    return;
}

char returna()
{
	return (_char_lower_a );
}

char returnplus()
{
	return ('+');
}

char returnStar()
{											
	return ('*');												
}

char returnChar(char c)
{
	return (c);
}

void main3()
{
	int i;
	i = 0;
	while(i < 45)
	{
		_array_char_a[i] = 'a';
		_array_int_a[i] = 100;
		_array_int_fibarray[i] = -1;
		i = i + 1;
	}

	i = 0;
	printf(" ");
	printf("%c", _char__);							
	_simple_char_t = _char_upper_A;
	printf(" ");
	printf("%c", _simple_char_t);
	printf(" ");
	printf("%c", '+');
	printf(" ");
	printf("%c", _array_char_a[_int_1]);
	printf(" ");

	printf("%c", returnChar(_array_char_a[_int_plus5]));
	printf(" ");

	printf("%c", returna());
	printf(" ");


	printf("%d", _int_34545);
	printf(" ");

	printf("%d", _int_minus400);
	printf(" ");

	printf("%d", _int_minus1563);
	printf(" ");

	printf("%d", _int_plus1000);
	printf(" ");

	printf("%d", 0);
	printf(" ");

	printf("%d", -888);
	printf(" ");

	printf("%d", +456);
	printf(" ");

	printf("%d", _array_int_a[20]);
	printf(" ");

	printf("%d", _array_int_a[_int_1]);
	printf(" ");

	printf("%d", fib(0));
	printf(" ");

	printf("%d", fib(_int_1));
	printf(" ");

	printf("%d", fib(_int_plus5));
	printf(" ");

	printf("%d", (100));
	printf(" ");

	printf("%d", (((_array_int_a[20]))));
	printf(" ");

	printf("%d", (fib(_int_plus5)));
	printf(" ");


	printf("%d", _char__ * _simple_char_t);
	printf(" ");

	printf("%d", '+' / _array_char_a[_int_1]);
	printf(" ");

	printf("%d", _array_char_a[_int_1] / _int_minus400);
	printf(" ");

	printf("%d", returnChar('/') * fib(_int_1));
	printf(" ");

	printf("%d", _int_minus400 * -888);
	printf(" ");

	printf("%d", _int_plus1000 / fib(_int_plus5));
	printf(" ");

	printf("%d", _char__ / _simple_char_t * fib(_int_1));
	printf(" ");

	printf("%d", _int_minus400 * -888 * fib(_int_0));
	printf(" ");

	printf("%d", _int_minus400 * -888 / _simple_char_t);
	printf(" ");

	printf("%d", returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5]));
	printf(" ");

	printf("%d", (_int_minus400 * -888 / _simple_char_t) / (_int_minus400 * -888) * ((((_array_int_a[20])))));
	printf(" ");

	printf("%d", _char__ * (returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5])));
	printf(" ");

	printf("%d", fib(fib(fib(6)) - fib(_int_plus5) ));
	printf(" ");

	printf("%d", _array_int_a[fib(_array_int_a[fib(fib(fib(_int_0)))] - _array_int_a[fib(fib(_array_int_a[0] / _array_int_a[0]))])]);
	printf(" ");


	printf("%d", + -888);
	printf(" ");

	printf("%d", - returna());
	printf(" ");

	printf("%d", - _array_int_a[fib(_array_int_a[fib(fib(fib(_int_0)))] - _array_int_a[fib(fib(_array_int_a[0] / _array_int_a[0]))])] + (_int_minus400 * -888 / _simple_char_t) / (_int_minus400 * -888) * ((((_array_int_a[20])))));
	printf(" ");

	printf("%d", + _array_int_a[fib(_array_int_a[fib(fib(fib(_int_0)))] - _array_int_a[fib(fib(_array_int_a[0] / _array_int_a[0]))])] - _char__ * (returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5])));
	printf(" ");

	printf("%d", + (+ _array_int_a[fib(_array_int_a[fib(fib(fib(_int_0)))] - _array_int_a[fib(fib(_array_int_a[0] / _array_int_a[0]))])] - _char__ * (returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5])))
			 - (- fib(fib(fib(6)) - fib(_int_plus5) )) + _int_minus400 * -888 * fib(_int_0));
	printf(" ");

	printf("%d", fib(_int_plus1000 / fib(_int_plus5) - 200 + (+ (+ _array_int_a[fib(_array_int_a[fib(fib(fib(_int_0)))] - _array_int_a[fib(fib(_array_int_a[0] / _array_int_a[0]))])] - _char__ * (returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5])))
			 - (- fib(fib(fib(6)) - fib(_int_plus5) )) + _int_minus400 * -888 * fib(_int_0)) / (- (+ _array_int_a[fib(_array_int_a[fib(fib(fib(_int_0)))] - _array_int_a[fib(fib(_array_int_a[0] / _array_int_a[0]))])] - _char__ * (returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5]) * returnChar(_array_char_a[_int_plus5])))
			 - (- fib(fib(fib(6)) - fib(_int_plus5) )) + _int_minus400 * -888 * fib(_int_0))));





}

/*void main()
{
	char choose;
	printf("give me your choice，a is Fibonacci，b is quicksort，c is expressions print：");
	scanf("%c", &choose);
	switch(choose)
	{
	case 'a' : main1(); break;
	case 'b' : main2(); break;
	case 'c' : main3(); break;
	default: printf("out of range");
	}
	return;


}*/

//程序部分开始
/*const char _ = '_', p_ = '+', m__ = '-', s0 = '*', d_0 = '/', a0a = 'a', _00 = '0'; 	//7种代表的标识符全了
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
	printf("*");
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
	i = max;
	;										while(i != 0)											
	{
		returnStar();								
		std::cout << returnStar();							 
		i = i - 1;
	}

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