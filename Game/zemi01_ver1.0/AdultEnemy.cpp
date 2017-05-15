#include "AdultEnemy.h"
#include "DxLib.h"


AdultEnemy::AdultEnemy()
{
	m_AdultHandle = LoadGraph("");
	m_x = 100;
	m_y = 10;
}


AdultEnemy::~AdultEnemy()
{
}

void AdultEnemy::Update() {
	m_y += 4;
}

void AdultEnemy::Draw() {
	DrawString(m_x, m_y, "ìG(ëÂêl)ÅB", GetColor(255, 255, 255));
}