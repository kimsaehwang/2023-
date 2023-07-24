#include "framework.h"
//#include "WinApiPoj.h"
#include "resource.h"
#include <commdlg.h>
#include<cmath>
#include<ctime>
#include<stdio.h>
#include<windowsx.h>
#include <vector>
#include "WinApiPoj.h"
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
#include <iostream>

using namespace std;
const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 1500;
const int CIRCLE_RADIUS = 5;
const int MOVE_STEP = 5;

RECT rectView;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPIPOJ, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIPOJ));

    MSG msg;

    while (true)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
    }
    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIPOJ));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPIPOJ);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);
    return NULL;
    
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, _T("GalsPanic"), WS_OVERLAPPEDWINDOW,
        200, 200, 700, 800, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}


#define timer_ID_2 123
static int prevX = 0;
static int prevY = 0;
static int xPos = WINDOW_WIDTH / 2;
static int yPos = WINDOW_HEIGHT / 2;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

std::vector<POINT> pathPoints; // 원의 이동 경로를 저장하는 벡터

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    static bool flag;
    static RECT rectView;
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    switch (message) 
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
        xPos = 10;
        yPos = 10;
        break;

    case WM_PAINT:
    {
        Rectangle(hdc, 5, 5, 690, 735);
        if (flag)
            SelectObject(hdc, GetStockObject(BLACK_BRUSH));
        Ellipse(hdc, xPos - CIRCLE_RADIUS, yPos - CIRCLE_RADIUS, xPos + CIRCLE_RADIUS, yPos + CIRCLE_RADIUS);

        if (!pathPoints.empty()) 
        {
            MoveToEx(hdc, pathPoints[0].x, pathPoints[0].y, NULL);
            for (size_t i = 1; i < pathPoints.size(); ++i)
            {
                LineTo(hdc, pathPoints[i].x, pathPoints[i].y);
            }
        }
        EndPaint(hWnd, &ps);
    }
    break;

    case WM_KEYDOWN:
        flag = true;
        switch (wParam)
        {
        case VK_LEFT:
            xPos -= MOVE_STEP;
            if (xPos < CIRCLE_RADIUS)
            {
                xPos = CIRCLE_RADIUS;
                cout << "LEFT end" << endl;
            }
            break;
        case VK_RIGHT:
            xPos += MOVE_STEP;
            if (xPos > rectView.right - CIRCLE_RADIUS)
            {
                xPos = rectView.right - CIRCLE_RADIUS;
                cout << "RIGHT end" << endl;
            }
            break;
        case VK_UP:
            yPos -= MOVE_STEP;
            if (yPos < CIRCLE_RADIUS)
            {
                yPos = CIRCLE_RADIUS;
                cout << "UP end" << endl;
            }
            break;
        case VK_DOWN:
            yPos += MOVE_STEP;
            if (yPos > rectView.bottom - CIRCLE_RADIUS)
            {
                yPos = rectView.bottom - CIRCLE_RADIUS;
                cout << "DOWN end" << endl;
            }
            break;
        default:
            break;
        }

        POINT point;
        point.x = xPos;
        point.y = yPos;
        pathPoints.push_back(point);

        if (wParam == VK_RIGHT)
        {
            SetTimer(hWnd, 1, 70, NULL);
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;

        
    case WM_KEYUP:
        flag = false;
        InvalidateRgn(hWnd, NULL, TRUE);
        break;

    case WM_TIMER:
        InvalidateRgn(hWnd, NULL, TRUE);
        break;

    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}