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
	m_sceneHandle = LoadGraph(SCENE_PIC);    // 画像のロード
	m_tutorialHandle = LoadGraph(TUTORIAL_BUTTON);
	m_gameHandle = LoadGraph(START_BUTTON);
	m_configHandle = LoadGraph(MENU_BUTTON);
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // サウンドのロード

	SetFontSize(32);

}

/***************************************
関数名 : Update()
概要   : 更新処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void Menu::Update() {

	Mouse_Input = GetMouseInput();
	GetMousePoint(&Mouse_x, &Mouse_y);
	
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {         // Escキーが押されていたら
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Title);    // シーンをタイトル画面に変更
		DeleteGraph(m_tutorialHandle);
		DeleteGraph(m_gameHandle);
		DeleteGraph(m_configHandle);
	}


	if (Mouse_Input & MOUSE_INPUT_LEFT && Mouse_x >= 200 && Mouse_x <= 420&& Mouse_y >=300 && Mouse_y <= 420) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Tutorial); // シーンをチュートリアル画面に変更
		DeleteGraph(m_tutorialHandle);
		DeleteGraph(m_gameHandle);
		DeleteGraph(m_configHandle);
	}
	if (Mouse_Input & MOUSE_INPUT_LEFT && Mouse_x >= 460 && Mouse_x <= 680 && Mouse_y >= 300 && Mouse_y <= 420) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Game); // シーンをゲーム画面に変更
		DeleteGraph(m_tutorialHandle);
		DeleteGraph(m_gameHandle);
		DeleteGraph(m_configHandle);
	}
	if (Mouse_Input & MOUSE_INPUT_LEFT && Mouse_x >= 720 && Mouse_x <= 920 && Mouse_y >= 300 && Mouse_y <= 420) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Config); // シーンを設定画面に変更
		DeleteGraph(m_tutorialHandle);
		DeleteGraph(m_gameHandle);
		DeleteGraph(m_configHandle);
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

	DrawExtendGraph(200, 300, 420, 420, m_tutorialHandle, TRUE);
	DrawExtendGraph(460, 300, 680, 420, m_gameHandle, TRUE);
	DrawExtendGraph(720, 300, 920, 420, m_configHandle, TRUE);

	DrawString(400, 200, "モードを選んでね", GetColor(0, 0, 0));
	
}