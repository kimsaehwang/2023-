#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	//2차원 배열 가로세로합
	/*
	int i, j;
	int matrix[5][6] = { {1,2,3,4,5},
						{6,7,8,9,10},
						{11,12,13,14,15},
						{16,17,18,19,20} };

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			matrix[i][5] += matrix[i][j];
			matrix[4][j] += matrix[i][j];
			matrix[4][5] += matrix[i][j];
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/

	//Q2 2차원 배열 달팽이
	/*
	int matrix[50][50];
	int n, m;

	printf("행과열 입력 : ");
	scanf("%d%d", &n, &m);

	int i = 0, j = 0, max = 1;

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			matrix[i][j] = 0;
		}
	}

	i = 0;
	j = 0;
	matrix[i][j] = 1;
	max = 2;

	while (max <= n * m)
	{
		while (j + 1 < m && matrix[i][j + 1] == 0)
		{
			j++;
			matrix[i][j] = max;
			max++;
		}
		while (i + 1 < n && matrix[i + 1][j] == 0)
		{
			i++;
			matrix[i][j] = max;
			max++;
		}
		while (j - 1 >= 0 && matrix[i][j - 1] == 0)
		{
			j--;
			matrix[i][j] = max;
			max++;
		}
		while (i - 1 >= 0 && matrix[i - 1][j] == 0)
		{
			i--;
			matrix[i][j] = max;
			max++;
		}
	}

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}
}
*/

	//여러개의 1차원배열을 2차원배열로
	/*
	int ary1[4] = { 1,2,3,4 };
	int ary2[4] = { 11,12,13,14 };
	int ary3[4] = { 21,22,23,24 };
	int* pary[3] = { ary1,ary2,ary3 };
	int i, j;

	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 4;j++)
		{
			printf("%5d", pary[i][j]);
		}
		printf("\n");
	}
	return 0;
	}
	*/

	//포인터 배열
	/*
	char* pary[5];
	int i;

	pary[0] = "dog";
	pary[1] = "elephatnt";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion";

	for (i = 0;i < 5;i++)
	{
		printf("%s\n", pary[i]);
	}
	return 0;
	}
	*/

	//Q1 행렬 프로그램 작성
	/*int i, j, m, n;
	int matrix[5][5];

	printf("행입력 : ");
	scanf("%d", &m);
	printf("열입력 : ");
	scanf("%d", &n);

	for (i = 0;i < m;i++)
	{
		printf("행 입력 : ");
		for (j = 0;j < n;j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\n");

	for (i = 0;i < n;i++)
	{
		for (j = m - 1;j >= 0;j--)
		{
			printf("%d", matrix[j][i]);
		}
		printf("\n");
	}
	}*/

	//3차원 배열 2반의 3명의 4과목점수
	/*
	int score[2][3][4] = {
		{{72,80,95,60},{68,98,83,90},{75,72,84,90}},
		{{66,85,90,88},{95,92,88,95},{43,72,56,75}} };

	int i, j, k;

	for (i = 0;i < 2;i++)
	{
		printf("%d반 점수...\n", i + 1);
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 4 ; k++)
			{
				printf("%5d", score[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
	}*/

	//char 배열 ex
	/*
	char animal[5][20];
	int i;
	int count;

	count = sizeof(animal) / sizeof(animal[0]);
	for (i = 0;i < count;i++)
	{
		scanf("%s", animal[i]);
	}

	for (i = 0;i < count;i++)
	{
		printf("%s", animal[i]);
	}
	return 0;
	}
	*/

	//학생3명의 4과목 총점,평균
	/*
	int score[3][4];
	int total;
	double avg;
	int i, j;

	for (i = 0;i < 3;i++)
	{
		printf("4과목의 점수 입력 : ");
		for (j = 0;j < 4;j++)
		{
			scanf("%d", &score[i][j]);
		}
	}

	for (i = 0;i < 3;i++)
	{
		total = 0;
		for (j = 0;j < 4;j++)
		{
			total += score[i][j];
		}
		avg = total / 4.0;
		printf("총점 : %d, 평균 : %.2lf\n", total, avg);
	}
	return 0;
	*/