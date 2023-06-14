#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SUBMIT 4

int badukdol[20][20] = { 0 };
int dol = 1;
int x = 20, y = 10;

void CursorView();
void Title();
void infoDraw();
int omokDraw();
void play();
void draw_badukpan(); 
int KeyControl();
void gotoxy(int x, int y);  
void erase_dol(int x, int y); 
void insert_key(char key, int* x, int* y); 
void put_spacebar(int badukdol[][20], int x, int y); 
void draw_badukdol(int badukdol[][20]);  
int winner(int badukdol[][20]);
int rule(int badukdol[][20]);

//Ŀ�� ����,���� �Լ�
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = 0; //Ŀ�� on/off
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//Ŀ���̵��Լ�
int KeyControl()
{
	char temp = getch();

	if (temp == '72') return UP;
	else if (temp == '85') return LEFT;
	else if (temp == '75') return RIGHT;
	else if (temp == '77') return DOWN;
	else if (temp == ' ') return SUBMIT;

}

void main() {
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);//�� �ٲٱ�
	
	while (1)
	{
		Title();
		int menucode = menudraw();
		if (menucode == 0)
		{
			omokDraw();
			int omokcode = omokDraw();
			if (omokcode == 0)
			{
				play();
				return 0;
			}
			else if (menucode == 1)
			{
				return 0;
			}
			else if (menucode == 2)
			{
				return 0;
			}
		}
		else if (menucode == 1)
		{
			infoDraw();
		}
		else if (menucode == 2)
		{
			return 0;
		}
		system("cls");
	}
	return 0;
}

void Title()
{
	printf("\n\n");
	printf("          #####    #     #    #####    #    #       \n");
	printf("         #     #   ##   ##   #     #   #   #        \n");
	printf("         #     #   # # # #   #     #   #  #         \n");
	printf("         #     #   #  #  #   #     #   ###          \n");
	printf("         #     #   #     #   #     #   #  #         \n");
	printf("         #     #   #     #   #     #   #   #        \n");
	printf("          #####    #     #    #####    #    #       \n");

}

