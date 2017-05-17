#include "DxLib.h"
#include "Game.h"
#include "Define.h"
#include "Player.h"
#include "Box.h"
#include "Time.h"


Game::Game(ISceneChanger* changer) : SceneTask(changer) {
}

/***************************************
関数名 : Initialize()
概要   :初期化処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/

void Game::Initialize() {
	m_sceneHandle = LoadGraph("");    // 画像のロード
	mSoundPlayHandle = LoadSoundMem(GAME_BGM); // サウンドのロード
	PlayerInitialize();               // プレイヤーの初期化
	BoxInitialize();                  // 段ボールの初期化
	TimerInitialize();

}

/***************************************
関数名 : Update()
概要   : 更新処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/

void Game::Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {       // Escキーが押されていたら
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Menu);   // シーンをメニューに変更
	}
	if (ReturnDeliveryNum() >= 20 ||
		ReturnTimerFlg() == true) {            // 段ボールを20個納品したら
		m_sceneChanger->ChangeScene(eScene_Result); // シーンをリザルトに変更
	}
	
	
	// 段ボールの動き、描画
	BoxMove();
	BoxView();

	// プレイヤーの動き、描画
	PlayerMove();
	PlayerView();

	TimerUpdate();
}

/***************************************
関数名 : Draw()
概要   : 描画処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/

void Game::Draw() {
	SceneTask::Draw(); // 親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
	DrawString(0, 40, "Rキーを押すとリザルト画面に戻ります。", GetColor(255, 255, 255));
}