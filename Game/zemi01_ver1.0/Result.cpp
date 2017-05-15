#include "DxLib.h"
#include "Result.h"


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
	m_sceneHandle = LoadGraph("");
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
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {      // Escキーが押されていたら
		m_sceneChanger->ChangeScene(eScene_Title); // シーンをタイトルに変更
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
	DrawString(0, 0, "リザルト画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとタイトル画面に戻ります。", GetColor(255, 255, 255));
}

