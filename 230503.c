#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int inputfunc(int num);
//int inputfunc2(int X);
//int sum_func(int n);
//int fac_func(int m);
//int abs(int num);
//int prime;

//int sum(int x, int y);
//int minus(int x, int y);
//int multiply(int x, int y);
//int division(int x, int y);

int main()
{
	int month;
	int adult = 0, child = 1, sum ;
	printf("몇 개월이 지났나요 : ");
	scanf("%d개월\n", &month);

	for (int i = 0;i <= month+1;++i)
	{
			printf("%d 마리 입니다.\n", adult);
			sum = adult + child;
			adult = child;
			child = sum;
	}
	
	return 0;
}
	/*
	int n, m;
	int a = 1 ;
	while (1) {
		printf("원하는 연산을 선택하시오(1.덧셈 2.뺄셈 3.곱셈 4.나눗셈 0.종료) : ");
		scanf("%d", &a);
		if (a == 0)
		{
			printf("종료합니다.");
			break;
		}
		else if(a > 4 || a < 0)
		{
			printf("1,2,3,4,0만 입력 해주세요.\n");
			continue;
		}

		printf("두 정수를 입력하시오 : ");
		scanf("%d %d", &n, &m);
		switch(a == 1)
		{
		case 1:
			a = n + m;
			break;
		case 2:
			a = n - m;
			break;
		case 3:
			a = n * m;
			break;
		case 4:
			a = n / m;
			break;
		case 0:
			break;
		}
		printf("%d\n", a);


		/*-----------------------------------------
		if (a == 1)
		{
			printf("%d\n", sum(n, m));
		}
		else if (a == 2)
		{
			printf("%d\n", minus(n, m));
		}
		else if (a == 3)
		{
			printf("%d\n", multiply(n, m));
		}
		else if (a == 4)
		{
			printf("%d\n", division(n, m));
		}
		
	}
	return 0;
}

int sum(int x, int y)
{
	return x + y;
}
int minus(int x, int y)
{
	return x - y;
}
int multiply(int x, int y)
{
	return x * y;
}
int division(int x, int y)
{
	return x / y;
}
*/
	/*
	int n;

	printf("정수를 입력하시오 : ");
	scanf("%d", &n);
	printf("합 : %d\n", sum_func(n));
	printf("곱 : %d\n", fac_func(n));
	return 0;
}

int sum_func(int n)
{
	if (n == 1) return n;
	return n + sum_func(n - 1);
}

int fac_func(int n)
{
	if (n == 1) return n;
	n *= fac_func(n - 1);
	return n;
}
	*/


	/*
	int num;
	printf("정수 입력 :");
	scanf("%d", &num);
	printf("절댓값은 : %d",abs(num));

	if (num == 0)
	{
		printf("종료합니다");
	}
	return 0;
	*/


	/*
	int prime2;
	prime = 1;
	prime = inputfunc(prime);
	prime = inputfunc2(prime);
	outputfunc(prime);
	return 0;
}
int inputfunc(int x)
{
	printf("2 이상의 정수를 입력하시오 : ");
	scanf("%d", &prime);
	return prime - 1;
}
int inputfunc2(int X)
{
	printf("2 이상의 정수를 입력하시오 : ");
	scanf("%d", &X);
	return X - 2;
}
void outputfunc()
{
	int i, j;
	int countnum;
	countnum = inputfunc2(countnum);
	for (i = 1;i <= prime;i++)
	{
		for (j = 2;j < i;j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%5d ", i);
			countnum++;
			if (countnum == 5)
			{
				printf("\n");
				countnum = 0;
			}
		}
	}
	return 0;

}
	
	*/


	/*
	//합이n값인 두 수구하기
	int a, n, z;
	printf("n을 입력하시오 : ");
	scanf("%d", &n);

	for (int i = 1;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			if (i + j == n)
			{
				printf("a = %d z = %d\n", i, j);
			}
		}
	}
	*/


	/*
	//소수 출력 프로그램
	int prime = 0;
	int countnum = 0;
	int count = 0;
	int i,j;
	printf("2 이상의 정수를 입력하시오 : ");
	scanf("%d", &prime);


	for (i = 1;i <= prime;i++)
	{
		for (j = 2;j < i;j++)
		{
			if (i % j == 0) 
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%5d ", i);
			countnum++;
			if (countnum == 5)
			{
				printf("\n");
				countnum = 0;
			}
		}	
	}
	return 0;
	*/

