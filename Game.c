#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void init();
void Title();
void gotoxy(int x, int y);
int KeyControl();

int main()
{
	KeyControl();
	Title();
	gotoxy(20 - 2, 11);
	printf("-> 게 임 시 작 ");
	gotoxy(20, 12);
	printf(" 게 임 정 보 ");
	gotoxy(20, 13);
	printf("    종 료  ");


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