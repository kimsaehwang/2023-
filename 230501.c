#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	
	//������ (2��~18��)
	/*
	int n;
	int k = 2;
	printf("���ϴ� ���� �Է��Ͻÿ� : ");
	scanf("%d",&n);
	printf("-------------------������-------------------\n");
	printf("--------------------------------------------\n");

	
	while (1)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int j = k; j < k + 3; j++)
			{
				printf("%d * %d = %d \t", j, i, i * j);
				if (j>= n)
				{
					break;
				}
			}
			printf("\n");
		}
		printf("--------------------------------------------\n");
		k += 3;

		if (n < k)
		{
			break;
		}
	}
	return 0;
}
	*/

	/*
	//�����4
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


	/*�����3
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


	/*�����2
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
	//�����1
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
	//�μ��� ���
	int m;
	int n;
	
	printf("�� ������ �Է� : ");
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