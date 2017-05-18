#include "DxLib.h"
#include "Tutorial.h"
#include "Define.h"



/***************************************
関数名 : Config()
概要   : コンストラクタ
引数   : なし
戻り値 : なし
備考   : なし
***************************************/

Tutorial::Tutorial(ISceneChanger * changer) : SceneTask(changer)
{
}

/***************************************
関数名 : Initialize()
概要   : 初期化処理
引数   : なし
戻り値 : なし
備考   : 画像をロードする
***************************************/
void Tutorial::Initialize()
{
	m_sceneHandle = LoadGraph(TUTORIAL_PIC);
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // サウンドのロード
	SetFontSize(32);
}

/***************************************
関数名 : Update()
概要   : 更新処理
引数   : なし
戻り値 : なし
備考   : シーンの切り替えなどを更新時に行う
***************************************/
void Tutorial::Update()
{
	Mouse_Input = GetMouseInput();
	GetMousePoint(&Mouse_x, &Mouse_y);
	if (Mouse_Input & MOUSE_INPUT_LEFT) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Menu); // シーンをメニューに変更
	}
}

/***************************************
関数名 : Draw()
概要   :描画処理
引数   : なし
戻り値 : なし
備考   : ロードした画像を表示させる
***************************************/
void Tutorial::Draw()
{
	SceneTask::Draw(); // 親クラスの描画メソッドを呼ぶ
	
	DrawString(320, 660, "クリックで戻れるよ！", GetColor(0, 0, 0));
}

