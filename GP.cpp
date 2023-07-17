#include <windows.h>
#include <TCHAR.H>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hwnd;
    MSG msg;
    WNDCLASS WndClass;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    WndClass.lpfnWndProc = WndProc;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.lpszClassName = _T("Window Class Name");
    WndClass.lpszMenuName = NULL;
    RegisterClass(&WndClass);
    hwnd = CreateWindow(_T("Window Class Name"),
        _T("Window Title Name"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
};
ShowWindow(hwnd, nCmdShow);
UpdateWindow(hwnd);
while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessag(&msg);
    DispatchMessage(&msg);
}
return(int)msg.wParam;



LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    static int x, y;
    static RECT rectView;
    static bool flag;

    switch (iMsg)
    {
    case WM_CREATE:
        GetClientRect(hwnd, &rectView);
        x = 20; y = 20;
        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        if (flag)
        { 
            SelectObject(hdc, GetStockObject(LTGRAY_BRUSH));
        }
        Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
        EndPaint(hwnd, &ps);
        break;

    case WM_KEYUP:
        flag = false;
        InvalidateRgn(hwnd, NULL, TRUE);
        break;

    case WM_KEYDOWN:
        if (wParam == VK_RIGHT) 
        {
            flag = true;
            x += 40;
            if (x + 20 > rectView.right)
                x -= 40;
        }
        else if (wParam == VK_LEFT)
        {
            flag = true;
            x -= 40;
            if (x - 20 < rectView.left)
                x += 40;
        }
        else if (wParam == VK_UP)
        {
            flag = true;
            y -= 40;
            if (y - 20 < rectView.top)
                y += 40;
        }
        else if (wParam == VK_DOWN) 
        {
            flag = true;
            y += 40;
            if (y + 20 > rectView.bottom)
                y -= 40;

        }
        InvalidateRgn(hwnd, NULL, TRUE);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}


