// Windows 헤더 파일
// C 런타임 헤더 파일입니다.
#include "framework.h"
#include "WinApiPoj.h"
#include "resource.h"
#include <commdlg.h>
#include<cmath>
#include<ctime>
#include<stdio.h>
#include<windowsx.h>

#define MAX_LOADSTRING 100

void DrawGrid(HWND hWnd, POINT center, int width, int height, int n = 0);

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
    // 기본 메시지 루프입니다:
    
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.

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
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW - 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPIPOJ);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, _T("Snake Game"), WS_OVERLAPPEDWINDOW,
        200, 200, 1024, 768, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

void DrawGrid(HWND hWnd, POINT center, int width, int height, int n)
{

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    static int x, y;
    static RECT rectView;

    switch (message)
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
        x = 20, y = 20;
        break;

    case WM_LBUTTONDOWN:
        hdc = GetDC(hWnd); //DC을얻는 방법 1
        ReleaseDC(hWnd, hdc);

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        Rectangle(hdc, x - 20, y - 20, x + 20, y + 20);
        EndPaint(hWnd, &ps);
        break;
  
    case WM_KEYDOWN:
        if (wParam == VK_RIGHT)SetTimer(hWnd, 1, 70, NULL);
        if (wParam == VK_LEFT)SetTimer(hWnd, 1, 70, NULL);
        if (wParam == VK_UP)SetTimer(hWnd, 1, 70, NULL);
        if (wParam == VK_DOWN)SetTimer(hWnd, 1, 70, NULL);
        break;

    case WM_TIMER:
        x += 40;
        if (x + 20 > rectView.right) x -= 40;
        InvalidateRgn(hWnd, NULL, TRUE);
        break;

    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break; 
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
