#include "framework.h"
#include "WinApiPoj.h"
#include "resource.h"
#include <commdlg.h>
#include<cmath>
#include<ctime>
#include<stdio.h>
#include<windowsx.h>
#include <vector>
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 600;
const int CIRCLE_RADIUS = 10;
const int MOVE_STEP = 5;

RECT rectView;

#define MAX_LOADSTRING 100

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
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

    HWND hWnd = CreateWindowW(szWindowClass, _T("GalsPanic"), WS_OVERLAPPEDWINDOW,
        200, 200, 500, 600, nullptr, nullptr, hInstance, nullptr);

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

std::vector<POINT> pathPoints; // ���� �̵� ��θ� �����ϴ� ����

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    static bool flag;
    static RECT rectView;
    switch (message) 
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
        xPos = 10;
        yPos = 10;
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // �׸��� �۾�
        if (flag)
            SelectObject(hdc, GetStockObject(LTGRAY_BRUSH));
        Ellipse(hdc, xPos - CIRCLE_RADIUS, yPos - CIRCLE_RADIUS, xPos + CIRCLE_RADIUS, yPos + CIRCLE_RADIUS);

        // �� �׸��� �۾�
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
            break;
        case VK_RIGHT:
            xPos += MOVE_STEP;
            break;
        case VK_UP:
            yPos -= MOVE_STEP;
            break;
        case VK_DOWN:
            yPos += MOVE_STEP;
            break;
        default:
            break;
        }

        // ���� �̵� ��θ� ����
        POINT point;
        point.x = xPos;
        point.y = yPos;
        pathPoints.push_back(point);

        // �����츦 �ٽ� �׸����� ��û
        if (wParam == VK_RIGHT)
        {
            SetTimer(hWnd, 1, 70, NULL);
            xPos += 40;
            if (xPos + 20 > rectView.right)xPos -= 40;
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