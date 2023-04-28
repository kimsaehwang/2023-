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
		printf("정수를 입력하시오 : ");
		scanf("%d", &num);

		sum = sum + num;
	} while (num);

	printf("정수의 합은 : %d\n", sum);

	sum = 0;
	num = 1;

	//while
	while (num)
	{
	    printf("정수를 입력하시오 : ");
	    scanf("%d", &num);

		sum = sum + num;
	}

	printf("정수의 합은 : %d\n", sum);

	sum = 0;
	num = 1;
	//for
	for ( ; num != 0 ; )
	{
		printf("정수를 입력하시오 : ");
		scanf("%d", &num);

		sum = sum + num;
	}

	printf("정수의 합은 : %d\n", sum);

	//양의 정수의 배수구하기
	/*
	int M;
	int N;
	int i;
	int multiply = 0;
	printf("양의 정수 2개 : ");
	scanf("%d %d", &M, &N);

	for (i = 1;i <= N;i++)
	{
		multiply = M * i;
        printf("%d\t", multiply);
	}
	if (M <= 0 || N <= 0)
	{
    printf("양의 정수가 아닙니다");
	}
	*/

	//두 정수사이의합
	/*
	int num1;
	int num2;
	int sum = 0;
	printf("두 수를입력 : ");
	scanf("%d %d", &num1, &num2);
	if (num1 > num2)
	{
		for (num2;num2 <= num1;num2++)
		{
			sum += num2;	
		}
        printf("합은 : %d", sum);
	}
	else if (num1 < num2)
	{
		for (num1;num1 <= num2;num1++)
		{
			sum += num1;	
		}
        printf("합은 : %d", sum);
	}
	else
	{
			printf("합은 : %d", num1);
	}
	*/

	/*
    //factorial계산
	int _result = 1;
	int n = 0;
	int i = 1;

	printf("정수 : ");
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
	//학점 출력 프로그램
	int kor, eng, mat, res;
	printf("국어, 영어, 수학의 점수 :");
	scanf("%d%d%d", &kor, &eng, &mat);
    res = (kor + eng + mat) / 3;
	if (res >= 90)
	{
		printf("평균이 %d 이므로 학점은 A 입니다", res);
	}
	else if (res >= 80)
	{
		printf("평균이 %d 이므로 학점은 B 입니다", res);
	}
	else if (res >= 70)
	{
		printf("평균이 %d 이므로 학점은 C 입니다", res);
	}
	else if (res >= 60)
	{
		printf("평균이 %d 이므로 학점은 D 입니다", res);
	}
	else
	{
			printf("평균이 %d 이므로 학점은 F 입니다", res);
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
	//두수 중 큰 수에서 작은 수 빼기
    //case1
	int a, b;
	printf("두 개의 정수를 입력하시오 :");
	scanf("%d %d", &a, &b);
	if (a > b)
	{
		printf("두 수의 차는 %d 입니다.", a - b);
	}
	else if (b > a)
	{
		printf("두 수의 차는 %d 입니다.", b - a);
	}
	else
	{
		printf("두 수의 차는 %d 입니다.", 0);
	}
	
	//case2
	int a, b, big, small;
	printf("두 개의 정수를 입력하시오 :");
	scanf("%d %d", &a, &b);

	big = (a > b) ? a : b;
	small = (a < b) ? a : b;
	printf("두 수의 차는 %d 입니다.", big - small);
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

	/*Q1)사용자로부터 정수 3개를 입력받아 각.a,b,c에 저장받고 조건연산자를 이용하여 
	이 변수들 중에 가장 큰 값을 출력하는 프로그램을 작성하라.
    
	int a=1, b=2, c=3, res, res1;
	printf("정수a : %d, 정수b :%d, 정수c : %d\n", a, b, c);
	res = (a > b) ? a : b;
	res1 = (res > c) ? res : c;
	printf("가장 큰 값 : %d\n", res1);
    */

	/*
	int a = 10, b = 20, res;

	res = (a > b) ? a : b; //더 큰값이 res에 저장
	printf("큰 값 : %d\n", res);
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
	printf("a / b의 결과 : %.1lf\n", res);

	a = (int)res;
	printf("(int) %.1lf의 결과 : %d\n", res, a);
	*/
return 0;
}
