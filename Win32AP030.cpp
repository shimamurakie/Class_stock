/*---------------------------------------------
Win32AP027.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>

// プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// 大域変数
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

	// ウィンドウクラスの情報を設定
	wcex.cbSize = sizeof(WNDCLASSEX);				// 構造体サイズ
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// スタイル
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
	wcex.lpszMenuName = NULL;							// メニュー名
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
		WINDOW_X,				// ウィンドウを表示する位置(X座標)
		WINDOW_Y,				// ウィンドウを表示する位置(Y座標)
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
	static LPCTSTR TEST_STR = _T("左ボタン・・・です^^");
	static LPCTSTR TEST_STR2 = _T("右ボタンですよ、そんなこともry");
	HDC hDC;

	switch (message) {
	case WM_LBUTTONDOWN:	// マウスの左ボタンが押されたとき
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


	case WM_RBUTTONDOWN:	// マウスのボタンが押されたとき
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
