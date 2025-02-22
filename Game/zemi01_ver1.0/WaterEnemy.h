

#include "EnemyTask.h"


class WaterEnemy : public EnemyTask
{
public:
	WaterEnemy();
	void Initialize() override;      // 初期化処理をオーバーライド
	void Update()     override;      // 更新処理をオーバーライド
	void Draw()       override;      // 描画処理をオーバーライド

private:
	int m_x;
	int m_y;
	int m_CenterX;
	int m_CenterY;
	int m_enemyHandle;
};

