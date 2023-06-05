#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
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
int bin_search2(const int a[], int n, int key);
int main()
{

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