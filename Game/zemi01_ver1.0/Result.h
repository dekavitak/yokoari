/***************************************
クラス名 : Result
作成者   : 高津 優太
概要     : リザルト画面
***************************************/

#include "SceneTask.h"

class Result : public SceneTask
{

public:
	Result(ISceneChanger * changer); // コンストラクタ
	void Initialize() override;      // 初期化処理をオーバーライド
	void Update()     override;      // 更新処理をオーバーライド
	void Draw()       override;      // 描画処理をオーバーライド
private:
	int Mouse_x;
	int Mouse_y;
	int Mouse_Input;
	int m_clearTime;

};

