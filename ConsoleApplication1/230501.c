#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	/*
	//구구단 (2단~18단)
	int n;
	int i;
	int	j;
	int line;
	printf("원하는 단을 입력하시오 : ");
    scanf("%d", &n);
	printf("줄을 정하세요 : ");
	scanf("%d", &line);
	printf("--------------------구구단----------------------\n");
	printf("------------------------------------------------\n");


	for (i = 2;i < n;i++)
	{
		for (j = 1;j <= 9;j++)
		{
			printf("%d * %d = %d ", i, j, i * j);
			if (line + 1 > 0)
			{
				printf("\t");
			}
			else
			{
				printf("\n");
			}
       printf("\n");
		}
      
	   printf("------------------------------------------------\n");

	}
	return 0;
	*/

	/*
	//별찍기4
	int n;
	scanf("%d", &n);

	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			if (i == j || i + j == n - 1 || j > i && j + i >= n-1 || j < i && j + i < n)
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	*/


	/*별찍기3
	int n;
	scanf("%d", &n);

	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			if (i == j || i + j == n-1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	*/


	/*별찍기2
	for (int i = 0; i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (i < n-j-1)
			{
				printf(" ");
			}
			else 
			{ 
			    printf("*");
			}
				
		}
		printf("\n");
	}
    */


	/*
	//별찍기1
	int n;
	scanf("%d", &n);
	
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
	*/


	/*
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);
		}
	}
	*/

	/*
	//두수의 배수
	int m;
	int n;
	
	printf("두 정수를 입력 : ");
	scanf("%d %d", &m, &n);

    for (int i=1;i <= 100;i++)
	{
		if (i % m ==0 || i % n ==0)
		{
			printf("%d ", i);
		}

	}
	*/
    
}