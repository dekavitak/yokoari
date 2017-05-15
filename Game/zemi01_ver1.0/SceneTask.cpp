#include "DxLib.h"
#include "SceneTask.h"

/***************************************
関数名 : SceneTssk()
概要   : コンストラクタ
引数   : ISceneChanger * changer
戻り値 : なし
備考   : 受け取った引数から次のシーンを判断する
***************************************/
SceneTask::SceneTask(ISceneChanger* changer) : m_sceneHandle(0)
{
	m_sceneChanger = changer;
}

/***************************************
関数名 : Finalize()
概要   : 終了処理
引数   : なし
戻り値 : なし
備考   : シーンの画像オブジェクトを破棄する
***************************************/
void SceneTask::Finalize()
{
	DeleteGraph(m_sceneHandle);
}

/***************************************
関数名 : Draw()
概要   : 描画処理
引数   : なし
戻り値 : なし
備考   : シーンの画像を表示する
***************************************/
void SceneTask::Draw()
{
	DrawGraph(0, 0, m_sceneHandle, FALSE);
}