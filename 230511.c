#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void swap_ptr(char** ppa, char** ppb);
//int sum(int, int);
//void func(int (*fp)(int, int));
//int sum(int a, int b);
//int mul(int a, int b);
//int max(int a, int b);
//void swap_age(int age,int age1);


int main(void)
{
	//Q4.���ڿ� ������ ����ϱ�(�޸� �Ҵ� ���뺹�� ����)
	/*
	char str[100];
	char temp;
	char* front = str;
	int len = strlen(str);  
	char* back = str + len - 1;
	int i;
	int count = 0;
	int* pi;
	int size = 5;
	int num;

	pi = (char*)calloc(size, sizeof(char));
	while(1)
	{
		printf("�Է� >> ");
		scanf("%c", &str);
		if (str == "Quit");
		if (count == size)
		{
			size += 5;
			pi = (char*)calloc(size, sizeof(char));
		}
		pi[count++] = num;

	for (i = 0; i < count; i++)
	{
		if (str[i] == '32')
		{
			temp = *(front+i);
			*(front + i) = *(back - i);
			*(back - i) = temp;
		}
		printf("%5d", pi[i]);
	}
	free(pi);
	return 0;
	}	
}
*/

	//calloc,realloc �Լ��� ����� ��� �Է�
	/*
	int* pi;
	int size = 5;
	int count = 0;
	int num;
	int i;
	pi = (int*)calloc(size, sizeof(int));
	while (1)
	{
		printf("����� �Է��ϼ��� => ");
		scanf("%d", &num);
		if (num <= 0)break;
		if (count == 0)
		{
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int));
		}
		pi[count++] = num;
	}
	for (i = 0;i < count;i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi);  //���� �Ҵ� ���� ���� �ݳ�
	return 0;
}
*/

	//malloc,free�Լ� Ȱ��
	/*
	char str[4][60] = { "cat","apple","tiger","banana" };

	int c;

	int* pi = (int*)malloc(sizeof(int)*1001);
	if (pi == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}

	free(pi); //�޸𸮸� ����/ �޸𸮰� �Ҵ��� �ȵǸ�\0���� ���´�
	return 0;
}*/

	//448p ��������
	/*
	int age, age1;
	double height, height1;
	void* vp;
	printf("ù ��° ����� ���̿� Ű �Է� : ");
	scanf("%d%.1lf\n", &age, &height);
	printf("�� ��° ����� ���̿� Ű �Է� : ");
	scanf("%d%.1lf", &age1, &height1);
	
	printf("ù ��° ����� ���̿� Ű : %d, %d", age, height);
	printf("�� ��° ����� ���̿� Ű : %d, %d", age1, height1);
	return 0;
}
void swap_age(int age,int age1)
{
	int temp;
	temp = age;
	age = age1;
	age1 = temp;
}
*/

	//�Լ� ȣ�� ���α׷�
	/*
	int sel;

	printf("01 �� ������ ��\n");
	printf("02 �� ������ ��\n");
	printf("03 �� ���� �߿��� ū �� ���\n");
	printf("���ϴ� ������ �����ϼ��� : ");
	scanf("%d", &sel);

	switch (sel)
	{
	case 1: func(sum);break;
	case 2: func(mul);break;
	case 3: func(max);break;
	}
	return 0;
}
	
void func(int (*fp)(int, int))
{
	int a, b;
	int res;

	printf("�� ���� �� ���� �Է��ϼ��� : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("������� : %d\n", res);
}

int sum(int a, int b)
{
	return (a + b);
}

int mul(int a, int b)
{
	return (a * b);
}

int max(int a, int b)
{
	if (a > b return a);
	else return b;
}
*/

	//�Լ� �����͸� Ȱ���� �ձ��ϱ�
	/*
	int (*fp)(int, int);
	int res;

	fp = sum;
	res = fp(10, 20);
	printf("result : %d\n", res);

	return 0;
}

int sum(int a, int b)
{
	return(a + b);
}
*/

	//Q2 int *maxptr; int *minptr; int arr[5];
	/*
	int arr[5] = { 1,2,3,4,5 };
	int* maxptr = &arr[4]; 
	int* minptr = &arr[0]; 
	int** maxpptr = &maxptr;
	int** minpptr = &minptr;
	
	printf("arr�� �ּҰ� : %p\n",&arr);
	printf("arr�� �ִ� �ּҰ� : %p\n",&arr[4]);
	printf("arr�� �ּ� �ּҰ� : %p\n",&arr[0]);
	printf("maxptr�� �� : %d\n",*maxptr);
	printf("minptr�� �� : %d\n",*minptr);
}

void MaxAndMin(int **maxptr,int **minptr)
{
	int* pt;
	pt = *maxptr;
	*maxptr = *minptr;
	*minptr = pt;

}
*/

	//���� �����͸� ����� ������ ��ȯ
	/*
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);
	swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}

void swap_ptr(char** ppa, char** ppb)
{
	char* pt;

	pt = *ppa;
	*ppa = *ppb;
	*ppb = pt;
}
*/

	//���� ������
	/*
	int a = 10;
	int* pi;
	int** ppi;

	pi = &a;
	ppi = &pi;

	printf("-------------------------------------------\n");
	printf("����    ������    &����    *����    **����\n");
	printf("-------------------------------------------\n");
	printf("  a%10d%10u\n", a, &a);
	printf(" pi%10u%10u%10d\n", pi, &pi, *pi);
	printf("ppi%10u%10u%10u%10u\n", ppi, &ppi, *ppi, **ppi);
	printf("-------------------------------------------\n");

	return 0;
}
*/

	//���ھ߱�
	/*
	int i, j, k;
	int count[3];
	srand((unsigned int)time(NULL));

	for (i = 0; i < 3; i++) {
		count[i] = rand() % 9 + 1;

		for (j = 0; j < i; j++) {
			if (count[i] == count[j]) {
				i--;  //�ߺ��� �߰ߵ� ��� i��° ���ڸ� �ٽ� �̴´�.
				break;
			}
		}
	}
	for (k = 0; k < 3; k++) {
		printf("%d ", count[k]);
	}
	printf("\n");

	int st = 0;
	int	ba = 0;
	int cnt = 1;
	int num[3];

	while (count[i] == num[3])
	{
		printf("%dȸ >> %ds%db", cnt,st,ba);
		scanf("%d", num[3]);
		cnt++;

		if (count[0] == num[0])
		{
			ba++;
		}

		
	
		
	}
}
*/