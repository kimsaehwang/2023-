#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int x;
	int y;
	scanf("%d %d", &x, &y);
	if (x > 0 && y > 0)
	{
		printf("1");
	}
	else if (x < 0 && y > 0)
	{
		printf("2");
	}
	else if (x < 0 && y < 0)
	{
		printf("3");
	}
	else
	{
		printf("4");
	}

}