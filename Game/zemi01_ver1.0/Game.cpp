#include "DxLib.h"
#include "Game.h"
#include "Player.h"
#include "Box.h"


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
	PlayerInitialize();               // プレイヤーの初期化
	BoxInitialize();                  // プレイヤーの初期化
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
		m_sceneChanger->ChangeScene(eScene_Menu);   // シーンをメニューに変更
	}
	if (CheckHitKey(KEY_INPUT_R) != 0) {            // Rキーが押されていたら
		m_sceneChanger->ChangeScene(eScene_Result); // シーンをリザルトに変更
	}
	kEnemy.Update();
	kEnemy.Draw();

	aEnemy.Update();
	aEnemy.Draw();

	wEnemy.Update();
	wEnemy.Draw();
	
	// 段ボールの動き、描画
	BoxMove();
	BoxView();

	// プレイヤーの動き、描画
	PlayerMove();
	PlayerView();
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