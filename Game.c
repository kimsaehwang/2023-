#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int KeyControl();
void init();
void Title();
int menudraw();
void infoDraw();
void omokDraw();
void gotoxy(int x, int y);


int main()
{
	while (1)
	{
		Title();
		int menucode = menudraw();
		if (menucode == 0)
		{
			omokDraw();
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
	while (1)
	{
		if (KeyControl() == SUBMIT) break;
	}
}

void omokDraw()
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
