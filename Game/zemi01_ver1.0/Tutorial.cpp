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
	m_sceneHandle = LoadGraph("");
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // サウンドのロード
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
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {      // Escキーが押されていたら
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
	DrawString(0, 0, "チュートリアル画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}

