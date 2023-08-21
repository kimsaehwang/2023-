#include <windows.h>
#include <tchar.h>
#include "resource.h"
#pragma comment( lib, "Msimg32.lib" )

HDC g_hmemDC = NULL;
HDC g_hBackBufferDC = NULL;
HBITMAP g_hBackBufferBMP = NULL;
HBITMAP g_hPlayer = NULL;
HBITMAP g_hBGA = NULL;

float g_fTime = 0.f;

enum ENUM_STATE		
{					
    IDLE,
    WALK
};

//플레이어의 이동 방향
enum ENUM_DIRECTION
{
    LEFT,
    RIGHT
};


int Current_Dir = LEFT;//현재 이동 방향을 담는 변수
int Current_State = IDLE;//현재 상태를 담는 변수
bool IsMoving;//현재 상태
int X_pos = 0;//캐릭터의 x,y좌표 위치 변수
int Y_pos = 0;
int X_Src_pos = 0;//해당 모션의 비트맵 x,y좌표
int Y_Src_pos = 0;
int Scene = 0;//장면을 나타내는 변수
int Src_Width = 0;//비트맵이미지에서 해당 모션의 가로길이
int Src_Height = 0;//비트맵이미지에서 해당 모션의 세로길이

HDC memDC;
HBITMAP memBitmap;
POINT stPos;
void CreateBackPage(HWND hWnd, HINSTANCE hInst, HDC* memDC, HBITMAP* memBitmap);

