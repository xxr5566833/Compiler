#include "stdafx.h"
#include "Compiler.h"

const int MAX_NUM = 1024;

void complete_num()

{

  int k[1024];

  int i,j,n,s,x1;

  int m,k2,h,leap,x2;


  for(j=2;j< MAX_NUM ;j=j+1)

  {

    n = -1;

    s = j;

    for(i=1; i<j; i=i+1)

    {

      x1 = (j/i) * i ;

      if( x1 == j )

      {

        n = n + 1;

        s = s - i;

	if (n >= 1024)

		printf("OVERFLOW! ") ;

        else

		k[n] = i;

      }

    }


    if(s==0)

    {

      printf("complete number: %d",j);

      for(i=0;i<=n;i=i+1)

      	printf("  %d",k[i]);

      printf("  ") ;

    }


  }




  printf("---------------------------------------------------------------\n");

  h = 0 ;

  leap = 1 ;

  for(m = 2 ; m <= MAX_NUM ; m=m+1)

  {

    k2 = m - 1;

    for(i=2; i<=k2; i=i+1){

      x2 = (m/i)*i ;

      if( x2 == m)

      {

        leap=0;

      }

     }

    if(leap == 1)

    {

      printf(" %d",m);

      h = h +1;


      x2 = (h/10)*10 ;

      if( x2 == h)

        printf("  ");

     }

     leap=1;

  }


  printf("The total is %d",h);


}



int main(int argc, char *argv[])
{

	char path[50];
	std::cout << "请输入文件路径 :" << std::endl;
	std::cin >> path;
	Compiler *c = new Compiler(path);
	c->begin();

}
