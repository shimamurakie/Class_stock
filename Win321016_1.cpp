
#define PI 3.141592


#include <windows.h>
#include <tchar.h>
#include <math.h>

// �v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// ���ϐ�
static TCHAR szWindowClass[] = _T("Win32AP016");
static TCHAR szTitle[] = _T("Win32AP016");
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
		100,								// �E�B���h�E��\������ʒu(X���W)
		100,								// �E�B���h�E��\������ʒu(Y���W)
		320,								// �E�B���h�E�̕�
		700,								// �E�B���h�E�̍���
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
	static LPCTSTR TEST_STR = _T("i");
	static LPCTSTR TEST_STR2 = _T("n");
	static LPCTSTR TEST_STR3 = _T("f");
	static LPCTSTR TEST_STR4 = _T("t");
	static LPCTSTR TEST_STR5 = _T("y");
	int deg = 0;

	static LOGFONT logfont;	// �t�H���g���̍\���� infinity
	HDC hDC;
	HFONT hFont;
	RECT	rc;
	HBRUSH	hBrush;
	PAINTSTRUCT ps;



	switch (message) {
	case WM_CREATE:			// �E�B���h�E���쐬���ꂽ�Ƃ�
		ZeroMemory(&logfont, sizeof(logfont));	// �t�H���g���\���̂��O�ŏ�����
		logfont.lfUnderline = TRUE;				// ����������
		logfont.lfCharSet = DEFAULT_CHARSET;	// �V�X�e���̃f�t�H���g�����Z�b�g���g��
		logfont.lfEscapement = 0;
		wsprintf(logfont.lfFaceName, _T("Times New Roman"));
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);		// GDI�֐��ɂ��`����J�n����
		hBrush = CreateSolidBrush(RGB(10, 10, 10));//250.445
		SelectObject(hDC, hBrush);
		RoundRect(hDC, 10, 10, 295, 585, 45, 45);
		Ellipse(hDC, 92, 34, 102, 44);

		Ellipse(hDC, 142, 20, 148, 26);
		Rectangle(hDC, 121, 36, 173, 43);
		DeleteObject(hBrush);
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hDC, hBrush);
		Ellipse(hDC, 92, 34, 102, 44);

		Ellipse(hDC, 142, 20, 148, 26);
		Rectangle(hDC, 121, 36, 173, 43);

		Rectangle(hDC, 25, 70, 280, 515);
		Ellipse(hDC, 125, 525, 167, 567);

		DeleteObject(hBrush);
		hBrush = CreateSolidBrush(RGB(10, 10, 10));
		SelectObject(hDC, hBrush);
		Ellipse(hDC, 128, 528, 164, 564);

		EndPaint(hWnd, &ps);				// GDI�֐��ɂ��`����I������
		break;

	case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ�Ƃ�
		hDC = GetDC(hWnd);
		hBrush = CreateSolidBrush(RGB(128, 128, 255));
		GetClientRect(hWnd, &rc);

		// �̈���e�L�X�g���̂ɂ���
		SetBkMode(hDC, TRANSPARENT);




		for (deg = 0; deg >= -3600; deg -= 150){
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			logfont.lfUnderline = 0;
			hFont = CreateFontIndirect(&logfont);
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);
			// �_���t�H���g���쐬����
			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 150;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 150;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR3,
				(int)_tcslen(TEST_STR3));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 150;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 150;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 150;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 150;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR4,
				(int)_tcslen(TEST_STR4));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 150;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR5,
				(int)_tcslen(TEST_STR5));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�

		}



		for (deg = 0; deg >= -3600; deg -= 90){
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont);
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);
			// �_���t�H���g���쐬����
			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 90;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 90;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR3,
				(int)_tcslen(TEST_STR3));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 90;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 90;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 90;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 90;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR4,
				(int)_tcslen(TEST_STR4));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 90;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR5,
				(int)_tcslen(TEST_STR5));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�

		}



		for (deg = 0; deg >= -3600; deg -= 75){
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont);
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);
			// �_���t�H���g���쐬����
			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 75;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 75;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR3,
				(int)_tcslen(TEST_STR3));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 75;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 75;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 75;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 75;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR4,
				(int)_tcslen(TEST_STR4));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�
			deg -= 75;
			hDC = GetDC(hWnd);//��������
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// �_���t�H���g���쐬����
			// �̈���e�L�X�g���̂ɂ���
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR5,
				(int)_tcslen(TEST_STR5));
			DeleteObject(hFont); 	// �쐬�����_���t�H���g���폜����
			ReleaseDC(hWnd, hDC);//�����܂�

		}

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

