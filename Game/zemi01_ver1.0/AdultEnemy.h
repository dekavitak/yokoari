#include "EnemyTask.h"
#include "Define.h"


class AdultEnemy : public EnemyTask
{
public:
	AdultEnemy();
	void Initialize() override;      // 初期化処理をオーバーライド
	void Update()     override;      // 更新処理をオーバーライド
	void Draw()       override;      // 描画処理をオーバーライド

private:
	int m_x;
	int m_y;
	int m_CenterX;
	int m_CenterY;
	int m_moveCnt = 0;
	int m_Flag = ENEMY_RIGHT;
	int count;
	// 画像ハンドル
	int EnemyImage[2];
	
};

