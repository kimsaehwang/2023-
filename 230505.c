#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//void swap(int* pfront, int* pback);

int main()
{
	//�迭 ������ ex) hello ->olleh

	int arr[6];
	int size = sizeof(arr) / sizeof(*arr);
	int* pf = arr + 1;
	int* pb = arr + 6;

	printf("���� 6�� �Է� : ");
	gets(arr);
	for (int i = 1;i <= 6;i++)
	{
		
		
	}
	puts(arr);
}

//void swap(int* pfront, int* pback)



	/*
	//�����͸� Ȱ���� ������
	char str[100];
	int size = sizeof(str) / sizeof(*str);

	printf("���ڿ� �Է�  -> ");
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
			*(str+i - 1) = *(str+i);
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

	printf("�տ� �ִ� �迭 ����� �� ��� : ");
	if (pa < pb)printf("%d\n", *pb);

	return 0;
	*/
	
	/*
	//�迭�� ���� ������ �����Ͽ� �迭 ��� ���
	int ary[3];
	int i;

	*(ary + 0) = 10;                   //ary[0] = 10;
	*(ary + 1) = *(ary + 0) + 10;      //ary[1] = ary[0] +10

	printf("�� ��° �迭 ��ҿ� Ű���� �Է� :");
	scanf("%d", ary + 2);              //&ary[2]

	for (i = 0;i < 3;i++)
	{
		printf("%5d", *(ary + i));
	}

	return 0;
	*/
