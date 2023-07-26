#include "framework.h"
#include "WinApiPoj.h"
#include <time.h>
#include<process.h>
#include <cmath>
#include <windowsx.h>
#include <Windows.h>

#define MAX_LOADSTRING 100

// ���� ����:
HWND hWnd;
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
unsigned __stdcall ThFunc(LPVOID lpParam);

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

    return (int)msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  �뵵: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_WINAPIPOJ));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPIPOJ);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   �뵵: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   �ּ�:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//

//int xPos1, yPos1, r, g, b;
//unsigned __stdcall ThFunc(LPVOID lpParam)
//{
//    HDC hdc;
//    int xPos, yPos;
//
//    hdc = GetDC(hWnd);
//    xPos = xPos1;
//    yPos = yPos1;
//    SelectObject(hdc, CreateSolidBrush(RGB(r, g, b)));
//    Ellipse(hdc, xPos - 10, yPos - 10, xPos + 10, yPos + 10);
//    for(int i=0;i<50;i++)
//    {
//        Sleep(1000);
//        Ellipse(hdc, xPos - 10, yPos - 10, xPos + 10, yPos + 10);
//        SelectObject(hdc, CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
//    }
//    ReleaseDC(hWnd, hdc);
//    return 0;
//}


//#define THREAD_NUM 50
//int xPos, yPos;
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    HDC hdc;
//    PAINTSTRUCT ps;
//    static HANDLE hThread[THREAD_NUM];
//    static int count = 0;
//    static RECT rt;
//
//    switch (message)
//    {
//    case WM_CREATE:
//        GetClientRect(hWnd, &rt);
//        break;
//    case WM_LBUTTONDOWN:
//        xPos1 = GET_X_LPARAM(lParam);
//        yPos1 = GET_Y_LPARAM(lParam);
//        r = rand() % 256;
//        g = rand() % 256;
//        b = rand() % 256;
//        InvalidateRect(hWnd, NULL, TRUE);
//        hThread[count] = (HANDLE)_beginthreadex(NULL, 0, (unsigned int(__stdcall*)(void*))ThFunc, NULL, 0, NULL);
//        count++;
//        break;
//    case WM_COMMAND:
//    {
//        int wmId = LOWORD(wParam);
//        // �޴� ������ ���� �м��մϴ�:
//        switch (wmId)
//        {
//        case IDM_ABOUT:
//            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//            break;
//        case IDM_EXIT:
//            DestroyWindow(hWnd);
//            break;
//        default:
//            return DefWindowProc(hWnd, message, wParam, lParam);
//        }
//    }
//    break;
//    case WM_PAINT:
//    {
//        PAINTSTRUCT ps;
//        HDC hdc = BeginPaint(hWnd, &ps);
//        EndPaint(hWnd, &ps); // ���⼭ EndPaint �Լ��� ȣ������ �ʽ��ϴ�.
//    }
//    break;
//
//    case WM_DESTROY:
//        for (int i = 0; i < THREAD_NUM; i++)
//            CloseHandle(hThread[i]);
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}

#define THREAD_NUM 50
int xPos, yPos;
COLORREF circleColor = RGB(0, 0, 0);
bool drawCircle = false;
CRITICAL_SECTION cs;
BOOL isDrawing = FALSE;

unsigned int __stdcall ThFunc(void*)
{
    HDC hdc = GetDC(NULL);
    HBRUSH hBrush = NULL; 
    SelectObject(hdc, CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
    while (drawCircle)
    {
        EnterCriticalSection(&cs);
        {
            Ellipse(hdc, xPos - 10, yPos - 10, xPos + 10, yPos + 10);
        }
        LeaveCriticalSection(&cs);
        Sleep(1000);
    }
    return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HANDLE hThread;
    DWORD dwThIDs;
    int count =0;
    HDC hdc = GetDC(hWnd);
    switch (message)
    {
    case WM_CREATE:
        InitializeCriticalSection(&cs);
    break;

    case WM_LBUTTONDOWN:
    {
        if (!isDrawing)
        {
            xPos = GET_X_LPARAM(lParam);
            yPos = GET_Y_LPARAM(lParam);
            drawCircle = TRUE;
            InvalidateRect(hWnd, NULL, FALSE);

            if (count < THREAD_NUM)
            {
                Ellipse(hdc, xPos - 10, yPos - 10, xPos + 10, yPos + 10);
                hThread = (HANDLE)_beginthreadex(NULL, 0, ThFunc, NULL, 0, NULL);
                count++;
            }
        }
    }
    break;

    case WM_COMMAND:
    {
        // �޴� ������ ���� �м��մϴ�:
        switch (LOWORD(wParam))
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;

    case WM_DESTROY:
        CloseHandle(hThread);
        DeleteCriticalSection(&cs);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
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


