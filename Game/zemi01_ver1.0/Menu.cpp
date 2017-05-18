#include "DxLib.h"
#include "Menu.h"
#include "Define.h"


Menu::Menu(ISceneChanger* changer) : SceneTask(changer) {
}

/***************************************
関数名 : Initialize()
概要   : 初期化処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void Menu::Initialize() {
	m_sceneHandle = LoadGraph("SCENE_PIC");    // 画像のロード
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // サウンドのロード
}

/***************************************
関数名 : Update()
概要   : 更新処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void Menu::Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {              // Gキーが押されていたら
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Game);     // シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {              // Cキーが押されていたら
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Config);   // シーンを設定画面に変更
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {              // Tキーが押されていたら
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Tutorial); // シーンをチュートリアル画面に変更
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {         // Escキーが押されていたら
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Title);    // シーンをタイトル画面に変更
	}
}

/***************************************
関数名 : Draw()
概要   : 描画処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void Menu::Draw() {
	SceneTask::Draw(); // 親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
	DrawString(0, 40, "Cキーを押すと　設定画面に進みます。", GetColor(255, 255, 255));
	DrawString(0, 60, "Tキーを押すとチュートリアル画面に進みます。", GetColor(255, 255, 255));
	DrawString(0, 80, "Escキーを押すと　タイトル画面に進みます。", GetColor(255, 255, 255));
}