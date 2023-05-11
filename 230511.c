#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void swap_ptr(char** ppa, char** ppb);
//int sum(int, int);
//void func(int (*fp)(int, int));
//int sum(int a, int b);
//int mul(int a, int b);
//int max(int a, int b);
//void swap_age(int age,int age1);


int main(void)
{
	//Q4.문자열 역으로 출력하기(메모리 할당 내용복사 연습)
	/*
	char str[100];
	char temp;
	char* front = str;
	int len = strlen(str);  
	char* back = str + len - 1;
	int i;
	int count = 0;
	int* pi;
	int size = 5;
	int num;

	pi = (char*)calloc(size, sizeof(char));
	while(1)
	{
		printf("입력 >> ");
		scanf("%c", &str);
		if (str == "Quit");
		if (count == size)
		{
			size += 5;
			pi = (char*)calloc(size, sizeof(char));
		}
		pi[count++] = num;

	for (i = 0; i < count; i++)
	{
		if (str[i] == '32')
		{
			temp = *(front+i);
			*(front + i) = *(back - i);
			*(back - i) = temp;
		}
		printf("%5d", pi[i]);
	}
	free(pi);
	return 0;
	}	
}
*/

	//calloc,realloc 함수를 사용한 양수 입력
	/*
	int* pi;
	int size = 5;
	int count = 0;
	int num;
	int i;
	pi = (int*)calloc(size, sizeof(int));
	while (1)
	{
		printf("양수만 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0)break;
		if (count == 0)
		{
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int));
		}
		pi[count++] = num;
	}
	for (i = 0;i < count;i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi);  //동적 할당 저장 공간 반납
	return 0;
}
*/

	//malloc,free함수 활용
	/*
	char str[4][60] = { "cat","apple","tiger","banana" };

	int c;

	int* pi = (int*)malloc(sizeof(int)*1001);
	if (pi == NULL)
	{
		printf("메모리 할당 실패\n");
		exit(1);
	}

	free(pi); //메모리를 해제/ 메모리가 할당이 안되면\0값이 나온다
	return 0;
}*/

	//448p 실전예제
	/*
	int age, age1;
	double height, height1;
	void* vp;
	printf("첫 번째 사람의 나이와 키 입력 : ");
	scanf("%d%.1lf\n", &age, &height);
	printf("두 번째 사람의 나이와 키 입력 : ");
	scanf("%d%.1lf", &age1, &height1);
	
	printf("첫 번째 사람의 나이와 키 : %d, %d", age, height);
	printf("두 번째 사람의 나이와 키 : %d, %d", age1, height1);
	return 0;
}
void swap_age(int age,int age1)
{
	int temp;
	temp = age;
	age = age1;
	age1 = temp;
}
*/

	//함수 호출 프로그램
	/*
	int sel;

	printf("01 두 정수의 합\n");
	printf("02 두 정수의 곱\n");
	printf("03 두 정수 중에서 큰 값 계산\n");
	printf("원하는 연산을 선택하세요 : ");
	scanf("%d", &sel);

	switch (sel)
	{
	case 1: func(sum);break;
	case 2: func(mul);break;
	case 3: func(max);break;
	}
	return 0;
}
	
void func(int (*fp)(int, int))
{
	int a, b;
	int res;

	printf("두 정수 의 값을 입력하세요 : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("결과값은 : %d\n", res);
}

int sum(int a, int b)
{
	return (a + b);
}

int mul(int a, int b)
{
	return (a * b);
}

int max(int a, int b)
{
	if (a > b return a);
	else return b;
}
*/

	//함수 포인터를 활용한 합구하기
	/*
	int (*fp)(int, int);
	int res;

	fp = sum;
	res = fp(10, 20);
	printf("result : %d\n", res);

	return 0;
}

int sum(int a, int b)
{
	return(a + b);
}
*/

	//Q2 int *maxptr; int *minptr; int arr[5];
	/*
	int arr[5] = { 1,2,3,4,5 };
	int* maxptr = &arr[4]; 
	int* minptr = &arr[0]; 
	int** maxpptr = &maxptr;
	int** minpptr = &minptr;
	
	printf("arr의 주소값 : %p\n",&arr);
	printf("arr의 최대 주소값 : %p\n",&arr[4]);
	printf("arr의 최소 주소값 : %p\n",&arr[0]);
	printf("maxptr의 값 : %d\n",*maxptr);
	printf("minptr의 값 : %d\n",*minptr);
}

void MaxAndMin(int **maxptr,int **minptr)
{
	int* pt;
	pt = *maxptr;
	*maxptr = *minptr;
	*minptr = pt;

}
*/

	//이중 포인터를 사용한 포인터 교환
	/*
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);
	swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}

void swap_ptr(char** ppa, char** ppb)
{
	char* pt;

	pt = *ppa;
	*ppa = *ppb;
	*ppb = pt;
}
*/

	//이중 포인터
	/*
	int a = 10;
	int* pi;
	int** ppi;

	pi = &a;
	ppi = &pi;

	printf("-------------------------------------------\n");
	printf("변수    변숫값    &연산    *연산    **연산\n");
	printf("-------------------------------------------\n");
	printf("  a%10d%10u\n", a, &a);
	printf(" pi%10u%10u%10d\n", pi, &pi, *pi);
	printf("ppi%10u%10u%10u%10u\n", ppi, &ppi, *ppi, **ppi);
	printf("-------------------------------------------\n");

	return 0;
}
*/

	//숫자야구
	/*
	int i, j, k;
	int count[3];
	srand((unsigned int)time(NULL));

	for (i = 0; i < 3; i++) {
		count[i] = rand() % 9 + 1;

		for (j = 0; j < i; j++) {
			if (count[i] == count[j]) {
				i--;  //중복이 발견될 경우 i번째 숫자를 다시 뽑는다.
				break;
			}
		}
	}
	for (k = 0; k < 3; k++) {
		printf("%d ", count[k]);
	}
	printf("\n");

	int st = 0;
	int	ba = 0;
	int cnt = 1;
	int num[3];

	while (count[i] == num[3])
	{
		printf("%d회 >> %ds%db", cnt,st,ba);
		scanf("%d", num[3]);
		cnt++;

		if (count[0] == num[0])
		{
			ba++;
		}

		
	
		
	}
}
*/