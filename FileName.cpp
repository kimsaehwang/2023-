#include <windows.h>

// ���� ����
int x = 0;
int y = 0;

// ������ ���ν���
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        // ���� ��ġ���� ���� ��ġ�� �� �׸���
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
        // WM_PAINT �޽����� �ٽ� ������ ȭ���� ������Ʈ
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


