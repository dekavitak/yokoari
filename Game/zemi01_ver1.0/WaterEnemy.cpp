#include "WaterEnemy.h"
#include "DxLib.h"
#include "Define.h"



WaterEnemy::WaterEnemy()
{
	m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
	m_y = 100;
}


void WaterEnemy::Initialize()
{

}

void WaterEnemy::Update()
{
	m_y++;
	if (m_y > STAGE_FLOOR) {

		m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
		m_y = -100;

	}
}

void WaterEnemy::Draw()
{
	DrawString(m_x, m_y, "êÖ", GetColor(255, 255, 255));
}

