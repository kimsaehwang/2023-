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

	//p353 도전문제
	char fir[80], sec[80], thr[80];

	printf("3개의 과일을 입력 : ");
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



	

	//주소를 반환하여 두 정수의 합 계산
	/*int* resp;

	resp = sum(10, 20);
	printf("두 정수의 합 : %d\n", *resp);

	return 0;
}

int* sum(int a, int b)
{
	static int res;

	res = a + b;

	return &res;
}*/

	//정적 지역변수
	/*
	int i;

	printf("일반 지역 변수 (auto)를 사용한 함수...\n");
	for (i = 0;i < 3;i++)
	{
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용한 함수...\n");
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
	printf("boy 위치 주소 : %p\n",str[7]);
	printf("")
	printf("바뀐 문자열 : %s", str);



	
	

}*/

	//지역변수
	/*
	printf("함수 호출 전 a 값 : %d\n", a);

	assign10();
	assign20();

	printf("함수 호출 후a 값 : %d\n", a);

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

	//strcpy,strstrncpy 활용
	/*
	char str[80] = "strawberry";

	printf("바꾸기 전 문자열 : %s\n", str);
	my_strcpy(str, "apple");                         //apple 복사
	printf("바꾼 후 문자열 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi")); //kiwi를 반환값으로 출력
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

	//strcpy함수
	/*char str[80] = "strawberry";

	printf("바꾸기 전 문자열 : %s\n", str);
	my_strcpy(str, "apple");                         //apple 복사
	printf("바꾼 후 문자열 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi")); //kiwi를 반환값으로 출력

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

	//strcmp,strncmp 함수 - 첫문자가 같다면 다음문자를 아스키코드값으로 차례로 비교함
	/*char str1[80] = "pear";
	char str2[80] = "peach";

	printf("사전에 나중에 나오는 과일 이름 : ");
	if (strcmp(str1, str2) > 0) //str1이 str2보다 크면(r과c비교)
	{
		printf("%s\n", str1);
	}
	else
	{
		printf("%s\n", str2);
	}
	return 0;*/

	//strlen 문자열 길이를 계산
	/*char str1[80], str2[80];
	char* resp;

	printf("2개의 과일 이름 입력 : ");
	scanf("%s%s", str1, str2);
	if (strlen(str1) > strlen(str2))
	{
		resp = str1;
	}
	else
	{
		resp = str2;
	}
	printf("이름이 긴 과일은 : %s\n", resp);

	return 0;*/

	//strcat,strncat사용
	/*char str[80] = "straw";

	strcat(str, "berry");     //str다음 문자열 berry붙임
	printf("%s\n", str);
	strncat(str, "piece", 3); //str다음 3개의 문자만 붙임
	printf("%s\n", str);

	return 0;*/

	//strncpy 사용 -n은 임의의 개수
	/*char str[20] = "mango tree";

	strncpy(str, "apple-pie", 5);

	printf("%s\n", str);

	return 0;*/

	//strcpy 사용
	/*char str1[80] = "strawberry";
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;

	printf("최초 문자열 : %s\n", str1);
	strcpy(str1, str2);                  //str1을 str2로 변경
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps1);                  //str1을 ps1로 변경
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps2);                  //str1을 ps2로 변경
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, "banana");             //str1을 banana로 변경
	printf("바뀐 문자열 : %s\n", str1);

	return 0;*/

	//문자열 연산은 모두 함수로
	/*int a = 10;
	int b = 20;

	char c[10] = "apple";
	char d[10] = "pie";

	printf("%d\n", a + b);
	printf("%s\n", c + d); //문자열 연산은 모두 함수로해야함

	return 0;*/

	//fputs를사용
	/*char str[80] = "apple juice";
	char* ps = "banana";

	puts(str);         //줄 바꿈
	fputs(ps, stdout); //줄 바꾸지않음
	puts("milk");

	return 0;*/

	//fgetc를사용
	/*int age;
	char name[20];

	printf("나이 입력 : ");
	scanf("%d", &age);
	fgetc(stdin);           //개행문자를 읽어들이는 문자입력함수
	printf("이름 입력 : ");
	gets(name);
	printf("나이 : %d, 이름 : %s\n", age, name);

	return 0;*/

	//fgets를사용
	/*char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	fgets(str, sizeof(str), stdin);//배열명,배열의크기,표준입력
	printf("입력한 문자열은 %s입니다.\n", str);

	return 0;*/

	//gets를 사용
	/*char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	gets(str);
	printf("입력한 문자열은 %s입니다.", str);

	return 0;*/

	//문자열 상수 구현방법
	/*char szbuf[12] = { "Test String" };
	char* pszData = "Test String";

	printf("%d\n", szbuf == pszData);
	printf("%d\n", "Test String" == pszData);
	printf("%d\n", "Test String" == "Data String");
	printf("%p\n", "Test String");
	printf("%p\n", "Data String");*/
