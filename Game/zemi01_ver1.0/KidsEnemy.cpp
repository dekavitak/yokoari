#include "KidsEnemy.h"
#include "DxLib.h"
#include "Define.h"



KidsEnemy::KidsEnemy()
{
	m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
	m_y = 100;
}


void KidsEnemy::Initialize()
{

}

void KidsEnemy::Update()
{
	m_y++;
	if (m_y > STAGE_FLOOR) {

		m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
		m_y = -100;

	}
}

void KidsEnemy::Draw()
{
	DrawString(m_x, m_y, "Žq‹Ÿ", GetColor(255, 255, 255));
}

