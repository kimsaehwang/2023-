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
	//��������
	/*int nx, ky;
	puts("bsearch �Լ��� ����Ͽ� �˻�");
	printf("��� ����: ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	printf("������������ �Է��ϼ���.\n");
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
	printf("�˻���: ");
	scanf("%d", &ky);
	int* p = bsearch(
		&ky,
		x,
		nx,
		sizeof(int),
		(int(*)(const void*, const void*))int_cmp
	);
	if (p == NULL)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
	free(x);
	return 0;
}*/