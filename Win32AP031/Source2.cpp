/*---------------------------------------------
Win32AP045.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>
#include "resource.h"

#define WINDOW_X			(100)
#define WINDOW_Y			(100)
#define WINDOW_WIDTH		(320)		// �E�B���h�E�̕�
#define WINDOW_HEIGHT		(568)		// �E�B���h�E�̍���

// �v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// ���ϐ�
static TCHAR szWindowClass[] = _T("Win32AP045");
static TCHAR szTitle[] = _T("Win32AP045");
HINSTANCE	hInst;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR pCmdLine,
	int nCmdShow) {

	WNDCLASSEX wcex;

	// �E�B���h�E�N���X�̏���ݒ�
	wcex.cbSize = sizeof(WNDCLASSEX);				// �\���̃T�C�Y
	wcex.style = CS_HREDRAW | CS_VREDRAW;		// �X�^�C��
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
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);	// ���j���[��
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
		WINDOW_X,						// �E�B���h�E��\������ʒu(X���W)
		WINDOW_Y,						// �E�B���h�E��\������ʒu(Y���W)
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
	static HMENU hMenu;
	MENUITEMINFO info;

	switch (message) {
	case WM_CREATE:
		hMenu = GetMenu(hWnd);
		break;

	case WM_COMMAND:		// ���ڂ��I�����ꂽ�Ƃ�
		switch (LOWORD(wParam)) {
		case ID_EXIT:		// �u�I���v
			SendMessage(hWnd, WM_CLOSE, 0, 0);
			break;

		case ID_DISABLE:		// �u���ڂ𖳌��ɂ���v
			info.cbSize = sizeof(info);
			info.fMask = MIIM_STATE;
			info.fState = MFS_DISABLED;
			SetMenuItemInfo(hMenu, ID_VERSION, FALSE, &info);	// �u�o�[�W�������v�𖳌��ɂ���
			DrawMenuBar(hWnd);	// ���j���[�o�[���ĕ`�悷��
			break;

		case ID_VERSION:		// �u�o�[�W�������v
			MessageBox(hWnd, _T("Sample Program version1.00"), _T("�o�[�W�������"), MB_OK);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
