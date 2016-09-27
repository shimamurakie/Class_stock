/*---------------------------------------------
Win32AP016.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>

// プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// 大域変数
static TCHAR szWindowClass[] = _T("Win32AP016");
static TCHAR szTitle[] = _T("Win32AP016");
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
		100,								// ウィンドウを表示する位置(X座標)
		100,								// ウィンドウを表示する位置(Y座標)
		320,								// ウィンドウの幅
		700,								// ウィンドウの高さ
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
	HDC hDC;
	HBRUSH	hBrush;
	PAINTSTRUCT ps;

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);		// GDI関数による描画を開始する
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

		EndPaint(hWnd, &ps);				// GDI関数による描画を終了する
		break;

	case WM_LBUTTONDOWN:	// マウスの左ボタンが押されたときに送られてくる
		MessageBox(hWnd, _T("左ボタンが押されました"), _T("メッセージ"), MB_OK);
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

