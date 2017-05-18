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

	// サウンドを止め、破棄する
	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 1) {
		mSoundPlayFlag = 0;
		StopSoundMem(mSoundPlayHandle);
		DeleteSoundMem(mSoundPlayHandle);

	}
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
	DrawExtendGraph(0, 0, 1000, 720, m_sceneHandle, FALSE);

	// サウンド再生フラグを立てる
	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 0) {
		PlaySoundMem(mSoundPlayHandle, DX_PLAYTYPE_LOOP, TRUE); // 再生
		mSoundPlayFlag = 1;
	}
}