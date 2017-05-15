/***************************************
クラス名 : Tutorial
作成者   : 高津 優太
概要     : チュートリアル画面
***************************************/

#include "SceneTask.h"

class Tutorial : public SceneTask
{
public:
	Tutorial(ISceneChanger * changer); // コンストラクタ
	void Initialize() override;      // 初期化処理をオーバーライド
	void Update()     override;      // 更新処理をオーバーライド
	void Draw()       override;      // 描画処理をオーバーライド

};

