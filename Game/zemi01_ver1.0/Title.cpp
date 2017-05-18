#include "DxLib.h"
#include "Title.h"
#include "Define.h"



/***************************************
関数名 : Title()
概要   : コンストラクタ
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
Title::Title(ISceneChanger * changer) : SceneTask(changer)
{
}

/***************************************
関数名 : Initialize()
概要   : 初期化処理
引数   : なし
戻り値 : なし
備考   : 画像をロードする
***************************************/
void Title::Initialize()
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
void Title::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {      // スペースキーが押されていたら
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Menu); // シーンをタイトルに変更
	}
}

/***************************************
関数名 : Draw()
概要   :描画処理
引数   : なし
戻り値 : なし
備考   : ロードした画像を表示させる
***************************************/
void Title::Draw()
{
	SceneTask::Draw(); // 親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "タイトル画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "スペースキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}

