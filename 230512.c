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
		
	//Q2 성적 처리 프로그램(512p)
	
	struct grade_student list[3];
	printf("학번 : ");
	scanf("%d\n", & list[1].num);
	printf("이름 : ");
	scanf("%d\n", &list[1].name);
	printf("국어,영어,수학 점수 : ");
	scanf("%d%d%d\n", &list[3].grade);
	


	//자기 참조 구조체 list
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

	//구조체 배열
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

	//다른 구조체를 멤버로 갖는 구조체 사용
	/*
	struct student yuni;

	yuni.pf.age = 17;
	yuni.pf.height = 164.5;
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("나이 : %d\n", yuni.pf.age);
	printf("키 : %.1lf\n", yuni.pf.height);
	printf("학번 : %d\n", yuni.id);
	printf("학점 : %.1lf\n", yuni.grade);

}
*/
	
	//구조체
	/*
	struct student s1;

	s1.num = 2;
	s1.grade = 2.7;
	printf("학번 : %d\n", s1.num);
	printf("학점 : %.1lf\n", s1.grade);

	return 0;
}
*/

	//Q1 소수 계산 프로그램
	/*int prime = 0;
	int i, j;
	int k = 2;

	while (1)
	{
	printf("\n>양수 입력(0입력시 종료) : ");
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

	//명령행 인수 처리
	/*
	int i;

	for (i = 0;i < argc;i++)
	{
		printf("%s\n", argv[i]);
	}
}*/

	//함수로 출력
	/*
	char temp[80];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20)
	{
		printf("문자열을 입력하세요 : ");
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

	//3개의 문자열을 저장하기위한 동적할당
	/*
	char temp[80];
	char* str[3];
	int i;

	for (i = 0;i < 3;i++)
	{
		printf("문자열을 입력하세요 : ");
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