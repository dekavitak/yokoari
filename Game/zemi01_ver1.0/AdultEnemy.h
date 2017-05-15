#pragma once
class AdultEnemy
{
public:
	AdultEnemy();
	~AdultEnemy();
	void Update();
	void Draw();

private:
	int m_AdultHandle;
	int m_x;
	int m_y;
};

