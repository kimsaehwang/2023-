#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int num;
	int sum = 0;

	//do~while
	do
	{
		printf("������ �Է��Ͻÿ� : ");
		scanf("%d", &num);

		sum = sum + num;
	} while (num);

	printf("������ ���� : %d\n", sum);

	sum = 0;
	num = 1;

	//while
	while (num)
	{
	    printf("������ �Է��Ͻÿ� : ");
	    scanf("%d", &num);

		sum = sum + num;
	}

	printf("������ ���� : %d\n", sum);

	sum = 0;
	num = 1;
	//for
	for ( ; num != 0 ; )
	{
		printf("������ �Է��Ͻÿ� : ");
		scanf("%d", &num);

		sum = sum + num;
	}

	printf("������ ���� : %d\n", sum);

	//���� ������ ������ϱ�
	/*
	int M;
	int N;
	int i;
	int multiply = 0;
	printf("���� ���� 2�� : ");
	scanf("%d %d", &M, &N);

	for (i = 1;i <= N;i++)
	{
		multiply = M * i;
        printf("%d\t", multiply);
	}
	if (M <= 0 || N <= 0)
	{
    printf("���� ������ �ƴմϴ�");
	}
	*/

	//�� ������������
	/*
	int num1;
	int num2;
	int sum = 0;
	printf("�� �����Է� : ");
	scanf("%d %d", &num1, &num2);
	if (num1 > num2)
	{
		for (num2;num2 <= num1;num2++)
		{
			sum += num2;	
		}
        printf("���� : %d", sum);
	}
	else if (num1 < num2)
	{
		for (num1;num1 <= num2;num1++)
		{
			sum += num1;	
		}
        printf("���� : %d", sum);
	}
	else
	{
			printf("���� : %d", num1);
	}
	*/

	/*
    //factorial���
	int _result = 1;
	int n = 0;
	int i = 1;

	printf("���� : ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		_result *= i;
		
	}
	if (!n)
	{
		_result = 0;
	}
    printf("%d !-> %d", n, _result);

	/*
	int a ;

	for (a=1;a<10;a *= 2)
	{
		printf("a : %d\n", a);
	}
	*/

	/*
	//���� ��� ���α׷�
	int kor, eng, mat, res;
	printf("����, ����, ������ ���� :");
	scanf("%d%d%d", &kor, &eng, &mat);
    res = (kor + eng + mat) / 3;
	if (res >= 90)
	{
		printf("����� %d �̹Ƿ� ������ A �Դϴ�", res);
	}
	else if (res >= 80)
	{
		printf("����� %d �̹Ƿ� ������ B �Դϴ�", res);
	}
	else if (res >= 70)
	{
		printf("����� %d �̹Ƿ� ������ C �Դϴ�", res);
	}
	else if (res >= 60)
	{
		printf("����� %d �̹Ƿ� ������ D �Դϴ�", res);
	}
	else
	{
			printf("����� %d �̹Ƿ� ������ F �Դϴ�", res);
	}
	*/

	/*
	int rank = 2,m = 0;

	switch (rank)
	{
	case 1:
		m = 300;
		break;
	case 2:
		m = 200;
		break;
	case 3:
		m = 100;
		break;
	default:
		m = 10;
		break;
	}
	printf("m : %d\n", m);
	*/

	/*
	//�μ� �� ū ������ ���� �� ����
    //case1
	int a, b;
	printf("�� ���� ������ �Է��Ͻÿ� :");
	scanf("%d %d", &a, &b);
	if (a > b)
	{
		printf("�� ���� ���� %d �Դϴ�.", a - b);
	}
	else if (b > a)
	{
		printf("�� ���� ���� %d �Դϴ�.", b - a);
	}
	else
	{
		printf("�� ���� ���� %d �Դϴ�.", 0);
	}
	
	//case2
	int a, b, big, small;
	printf("�� ���� ������ �Է��Ͻÿ� :");
	scanf("%d %d", &a, &b);

	big = (a > b) ? a : b;
	small = (a < b) ? a : b;
	printf("�� ���� ���� %d �Դϴ�.", big - small);
    */

	/*
	int a = 0, b = 0;

	if (a > 0)
	{
		b = 1;
	}
	else if (a == 0)
	{
		b = 2;
	}
	else
	{
		b = 3;
	}

	printf("b : %d\n", b);
	*/

	/*
	int a = 10;

	if (a >= 0)
	{
		a = 1;
	}
	else
	{
		a = -1;
	}
	printf("a : %d\n", a);
	*/

	/*
	int a = 20;
	int b = 0;

	if (a > 10)
	{
		b = a;
	}
	printf("a : %d, b: %d \n", a, b);
	*/

	/*
	int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a ^ b);
	printf("a | b : %d\n", a | b);
	printf("~a : %d\n", ~a);
	printf("a << 1 : %d\n", a << 1);
	printf("a >> 2 : %d\n", a >> 2);
	*/

	/*Q1)����ڷκ��� ���� 3���� �Է¹޾� ��.a,b,c�� ����ް� ���ǿ����ڸ� �̿��Ͽ� 
	�� ������ �߿� ���� ū ���� ����ϴ� ���α׷��� �ۼ��϶�.
    
	int a=1, b=2, c=3, res, res1;
	printf("����a : %d, ����b :%d, ����c : %d\n", a, b, c);
	res = (a > b) ? a : b;
	res1 = (res > c) ? res : c;
	printf("���� ū �� : %d\n", res1);
    */

	/*
	int a = 10, b = 20, res;

	res = (a > b) ? a : b; //�� ū���� res�� ����
	printf("ū �� : %d\n", res);
	*/

	/*
	int a = 10, b = 20;
	int res = 2;

	a += 20;
	res *= (b + 10);

	printf("a = %d, b = %d\n", a, b);
	printf("res = %d\n", res);
	*/

	/*
	int a = 20, b = 3;
	double res;

	res = ((double)a / (double)b);
	printf("a = %d, b = %d\n", a, b);
	printf("a / b�� ��� : %.1lf\n", res);

	a = (int)res;
	printf("(int) %.1lf�� ��� : %d\n", res, a);
	*/
return 0;
}
