#pragma once
class WaterEnemy
{
public:
	WaterEnemy();
	~WaterEnemy();
	void Update();
	void Draw();

private:
	int m_WaterHandle;
	int m_x;
	int m_y;
};

