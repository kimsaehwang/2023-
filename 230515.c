#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//Q1. p554��������
	FILE* afp, * bfp, *cfp;
	char str[20];
	char res, res1;
	int ch;

	afp = fopen("a.txt", "r");
	if (afp == NULL)
	{
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	bfp = fopen("b.txt", "r");
	if (bfp == NULL)
	{
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	cfp = fopen("c.txt", "w");
	if (cfp == NULL)
	{
		printf("��� ������ ���� ���߽��ϴ�.");
		return 1;
	}

	while (1)
	{
		ch = fgetc(bfp);
		if (bfp == EOF)
		{
			break;
		}
		putchar(ch);

		if (strcmp(afp,bfp) == 0)
		{
			fprintf(cfp, "%s", str);
		}
		else
		{
			break;
		}
	}


	fclose(afp);
	fclose(bfp);
	fclose(cfp);

	return 0;
}

	//���۸� ���������ν� ����� ����
	/*FILE* fp;
	int age;
	char name[20];

	fp = fopen("a.txt", "r");

	fscanf(fp, "%d", &age);
	fgets(name, sizeof(name), fp);

	printf("���� : %d, �̸� : %s", age, name);
	fclose(fp);

	return 0;
}*/

	//�پ��� �ڷ��� ���
	/*FILE* ifp, * ofp;
	char name[20];
	int kor, eng, math;
	int total;
	double avg;
	int res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}
	ofp = fopen("b.txt", "w");
	if (ofp == NULL)
	{
		printf("��� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
		if (res == EOF)
		{
			break;
		}
		total = kor + eng + math;
		avg = total / 3.0;
		fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
	}
	fclose(ifp);
	fclose(ofp);

	return 0;
}*/

	//�������� ������ ���ٷ� ��� a.txt -> b.txt
	/*FILE* ifp, * ofp;
	char str[80];
	char* res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}
	ofp = fopen("b.txt", "w");
	if (ofp == NULL)
	{
		printf("��� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL)
		{
			break;
		}
		str[strlen(str) - 1] = '\0';
		fputs(str, ofp);
		fputs(" ", ofp);
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}*/

	//a+ ������ ������ ���
	/*FILE* fp;
	char str[20];

	fp = fopen("a.txt", "a+");
	if (fp == NULL)
	{
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		printf("�����Է� : ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0)
		{
			break;
		}
		else if (strcmp(str, "list") == 0)
		{
			fseek(fp, 0, SEEK_SET);
			while (1)
			{
				fgets(str, sizeof(str), fp);
				if (feof(fp))
				{
					break;
				}
				printf("%s", str);
			}
		}
		else
		{
			fprintf(fp, "%s", str);
		}
	}
	fclose(fp);

	return 0;
}*/

	//stdin,stdout ���������
	/*int ch;
	while (1)
	{
		ch = fgetc(stdin);
		if (ch == EOF)
		{
			break;
		}
		fputc(ch, stdout);
	}
	return 0;
}*/

	//���ڿ��� ���Ϸ� ����ϴ� ���α׷�
	/*FILE* fp;
	char str[] = "banana";
	int i;

	fp = fopen("b.txt", "w");
	if (fp == NULL)
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return 1;
	}


	i = 0;
	while (str[i] !='\0')
	{
		fputc(str[i], fp);
		i++;
	}
	fputc('\n', fp);
	fclose(fp);

	return 0;
}*/