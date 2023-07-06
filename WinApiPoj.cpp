// WinApiPoj.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WinApiPoj.h"
#include "resource.h"
#include <commdlg.h>
#include<cmath>
#include<ctime>
#include<stdio.h>
#include<windowsx.h>

// >>:
#pragma comment(lib,"msimg32.lib")

HBITMAP hBackImage;
BITMAP bitBack;

HBITMAP hFrontImage;
BITMAP bitFront;

HBITMAP hTransparentImage;
BITMAP bitTransparent;

// >> : ANI
HBITMAP hAniImage;
BITMAP bitAni;
const int SPRITE_SIZE_X = 57;
const int SPRITE_SIZE_Y = 52;

int RUN_FRAME_MAX = 0;
int RUN_FRAME_MIN = 0;
int curframe = RUN_FRAME_MIN;

int SPRITE_FRAME_COUNT_X = 0;
int SPRITE_FRAME_COUNT_Y = 0;
// << : ANI

// >> :함수
RECT rectView;

void CreateBitmap();
void DrawBitmap(HWND hWnd, HDC hdc);
void DestroyBitmap();
void UpdateFrame(HWND hWnd);
void DrawRectText(HDC hdc);
VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void Update();
void Render();
// <<:함수

// >>:더블버퍼링
HBITMAP hDoubleBufferImage;
void DrawBitmapDoubleBuffering(HWND hwnd, HDC hdc);

// <<:더블버퍼링

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
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIPOJ));

    MSG msg;

    // 기본 메시지 루프입니다:
    /*
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    */
    while (true)
    {
        if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
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
        else
        {
            //Update();
            //Render();
        }
    }
    return (int) msg.wParam;
}


void CreateBitmap()
{
    {
        hBackImage = (HBITMAP)LoadImage(NULL, TEXT("image/수지.bmp"),
            IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        if (hBackImage == NULL)
        {
            DWORD dwError = GetLastError();
            MessageBox(NULL, _T("이미지 로드 에러"), _T("에러"), MB_OK);
            return;
        }
        GetObject(hBackImage, sizeof(BITMAP), &bitBack);
    }

    {
        hTransparentImage = (HBITMAP)LoadImage(NULL, TEXT("image/sigong.bmp"),
            IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        if (hTransparentImage == NULL)
        {
            DWORD dwError = GetLastError();
            MessageBox(NULL, _T("이미지 로드 에러 2"), _T("에러"), MB_OK);
            return;
        }
        GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);
    }

    {
        hAniImage = (HBITMAP)LoadImage(NULL, TEXT("image/zero_run.bmp"),
            IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        if (hAniImage == NULL)
        {
            DWORD dwError = GetLastError();
            MessageBox(NULL, _T("이미지 로드 에러 3"), _T("에러"), MB_OK);
            return;
        }
        GetObject(hAniImage, sizeof(BITMAP), &bitAni);

        SPRITE_FRAME_COUNT_X = bitAni.bmWidth / SPRITE_SIZE_X;
        SPRITE_FRAME_COUNT_Y = bitAni.bmHeight / SPRITE_SIZE_Y;
    }

    {
        hFrontImage = (HBITMAP)LoadImage(NULL, TEXT("image/Background.bmp"),
            IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        if (hFrontImage == NULL)
        {
            DWORD dwError = GetLastError();
            MessageBox(NULL, _T("이미지 로드 에러4"), _T("에러"), MB_OK);
            return;
        }
        GetObject(hFrontImage, sizeof(BITMAP), &bitFront);
    }
}

void DrawBitmap(HWND hWnd, HDC hdc)
{
    HDC hMemDC;
    HBITMAP hOldBitmap;
    int bx, by;

    { //수지
        hMemDC = CreateCompatibleDC(hdc);
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
        bx = bitBack.bmWidth;
        by = bitBack.bmHeight;

        BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);

        //SelectObject(hMemDC, hOldBitmap);
        DeleteDC(hMemDC);
    }

    {//시공
        hMemDC = CreateCompatibleDC(hdc);
       hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTransparentImage);
        bx = bitTransparent.bmWidth;
        by = bitTransparent.bmHeight;


        //BitBlt(hdc, 150, 150, bx, by, hMemDC, 0, 0, SRCCOPY);
        TransparentBlt(hdc, 150, 150, bx * 2, by * 2, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));

        TransparentBlt(hdc, 150, 300, bx / 2, by / 2, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));

        //SelectObject(hMemDC, hOldBitmap);
        DeleteDC(hMemDC);
    }

    {//ANI
        hMemDC = CreateCompatibleDC(hdc);
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage);
        bx = bitAni.bmWidth / SPRITE_FRAME_COUNT_X;
        by = bitAni.bmHeight / SPRITE_FRAME_COUNT_Y;

       //BitBlt(hdc, 150, 150, bx, by, hMemDC, 0, 0, SRCCOPY);
        int xStart = curframe * bx;
        int yStart = 0;
        TransparentBlt(hdc, 250, 150, bx * 2, by * 2, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));
        TransparentBlt(hdc, 250, 150, bx / 2, by / 2, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));
        //SelectObject(hMemDC, hOldBitmap);
        DeleteDC(hMemDC);
    }
}
void DestroyBitmap()
{
    DeleteObject(hAniImage);
    DeleteObject(hBackImage);
    DeleteObject(hTransparentImage);
}
void UpdateFrame(HWND hWnd)
{
    curframe++;
    if (curframe > RUN_FRAME_MAX)
        curframe = RUN_FRAME_MIN;
    InvalidateRgn(hWnd, NULL, false);
}

