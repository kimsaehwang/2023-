#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntQueue.h"

/*
int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}
int bin_search2(const int a[], int n, int key);

typedef struct
{
	int max;
	int ptr;
	int* stk;
}Intstack;*/



int main(void)
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("ť�� ������ �����߽��ϴ�.");
		return 1;
	}
	while (1)
	{
		int m, x;

		printf("���� ������ ��: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (0)����: ");
		scanf("%d", &m);

		if (m == 0)break;
		switch (m)
		{
		case1:
			printf("������: ");scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a����: ��ť�� �����Ͽ����ϴ�.");
			break;

		case2:
			if (Degue(&que, &x) == -1)
				puts("\a����: ��ť�� �����Ͽ����ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case3:
			if (Peek(&que, &x) == -1)
				puts("\a����: ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case4:
			Printf(&que);
			break;
		}
	}
	Terminate(&que);
	return 0;
}
	//����
	/*IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("���� ������ �����߽��ϴ�.");
		return 1;
	}
	while (1)
	{
		int menu, x;
		printf("���� ������ ��: %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (0)����: ");
		scanf("%d", &menu);

		if (menu == 0)break;
		switch (menu)
		{
		case 1:
			printf("������: ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a����: Ǫ�ÿ� �����߽��ϴ�.");
			break;
		case2:
			if (Pop(&s, &x) == -1)
				puts("\a����: �˿� �����߽��ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case3:
			if (Peek(&s, &x) == -1)
				puts("\a����: ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;
		case4:
			print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}*/
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