// 전역 변수:
HINSTANCE g_Instance;     

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void MoveToRight(void);
void MoveToLeft(void);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR strCmdLine, int nShowCmd)
{
	g_Instance = hInstance;

	WNDCLASSEX wcex;
	memset(&wcex, 0, sizeof(wcex));

	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hInstance = hInstance;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hIconSm = NULL;
	wcex.lpszMenuName = NULL;
	wcex.lpfnWndProc = WndProc;
	wcex.lpszClassName = L"SuperMario";
	RegisterClassEx(&wcex);

	HWND hWnd = CreateWindow(L"SuperMario", L"SuperMario", WS_OVERLAPPEDWINDOW,
		200, 200, 800, 800, nullptr, nullptr, hInstance, nullptr);

	if (hWnd == NULL)
	{
		MessageBox(NULL, L"윈도우 생성 실패", L"에러", MB_ICONERROR | MB_OK);
		return -1;
	}

	ShowWindow(hWnd, SW_SHOW);

	MSG msg;
	memset(&msg, 0, sizeof(msg));

	
	while (msg.message != WM_QUIT)
	{
		SelectObject(g_hmemDC, g_hBGA);
		BitBlt(g_hBackBufferDC, 0, 0, 800, 800, g_hmemDC, 0, 0, SRCCOPY);

		SelectObject(g_hmemDC, g_hPlayer);
		BitBlt(g_hBackBufferDC, X_pos, Y_pos, Src_Width, Src_Height, g_hmemDC, X_Src_pos, Y_Src_pos, SRCCOPY);

		InvalidateRect(hWnd, NULL, false);

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = 0;

	switch (uMsg)
	{
	//	키보드에서 키가 떼지는 경우
	case WM_KEYUP:
	{
		//	방향 키를 누르고 있다가 떼지면, IDLE 상태가 된다.
		switch (wParam)
		{
		case VK_UP:
		case VK_DOWN:
		case VK_RIGHT:
		case VK_LEFT:
		{
			if (IsMoving == true)
			{
				IsMoving = false;
				Current_State = IDLE;
				Scene = 0;
				Current_Dir = RIGHT;	//	이미지에서 IDLE은 오른쪽 모습만 있어서.
			}
			break;
		}
		}
		break;
	}

	case WM_KEYDOWN:				
	{							
		switch (wParam)
		{
		case VK_UP:
		{
			//	IDLE 상태에서 키가 눌린 경우 
			if (IsMoving == false)
			{
				Scene = 0;
				IsMoving = true;
				Current_State = WALK;
			}

			Y_pos -= 8;

			if (Current_Dir == RIGHT)			MoveToRight();
			else if (Current_Dir == LEFT)		MoveToLeft();

			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}

		case VK_DOWN:
		{
			//	IDLE 상태에서 키가 눌린 경우 
			if (IsMoving == false)
			{
				Scene = 0;
				IsMoving = true;
				Current_State = WALK;
			}

			Y_pos += 8;

			if (Current_Dir == RIGHT)			MoveToRight();
			else if (Current_Dir == LEFT)		MoveToLeft();

			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}

		case VK_RIGHT:				//	오른쪽 방향키 라면
		{
			IsMoving = true;		//	IsMoving은 true값. 이유는 움직이는 상태여서
			Current_State = WALK;	//	움직이니까, 걷는 상태.
			X_pos += 8;				//	플레이어의 좌표를 오른쪽으로 8만큼 이동
			Current_Dir = RIGHT;	//	이동방향 오른쪽으로 설정

			MoveToRight();			//	오른쪽 이동방향으로 프레임 정보 설정

			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}

		case VK_LEFT:				//	오른쪽 방향키 라면
		{
			IsMoving = true;		//	IsMoving은 true값. 이유는 움직이는 상태여서
			Current_State = WALK;	//	움직이니까, 걷는 상태.
			X_pos -= 8;				//	플레이어의 좌표를 왼쪽으로 8만큼 이동
			Current_Dir = LEFT;		//	이동방향 왼쪽으로 설정

			MoveToLeft();			//	왼쪽 이동방향으로 프레임 정보 설정

			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		}
		break;
	}


	case WM_TIMER:
	{
		if (Current_State == IDLE && IsMoving == false)
		{
			if (Scene == 0)					//	0번째 장면이면
			{
				X_Src_pos = 0;					//	0번째 장면의 비트맵이미지의 X좌표 세팅
				Y_Src_pos = 0;					//	0번째 장면의 비트맵이미지의 Y좌표 세팅
				Src_Width = 50;					//	0번째 장면의 비트맵이미지의 가로 길이
				Src_Height = 50;				//	0번째 장면의 비트맵이미지의 세로 길이
				Scene = 1;						//	0번째 장면에서 1번째 장면으로 옮겨줘야 하므로.
			}
			else if (Scene == 1)
			{
				X_Src_pos = 23;
				Y_Src_pos = 0;
				Src_Width = 50;
				Src_Height = 50;
				Scene = 2;
			}
			else if (Scene == 2)
			{
				X_Src_pos = 43;
				Y_Src_pos = 0;
				Src_Width = 50;
				Src_Height = 50;
				Scene = 3;
			}
			else if (Scene == 3)
			{
				X_Src_pos = 64;
				Y_Src_pos = 0;
				Src_Width = 50;
				Src_Height = 50;
				Scene = 4;
			}
			else if (Scene == 4)		//	마지막 장면이다.
			{
				X_Src_pos = 85;
				Y_Src_pos = 0;
				Src_Width = 50;
				Src_Height = 50;
				Scene = 0;				//	마지막 장면이므로, 다시 장면을 0번째 장면으로 이동시킴.
			}
		}
		/*	InvalidateRect 함수를 호출해서, WM_PAINT 메시지를 발생시켜 이미지를 불러온다.	*/
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}

	case WM_CREATE:
	{
		X_pos = 0;
		Y_pos = 0;
		X_Src_pos = 0;
		Y_Src_pos = 37;
		Src_Width = 23;
		Src_Height = 35;

		HDC hDC = GetDC(hWnd);
		g_hmemDC = CreateCompatibleDC(hDC);
		g_hBackBufferDC = CreateCompatibleDC(hDC);

		g_hBackBufferBMP = CreateCompatibleBitmap(hDC, 800, 800);

		SelectObject(g_hBackBufferDC, g_hBackBufferBMP);

		HINSTANCE ins = (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE);

		g_hBGA = LoadBitmap(ins, MAKEINTRESOURCE(IDB_BITMAP1));
		g_hPlayer = LoadBitmap(ins, MAKEINTRESOURCE(IDB_BITMAP4));

		ReleaseDC(hWnd, hDC);
		break;
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hDC = BeginPaint(hWnd, &ps);
		BitBlt(hDC, 0, 0, 800, 800, g_hBackBufferDC, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		break;
	}

	case WM_DESTROY:
	{
		DeleteDC(g_hmemDC);
		DeleteDC(g_hBackBufferDC);

		DeleteObject(g_hBackBufferBMP);
		DeleteObject(g_hPlayer);
		DeleteObject(g_hBGA);

		PostQuitMessage(0);
		break;
	}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void MoveToRight(void)
{
	if (Scene == 0)		//0번째 씬
	{
		X_Src_pos = 0;		//비트맵이미지의 X좌표
		Y_Src_pos = 37;		//비트맵이미지의 Y좌표
		Src_Width = 23;		//비트맵이미지 가로길이
		Src_Height = 36;	//비트맵이미지 세로길이
		Scene = 1;
	}
	else if (Scene == 1)
	{
		X_Src_pos = 23;
		Y_Src_pos = 37;
		Src_Width = 20;
		Src_Height = 36;
		Scene = 2;
	}
	else if (Scene == 2)
	{
		X_Src_pos = 43;
		Y_Src_pos = 37;
		Src_Width = 24;
		Src_Height = 36;
		Scene = 3;
	}
	else if (Scene == 3)
	{
		X_Src_pos = 67;
		Y_Src_pos = 36;
		Src_Width = 25;
		Src_Height = 36;
		Scene = 4;
	}
	else if (Scene == 4)
	{
		X_Src_pos = 92;
		Y_Src_pos = 37;
		Src_Width = 25;
		Src_Height = 36;
		Scene = 5;
	}
	else if (Scene == 5)
	{
		X_Src_pos = 114;
		Y_Src_pos = 37;
		Src_Width = 22;
		Src_Height = 36;
		Scene = 6;
	}
	else if (Scene == 6)
	{
		X_Src_pos = 135;
		Y_Src_pos = 37;
		Src_Width = 21;
		Src_Height = 36;
		Scene = 7;
	}
	else if (Scene == 7)
	{
		X_Src_pos = 159;
		Y_Src_pos = 37;
		Src_Width = 24;
		Src_Height = 36;
		Scene = 0;
	}
}

void MoveToLeft(void)
{
	if (Scene == 0)
	{
		X_Src_pos = 350;
		Y_Src_pos = 36;
		Src_Width = 20;
		Src_Height = 36;
		Scene = 1;
	}
	else if (Scene == 1)
	{
		X_Src_pos = 330;
		Y_Src_pos = 36;
		Src_Width = 20;
		Src_Height = 36;
		Scene = 2;
	}
	else if (Scene == 2)
	{
		X_Src_pos = 305;
		Y_Src_pos = 36;
		Src_Width = 25;
		Src_Height = 36;
		Scene = 3;
	}
	else if (Scene == 3)
	{
		X_Src_pos = 280;
		Y_Src_pos = 36;
		Src_Width = 25;
		Src_Height = 36;
		Scene = 4;
	}
	else if (Scene == 4)
	{
		X_Src_pos = 258;
		Y_Src_pos = 36;
		Src_Width = 22;
		Src_Height = 36;
		Scene = 5;
	}
	else if (Scene == 5)
	{
		X_Src_pos = 238;
		Y_Src_pos = 36;
		Src_Width = 20;
		Src_Height = 36;
		Scene = 6;
	}
	else if (Scene == 6)
	{
		X_Src_pos = 213;
		Y_Src_pos = 36;
		Src_Width = 25;
		Src_Height = 36;
		Scene = 7;
	}
	else if (Scene == 7)
	{
		X_Src_pos = 189;
		Y_Src_pos = 36;
		Src_Width = 24;
		Src_Height = 36;
		Scene = 0;
	}
}



//#include "framework.h"
//#include "Super_Mario.h"
//#include"mainGame.h"
//HINSTANCE m_hInstance;
//HWND m_hWnd;
//POINT m_ptMouse = { 0,0 };
//
//
////메인게임
//mainGame mg;
//
//LPTSTR m_lpszClass = TEXT("SUPERMARIO");
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//void setWindowSize(int x, int y, int width, int height);
//
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpszCmdParam, int nCmdShow)
//{
//	m_hInstance = hInstance;
//
//	WNDCLASS wndClass;
//
//
//	wndClass.cbClsExtra = 0;
//	wndClass.cbWndExtra = 0;
//	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//
//
//	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//
//	wndClass.hInstance = hInstance;
//	wndClass.lpfnWndProc = (WNDPROC)WndProc;
//	wndClass.lpszClassName = m_lpszClass;
//	wndClass.lpszMenuName = NULL;
//
//	wndClass.style = CS_HREDRAW | CS_VREDRAW;
//
//	RegisterClass(&wndClass);
//
//
//	m_hWnd = CreateWindow(
//		WINNAME,
//		WINNAME,
//		WS_OVERLAPPEDWINDOW,
//		WINSTARTX,
//		WINSTARTY,
//		WINSIZEX,
//		WINSIZEY,
//		NULL,
//		(HMENU)NULL,
//		hInstance,
//		NULL);
//
//
//
//	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
//	ShowWindow(m_hWnd, nCmdShow);
//
//	//메인게임 초기화 실패하면 종료
//	if (FAILED(mg.init()))
//	{
//		return 0;
//	}
//
//	MSG message;
//
//	while (GetMessage(&message, 0, 0, 0))
//	{
//		TranslateMessage(&message);
//		DispatchMessage(&message);
//	}
//
//
//	//메시지 루프를 다돌면 해제하자.
//	mg.release();
//
//	return message.wParam;
//
//}
//
////윈도우 프로시져 : 메세지를 운영체제에 전달한다. 강제로 운영체제가 호출
////hWnd : 윈도우가 발생한 메세지인지 구분
////imessage : 메세지 구분번호
////wParam : 마우스 버튼의 상태, 키보드 조합키의 상태를 전달한다.
////lParam :  마우스 클릭 좌표를 전달
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	return mg.MainProc(hWnd, iMessage, wParam, lParam);
//}
//
////위도우 크기조정 
////클라이언트 영역 사이즈 잡자
//void setWindowSize(int x, int y, int width, int height)
//{
//	RECT rc;
//	rc.left = 0;
//	rc.top = 0;
//	rc.right = width;
//	rc.bottom = height;
//
//	//위 RECT정보로 윈도우 사이즈 셋팅
//	SetWindowPos(m_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
//}