static int yPos = 0;
void DrawRectText(HDC hdc)
{
   
    TCHAR strTest[] = _T("이미지 출력");
    TextOut(hdc, 10, yPos, strTest, _tcslen(strTest));
}

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
    UpdateFrame(hWnd);

    yPos += 5;
    if (yPos > rectView.bottom)yPos = 0;
}

void Update()
{
    // : WM_KEYDOWN , WM_KEYUP
    if (GetKeyState('A') & 0x8000)
    {
    }

    if (GetKeyState('D') & 0x8000)
    {
    }

    if (GetKeyState('W') & 0x8000)
    {
    }

    if (GetKeyState('s') & 0x8000)
    {
    }
}

void Render()
{
}

void DrawBitmapDoubleBuffering(HWND hwnd, HDC hdc)
{
    HDC hMemDC;
    HBITMAP hOldBitmap;
    int bx, by;

    HDC hMemDC2;
    HBITMAP hOldBitmap2;

    hMemDC = CreateCompatibleDC(hdc);
    if (hDoubleBufferImage == NULL)
    {
        hDoubleBufferImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
    }
    hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBufferImage);

    { //수지
        hMemDC2 = CreateCompatibleDC(hMemDC);
        hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
        bx = bitBack.bmWidth;
        by = bitBack.bmHeight;

        BitBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);

        SelectObject(hMemDC2, hOldBitmap2);
        DeleteDC(hMemDC2);
    }

    {//시공
        hMemDC2 = CreateCompatibleDC(hMemDC);
        hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hTransparentImage);
        bx = bitTransparent.bmWidth;
        by = bitTransparent.bmHeight;


        //BitBlt(hdc, 150, 150, bx, by, hMemDC, 0, 0, SRCCOPY);
        TransparentBlt(hMemDC, 150, 150, bx * 2, by * 2, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));

        TransparentBlt(hMemDC, 150, 300, bx / 2, by / 2, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));

        SelectObject(hMemDC2, hOldBitmap2);
        DeleteDC(hMemDC2);
    }

    {//ani
        hMemDC2 = CreateCompatibleDC(hMemDC);
        hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hAniImage);
        bx = bitAni.bmWidth / SPRITE_FRAME_COUNT_X;
        by = bitAni.bmHeight / SPRITE_FRAME_COUNT_Y;

        int xStart = curframe * bx;
        int yStart = 0;
        
        static int xPos = 0;
        TransparentBlt(hMemDC, xPos + 150, 300, bx, by, hMemDC2, xStart, yStart, bx, by, RGB(255, 0, 255));
        DeleteDC(hMemDC2);

        xPos++;
        SelectObject(hMemDC2, hOldBitmap2);
        DeleteDC(hMemDC2);
    }
    // <<: hMemDC 에 그려주기

    { //Background
        hMemDC2 = CreateCompatibleDC(hMemDC);
        hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hFrontImage);
        bx = bitFront.bmWidth;
        by = bitFront.bmHeight;

        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hMemDC2, hBrush);

        Ellipse(hMemDC2, 250, 100, 750, 500);

        SelectObject(hMemDC2, oldBrush);
        DeleteObject(hBrush);

        TransparentBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));
        SelectObject(hMemDC2, hOldBitmap2);

        DeleteDC(hMemDC2);
    }

    // >> : hdc에 그려주기
    //BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMemDC, 0, 0, SRCCOPY);
    TransparentBlt(hdc, 0, 0, rectView.right, rectView.bottom, 
                    hMemDC, 0, 0, rectView.right, rectView.bottom,
                    RGB(255, 0, 255));



    SelectObject(hMemDC, hOldBitmap);
    DeleteDC(hMemDC);
}

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIPOJ));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW-2);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPIPOJ);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, _T("szTitle"), WS_OVERLAPPEDWINDOW,
       200, 200, 1024, 768, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
