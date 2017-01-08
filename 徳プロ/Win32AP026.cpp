/*---------------------------------------------
Win32BP028.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>

// プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// 大域変数
static TCHAR szWindowClass[] = _T("Win32BP028");
static TCHAR szTitle[] = _T("Win32BP028");
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
	wcex.lpszMenuName = NULL;						// メニュー名
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
		568,								// ウィンドウの高さ
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
	static POINT start;		   // 四角形の始点
	static POINT end;			 // 四角形の終点
	static POINT old_end;		 // 古い四角形の終点
	static BOOL push = FALSE;	 // 左ボタンが押されているか
	HDC hDC;
	HPEN hPen;
	HBRUSH hBrush;
	PAINTSTRUCT ps;

	switch (message) {
	case WM_LBUTTONDOWN:	// マウスの左ボタンが押されたとき
							// マウスキャプチャを開始する
		SetCapture(hWnd);

		// マウスカーソルの位置を取得して、始点として保存しておく
		start.x = LOWORD(lParam);
		start.y = HIWORD(lParam);
		// 古い終点としても保存
		old_end = start;

		push = TRUE;	 // 左ボタンが押された
		break;

	case WM_LBUTTONUP:	  // マウスの左ボタンが離されたとき
						  // マウスカーソルの位置を取得して、終点として保存しておく
		end.x = LOWORD(lParam);
		end.y = HIWORD(lParam);
		// 無効領域を発生させて、WM_PAINTを発生させる
		InvalidateRect(hWnd, NULL, FALSE);
		push = FALSE;	// 左ボタンが押されてない
						// マウスキャプチャを終了する
		ReleaseCapture();
		break;

	case WM_MOUSEMOVE:	  // マウスカーソルが移動したとき
		if (push) {
			// マウスカーソルの位置を取得して、終点として保存しておく
			end.x = LOWORD(lParam);
			end.y = HIWORD(lParam);
			// 無効領域を発生させて、WM_PAINTを発生させる
			InvalidateRect(hWnd, NULL, FALSE);
		}
		break;

	case WM_PAINT:		  // 無効領域があるとき
						  // 四角形を描く
		hDC = BeginPaint(hWnd, &ps);
		if (push)
		{
			// ドラッグ中の描画処理
			SetROP2(hDC, R2_NOT);							// 前景モードを変更
			hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));			// 黒い点線のペンを作成
			hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);	// 空のブラシを取得
			SelectObject(hDC, hPen);				// 作成したペンを使用するように設定
			SelectObject(hDC, hBrush);				// 取得したブラシを使用するように設定
			Rectangle(hDC, start.x, start.y, old_end.x, old_end.y);		// 四角形を描画
			Rectangle(hDC, start.x, start.y, end.x, end.y);			// 四角形を描画
			DeleteObject(hPen);								// 作成したペンを削除
			old_end = end;									// 今回の終点を保存
		}
		else {
			// ドラッグ中ではないときの描画処理
			hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);	// 空のブラシを取得
			SelectObject(hDC, hBrush);				// 取得したブラシを使用するように設定
			Rectangle(hDC, start.x, start.y, end.x, end.y);			// 四角形を描画
		}
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:		// ウィンドウが破棄されるとき
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

