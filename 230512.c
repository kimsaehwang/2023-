#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void print_str(char** ps);
struct grade_student
{
	char name[20];
	int num;
	int grade[3];
	struct list* next;
};

int main(void)
{
	//createconsolescreenbuffer
	//getasynckeystate
		
	//Q2 ���� ó�� ���α׷�(512p)
	
	struct grade_student list[3];
	printf("�й� : ");
	scanf("%d\n", & list[1].num);
	printf("�̸� : ");
	scanf("%d\n", &list[1].name);
	printf("����,����,���� ���� : ");
	scanf("%d%d%d\n", &list[3].grade);
	


	//�ڱ� ���� ����ü list
	/*
	struct list a = { 10,0 }, b = { 20.0 }, c = { 30,0 };
	struct list* head = &a, * current;

	a.next = &b;
	b.next = &c;

	printf("head -> num : %d\n", head->num);
	printf("head -> next -> num : %d\n", head->next->num);

	printf("list all : ");
	current = head;
	while (current != NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

	return 0;
}
*/

	//����ü �迭
	/*struct address list[5];
	int i;
	for (i = 0;i < 5;i++)
	{
	scanf("%10s%5d%15s%20s", &list[i].name, &list[i].age, &list[i].tel, &list[i].addr);
	}
	for (i = 0;i < 5;i++)
	{
		printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
	}
	return 0;
}*/

	//�ٸ� ����ü�� ����� ���� ����ü ���
	/*
	struct student yuni;

	yuni.pf.age = 17;
	yuni.pf.height = 164.5;
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("���� : %d\n", yuni.pf.age);
	printf("Ű : %.1lf\n", yuni.pf.height);
	printf("�й� : %d\n", yuni.id);
	printf("���� : %.1lf\n", yuni.grade);

}
*/
	
	//����ü
	/*
	struct student s1;

	s1.num = 2;
	s1.grade = 2.7;
	printf("�й� : %d\n", s1.num);
	printf("���� : %.1lf\n", s1.grade);

	return 0;
}
*/

	//Q1 �Ҽ� ��� ���α׷�
	/*int prime = 0;
	int i, j;
	int k = 2;

	while (1)
	{
	printf("\n>��� �Է�(0�Է½� ����) : ");
	scanf("%d", &prime);
	if (prime == 0)break;
		for (i = 1;i < prime;i++)
		{
			for (j = k;j < i;j++)
			{
				if (i % j == 0)
				{
					printf(" X ");
					break;
				}
			}
			if (i == j) printf("%2d ", i);
			if (i > 5 && i % 5 == 1) printf("\n");
		}
	}
	return 0;
}*/

	//����� �μ� ó��
	/*
	int i;

	for (i = 0;i < argc;i++)
	{
		printf("%s\n", argv[i]);
	}
}*/

	//�Լ��� ���
	/*
	char temp[80];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20)
	{
		printf("���ڿ��� �Է��ϼ��� : ");
		gets(temp);
		if (strcmp(temp, "end") == 0)break;
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}
	print_str(str);

	for (i = 0;str[i] != NULL;i++)
	{
		free(str[i]);
	}
	return 0;
}
void print_str(char** ps)
{
	while (*ps != NULL)
	{
		printf("%s\n", *ps);
		ps++;
	}
}*/

	//3���� ���ڿ��� �����ϱ����� �����Ҵ�
	/*
	char temp[80];
	char* str[3];
	int i;

	for (i = 0;i < 3;i++)
	{
		printf("���ڿ��� �Է��ϼ��� : ");
		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
	}

	for (i = 0;i < 3;i++)
	{
		printf("%s\n", str[i]);
	}

	for (i = 0;i < 3;i++)
	{
		free(str[i]);
	}
	return 0;
}*/