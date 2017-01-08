/*---------------------------------------------
Win32AP016.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>

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
	HDC hDC;
	HBRUSH	hBrush;
	PAINTSTRUCT ps;

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);		// GDI�֐��ɂ��`����J�n����
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hDC, hBrush);
		RoundRect(hDC, 10, 10, 295, 585, 68, 68);
		RoundRect(hDC, 6, 78, 11, 98,2,2);
		RoundRect(hDC, 6, 119, 11, 154,2,2);
		RoundRect(hDC, 6, 164, 11, 199,2,2);
		RoundRect(hDC, 294, 119, 299, 154,2,2);
/*		Ellipse(hDC, 92, 34, 102, 44);

		Ellipse(hDC, 142, 20, 148, 26);
		Rectangle(hDC, 121, 36, 173, 43); */
		DeleteObject(hBrush);
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hDC, hBrush);
		Ellipse(hDC, 96, 40, 106, 50);

		Ellipse(hDC, 148, 26, 154, 32);
		Rectangle(hDC, 126, 42, 178, 49);
		Ellipse(hDC, 130, 530, 172, 572);

		DeleteObject(hBrush);
		hBrush = CreateSolidBrush(RGB(250, 240, 0));
		SelectObject(hDC, hBrush);
		Rectangle(hDC, 25, 70, 280, 520);


		DeleteObject(hBrush);
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hDC, hBrush);
		Ellipse(hDC, 133, 533, 169, 569);

		EndPaint(hWnd, &ps);				// GDI�֐��ɂ��`����I������
		break;

	case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ�Ƃ��ɑ����Ă���
		MessageBox(hWnd, _T("���{�^����������܂���"), _T("���b�Z�[�W"), MB_OK);
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

