#include <windows.h>

// 전역 변수
int x = 0;
int y = 0;

// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        // 현재 위치에서 이전 위치로 선 그리기
        MoveToEx(hdc, 0, 0, NULL);
        LineTo(hdc, x, y);
        EndPaint(hWnd, &ps);
        break;

    case WM_KEYDOWN:
        switch (wParam) {
        case VK_LEFT:
            x -= 10;
            break;
        case VK_UP:
            y -= 10;
            break;
        case VK_RIGHT:
            x += 10;
            break;
        case VK_DOWN:
            y += 10;
            break;
        }
        // WM_PAINT 메시지를 다시 보내서 화면을 업데이트
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


