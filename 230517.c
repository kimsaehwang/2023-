#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int input_data(void);
double average(void);
void print_data(double);

int count = 0;
static int total = 0;

int main(void)
{

	//extern�� static ����ϱ� (average.c , inout.c)
	/*double avg;

	total = input_data();
	avg = average();
	print_data(avg);

	return 0;
}

void print_data(double avg)
{
	printf("�Է��� ����� ���� : %d\n", count);
	printf("��ü �հ� ��� : %d, %.1lf\n", total, avg);
}*/

	//#��##�� ����� ��ũ���Լ�
	/*int a1, a2;

	NAME_CAT(a, 1) = 10;
	NAME_CAT(a, 2) = 20;
	PRINT_EXPR(a1 + a2);
	PRINT_EXPR(a2 - a1);

	return 0;
}*/

	//�̹� ���ǵ� ��ũ���� ����
	/*printf("������ ��¥�� �ð� : %s,%s\n\n", __DATE__, __TIME__);
	printf("���ϸ� : %s\n", __FILE__);
	printf("�Լ��� : %s\n", __FUNCTION__);
	printf("���ȣ : %d\n", __LINE__);

#line 100 "macro.c"
	func();

	return 0;
}

void func(void)
{
	printf("\n");
	printf("���ϸ� : %s\n", __FILE__);
	printf("�Լ��� : %s\n", __FUNCTION__);
	printf("���ȣ : %d\n", __LINE__);
}*/