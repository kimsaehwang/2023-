#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//void input_nums(int* lotto_nums);
//void print_nums(int* lotto_nums);
//void check_duplication(int* lotto_nums, int* i);

int main()
{
	// 길이가 가장 긴 단어
	/*
	char ch;
	int count = 0;
	int temp = 0;
	while ((scanf("%c", &ch)) != -1) // Ctrl+Z가 입력시 종료
	{
		if (ch != '\n')
		{
			count++;
		}
		else
		{
			if (temp < count)
			{ 
				temp = count;
				count = 0;
			}
		}
	}
	printf("가장 긴 단어의 길이 : %d", temp);
	return 0;
}
*/

	//로또 번호생성기(함수)
	/*
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);

	return 0;
}

void input_nums(int* lotto_nums)
{
	for (int i = 0; i < 6; i++)
	{
		printf("번호 입력 : ");
		scanf("%d", &lotto_nums[i]);
		if(check_range(lotto_nums, &i))
		{
			continue;
		}
		check_duplication(lotto_nums, &i);
	}
}

int check_range(int* lotto_nums, int* i)
{
	if (*(lotto_nums + *i) <= 0 || *(lotto_nums + *i) > 45)
	{
		printf("1~45숫자를 입력해주세요!\n");
		(*i)--;
	}
	return 0;
}

void check_duplication(int* lotto_nums, int* i)
{
	for (int j = 0; j < *i; j++)
	{
		if (*(lotto_nums + *i) == *(lotto_nums + j))
		{
			printf("같은 번호를 입력 하셨습니다!\n");
			(*i)--;
		}
	}
}

void print_nums(int* lotto_nums)
{
	for (int i = 0; i < 6; i++)
	{
		printf("%3d", lotto_nums[i]);
	}
}
*/

	//문자열 뒤집기 
	/*char str[100];
	char* front = str;
	int i = 0;
	gets(str);

	int len = strlen(str);     //문자열 길이갯수를 str에 저장
	char* back = str + len -1; //전체길이 + len - 1을 하면 마지막자리
	
	for (i = 0; i < len; i++)
	{
		if (str[i] == '\0')
		{
			break;
		}
	}

	char temp;
	for (i = 0; i < len / 2; i++)
	{
		temp = *(front + i);
		*(front + i) = *(back - i);
		*(back - i) = temp;
	} 

	puts(str);
	return 0;
}*/

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

	//포인터를 활용한 광고판
	/*char str[100];
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


	//배열명에 정수 연산을 수행하여 배열 요소 사용
	/*int ary[3];
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