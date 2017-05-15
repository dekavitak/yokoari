
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	int y, add;
	int NowTime;
	int ChangeTime;
	int ScreenMode;

	int x = 0;
	int Handle00;     // 画像格納用ハンドル

					  // 画面サイズは768x576 にしておく
	SetGraphMode(768, 576, 32);

	
	ScreenMode = 0;
	SetWindowSize(1156, 576);
	Handle00 = LoadGraph("hako.png"); // 画像のロード

												  // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {


		DrawGraph(x, 0, Handle00, TRUE); //画像の描画
		x++; // xを1増やす
	}


	// ウインドウモードで起動
	ChangeWindowMode(TRUE);

	// ウインドウのサイズを手動ではできず、且つウインドウのサイズに合わせて拡大もしないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	

	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0) return -1;

	// 起動時の時間を保存しておく
	ChangeTime = GetNowCount();

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// 画面内を左右に移動する四角の処理の初期化
	y = 0;
	add = 8;

	// メインループ(何かキーが押されたらループを抜ける)
	while (ProcessMessage() == 0)
	{
		// 画面のクリア
		ClearDrawScreen();

		// 画面内を左右に移動する四角の処理
		y += add;
		if (y <0 || y >= 540)
		{
			add = -add;
		}
		DrawBox(y, 10, y + 80, 80, GetColor(255, 255, 255), TRUE);

	
		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}

	


	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}