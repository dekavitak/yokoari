/***************************************
クラス名 : SceneTask
作成者   : 高津 優太
概要     : シーンの基底クラス
***************************************/

#pragma once

#include "IScene.h"
#include "ISceneChanger.h"

class SceneTask : public IScene
{

protected:
	int m_sceneHandle;             // シーン画像ハンドル格納用変数
	int mSoundPlayHandle;          // サウンド格納用変数
	int mSoundPlayFlag = 0;        // サウンド再生フラグ
	ISceneChanger* m_sceneChanger; // クラス所有元にシーン切り替えを伝えるインターフェース

public:
	SceneTask(ISceneChanger* changer);   // コンストラクタ	
	virtual ~SceneTask() {}               // デストラクタ
	virtual void Initialize() override {} // 初期化処理をオーバーライド
	virtual void Finalize()   override;  // 終了処理をオーバーライド
	virtual void Update()     override {} // 更新処理をオーバーライド
	virtual void Draw()       override;  // 描画処理をオーバーライド

};

