#include "DxLib.h"
#include "SystemManager.h"


/***************************************
関数名 : SystemManager()
概要   : コンストラクタ
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
SystemManager::SystemManager()
{
	this->GameIsInit();
}

/***************************************
関数名 : ~SystemManager()
概要   : デストラクタ
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
SystemManager::~SystemManager()
{
	this->GameIsEnd();
}

/***************************************
関数名 : Update()
概要   : 更新処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
int SystemManager::Update()
{
	sceneMgr.Initialize(); // シーンの初期化処理を呼び出す

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去

		sceneMgr.Update();  // 更新処理を呼び出す
		sceneMgr.Draw();    // 描画処理を呼び出す

	}

	sceneMgr.Finalize(); // 終了処理を呼び出す

	return 0;
}

/***************************************
関数名 : GameIsInit
概要   : ゲームの初期化
引数   : なし
戻り値 : なし
備考   : コンストラクタが呼ばれた時に呼ばれる
***************************************/
void SystemManager::GameIsInit()
{

	//width height
	this->GetWindowMode(1280, 720);

	//ウインドウの名前を設定する
	SetMainWindowText("働け！ヨコアリくん！");

	//ウインドウの二重生成ができるかを設定する　TRUE：可能　FALSE：不可能
	SetDoubleStartValidFlag(FALSE);

	//裏画面のセット
	SetDrawScreen(DX_SCREEN_BACK);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {

		return;
	}

}

/***************************************
関数名 : GameIsEnd
概要   : ゲームの終了処理
引数   : なし
戻り値 : なし
備考   : デストラクタが呼ばれた時に呼ばれる
***************************************/
void SystemManager::GameIsEnd()
{
	DxLib_End();

	return;
}

/***************************************
関数名 : GetWindowMode
概要   : ウィンドウのサイズ指定
引数   : int width int height
戻り値 : なし
備考   : なし
***************************************/
void SystemManager::GetWindowMode(int width, int height)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(width, height, 32);
}