#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

intsumof(int a, int b);

int main()
{
	int a, b;
	int sum = 0;
	printf("a,b의 값: ");
	scanf("%d%d", &a, &b);

	if (a > b)
	{
		sum = (a + b) * (a - b + 1) * 1 / 2;
	}
	else if (b > a)
	{
		sum = (a + b) * (b - a + 1) * 1 / 2;
	}
	printf("a부터b까지의 합 : %d", sum);

	/*int n;
	printf("n의 값: ");
	scanf("%d", &n);
	
	n = (1 + n) * (n - 1 + 1) * 1 / 2;
	printf("1부터n까지의 합 : %d", n);*/

}