#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
	//문자열 뒤집기 
	char str[100];
	int len; 
	len = strlen(str);//문자열 길이갯수를 str에 저장
	char* front = &str[0];
	char* back = &str[99];

	gets(str);
	
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = *(front + i);
		*(front + i) = *(back - i);
		*(back - i) = temp;
	}
	for (int i = 0; i <= len; i++)
	{
		puts(str);
	}
	return 0;
}


	//숫자뒤집기
	/*
	int arr[6] = { 1,2,3,4,5,6 };
	int* front = &arr[0];
	int* back = &arr[5];

	int temp;

	for (int i = 0; i < 3; i++)
	{
		temp = *(front+i);
		*(front + i) = *(back - i);
		*(back - i) = temp;
	}

	for (int i = 0; i <= 5; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}
*/



	/*
	//포인터를 활용한 광고판
	char str[100];
	int size = sizeof(str) / sizeof(*str);
	printf("문자열 입력  -> ");
	gets(str);
	while (1)
	{
		int temp;
		temp = *str;
		for (int i = 1;i < size;i++)
		{
			if (*(str+i) == '\0')
			{
				*(str+i - 1) = temp;
				break;
			}
			*(str + i - 1) = *(str + i);
		}
		puts(str);
		Sleep(500);
		system("cls");
	}
	return 0;
}
*/

/*
int ary[5] = { 10,20,30,40,50 };
int* pa = ary;
int* pb = pa + 3;
printf("pa : %u\n", pa);
printf("pb : %u\n", pb);
pa++;
printf("pb - pa : %u\n", pb - pa);
printf("앞에 있는 배열 요소의 값 출력 : ");
if (pa < pb)printf("%d\n", *pb);
return 0;
*/

/*
//배열명에 정수 연산을 수행하여 배열 요소 사용
int ary[3];
int i;
*(ary + 0) = 10;                   //ary[0] = 10;
*(ary + 1) = *(ary + 0) + 10;      //ary[1] = ary[0] +10
printf("세 번째 배열 요소에 키보드 입력 :");
scanf("%d", ary + 2);              //&ary[2]
for (i = 0;i < 3;i++)
{
	printf("%5d", *(ary + i));
}
return 0;
*/