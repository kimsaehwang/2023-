#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//void swap(int* pa, int* pb);
//void swap(double* pa, double* pb);
//void line_up(double* maxp, double* midp, double* minp);

int main()
{
	/*
	double max, mid, min;

	printf("실수값 3개 입력 : ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);

	return 0;
}
void swap(double* pa, double* pb)
{
	double temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void line_up(double* maxp, double* midp, double* minp)
{
	if (*maxp < *midp)
	{
		swap(maxp, midp);
	}
	if (*midp < *minp)
	{
		swap(minp, midp);
	}
	if (*midp > *maxp)
	{
		swap(maxp, midp);
	}
}
*/

	/*
	int a = 10, b = 20;
	swap(&a, &b);
	printf("a:%d, b:%d\n", a, b);
	return 0;
}
void swap(int* pa, int* pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
*/


	/*
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	*ptr1 += 10;
	*ptr2 -= 10;
	ptr1 = &num2;
	ptr2 = &num1;
	
	printf("ptr1 :%d ptr2 :%d\n", *ptr1, *ptr2);
	printf("num1 :%d num2 :%d", num1, num2);

}
*/


	/*
	char ch;
	int in;
	double db;

	char* pc = &ch;
	int* pi = &in;
	double* pd = &db;

	printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
	printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

	printf("char * 포인터의 크기 : %d\n", sizeof(pc));
	printf("int * 포인터의 크기 : %d\n", sizeof(pi));
	printf("double * 포인터의 크기 : %d\n", sizeof(pd));

	printf("char * 포인터가 가리키는 변수의크기 : %d\n", sizeof(*pc));
	printf("int * 포인터가 가리키는 변수의크기 : %d\n", sizeof(*pi));
	printf("double * 포인터가 가리키는 변수의크기 : %d\n", sizeof(*pd));


}
*/


	/*
	int a = 10, b = 20;
	const int* pa = &a; //*pa값을 못바꿈

	printf("변수 a 값 : %d\n", *pa);
	pa = &b;
	printf("변수 b 값 : %d\n", *pa);
	pa = &a;
	a = 20;
	printf("변수 a 값 : %d\n", *pa);

	return 0;

}
*/


	/*	
	int a = 10, b = 15, total;
	double avg;
	const int* pa = &a;
	int* pa, * pb;
	int* pt = &total;
	double* pg = &avg;

	pa = &a;
	pb = &b;
	a = 20;

	*pt = *pa + *pb;
	*pg = *pt / 2.0;

	
	printf("두 정수의값 : %d, %d\n", *pa, *pb);
	printf("두 정수의 합 : %d\n", *pt);
	printf("두 정수의 평균 : %.1lf\n", *pg);
	print("%p   %p\n", &pt, &total);
	return 0;
	
}
*/
	
	char str[100];
	int size = sizeof(str) / sizeof(str[0]);

	printf("문자열 입력  -> ");
	gets(str);
	while (1)
	{
		int temp;
		temp = str[0];
		for (int i = 1;i < size;i++)
		{
			if (str[i] == '\0')
			{
				str[i - 1] = temp;
				break;
			}
			str[i - 1] = str[i];
		}
		puts(str);
		Sleep(1000);
		system("cls");
	}
	
	return 0;
}

	/*
	char str[] = "Be Happy!";
	char str1[] = "Be Happy!";
	printf("문자열 입력 : %s\n", str);

	for (int i = 0;str[i];i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
			
		}
	}

	for (int i = 0;str1[i];i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			str1[i] = str1[i] - 32;

		}
	}

	printf("소문자로 -> %s\n", str);
	printf("대문자로 -> %s", str1);
	return 0;
	*/

	/*
	char str[5];

	str[0] = '0';
	str[1] = 'k';
	printf(" % s\n", str);

	return 0;
	*/

	/*
	char str[80];
	
	printf("문자열 입력 : ");
	gets(str);
	puts("입력된 문자열 : ");
	puts(str);

	
	return 0;
	*/

	/*
	//5개의 정수 (최대값 최소값 합)
	int num[5];
	int tot = 0;
	int i = 0;
	int count;
	int big;
	int small;

	count = sizeof(num) / sizeof(num[0]);

	printf("5개의정수 : ");

	for (i = 0;i < count;i++)
	{
		scanf("%d", &num[i]);
	}

	big = num[0];
	small = num[0];

	for (i = 0;i < count;i++)
	{
		tot = tot + num[i];
	}
	for (i = 0;i < count;i++)
	{
		if (num[i] > big)
		{
			big = num[i];
		}
		if (num[i] < small)
		{
			small = num[i];
		}
	}

	printf("최대값 : %d\n", big);
	printf("최소값 : %d\n", small);
	printf("총합 : %d\n", tot);

	return 0;
	*/

	/*
	int score[6];
	int i;
	int total = 0;
	double avg;
	int count;

	count = sizeof(score) / sizeof(score[0]);

	for (i = 0;i < count;i++)
	{
		scanf("%d", &score[i]);
	}
	for (i = 0;i < count;i++)
	{
		total += score[i];
	}
	avg = total / 5.0;

	for (i = 0;i < count;i++)
	{
		printf("%5d", score[i]);
	}
	printf("\n");

	printf("평균 : %.1lf\n", avg);

	return 0;
	*/

/* sdf */
//	int ary[5];
//
//	ary[0] = 10;
//	ary[1] = 20;
//	ary[2] = ary[0] + ary[1];
//	scanf("%d", &ary[3]);
//
//	printf("%d\n", ary[2]);
//	printf("%d\n", ary[3]);
//	printf("%d\n", ary[4]);
//
//	return 0;
//	
//}
