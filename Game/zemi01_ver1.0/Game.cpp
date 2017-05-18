#include "DxLib.h"
#include "Game.h"
#include "Define.h"
#include "Player.h"
#include "Box.h"
#include "Time.h"
#include "Truck.h"



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
	m_sceneHandle = LoadGraph(STAGE_PIC);    // 画像のロード
	mSoundPlayHandle = LoadSoundMem(GAME_BGM); // サウンドのロード
	PlayerInitialize();               // プレイヤーの初期化

	for (int i = 0; i < BOX_LENGTH; i++) {
		BoxInitialize(i);                  // 段ボールの初期化
	}

	TimerInitialize();      // 時間の初期化
	TruckInitialize();      // 納品者の初期化

	SetFontSize(16);
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
		m_sceneChanger->ChangeScene(eScene_Result);   // シーンをメニューに変更
	}
	if (ReturnDeliveryNum() >= 20 ||
		ReturnTimerFlg() == true) {            // 段ボールを20個納品したら
		m_sceneChanger->ChangeScene(eScene_Result); // シーンをリザルトに変更
	}
	enemyMgr.Update();
	enemyMgr.Draw();
	
	// 段ボールの動き、描画
	BoxUpdate();
	BoxRender();

	// プレイヤーの動き、描画
	PlayerUpdate();
	PlayerRender();

	// 時間の表示
	TimerUpdate();

	// 納品者の描画
	TruckRender();
	TruckUpdate();
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
	
}