#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#ifndef ___Intstack
#define ___Intstack
/*
int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}*/
//int bin_search2(const int a[], int n, int key);

typedef struct
{
	int max;
	int ptr;
	int* stk;
}Intstack;
int main(void)
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("스택 생성에 실패했습니다.");
		return 1;
	}
	while (1)
	{
		int menu, x;
		printf("현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료: ");
		scanf("%d", &menu);

		if (menu == 0)break;
		switch (menu)
		{
		case 1:
			printf("데이터: ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류: 푸시에 실패했습니다.");
			break;
		case2:
			if (Pop(&s, &x) == -1)
				puts("\a오류: 팝에 실패했습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;
		case3:
			if (Peek(&s, &x) == -1)
				puts("\a오류: 피크에 실패했습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;
		case4:
			print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}
	//오름차순
	/*int nx, ky;
	puts("bsearch 함수를 사용하여 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	printf("오름차순으로 입력하세요.\n");
	printf("x[0]: ");
	scanf("%d", &x[0]);
	for (int i = 1;i < nx;i++)
	{
		do
		{
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("검색값: ");
	scanf("%d", &ky);
	int* p = bsearch(
		&ky,
		x,
		nx,
		sizeof(int),
		(int(*)(const void*, const void*))int_cmp
	);
	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d은(는) x[%d]에 있습니다.\n", ky, (int)(p - x));
	free(x);
	return 0;
}*/