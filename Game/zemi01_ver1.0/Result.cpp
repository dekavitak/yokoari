#include "DxLib.h"
#include "Result.h"
#include "Define.h"
#include "Time.h"


/***************************************
関数名 : Result()
概要   : コンストラクタ
引数   : なし
戻り値 : なし
備考   : なし
***************************************/

Result::Result(ISceneChanger * changer) : SceneTask(changer)
{
}

/***************************************
関数名 : Initialize()
概要   : 初期化処理
引数   : なし
戻り値 : なし
備考   : 画像をロードする
***************************************/
void Result::Initialize()
{
	m_clearTime = ClearTime();
	m_sceneHandle = LoadGraph(SCENE_PIC);
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
void Result::Update()
{
	Mouse_Input = GetMouseInput();
	GetMousePoint(&Mouse_x, &Mouse_y);
	if (Mouse_Input & MOUSE_INPUT_LEFT) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Title); // シーンをメニューに変更
	}
}

/***************************************
関数名 : Draw()
概要   :描画処理
引数   : なし
戻り値 : なし
備考   : ロードした画像を表示させる
***************************************/
void Result::Draw()
{
	
	SceneTask::Draw(); // 親クラスの描画メソッドを呼ぶ
	DrawFormatString(320, 250,GetColor(0, 0, 0),"%d", ClearTime());
	DrawString(320, 660, "クリックで戻れるよ！", GetColor(0, 0, 0));
}

