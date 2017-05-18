/***************************************
クラス名 : EnemyTask.h
作成者   : 高津 優太
概要     : 敵の基底クラス
***************************************/


#pragma once
#include "IEnemy.h"

class EnemyTask : public IEnemy {


public:
	EnemyTask();							 // コンストラクタ	
	virtual ~EnemyTask() {}               // デストラクタ
	virtual void Initialize() override {}    // 初期化処理をオーバーライド
	virtual void Finalize()   override;      // 終了処理をオーバーライド
	virtual void Update()     override {}	 // 更新処理をオーバーライド
	virtual void Draw()       override;		 // 描画処理をオーバーライド


};