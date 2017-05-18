/***************************************
クラス名 : SceneManager.h
作成者   : 高津 優太
概要     : シーン管理部
***************************************/

#include "ISceneChanger.h"
#include "SceneTask.h"

class SceneManager : public ISceneChanger, IScene {
	

private:
	SceneTask* mScene;    // シーン管理変数
	eScene mNextScene;    // 次のシーン管理変数

public:
	SceneManager();             // コンストラクタ
	void Initialize() override; // 初期化
	void Finalize()   override; //終了処理
	void Update()     override; //更新
	void Draw()       override; //描画

								// 引数 nextScene にシーンを変更する					 
	void ChangeScene(eScene NextScene) override;

};