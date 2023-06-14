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

//커서 굵기,끄기 함수
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = 0; //커서 on/off
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//커서이동함수
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);//색 바꾸기
	
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

//첫화면 선택 함수
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

//조작법 함수
void infoDraw()
{
	system("cls");
	printf("\n");
	printf("                   [조작법]\n\n");
	printf("              이 동 : 방 향 키\n");
	printf("           돌 놓 기 : 스 페 이 스 바\n\n");
	printf("        승 리 조 건 : 같은색 5개가 이어지면 이김\n\n");
	printf("           spacebar 누르면 바둑돌 놓음\n");
	printf("           제 작 자 : 김 세 황");
	while (1)
	{
		if (KeyControl() == SUBMIT) break;
	}
}

//메뉴 선택 함수
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

//오목실행 함수
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

//바둑판그리는함수
void draw_badukpan() {
	system("cls");
	printf("\n\n");

	printf("┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐\n");
	for (int i = 0;i < 18;i++)
	{
		printf("├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤\n");
	} 
	printf("└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘\n\n");
}

//커서이동함수
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 바둑돌지우는함수 
void erase_dol(int x, int y)
{
	gotoxy(x, y);
	if (x == 0 && y == 0)
	{
		printf("┌");
	}
	else if (x == 42 && y == 0)
	{
		printf("┐");
	}
	else if (x == 0 && y == 21)
	{
		printf("└");
	}
	else if (x == 42 && y == 21)
	{
		printf("┘");
	}
	else if (x == 0)
	{
		printf("├");
	}
	else if (y == 0)
	{
		printf("┬");
	}
	else if (x == 42)
	{
		printf("┤");
	}
	else if (y == 21)
	{
		printf("┴");
	}
	else
	{
		printf("┼");
	}

}

// 키입력받는 함수 
void insert_key(char key, int* x, int* y) 
{
	switch (key) {
	case 75: if (*x - 2 < 0) {
		break;
	}
		   else { *x -= 2; }
		   printf(" ");
		   break; // 왼쪽
	case 77: if (*x + 2 > 38)
	{
		break;
	}
		   else {
		*x += 2;
	}
		   printf(" ");
		   break; // 오른쪽
	case 72: if (*y - 1 < 2)
	{
		break;
	}
		   else {
		*y -= 1;
	}
		   printf(" ");
		   break; // 위쪽
	case 80: if (*y + 1 > 21)
	{
		break;
	}

	else 
	{
		*y += 1;
	}
		   printf(" ");
		   break; // 아래쪽
	case 32: put_spacebar(badukdol, *x, *y); // 스페이스바
		break;

	default:
		break;
	}
}

// 바둑돌놓는함수
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

// 바둑돌그리는함수
void draw_badukdol(int badukdol[][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (badukdol[j][i] == 1)
			{
				gotoxy(i * 2, j);
				printf("○");
			}

			else if (badukdol[j][i] == 2)
			{
				gotoxy(i * 2, j);
				printf("●");
			}
		}
	}
}

//승리 결정 함수
int winner(int badukdol[][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)//badukdol[i][j] = 1 -> 흑돌 || badukdol[i][j] = 2 -> 백돌
		{
			if (badukdol[i][j] == 1 && badukdol[i][j + 1] == 1 && badukdol[i][j + 2] == 1 && badukdol[i][j + 3] == 1 && badukdol[i][j + 4] == 1)
			{
				gotoxy(1, 23);
				printf("[흑돌 승리]");
				exit(0);
			}// 흑돌 가로

			else if (badukdol[i][j] == 2 && badukdol[i][j + 1] == 2 && badukdol[i][j + 2] == 2 && badukdol[i][j + 3] == 2 && badukdol[i][j + 4] == 2)
			{
				gotoxy(1, 23);
				printf("[백돌 승리]");
				exit(0);
			}//백돌 가로

			else if (badukdol[j][i] == 1 && badukdol[j + 1][i] == 1 && badukdol[j + 2][i] == 1 && badukdol[j + 3][i] == 1 && badukdol[j + 4][i] == 1)
			{
				gotoxy(1, 23);
				printf("[흑돌 승리]");
				exit(0);
			} //흑돌 세로

			else if (badukdol[j][i] == 2 && badukdol[j + 1][i] == 2 && badukdol[j + 2][i] == 2 && badukdol[j + 3][i] == 2 && badukdol[j + 4][i] == 2)
			{
				gotoxy(1, 23);
				printf("[백돌 승리]");
				exit(0);
			}//백돌 세로

			else if (badukdol[i][j] == 1 && badukdol[i + 1][j + 1] == 1 && badukdol[i + 2][j + 2] == 1 && badukdol[i + 3][j + 3] == 1 && badukdol[i + 4][j + 4] == 1)
			{
				gotoxy(1, 23);
				printf("[흑돌 승리]");
				exit(0);
			}// 흑돌 왼쪽위대각선

			else if (badukdol[i][j] == 2 && badukdol[i + 1][j + 1] == 2 && badukdol[i + 2][j + 2] == 2 && badukdol[i + 3][j + 3] == 2 && badukdol[i + 4][j + 4] == 2)
			{
				gotoxy(1, 23);
				printf("[백돌 승리]");
				exit(0);
			}// 백돌 왼쪽위각선

			else if (badukdol[19 - j][i] == 1 && badukdol[18 - j][i + 1] == 1 && badukdol[17 - j][i + 2] == 1 && badukdol[16 - j][i + 3] == 1 && badukdol[15 - j][i + 4] == 1)
			{
				gotoxy(1, 23);
				printf("[흑돌 승리]");
				exit(0);
			} //흑돌 아래쪽대각선

			else if (badukdol[19 - j][i] == 2 && badukdol[18 - j][i + 1] == 2 && badukdol[17 - j][i + 2] == 2 && badukdol[16 - j][i + 3] == 2 && badukdol[15 - j][i + 4] == 2)
			{
				gotoxy(1, 23);
				printf("[백돌 승리]");
				exit(0);
			} //백돌 아래쪽대각선
		}
	}
	return 0;
}

