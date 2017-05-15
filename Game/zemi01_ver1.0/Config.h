/***************************************
クラス名 : Config
作成者   : 高津 優太
概要     : 設定画面
***************************************/

#include "SceneTask.h"

class Config : public SceneTask
{
public:
	Config(ISceneChanger * changer); // コンストラクタ
	void Initialize() override;      // 初期化処理をオーバーライド
	void Update()     override;      // 更新処理をオーバーライド
	void Draw()       override;      // 描画処理をオーバーライド

};

