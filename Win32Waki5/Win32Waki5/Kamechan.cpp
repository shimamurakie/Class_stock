
/*------------------------------------------------------------------------
Win32AP034.cpp		 Kamesan�𓮂���
---------------------------------------------------------------------------*/

#include <windows.h>
#include <tchar.h>
#include <stdlib.h>

#define	ID_MYTIMER	(32767)
#define	ID_MYCHILD	(100)
#define	CHD_WIDTH	(64)
#define	CHD_HEIGHT	(64)

// �v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChdProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

BOOL InitApp(HINSTANCE, WNDPROC, LPCTSTR);
BOOL InitInstance(HINSTANCE, int, LPCTSTR);


int 	a = 2;
int 	b = 2;

static TCHAR szClassName[] = _T("Win32AP034");
static TCHAR szchClassName[] = _T("child");
static TCHAR szTitle[] = _T("SSN Kamesan");

int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow) {
	MSG msg;

	if (!hPrevInst) {
		if (!InitApp(hCurInst, WndProc, szClassName)) {
			return FALSE;
		}
	}
	if (!InitInstance(hCurInst, nCmdShow, szClassName)) {
		return FALSE;
	}
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

BOOL InitApp(HINSTANCE hInst, WNDPROC WndProc, LPCTSTR szClassName) {
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;

	return (RegisterClass(&wc));
}


BOOL InitInstance(HINSTANCE hInst, int nCmdShow, LPCTSTR szClassName) {
	HWND hWnd;

	hWnd = CreateWindow(
		szClassName,
		szTitle,						//�^�C�g���o�[�ɂ��̖��O���\������܂�
		WS_OVERLAPPEDWINDOW,	//�E�B���h�E�̎��
		100,								// �E�B���h�E��\������ʒu(X���W)
		100,								// �E�B���h�E��\������ʒu(Y���W)
		620,								// �E�B���h�E�̕�
		340,			//����
		NULL,						//�e�E�B���h�E�̃n���h���A�e�����Ƃ���NULL
		NULL,			//���j���[�n���h���A�N���X���j���[���g���Ƃ���NULL
		hInst,			//�C���X�^���X�n���h��
		NULL);

	if (!hWnd) {
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	RECT		rc;
	static int 	x=100;
	static int 	y=100;
	int mm = 40;
	static int 	direction;
	static HWND		hChdWnd;
	HINSTANCE		hInst;
	enum { right_down, left_down, right_up, left_up };

	HDC hDC;
	HBRUSH  hBrush;

	PAINTSTRUCT	ps;

	switch (message) {
	case WM_PAINT: {

		hDC = BeginPaint(hWnd, &ps);	// GDI�֐��ɂ��`����J�n����
		hBrush = CreateSolidBrush(RGB(255, 255, 255));	//��
		Rectangle(hDC, 0, 0, 700, 700);

		DeleteObject(hBrush);
		hBrush = CreateSolidBrush(RGB(0, 0, 0));	//��
		SelectObject(hDC, hBrush);
		RoundRect(hDC, 10, 10, 585, 295, 68, 68);
		RoundRect(hDC, 78, 294, 98, 299, 2, 2);
		RoundRect(hDC, 119, 294, 154, 299, 2, 2);
		RoundRect(hDC, 164, 294, 199, 299, 2, 2);
		RoundRect(hDC, 119, 6, 154, 11, 2, 2);
		DeleteObject(hBrush);
		hBrush = CreateSolidBrush(RGB(255, 255, 255));	//��
		SelectObject(hDC, hBrush);
		Ellipse(hDC, 40, 96, 50, 106);

		Ellipse(hDC, 26, 148, 32, 154);
		Rectangle(hDC, 42, 126, 49, 178);
		Ellipse(hDC, 530, 130, 572, 172);

	//	DeleteObject(hBrush);
	//	hBrush = CreateSolidBrush(RGB(250, 250, 250));	//�قڔ�
	//	SelectObject(hDC, hBrush);
		Rectangle(hDC, 70, 25, 520, 280);

		DeleteObject(hBrush);
		hBrush = CreateSolidBrush(RGB(0, 0, 0));	//��
		SelectObject(hDC, hBrush);
		Ellipse(hDC, 533, 133, 569, 169);

		DeleteObject(hBrush);

		break;
	}
	}

	switch (message) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		InitApp(hInst, ChdProc, szchClassName);

		hChdWnd = CreateWindow(
			szchClassName,			// �E�B���h�E�N���X��
			NULL,					// �^�C�g���o�[�ɕ\�����镶����
			WS_CHILD,				// �E�B���h�E�̎��
			0,						// �E�B���h�E��\������ʒu(X���W�j
			0,						// �E�B���h�E��\������ʒu(Y���W�j
			CHD_WIDTH,			// �E�B���h�E�̕�
			CHD_HEIGHT,			// �E�B���h�E�̍���
			hWnd,					// �e�E�B���h�E�̃E�B���h�E�n���h��
			(HMENU)ID_MYCHILD,	// ���j���[�n���h��
			hInst,					// �C���X�^���X�n���h��
			NULL					// ���̑��̍쐬�f�[�^
			);

		ShowWindow(hChdWnd, SW_SHOW);
		UpdateWindow(hChdWnd);

		SetTimer(hWnd, ID_MYTIMER, 10, NULL);
		break;



	case WM_TIMER:
		GetClientRect(hWnd, &rc);
		MoveWindow(hChdWnd, x, y, CHD_WIDTH, CHD_HEIGHT, TRUE);

		switch (direction) {
		case right_down:
			x += a;
			y += b;
			if (x >= rc.right - CHD_WIDTH -88) {
				a = rand() % (6) + 3;
				b = rand() % (4) + 2;
				direction = left_down;


			}
			if (y >= rc.bottom - CHD_HEIGHT- 26) {
				a = rand() % (6) + 3;
				b = rand() % (4) + 2;
				direction = right_up;
			}
			break;

		case left_down:
			x -= a;
			y += b;
			if (y >= rc.bottom - CHD_HEIGHT-26) {
				a = rand() % (6) + 3;
				b = rand() % (4) + 2;
				direction = left_up;
			}
			if (x < 75) {
				a = rand() % (6) + 3;
				b = rand() % (4) + 2;
				direction = right_down;

			}
			break;

		case left_up:
			x -= a;
			y -= b;
			if (x < 75) {
				a = rand() % (6) + 3;
				b = rand() % (4) + 2;
				direction = right_up;

			}
			if (y < 29) {
				a = rand() % (6) + 3;
				b = rand() % (4) + 2;
				direction = left_down;
			}
			break;

		case right_up:
			x += a;
			y -= b;
			if (y < 29) {
				a = rand() % (6) + 3;
				b = rand() % (4) + 2;
				direction = right_down;
			}
			if (x >= rc.right - CHD_WIDTH -88) {
				a = rand() % (6) + 3;
				b = rand() % (4) + 2;
				direction = left_up;

			}
			break;
		}
		break;

	case WM_DESTROY:
		KillTimer(hWnd, ID_MYTIMER);
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}


LRESULT CALLBACK ChdProc(HWND hChdWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static HBITMAP	hBitmap;
	static HBITMAP	hPrevBitmap;
	HINSTANCE		hInst;
	PAINTSTRUCT	ps;
	HDC			hDC;
	HDC			hCompatDC;


	switch (message) {
	case WM_PAINT:



		hInst = (HINSTANCE)GetWindowLong(hChdWnd, GWL_HINSTANCE);

		hBitmap = (HBITMAP)LoadImage(
			hInst,
			_T("asekame.bmp"),
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE);

		if (hBitmap == NULL) {
			MessageBox(
				hChdWnd,
				_T("�r�b�g�}�b�v�̃��[�h�Ɏ��s���܂���"),
				_T("�G���["),
				MB_OK | MB_ICONWARNING
				);
			return 0;
		}

		hDC = BeginPaint(hChdWnd, &ps);
		hCompatDC = CreateCompatibleDC(hDC);
		SelectObject(hCompatDC, hBitmap);

		BitBlt(hDC, 0, 0, CHD_WIDTH, CHD_HEIGHT, hCompatDC, 0, 0, SRCCOPY);

		DeleteDC(hCompatDC);
		DeleteObject(hBitmap);


		EndPaint(hChdWnd, &ps);
		break;

	default:
		return(DefWindowProc(hChdWnd, message, wParam, lParam));
	}
	return 0;
}