//ùȭ�� ���� �Լ�
int menudraw()
{
	int x = 20;
	int y = 12;
	gotoxy(x - 2, y);
	printf("> �� �� �� �� ");
	gotoxy(x, y + 1);
	printf("�� �� �� �� ");
	gotoxy(x, y + 2);
	printf("   �� ��  ");

	while (1)
	{
		int n = KeyControl();
		switch (n) {
		case 72:
		{
			if (y > 12)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case 80:
		{
			if (y < 14)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT:
		{
			return y - 12;
		}
		}
	}
}

//���۹� �Լ�
void infoDraw()
{
	system("cls");
	printf("\n");
	printf("                   [���۹�]\n\n");
	printf("              �� �� : �� �� Ű\n");
	printf("           �� �� �� : �� �� �� �� ��\n\n");
	printf("        �� �� �� �� : ������ 5���� �̾����� �̱�\n\n");
	printf("           spacebar ������ �ٵϵ� ����\n");
	printf("           �� �� �� : �� �� Ȳ");
	while (1)
	{
		if (KeyControl() == SUBMIT) break;
	}
}

//�޴� ���� �Լ�
int omokDraw()
{
	int x = 20;
	int y = 6;
	system("cls");

	gotoxy(x - 2, y);
	printf("> 2 �� �� ");
	gotoxy(x, y + 1);
	printf("1 �� �� (�غ���)");
	gotoxy(x, y + 2);
	printf(" �� ��  ");

	while (1)
	{
		int n = KeyControl();
		switch (n) {
		case 72:
		{
			if (y > 6)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case 80:
		{
			if (y < 8)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT:
		{
			return 0;
		}
		}
	}
}

//������� �Լ�
void play() {
	char key;

	draw_badukpan();
	gotoxy(x, y);

	while (1)
	{
		gotoxy(x, y);
		key = getch();
		erase_dol(x, y);
		insert_key(key, &x, &y);
		draw_badukdol(badukdol);
	}
	return 0;
}

//�ٵ��Ǳ׸����Լ�
void draw_badukpan() {
	system("cls");
	printf("\n\n");

	printf("������������������������������������������������������������������������������\n");
	for (int i = 0;i < 18;i++)
	{
		printf("������������������������������������������������������������������������������\n");
	} 
	printf("������������������������������������������������������������������������������\n\n");
}

//Ŀ���̵��Լ�
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// �ٵϵ�������Լ� 
void erase_dol(int x, int y)
{
	gotoxy(x, y);
	if (x == 0 && y == 0)
	{
		printf("��");
	}
	else if (x == 42 && y == 0)
	{
		printf("��");
	}
	else if (x == 0 && y == 21)
	{
		printf("��");
	}
	else if (x == 42 && y == 21)
	{
		printf("��");
	}
	else if (x == 0)
	{
		printf("��");
	}
	else if (y == 0)
	{
		printf("��");
	}
	else if (x == 42)
	{
		printf("��");
	}
	else if (y == 21)
	{
		printf("��");
	}
	else
	{
		printf("��");
	}

}

// Ű�Է¹޴� �Լ� 
void insert_key(char key, int* x, int* y) 
{
	switch (key) {
	case 75: if (*x - 2 < 0) {
		break;
	}
		   else { *x -= 2; }
		   printf(" ");
		   break; // ����
	case 77: if (*x + 2 > 38)
	{
		break;
	}
		   else {
		*x += 2;
	}
		   printf(" ");
		   break; // ������
	case 72: if (*y - 1 < 2)
	{
		break;
	}
		   else {
		*y -= 1;
	}
		   printf(" ");
		   break; // ����
	case 80: if (*y + 1 > 21)
	{
		break;
	}

	else 
	{
		*y += 1;
	}
		   printf(" ");
		   break; // �Ʒ���
	case 32: put_spacebar(badukdol, *x, *y); // �����̽���
		break;

	default:
		break;
	}
}

// �ٵϵ������Լ�
void put_spacebar(int badukdol[][20], int x, int y)
{
	if (badukdol[y][x / 2] == 0)
	{
		if (dol == 1)
		{
			badukdol[y][x / 2] = 1;
			dol = 2;
		}
		else
		{
			badukdol[y][x / 2] = 2;
			dol = 1;
		}
		if (winner(badukdol))
		{
			return 0;
		}
	}
}

// �ٵϵ��׸����Լ�
void draw_badukdol(int badukdol[][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (badukdol[j][i] == 1)
			{
				gotoxy(i * 2, j);
				printf("��");
			}

			else if (badukdol[j][i] == 2)
			{
				gotoxy(i * 2, j);
				printf("��");
			}
		}
	}
}

//�¸� ���� �Լ�
int winner(int badukdol[][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)//badukdol[i][j] = 1 -> �浹 || badukdol[i][j] = 2 -> �鵹
		{
			if (badukdol[i][j] == 1 && badukdol[i][j + 1] == 1 && badukdol[i][j + 2] == 1 && badukdol[i][j + 3] == 1 && badukdol[i][j + 4] == 1)
			{
				gotoxy(1, 23);
				printf("[�浹 �¸�]");
				exit(0);
			}// �浹 ����

			else if (badukdol[i][j] == 2 && badukdol[i][j + 1] == 2 && badukdol[i][j + 2] == 2 && badukdol[i][j + 3] == 2 && badukdol[i][j + 4] == 2)
			{
				gotoxy(1, 23);
				printf("[�鵹 �¸�]");
				exit(0);
			}//�鵹 ����

			else if (badukdol[j][i] == 1 && badukdol[j + 1][i] == 1 && badukdol[j + 2][i] == 1 && badukdol[j + 3][i] == 1 && badukdol[j + 4][i] == 1)
			{
				gotoxy(1, 23);
				printf("[�浹 �¸�]");
				exit(0);
			} //�浹 ����

			else if (badukdol[j][i] == 2 && badukdol[j + 1][i] == 2 && badukdol[j + 2][i] == 2 && badukdol[j + 3][i] == 2 && badukdol[j + 4][i] == 2)
			{
				gotoxy(1, 23);
				printf("[�鵹 �¸�]");
				exit(0);
			}//�鵹 ����

			else if (badukdol[i][j] == 1 && badukdol[i + 1][j + 1] == 1 && badukdol[i + 2][j + 2] == 1 && badukdol[i + 3][j + 3] == 1 && badukdol[i + 4][j + 4] == 1)
			{
				gotoxy(1, 23);
				printf("[�浹 �¸�]");
				exit(0);
			}// �浹 �������밢��

			else if (badukdol[i][j] == 2 && badukdol[i + 1][j + 1] == 2 && badukdol[i + 2][j + 2] == 2 && badukdol[i + 3][j + 3] == 2 && badukdol[i + 4][j + 4] == 2)
			{
				gotoxy(1, 23);
				printf("[�鵹 �¸�]");
				exit(0);
			}// �鵹 ����������

			else if (badukdol[19 - j][i] == 1 && badukdol[18 - j][i + 1] == 1 && badukdol[17 - j][i + 2] == 1 && badukdol[16 - j][i + 3] == 1 && badukdol[15 - j][i + 4] == 1)
			{
				gotoxy(1, 23);
				printf("[�浹 �¸�]");
				exit(0);
			} //�浹 �Ʒ��ʴ밢��

			else if (badukdol[19 - j][i] == 2 && badukdol[18 - j][i + 1] == 2 && badukdol[17 - j][i + 2] == 2 && badukdol[16 - j][i + 3] == 2 && badukdol[15 - j][i + 4] == 2)
			{
				gotoxy(1, 23);
				printf("[�鵹 �¸�]");
				exit(0);
			} //�鵹 �Ʒ��ʴ밢��
		}
	}
	return 0;
}

