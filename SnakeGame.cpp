#include <windows.h>
#include "framework.h"
#include "WinApiPoj.h"
#include "resource.h"
#include <commdlg.h>
#include<cmath>
#include<ctime>
#include<stdio.h>
#include<windowsx.h>

// 게임 화면 크기
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int SNAKE_START_X = 10;
const int SNAKE_START_Y = 10;
const int SNAKE_START_LENGTH = 3;

enum Direction { UP, DOWN, LEFT, RIGHT };

struct SnakeSegment {
    int x, y;
};

SnakeSegment snake[100];  // 스네이크 배열
Direction snakeDirection; // 스네이크 이동 방향
int snakeLength;          // 스네이크 길이
int fruitX, fruitY;       // 과일의 위치
bool gameOver;            // 게임 오버 여부

void InitializeGame();
void ProcessInput();
void UpdateGame();
void DrawGame(HDC hdc);

// 게임 초기화
void InitializeGame()
{
    snake[0].x = SNAKE_START_X;
    snake[0].y = SNAKE_START_Y;
    snakeLength = SNAKE_START_LENGTH;
    snakeDirection = RIGHT;
    gameOver = false;

    // 초기 과일 위치 설정
    fruitX = rand() % SCREEN_WIDTH;
    fruitY = rand() % SCREEN_HEIGHT;
}

// 키보드 입력 함수
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
    // 스네이크 이동
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

    // 스네이크와 과일 충돌 체크
    if (snake[0].x == fruitX && snake[0].y == fruitY)
    {
        snakeLength++;
        // 새로운 과일 위치 설정
        fruitX = rand() % SCREEN_WIDTH;
        fruitY = rand() % SCREEN_HEIGHT;
    }

    // 스네이크 자기 자신과 충돌 체크
    for (int i = 1; i < snakeLength; ++i)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            gameOver = true;
            break;
        }
    }

    // 스네이크가 화면을 벗어나는지 체크
    if (snake[0].x < 0 || snake[0].x >= SCREEN_WIDTH ||
        snake[0].y < 0 || snake[0].y >= SCREEN_HEIGHT)
    {
        gameOver = true;
    }
}

// 게임 화면 그리기 함수
void DrawGame(HDC hdc)
{
    // 배경 지우기
    RECT rect;
    rect.left = 0;
    rect.top = 0;
    rect.right = SCREEN_WIDTH;
    rect.bottom = SCREEN_HEIGHT;
    FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

    // 스네이크
    for (int i = 0; i < snakeLength; i++)
    {
        Rectangle(hdc, snake[i].x, snake[i].y, snake[i].x + 10, snake[i].y + 10);
    }

    // 먹이
    Ellipse(hdc, fruitX, fruitY, fruitX + 10, fruitY + 10);

    // 게임 오버 텍스트 그리기
    if (gameOver)
    {
        SetTextColor(hdc, RGB(255, 255, 255));
        SetBkMode(hdc, TRANSPARENT);
        TextOut(hdc,10,10,TEXT("GAME OVER"),30);
    }
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        InitializeGame();
        SetTimer(hwnd, 1, 10, NULL); // 10ms마다 타이머 발생
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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd = CreateGameWindow(hInstance);
    if (hwnd == NULL)
        return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}