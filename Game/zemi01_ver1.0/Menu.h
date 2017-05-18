/***************************************
クラス名 : Menu
作成者   : 高津 優太
概要     : メニュー画面
***************************************/

#include "SceneTask.h"

class Menu : public SceneTask {


public:
	Menu(ISceneChanger* changer);
	void Initialize() override;    // 初期化処理をオーバーライド。
	void Update()     override;    // 更新処理をオーバーライド。
	void Draw()       override;    // 描画処理をオーバーライド。

private:
	int m_tutorialHandle;
	int m_gameHandle;
	int m_configHandle;

	int Mouse_x;
	int Mouse_y;
	int Mouse_Input;

};