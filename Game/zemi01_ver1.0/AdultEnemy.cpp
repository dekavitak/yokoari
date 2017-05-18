#include "AdultEnemy.h"
#include "DxLib.h"



AdultEnemy::AdultEnemy()
{
	m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
	m_y = 100;
	m_moveCnt = 0;
	m_Flag = ENEMY_RIGHT;
}



void AdultEnemy::Initialize()
{

}

void AdultEnemy::Update()
{
	if (m_moveCnt == 50 && m_Flag == ENEMY_RIGHT) {
		m_moveCnt = 0;
		m_Flag = ENEMY_LEFT;
	}
	if (m_moveCnt == 50 && m_Flag == ENEMY_LEFT) {
		m_moveCnt = 0;
		m_Flag = ENEMY_RIGHT;
	}

	if (m_Flag == ENEMY_RIGHT) {
		m_x++;
		m_moveCnt++;
	}
	if (m_Flag == ENEMY_LEFT) {
		m_x--;
		m_moveCnt++;
	}

	m_y++;
	if (m_y > STAGE_FLOOR) {

		m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
		m_y = -200;

	}
}

void AdultEnemy::Draw()
{
	DrawString(m_x, m_y, "ëÂêl", GetColor(255, 255, 255));
}

