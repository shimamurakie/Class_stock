/*---------------------------------------------
Win32AP032.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>

// �v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// ���ϐ�
static TCHAR szWindowClass[] = _T("Win32AP032");
static TCHAR szTitle[] = _T("Win32AP032");
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
		CW_USEDEFAULT,				// �E�B���h�E��\������ʒu(X���W�j
		CW_USEDEFAULT,				// �E�B���h�E��\������ʒu(Y���W�j
		CW_USEDEFAULT,				// �E�B���h�E�̕�
		CW_USEDEFAULT,				// �E�B���h�E�̍���
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
	static LPCTSTR TEST_STR = _T("AA");
	static LOGFONT logfont;	// �t�H���g���̍\����
	HDC hDC;
	HFONT hFont;
	int angle;

	switch (message) {
	case WM_CREATE:			// �E�B���h�E���쐬���ꂽ�Ƃ�
		ZeroMemory(&logfont, sizeof(logfont));	// �t�H���g���\���̂��O�ŏ�����
		logfont.lfCharSet = DEFAULT_CHARSET;
		
		// �V�X�e���̃f�t�H���g�����Z�b�g���g��
		logfont.lfHeight = 30;
		logfont.lfWeight = 700;
		wsprintf(logfont.lfFaceName, _T("MS P�S�V�b�N"));
		break;

	case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ�Ƃ�
		hDC = GetDC(hWnd);
		for (angle = 2700; angle >= -2700; angle += -900) {
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			SelectObject(hDC, hFont);
			logfont.lfEscapement = angle;
			TextOut(
				hDC,
				LOWORD(lParam),
				HIWORD(lParam),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 					// �쐬�����_���t�H���g���폜����
		}
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
