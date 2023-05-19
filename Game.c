#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>﻿
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int KeyControl();
void init();
void Title();
int omok();
int menudraw();
void infoDraw();
int omokDraw();
void gotoxy(int x, int y);

enum
{
	YELLOW, VIOLET,GREEN
};

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = 0; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}

int main()
{
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
				omok();
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
		printf("입력한 키값은 : %d\n", menucode);
	}
	return 0;
}

void Title()
{
	setColor(GREEN);
	printf("\n\n");
	printf("           #####  #     #  #####  #    #       \n");
	printf("          #     # ##   ## #     # #   #        \n");
	printf("          #     # # # # # #     # #  #         \n");
	printf("          #     # #  #  # #     # ###          \n");
	printf("          #     # #     # #     # #  #         \n");
	printf("          #     # #     # #     # #   #        \n");
	printf("           #####  #     #  #####  #    #       \n");
	
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int KeyControl()
{
	char temp = getch();

	if (temp == 'w' || temp == 'W') return UP;
	else if (temp == 'a' || temp == 'a') return LEFT;
	else if (temp == 'd' || temp == 'd') return RIGHT;
	else if (temp == 's' || temp == 's') return DOWN;
	else if (temp == ' ') return SUBMIT;

}

int menudraw()
{
	int x = 20;
	int y = 12;
	gotoxy(x - 2, y);
	printf("> 게 임 시 작 ");
	gotoxy(x, y + 1);
	printf("게 임 정 보 ");
	gotoxy(x, y + 2);
	printf("   종 료  ");

	while (1)
	{
		int n = KeyControl();
		switch (n) {
		case UP:
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

		case DOWN:
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

void infoDraw()
{
	system("cls");
	printf("\n\n");
	printf("                   [조작법]\n\n");
	printf("              이 동 : W, A, S, D\n");
	printf("           돌 놓 기 : 스 페 이 스 바\n");
	printf("        승 리 조 건 : 같은색 5개가 이어지면 이김\n\n");
	printf("           spacebar 누르면 돌아감");
	printf("           제 작 자 : 김 세 황");
	while (1)
	{
		if (KeyControl() == SUBMIT) break;
	}
}

int omokDraw()
{
	int x = 20;
	int y = 6;
	system("cls");

	gotoxy(x - 2, y);
	printf("> 2 인 용 ");
	gotoxy(x, y + 1);
	printf("1 인 용 (준비중)");
	gotoxy(x, y + 2);
	printf(" 뒤 로  ");

	while (1)
	{
		int n = KeyControl();
		switch (n) {
		case UP:
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

		case DOWN:
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
			return y - 6;
		}
		}
	}
}

int omok()
{
	system("cls");
	printf("\n\n");
	
	printf("┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐\n");
	for (int i = 0;i < 18;i++)
	{
		printf("├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤\n");
	}
	printf("└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘\n\n");

	

	//printf("○ : %d  ● : %d", );
	int x = 38;     //0~38 짝수만
	int y = 2;      //2~21
	int m = 2;
	gotoxy(x , y);
	while (1)
	{
		int cnt;
		int n = KeyControl();
		switch (n) {
		case UP:
		{
			if (y > 2)
			{
				gotoxy(x - 2, y);
				//printf(" ");
				gotoxy(x - 2, --y);

			}
			break;
		}

		case DOWN:
		{
			if (y < 21)
			{
				gotoxy(x - 2, y);
				//printf(" ");
				gotoxy(x - 2, ++y);
			}
			break;
		}

		case LEFT:
		{
			if (x > 0)
			{
				gotoxy(x, y);
				//printf(" ");
				x -= 2;
				gotoxy(x, y);
			}
			break;
		}

		case RIGHT:
		{
			if (x < 38)
			{
				gotoxy(x, y);
				//printf(" ");
				x += 2;
				gotoxy(x, y);
			}
			break;
		}

		case SUBMIT:
		{
			
			printf("●");
		
		}
		}
	}
}