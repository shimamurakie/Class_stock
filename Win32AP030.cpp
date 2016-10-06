/*---------------------------------------------
Win32AP027.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>

// �v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// ���ϐ�
#define WINDOW_X			(100)
#define WINDOW_Y			(100)
#define WINDOW_WIDTH		(320)
#define WINDOW_HEIGHT		(568)

static TCHAR szWindowClass[] = _T("Win32AP027");
static TCHAR szTitle[] = _T("Win32AP027");
HINSTANCE	hInst;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR pCmdLine,
	int nCmdShow) {

	WNDCLASSEX wcex;

	// �E�B���h�E�N���X�̏���ݒ�
	wcex.cbSize = sizeof(WNDCLASSEX);				// �\���̃T�C�Y
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// �X�^�C��
	wcex.lpfnWndProc = WndProc;							// �E�B���h�E�v���V�[�W��
	wcex.cbClsExtra = 0;									// �g�����P
	wcex.cbWndExtra = 0;									// �g�����Q
	wcex.hInstance = hInstance;							// �C���X�^���X�n���h��
	wcex.hIcon = (HICON)LoadImage(					// �A�C�R��
		NULL,
		MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED
		);
	wcex.hIconSm = wcex.hIcon;							// �q�A�C�R��
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;							// ���j���[��
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	// �E�B���h�E�N���X��o�^����
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,
			_T("�E�B���h�E�̓o�^�Ɏ��s���܂���"),
			_T("�E�B���h�E�̓o�^�G���["),
			NULL);
		return 1;
	}

	hInst = hInstance; // �C���X�^���X��n���h������ϐ��Ɋi�[

					   // �E�B���h�E���쐬����
	HWND hWnd = CreateWindow(
		szWindowClass,					// �E�B���h�E�N���X��
		szTitle,							// �^�C�g���o�[�ɕ\�����镶����
		WS_OVERLAPPEDWINDOW,		// �E�B���h�E�̎��
		WINDOW_X,				// �E�B���h�E��\������ʒu(X���W)
		WINDOW_Y,				// �E�B���h�E��\������ʒu(Y���W)
		WINDOW_WIDTH,				// �E�B���h�E�̕�
		WINDOW_HEIGHT,				// �E�B���h�E�̍���
		NULL,							// �e�E�B���h�E�̃E�B���h�E�n���h��
		NULL,							// ���j���[�n���h��
		hInst,							// �C���X�^���X�n���h��
		NULL							// ���̑��̍쐬�f�[�^
		);

	if (!hWnd) {
		MessageBox(NULL,
			_T("�E�B���h�E�̍쐬�Ɏ��s���܂���"),
			_T("�E�B���h�E�̍쐬�G���["),
			NULL);
		return 1;
	}

	// �E�B���h�E��\������
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// ���b�Z�[�W����[�v
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

// �E�B���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static LPCTSTR TEST_STR = _T("���{�^���E�E�E�ł�^^");
	static LPCTSTR TEST_STR2 = _T("�E�{�^���ł���A����Ȃ��Ƃ�ry");
	HDC hDC;

	switch (message) {
	case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ�Ƃ�
		hDC = GetDC(hWnd);
		TextOut(hDC, 50, 100, TEST_STR, (int)_tcslen(TEST_STR));
		SetTextColor(hDC, RGB(225, 0, 0));
		TextOut(hDC, 50, 120, TEST_STR, (int)_tcslen(TEST_STR));
		SetTextColor(hDC, RGB(0, 225, 0));
		TextOut(hDC, 50, 140, TEST_STR, (int)_tcslen(TEST_STR));
		SetTextColor(hDC, RGB(0, 0, 225));
		TextOut(hDC, 50, 160, TEST_STR, (int)_tcslen(TEST_STR));
		SetTextColor(hDC, RGB(0, 0, 0));
		ReleaseDC(hWnd, hDC);
		break;


	case WM_RBUTTONDOWN:	// �}�E�X�̃{�^���������ꂽ�Ƃ�
		hDC = GetDC(hWnd);
		TextOut(hDC, 50, 100, TEST_STR2, (int)_tcslen(TEST_STR2));
		SetTextColor(hDC, RGB(225, 100, 0));
		TextOut(hDC, 50, 120, TEST_STR2, (int)_tcslen(TEST_STR2));
		SetTextColor(hDC, RGB(100, 225, 0));
		TextOut(hDC, 50, 140, TEST_STR2, (int)_tcslen(TEST_STR2));
		SetTextColor(hDC, RGB(0, 100, 225));
		TextOut(hDC, 50, 160, TEST_STR2, (int)_tcslen(TEST_STR2));
		SetTextColor(hDC, RGB(225, 0, 100));
		ReleaseDC(hWnd, hDC);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}
