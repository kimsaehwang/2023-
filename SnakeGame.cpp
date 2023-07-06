// Windows ��� ����
// C ��Ÿ�� ��� �����Դϴ�.
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

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
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

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPIPOJ, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���ø����̼� �ʱ�ȭ�� �����մϴ�:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIPOJ));

    MSG msg;
    // �⺻ �޽��� �����Դϴ�:
    
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}
//  �Լ�: MyRegisterClass()
//
//  �뵵: â Ŭ������ ����մϴ�.

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
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

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
        hdc = GetDC(hWnd); //DC����� ��� 1
        ReleaseDC(hWnd, hdc);

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
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
