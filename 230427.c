#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int M = 0, N = 0;
	printf("몇년동안 담배 폈나요? ");
	scanf("%d", &N);
	printf("하루에 몇개피 담배를 폈나요? ");
	scanf("%d", &M);

	int nminute = 220 * (N * M * 365);//줄어든 시간(분)
	int nhour = nminute / 60;
	int nday = nhour / 24;
	int nyear = nday / 365;

	int day1 = nday % 365;
	int hour1 = nhour % 24;
	int minute1 = nminute % 60;

	printf("줄어든 수명 : %d년 %d일 %d시 %d분\n", nyear, day1, hour1, minute1);

	int Nminute = (100 * 365 * 24 * 60) - (220 * (N * M * 365));//기대 수명(분)
	int Nhour = Nminute / 60;
	int Nday = Nhour / 24;
	int Nyear = Nday / 365;

	int day2 = Nday % 365;
	int hour2 = Nhour % 24;
	int minute2 = Nminute % 60;

	printf("기대 수명 : %d살 %d일 %d시 %d분", Nyear, day2, hour2, minute2);
	return 0;
}
	/*
	int a, b, tot;
	double avg;

	printf("두 과목의 점수 : ");
	scanf("%d%d", &a, &b);
	tot = a + b;
	avg = tot / 2.0;

	printf("평균 : %.1f\n", avg);
	return 0;
	*/

	/*
	double a = 4.0, b = 1.2;

	printf("%.1f + %.1f = %.1lf \n",a, b, a + b);
	printf("%.1f - %.1f = %.1lf \n", a, b, a - b);
	printf("%.1f * %.1f = %.1lf \n", a, b, a * b);
	printf("%.1f / %.1f = %.1lf \n", a, b, a / b);
	return 0;
	*/

	/*
	int a = 5, b = 2;
	printf("%d\n", a != b);

	return 0;

	*/

	/*
	int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("초깃값 a=%d,b=%d\n", a, b);
	printf("전위형: (++a) * 3 = %d,후위형: (b++) * 3 = %d\n", pre, post);

	return 0;
	*/

	/*
	int a = 5;
	int b = 2;
	//a=a+1;
	printf("%d\n", ++a);
	printf("%d\n", a);
	return 0;
	*/

	/*
	double d5 = 5.0;
	double d2 = 2.0;
	int    i5 = 5;
	int    i2 = 2;

	int a = d5 / i2;
	int b = i5 / d2;

	printf("%d %d\n", a, b);
	printf("%f %f\n", a, b);

	double a2 = 5.0 / 2;
	double b2 = 5 / 2.0;

	printf("%f %f\n", a2, b2);
	printf("%d %d\n", a2, b2);
	*/
	
	/*몫과나머지 구하는법
	double apple;
	int banana;
	int orange;

	apple = 5.0 / 2;
	banana = 5 / 2.0;
	orange = 5 % 2;

	printf("apple : %.1lf\n",apple);
	printf("banana : %d\n",banana);
	printf("orange : %d\n",orange);

	return 0;
	*/

	/* 학점
	char grade;
	char name[20];

	printf("학점 입력 :");
	scanf("%c", &grade);
	printf("이름 입력 : ");
	scanf("%s", name);
	printf("%s의 학점은 %c입니다.\n", name, grade);

	return 0;
	*/

/* 나이,키
	int age;
	double height;
	printf("나이와 키를 입력하시오 :");
	scanf("%d%lf", &age, &height);
	printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age,height);
	*/

	/*
	char name[128];
	scanf("%s", name);
	//printf("ret value :%d\n", ret);
	return 0;
	*/

	/* 세수의합
	int kor = 70;
	int eng = 80;
	int mat = 90;
	int tot;
	tot = kor + eng + mat;
	printf("국어 : %d,영어 : %d,수학 : %d\n", kor, eng, mat);
	printf("총점 : %d", tot);
	return 0;
	*/

	/*
	char  alphabet=0; //0~255
	int   year=0, month=0;
	int age = 0;
	float   pi=0.0f;
	double  doublepI=0.0;
	doublepI = 3.14f;

	char a;
	a = 'A';
	const double  tax_rate = 0.12;//세율 초기화

	int i;
	int My_Student_Number;

	char name[128];
	int nNunber = 0;
	int NNunber = 0;//위와다름
	int iNumber = 0;
	char cA = 'c';
	char strName[128];
	char sName[128];
	float fNumber = 0.0f;
	double dNumber = 0.0;



		dNumber = 0.11111111;
	    fNumber = 0.1234f;
/*
	strcpy(name, "hong");//strcpy_s(name, 128, "hong");
	printf("%s \n",name);


	
	year = 2023;
	pi = 3.14f;
	month = 4;
	year = month;

	short sh = 61000;
	printf("%d\n", sizeof(sh));

	float ft = 1.234567890123456789f;
	double db = 1.234567890123456789;

	printf("float형 변수의값 : %.20f\n", ft);//9번째부터 다름
	printf("double형 변수의값 : %.20lf\n", db);//17번째부터 다름

	float f1;
	f1 = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
	printf("%.20f", f1);

	return 0;
	*/