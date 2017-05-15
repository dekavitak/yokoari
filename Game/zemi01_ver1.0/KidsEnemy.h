#pragma once
class KidsEnemy
{
public:
	KidsEnemy();
	~KidsEnemy();
	void Update();
	void Draw();

private:
	int m_kidsEnemyHandle;
	int m_x;
	int m_y;
};

