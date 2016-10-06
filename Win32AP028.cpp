/*---------------------------------------------
Win32BP025.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>

// �v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// ���ϐ�
static TCHAR szWindowClass[] = _T("Win32BP025");
static TCHAR szTitle[] = _T("Win32BP025");
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
		568,								// �E�B���h�E�̍���
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
	static POINT start;		// �l�p�`�̎n�_
	static POINT end;		// �l�p�`�̏I�_
	HDC hDC;
	HBRUSH	hBrush;
	PAINTSTRUCT ps;

	switch (message) {
	case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ�Ƃ�
							// �}�E�X�J�[�\���̈ʒu���擾���āA�n�_�Ƃ��ĕۑ����Ă���
		start.x = LOWORD(lParam);
		start.y = HIWORD(lParam);
		break;

	case WM_LBUTTONUP:		// �}�E�X�̍��{�^���������ꂽ�Ƃ�
							// �}�E�X�J�[�\���̈ʒu���擾���āA�I�_�Ƃ��ĕۑ����Ă���
		end.x = LOWORD(lParam);
		end.y = HIWORD(lParam);

		// �����̈�𔭐������āAWM_PAINT�𔭐�������
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_PAINT:			// �����̈悪����Ƃ�
							// �l�p�`��`��
		hDC = BeginPaint(hWnd, &ps);
		hBrush = CreateSolidBrush(RGB(192, 192, 255));
		SelectObject(hDC, hBrush);						// �쐬�����_���u���V���g�p����	
		Rectangle(hDC, start.x, start.y, end.x, end.y);
		DeleteObject(hBrush);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:		// �E�B���h�E���j�������Ƃ�
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
