#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//char swap(char* pd, char* ps);
void swap(char* fir, char* sec);
int my_strcmp(char* pa, char* pb);
void line_up(char* fir, char* sec, char* thr);
//void assign10(void);
//void assign20(void);

//void auto_func(void);
//void static_func(void);

//int* sum(int a, int b);

int main()
{

	//p353 ��������
	char fir[80], sec[80], thr[80];

	printf("3���� ������ �Է� : ");
	scanf("%s %s %s", fir, sec, thr);
	line_up(&fir, &sec, &thr);
	printf("%s %s %s", fir, sec, thr);
}

void line_up(char* fir, char* sec, char* thr)
{
	if (*fir > *sec)
	{
		swap(fir, sec);
	}
	if (*sec > *thr)
	{
		swap(thr, sec);
	}
	if (*sec < *fir)
	{
		swap(fir, sec);
	}
}

void swap(char* fir, char* sec)
{
	char temp[80];
	strcpy(temp, fir);
	strcpy(fir, sec);
	strcpy(sec, temp);
}


int my_strcmp(char* pa, char* pb)
{
	while ((*pa == *pb) && (*pa != '\0'))
	{
		pa++;
		pb++;
	}
	
	if (*pa > *pb) return 1;
	else if (*pa < *pb)return -1;
	else return 0;
}



	

	//�ּҸ� ��ȯ�Ͽ� �� ������ �� ���
	/*int* resp;

	resp = sum(10, 20);
	printf("�� ������ �� : %d\n", *resp);

	return 0;
}

int* sum(int a, int b)
{
	static int res;

	res = a + b;

	return &res;
}*/

	//���� ��������
	/*
	int i;

	printf("�Ϲ� ���� ���� (auto)�� ����� �Լ�...\n");
	for (i = 0;i < 3;i++)
	{
		auto_func();
	}

	printf("���� ���� ����(static)�� ����� �Լ�...\n");
	for (i = 0;i < 3;i++)
	{
		static_func();
	}
	return 0;
}

void auto_func(void)
{
	auto int a = 0;

	a++;
	printf("%d\n", a);
}

void static_func(void)
{
	static int a;

	a++;
	printf("%d\n", a);
}

	/*
	char str[50] = "I am a boy. I'm happy!";
	char* pa = "girl";
	char* resp;
	char temp;
	printf("boy ��ġ �ּ� : %p\n",str[7]);
	printf("")
	printf("�ٲ� ���ڿ� : %s", str);



	
	

}*/

	//��������
	/*
	printf("�Լ� ȣ�� �� a �� : %d\n", a);

	assign10();
	assign20();

	printf("�Լ� ȣ�� ��a �� : %d\n", a);

	return 0;
}

void assign10(void)
{
	a = 10;
}

void assign20(void)
{
	int a;

	a = 20;
}
*/

	//strcpy,strstrncpy Ȱ��
	/*
	char str[80] = "strawberry";

	printf("�ٲٱ� �� ���ڿ� : %s\n", str);
	my_strcpy(str, "apple");                         //apple ����
	printf("�ٲ� �� ���ڿ� : %s\n", str);
	printf("�ٸ� ���ڿ� ���� : %s\n", my_strcpy(str, "kiwi")); //kiwi�� ��ȯ������ ���
	strncpy(str, "kiwi",3);
	printf("%s\n", str);
	return 0;
}

char* my_strcpy(char* pd, char* ps)
{
	char* po = pd;

	while (*pd != '\0')
	{
		pd++;
	}
	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return po;
}
*/

	//strcpy�Լ�
	/*char str[80] = "strawberry";

	printf("�ٲٱ� �� ���ڿ� : %s\n", str);
	my_strcpy(str, "apple");                         //apple ����
	printf("�ٲ� �� ���ڿ� : %s\n", str);
	printf("�ٸ� ���ڿ� ���� : %s\n", my_strcpy(str, "kiwi")); //kiwi�� ��ȯ������ ���

	return 0;
}

char* my_strcpy(char* pd, char* ps)
{
	char* po = pd;

	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';

	return po;
}*/

	//strcmp,strncmp �Լ� - ù���ڰ� ���ٸ� �������ڸ� �ƽ�Ű�ڵ尪���� ���ʷ� ����
	/*char str1[80] = "pear";
	char str2[80] = "peach";

	printf("������ ���߿� ������ ���� �̸� : ");
	if (strcmp(str1, str2) > 0) //str1�� str2���� ũ��(r��c��)
	{
		printf("%s\n", str1);
	}
	else
	{
		printf("%s\n", str2);
	}
	return 0;*/

	//strlen ���ڿ� ���̸� ���
	/*char str1[80], str2[80];
	char* resp;

	printf("2���� ���� �̸� �Է� : ");
	scanf("%s%s", str1, str2);
	if (strlen(str1) > strlen(str2))
	{
		resp = str1;
	}
	else
	{
		resp = str2;
	}
	printf("�̸��� �� ������ : %s\n", resp);

	return 0;*/

	//strcat,strncat���
	/*char str[80] = "straw";

	strcat(str, "berry");     //str���� ���ڿ� berry����
	printf("%s\n", str);
	strncat(str, "piece", 3); //str���� 3���� ���ڸ� ����
	printf("%s\n", str);

	return 0;*/

	//strncpy ��� -n�� ������ ����
	/*char str[20] = "mango tree";

	strncpy(str, "apple-pie", 5);

	printf("%s\n", str);

	return 0;*/

	//strcpy ���
	/*char str1[80] = "strawberry";
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;

	printf("���� ���ڿ� : %s\n", str1);
	strcpy(str1, str2);                  //str1�� str2�� ����
	printf("�ٲ� ���ڿ� : %s\n", str1);

	strcpy(str1, ps1);                  //str1�� ps1�� ����
	printf("�ٲ� ���ڿ� : %s\n", str1);

	strcpy(str1, ps2);                  //str1�� ps2�� ����
	printf("�ٲ� ���ڿ� : %s\n", str1);

	strcpy(str1, "banana");             //str1�� banana�� ����
	printf("�ٲ� ���ڿ� : %s\n", str1);

	return 0;*/

	//���ڿ� ������ ��� �Լ���
	/*int a = 10;
	int b = 20;

	char c[10] = "apple";
	char d[10] = "pie";

	printf("%d\n", a + b);
	printf("%s\n", c + d); //���ڿ� ������ ��� �Լ����ؾ���

	return 0;*/

	//fputs�����
	/*char str[80] = "apple juice";
	char* ps = "banana";

	puts(str);         //�� �ٲ�
	fputs(ps, stdout); //�� �ٲ�������
	puts("milk");

	return 0;*/

	//fgetc�����
	/*int age;
	char name[20];

	printf("���� �Է� : ");
	scanf("%d", &age);
	fgetc(stdin);           //���๮�ڸ� �о���̴� �����Է��Լ�
	printf("�̸� �Է� : ");
	gets(name);
	printf("���� : %d, �̸� : %s\n", age, name);

	return 0;*/

	//fgets�����
	/*char str[80];

	printf("������ ���Ե� ���ڿ� �Է� : ");
	fgets(str, sizeof(str), stdin);//�迭��,�迭��ũ��,ǥ���Է�
	printf("�Է��� ���ڿ��� %s�Դϴ�.\n", str);

	return 0;*/

	//gets�� ���
	/*char str[80];

	printf("������ ���Ե� ���ڿ� �Է� : ");
	gets(str);
	printf("�Է��� ���ڿ��� %s�Դϴ�.", str);

	return 0;*/

	//���ڿ� ��� �������
	/*char szbuf[12] = { "Test String" };
	char* pszData = "Test String";

	printf("%d\n", szbuf == pszData);
	printf("%d\n", "Test String" == pszData);
	printf("%d\n", "Test String" == "Data String");
	printf("%p\n", "Test String");
	printf("%p\n", "Data String");*/
