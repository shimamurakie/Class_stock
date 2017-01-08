
#define PI 3.141592


#include <windows.h>
#include <tchar.h>
#include <math.h>

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
	static LPCTSTR TEST_STR = _T("i");
	static LPCTSTR TEST_STR2 = _T("n");
	static LPCTSTR TEST_STR3 = _T("f");
	static LPCTSTR TEST_STR4 = _T("t");
	static LPCTSTR TEST_STR5 = _T("y");
	int deg = 0;

	static LOGFONT logfont;	// フォント情報の構造体 infinity
	HDC hDC;
	HFONT hFont;
	RECT	rc;
	HBRUSH	hBrush;
	PAINTSTRUCT ps;



	switch (message) {
	case WM_CREATE:			// ウィンドウが作成されたとき
		ZeroMemory(&logfont, sizeof(logfont));	// フォント情報構造体を０で初期化
		logfont.lfUnderline = TRUE;				// 下線を引く
		logfont.lfCharSet = DEFAULT_CHARSET;	// システムのデフォルト文字セットを使う
		logfont.lfEscapement = 0;
		wsprintf(logfont.lfFaceName, _T("Times New Roman"));
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);		// GDI関数による描画を開始する
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

		EndPaint(hWnd, &ps);				// GDI関数による描画を終了する
		break;

	case WM_LBUTTONDOWN:	// マウスの左ボタンが押されたとき
		hDC = GetDC(hWnd);
		hBrush = CreateSolidBrush(RGB(128, 128, 255));
		GetClientRect(hWnd, &rc);

		// 領域をテキスト自体にする
		SetBkMode(hDC, TRANSPARENT);




		for (deg = 0; deg >= -3600; deg -= 150){
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			logfont.lfUnderline = 0;
			hFont = CreateFontIndirect(&logfont);
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);
			// 論理フォントを作成する
			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 150;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 150;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR3,
				(int)_tcslen(TEST_STR3));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 150;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 150;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 150;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 150;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR4,
				(int)_tcslen(TEST_STR4));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 150;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 50 * sin(deg * PI / 1800),
				HIWORD(lParam) - 50 * cos(deg * PI / 1800),
				TEST_STR5,
				(int)_tcslen(TEST_STR5));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで

		}



		for (deg = 0; deg >= -3600; deg -= 90){
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont);
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);
			// 論理フォントを作成する
			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 90;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 90;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR3,
				(int)_tcslen(TEST_STR3));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 90;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 90;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 90;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 90;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR4,
				(int)_tcslen(TEST_STR4));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 90;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 85 * sin(deg * PI / 1800),
				HIWORD(lParam) - 85 * cos(deg * PI / 1800),
				TEST_STR5,
				(int)_tcslen(TEST_STR5));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで

		}



		for (deg = 0; deg >= -3600; deg -= 75){
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont);
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);
			// 論理フォントを作成する
			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 75;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 75;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR3,
				(int)_tcslen(TEST_STR3));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 75;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 75;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR2,
				(int)_tcslen(TEST_STR2));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 75;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR,
				(int)_tcslen(TEST_STR));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 75;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR4,
				(int)_tcslen(TEST_STR4));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで
			deg -= 75;
			hDC = GetDC(hWnd);//ここから
			//lfHeight;
			logfont.lfEscapement = deg;
			hFont = CreateFontIndirect(&logfont); 	// 論理フォントを作成する
			// 領域をテキスト自体にする
			SetBkMode(hDC, TRANSPARENT);

			SelectObject(hDC, hFont);
			TextOut(
				hDC,
				LOWORD(lParam) - 120 * sin(deg * PI / 1800),
				HIWORD(lParam) - 120 * cos(deg * PI / 1800),
				TEST_STR5,
				(int)_tcslen(TEST_STR5));
			DeleteObject(hFont); 	// 作成した論理フォントを削除する
			ReleaseDC(hWnd, hDC);//ここまで

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

