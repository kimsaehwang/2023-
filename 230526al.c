#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

intsumof(int a, int b);

int main()
{
	int a, b;
	int sum = 0;
	printf("a,b�� ��: ");
	scanf("%d%d", &a, &b);

	if (a > b)
	{
		sum = (a + b) * (a - b + 1) * 1 / 2;
	}
	else if (b > a)
	{
		sum = (a + b) * (b - a + 1) * 1 / 2;
	}
	printf("a����b������ �� : %d", sum);

	/*int n;
	printf("n�� ��: ");
	scanf("%d", &n);
	
	n = (1 + n) * (n - 1 + 1) * 1 / 2;
	printf("1����n������ �� : %d", n);*/

}