/***************************************
クラス名 : Game
作成者   : 高津 優太
概要     : メインゲームの処理をここに書いていく
***************************************/

#include "SceneTask.h"
#include "ISceneChanger.h"
#include "EnemyManager.h"



//ゲーム画面クラス
class Game : public SceneTask {

public:
	Game::Game(ISceneChanger* changer);
	void Initialize() override;    // 初期化処理をオーバーライド。
	void Update()     override;    // 更新処理をオーバーライド。
	void Draw()       override;    // 描画処理をオーバーライド。
	EnemyManager enemyMgr;




};