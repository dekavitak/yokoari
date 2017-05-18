/***************************************
クラス名 : EnemyManager.h
作成者   : 高津 優太
概要     : 敵管理部
***************************************/


#include "EnemyTask.h"

class EnemyManager : public IEnemy {

private:
	EnemyTask* mEnemy[3];    // 敵管理変数


public:
	EnemyManager();             // コンストラクタ
	void Initialize() override; // 初期化
	void Finalize()   override; //終了処理
	void Update()     override; //更新
	void Draw()       override; //描画

};