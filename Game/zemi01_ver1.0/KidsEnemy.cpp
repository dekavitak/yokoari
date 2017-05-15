#include "KidsEnemy.h"
#include "DxLib.h"



KidsEnemy::KidsEnemy()
{
	m_kidsEnemyHandle = LoadGraph("");
	m_x = 10;
	m_y = 10;
}


KidsEnemy::~KidsEnemy()
{
}

void KidsEnemy::Update() {
	m_y += 4;
}

void KidsEnemy::Draw() {
	DrawString(m_x, m_y, "�G(�q��)�B", GetColor(255, 255, 255));
}