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
	printf("�� ������ �������� : ");
	scanf("%d����\n", &month);

	for (int i = 0;i <= month+1;++i)
	{
			printf("%d ���� �Դϴ�.\n", adult);
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
		printf("���ϴ� ������ �����Ͻÿ�(1.���� 2.���� 3.���� 4.������ 0.����) : ");
		scanf("%d", &a);
		if (a == 0)
		{
			printf("�����մϴ�.");
			break;
		}
		else if(a > 4 || a < 0)
		{
			printf("1,2,3,4,0�� �Է� ���ּ���.\n");
			continue;
		}

		printf("�� ������ �Է��Ͻÿ� : ");
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

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &n);
	printf("�� : %d\n", sum_func(n));
	printf("�� : %d\n", fac_func(n));
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
	printf("���� �Է� :");
	scanf("%d", &num);
	printf("������ : %d",abs(num));

	if (num == 0)
	{
		printf("�����մϴ�");
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
	printf("2 �̻��� ������ �Է��Ͻÿ� : ");
	scanf("%d", &prime);
	return prime - 1;
}
int inputfunc2(int X)
{
	printf("2 �̻��� ������ �Է��Ͻÿ� : ");
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
	//����n���� �� �����ϱ�
	int a, n, z;
	printf("n�� �Է��Ͻÿ� : ");
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
	//�Ҽ� ��� ���α׷�
	int prime = 0;
	int countnum = 0;
	int count = 0;
	int i,j;
	printf("2 �̻��� ������ �Է��Ͻÿ� : ");
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

