#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int input_data(void);
double average(void);
void print_data(double);

int count = 0;
static int total = 0;

int main(void)
{

	//extern과 static 사용하기 (average.c , inout.c)
	/*double avg;

	total = input_data();
	avg = average();
	print_data(avg);

	return 0;
}

void print_data(double avg)
{
	printf("입력한 양수의 개수 : %d\n", count);
	printf("전체 합과 평균 : %d, %.1lf\n", total, avg);
}*/

	//#과##을 사용한 매크로함수
	/*int a1, a2;

	NAME_CAT(a, 1) = 10;
	NAME_CAT(a, 2) = 20;
	PRINT_EXPR(a1 + a2);
	PRINT_EXPR(a2 - a1);

	return 0;
}*/

	//이미 정의된 매크로의 정의
	/*printf("컴파일 날짜와 시간 : %s,%s\n\n", __DATE__, __TIME__);
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);

#line 100 "macro.c"
	func();

	return 0;
}

void func(void)
{
	printf("\n");
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);
}*/