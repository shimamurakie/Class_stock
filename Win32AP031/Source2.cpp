/*---------------------------------------------
Win32AP045.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>
#include "resource.h"

#define WINDOW_X			(100)
#define WINDOW_Y			(100)
#define WINDOW_WIDTH		(320)		// ウィンドウの幅
#define WINDOW_HEIGHT		(568)		// ウィンドウの高さ

// プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// 大域変数
static TCHAR szWindowClass[] = _T("Win32AP045");
static TCHAR szTitle[] = _T("Win32AP045");
HINSTANCE	hInst;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR pCmdLine,
	int nCmdShow) {

	WNDCLASSEX wcex;

	// ウィンドウクラスの情報を設定
	wcex.cbSize = sizeof(WNDCLASSEX);				// 構造体サイズ
	wcex.style = CS_HREDRAW | CS_VREDRAW;		// スタイル
	wcex.lpfnWndProc = WndProc;							// ウィンドウプロシージャ
	wcex.cbClsExtra = 0;									// 拡張情報１
	wcex.cbWndExtra = 0;									// 拡張情報２
	wcex.hInstance = hInstance;							// インスタンスハンドル
	wcex.hIcon = (HICON)LoadImage(					// アイコン
		NULL,
		MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED
		);
	wcex.hIconSm = wcex.hIcon;							// 子アイコン
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);	// メニュー名
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	// ウィンドウクラスを登録する
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,
			_T("ウィンドウの登録に失敗しました"),
			_T("ウィンドウの登録エラー"),
			NULL);
		return 1;
	}

	hInst = hInstance; // インスタンス･ハンドルを大域変数に格納

					   // ウィンドウを作成する
	HWND hWnd = CreateWindow(
		szWindowClass,					// ウィンドウクラス名
		szTitle,							// タイトルバーに表示する文字列
		WS_OVERLAPPEDWINDOW,		// ウィンドウの種類
		WINDOW_X,						// ウィンドウを表示する位置(X座標)
		WINDOW_Y,						// ウィンドウを表示する位置(Y座標)
		WINDOW_WIDTH,				// ウィンドウの幅
		WINDOW_HEIGHT,				// ウィンドウの高さ
		NULL,							// 親ウィンドウのウィンドウハンドル
		NULL,							// メニューハンドル
		hInst,							// インスタンスハンドル
		NULL							// その他の作成データ
		);

	if (!hWnd) {
		MessageBox(NULL,
			_T("ウィンドウの作成に失敗しました"),
			_T("ウィンドウの作成エラー"),
			NULL);
		return 1;
	}

	// ウィンドウを表示する
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// メッセージ･ループ
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static HMENU hMenu;
	MENUITEMINFO info;

	switch (message) {
	case WM_CREATE:
		hMenu = GetMenu(hWnd);
		break;

	case WM_COMMAND:		// 項目が選択されたとき
		switch (LOWORD(wParam)) {
		case ID_EXIT:		// 「終了」
			SendMessage(hWnd, WM_CLOSE, 0, 0);
			break;

		case ID_DISABLE:		// 「項目を無効にする」
			info.cbSize = sizeof(info);
			info.fMask = MIIM_STATE;
			info.fState = MFS_DISABLED;
			SetMenuItemInfo(hMenu, ID_VERSION, FALSE, &info);	// 「バージョン情報」を無効にする
			DrawMenuBar(hWnd);	// メニューバーを再描画する
			break;

		case ID_VERSION:		// 「バージョン情報」
			MessageBox(hWnd, _T("Sample Program version1.00"), _T("バージョン情報"), MB_OK);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
