#include <windows.h>
#include "framework.h"
#include "WinApiPoj.h"
#include "resource.h"
#include <commdlg.h>
#include<cmath>
#include<ctime>
#include<stdio.h>
#include<windowsx.h>

// ���� ȭ�� ũ��
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int SNAKE_START_X = 10;
const int SNAKE_START_Y = 10;
const int SNAKE_START_LENGTH = 3;

enum Direction { UP, DOWN, LEFT, RIGHT };

struct SnakeSegment {
    int x, y;
};

SnakeSegment snake[100];  // ������ũ �迭
Direction snakeDirection; // ������ũ �̵� ����
int snakeLength;          // ������ũ ����
bool gameOver;            // ���� ���� ����

void InitializeGame();
void ProcessInput();
void UpdateGame();
void DrawGame(HDC hdc);

// ���� �ʱ�ȭ
void InitializeGame()
{
    snake[0].x = SNAKE_START_X;
    snake[0].y = SNAKE_START_Y;
    snakeLength = SNAKE_START_LENGTH;
    snakeDirection = RIGHT;
    gameOver = false;


}

// Ű���� �Է� �Լ�
void ProcessInput()
{
    if (GetAsyncKeyState(VK_UP) && snakeDirection != DOWN)
        snakeDirection = UP;
    else if (GetAsyncKeyState(VK_DOWN) && snakeDirection != UP)
        snakeDirection = DOWN;
    else if (GetAsyncKeyState(VK_LEFT) && snakeDirection != RIGHT)
        snakeDirection = LEFT;
    else if (GetAsyncKeyState(VK_RIGHT) && snakeDirection != LEFT)
        snakeDirection = RIGHT;
}


void UpdateGame()
{
    // ������ũ �̵�
    for (int i = snakeLength - 1; i > 0; --i)
    {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }

    switch (snakeDirection)
    {
    case UP:
        snake[0].y--;
        break;
    case DOWN:
        snake[0].y++;
        break;
    case LEFT:
        snake[0].x--;
        break;
    case RIGHT:
        snake[0].x++;
        break;
    }

    // ������ũ�� ȭ���� ������� üũ
    if (snake[0].x < 0 || snake[0].x >= SCREEN_WIDTH ||
        snake[0].y < 0 || snake[0].y >= SCREEN_HEIGHT)
    {
        gameOver = true;
    }
}

// ���� ȭ�� �׸��� �Լ�
void DrawGame(HDC hdc)
{
    // ��� �����
    RECT rect;
    rect.left = 0;
    rect.top = 0;
    rect.right = SCREEN_WIDTH;
    rect.bottom = SCREEN_HEIGHT;
    FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

    // ������ũ
    for (int i = 0; i < snakeLength; i++)
    {
        Rectangle(hdc, snake[i].x, snake[i].y, snake[i].x + 10, snake[i].y + 10);
    }
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        InitializeGame();
        SetTimer(hwnd, 1, 10, NULL); // 10ms���� Ÿ�̸� �߻�
        break;
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_TIMER:
        if (!gameOver)
        {
            ProcessInput();
            UpdateGame();
            InvalidateRect(hwnd, NULL, FALSE);
        }
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        DrawGame(hdc);
        
        EndPaint(hwnd, &ps);
        break;
    }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


HWND CreateGameWindow(HINSTANCE hInstance)
{
    const wchar_t CLASS_NAME[] = L"SnakeGame";
    const wchar_t WINDOW_NAME[] = L"Snake Game";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    return CreateWindowEx(
        0,
        CLASS_NAME,
        WINDOW_NAME,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL);
}