/*void OutFromFile(TCHAR filename[], HWND hWnd)
{
    FILE* fptr;
    HDC hdc;
    int line;
    TCHAR buffer[500];
    line = 0;
    hdc = GetDC(hWnd);
#ifdef _UNICODE
    _tfopen_s(&fptr, filename, _T("r,ccs = UNICODE"));
#else
    _tfopen_s(&fptr, filename, _T("r"));
#endif
    while (_fgetts(buffer, 100, fptr) != NULL)
    {
        if (buffer[_tcslen(buffer) - 1] == _T('\n'))
            buffer[_tcslen(buffer) - 1] = NULL;
        TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
        line++;
    }
    fclose(fptr);
    ReleaseDC(hWnd, hdc);
}*/

#define timer_ID_2 123
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc, memdc;
    PAINTSTRUCT ps;
    static BOOL bFlag;
    switch (message)
    {
    case WM_SIZE://윈도우 크기 변경할때마다 가져옴
        GetClientRect(hWnd, &rectView);
        break;

    case WM_CREATE:
    {
        CreateBitmap();
        GetClientRect(hWnd, &rectView);
        SetTimer(hWnd, timer_ID_2, 30, AniProc);//애니 타이머 콜백가능함
    }
    break;

    case WM_TIMER:
    if (wParam == timer_ID_2)
    {
        UpdateFrame(hWnd);
        InvalidateRgn(hWnd, NULL, TRUE);
    }

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        //DrawBitmap(hWnd, hdc);
        DrawBitmapDoubleBuffering(hWnd, hdc);
        DrawRectText(hdc);
        EndPaint(hWnd, &ps);
        break;
    
    case WM_KEYUP:
    {
        int breakpoint = 999;
        bFlag = FALSE;
        InvalidateRgn(hWnd, NULL, TRUE);
    }
    break;

    case WM_DESTROY:
        KillTimer(hWnd, timer_ID_2);
        DestroyBitmap();
        break;
    }
    return (DefWindowProc(hWnd, message, wParam, lParam));
}
    /*switch (message)
    {

    case WM_LBUTTONDOWN:
    {
        srand(static_cast<unsigned int>(time(nullptr)));

        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        HDC hdc = GetDC(hWnd);

        int shape = rand() % 3;
        int size = rand() % 100;

        switch (shape)
            {
        case 0:
            Rectangle(hdc, x, y, x + 100, y + 100);
            break;
        case 1:
            Ellipse(hdc, x, y, x + 100, y + 100);
            break;
        case 2:
            POINT center = { x, y };
            star(hdc, center, size, 5);
            break;
        }
        ReleaseDC(hWnd, hdc);
        break;
    }


    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return(DefWindowProc(hWnd, message, wParam, lParam));*/
    /*
    HDC hdc;
    PAINTSTRUCT ps;
    static int x, y, circleRadius;
    static BOOL selectedMenu;
    static BOOL bFlag;
    static BOOL COPY;
    enum {CIRCLE,RECTANGLE,STAR,NONE};
    static POINT ptMousePos;
    static POINT ptCurPos;
    static RECT rectView;
    static HMENU hMenu, hSubMenu;
    OPENFILENAME OFN;
    TCHAR lpstrFile[100] = _T("");
    TCHAR filter[] = _T("Every file(*.*) \0*.*\0Text file\0*.txt;*.doc\0");

    switch (message)
    {
    case WM_CREATE:

        hMenu = GetMenu(hWnd);
        hSubMenu = GetSubMenu(hMenu, 2);
        COPY = FALSE;
        EnableMenuItem(hSubMenu, ID_EDIT_PASTE, MF_GRAYED);
        EnableMenuItem(hSubMenu, ID_EDIT_COPY, MF_GRAYED);
        break;

    case WM_COMMAND:
       {
        int wmId = LOWORD(wParam);
        *switch (wmId)
            * {
        *case ID_DRAW_CIRCLE:
            * {
                int temp = selectedMenu;
                int ans = MessageBox(hWnd, _T("원 그릴래?"), _T("도형 선택"), MB_YESNOCANCEL);
                if (ans == IDYES)
                {
                    selectedMenu = CIRCLE;
                }
                else if (ans == IDNO)
                {
                    selectedMenu = NONE;
                }
                else
                {
                    selectedMenu = temp;
                }
            }
            selectedMenu = CIRCLE;
        }
        break;
    case ID_DRAW_RECTANGLE:
        selectedMenu = RECTANGLE;
        break;
    case ID_DRAW_STAR:
        selectedMenu = STAR;
        break;
        if (LOWORD(wParam) == ID_EDIT_COPY)
        {
            COPY = TRUE;
            InvalidateRgn(hWnd, NULL, TRUE);
        }
        switch (LOWORD(wParam))
        {
        case ID_FILEOPEN:
            memset(&OFN, 0, sizeof(OPENFILENAME));
            OFN.lStructSize = sizeof(OPENFILENAME);
            OFN.hwndOwner = hWnd;
            OFN.lpstrFilter = filter;
            OFN.lpstrFile = lpstrFile;
            OFN.nMaxFile = 256;
            OFN.lpstrInitialDir = _T(".");
            if (GetOpenFileName(&OFN) != 0)
                OutFromFile(OFN.lpstrFile, hWnd);
            break;
        }
    }
        break;
    case WM_LBUTTONDOWN:
        ptMousePos.x = LOWORD(lParam);
        ptMousePos.y = HIWORD(lParam);
        ptCurPos.x += circleRadius;
        if (ptCurPos.x + circleRadius > rectView.right)
            ptCurPos.x = rectView.right - circleRadius;

        if (wParam == VK_RIGHT || wParam == VK_LEFT || wParam == VK_UP || wParam == VK_DOWN)
        {
            bFlag = TRUE;
        }

        if (wParam == 'C' || wParam == 'c')
        {
            UINT state = GetMenuState(hSubMenu, ID_EDIT_COPY, MF_BYCOMMAND);
            if ((state == MF_DISABLED) || (state == MF_GRAYED))
            {
                EnableMenuItem(hSubMenu, ID_EDIT_COPY, MF_ENABLED);
            }
            else if (state == MF_ENABLED)
            {
                EnableMenuItem(hSubMenu, ID_EDIT_COPY, MF_GRAYED);
            }
        }
        InvalidateRgn(hWnd, NULL, TRUE);
        break;

    case WM_KEYUP:
    {
        int breakpoint = 999;
        bFlag = FALSE;
        InvalidateRgn(hWnd, NULL, TRUE);
    }
    break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        switch (selectedMenu)
        {
        case CIRCLE:
        {
            static TCHAR str[100] = L"원";
            TextOut(hdc, ptMousePos.x, ptMousePos.y, str, _tcslen(str));
        }
        break;
        case RECTANGLE:
        {
            static TCHAR str[100] = L"사각형";
            TextOut(hdc, ptMousePos.x, ptMousePos.y, str, _tcslen(str));
        }
        break;
        case STAR:
        {
            static TCHAR str[100] = L"별";
            TextOut(hdc, ptMousePos.x, ptMousePos.y, str, _tcslen(str));
        }
        break;
        case NONE:
        {
            static TCHAR str[100] = L"아무일도 일어나지 않음";
            TextOut(hdc, ptMousePos.x, ptMousePos.y, str, _tcslen(str));
        }
        default:
            break;
        }
        EndPaint(hWnd, &ps);
        break;


    case ID_FILEOPEN:
    {
        TCHAR filter[] = _T("Every file(*.*) \0*.*\0Text file\0*.txt;*.doc\0");
        TCHAR lpstrFile[100] = _T("");

        OPENFILENAME ofn;
        memset(&ofn, 0, sizeof(OPENFILENAME));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = hWnd;
        ofn.lpstrFilter = filter;
        ofn.lpstrFile = lpstrFile;
        ofn.nMaxFile = 100;
        ofn.lpstrInitialDir = _T(".");
        if (GetOpenFileName(&ofn) != 0)
        {
            TCHAR str[100];
            _stprintf_s(str, _T("%s 파일을 열겠습니까?"), ofn.lpstrFile);
            MessageBox(hWnd, str, _T("파일 선택"), MB_OK);
        }
    }
    break;
    case IDM_ABOUT:
        DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
    case IDM_EXIT:
        DestroyWindow(hWnd);
        break;
    }

    return (DefWindowProc(hWnd, message, wParam, lParam));
}

void DrawCircle(HDC hdc, POINT pt, BOOL bFlag)
{
    if (bFlag)
        SelectObject(hdc, GetStockObject(LTGRAY_BRUSH));
}*/

    //void star(HDC hdc, POINT& center, double radius, int n)
//{
//    POINT points[10];
//    double angle = 2.0 * PI / n;
//    for (int j = 0; j < n * 2; j++)
//    {
//        double currentAngle = j * angle;
//        int px = center.x + static_cast<int>(radius * sin(currentAngle));
//        int py = center.y + static_cast<int>(radius * cos(currentAngle));
//        points[j % n] = { px, py };
//    }
//    Polygon(hdc, points, n);
//}



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
