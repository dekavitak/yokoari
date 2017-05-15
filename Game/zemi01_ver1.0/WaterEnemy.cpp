#include "WaterEnemy.h"
#include "DxLib.h"


WaterEnemy::WaterEnemy()
{
	m_WaterHandle = LoadGraph("");
	m_x = 200;
	m_y = 100;
}


WaterEnemy::~WaterEnemy()
{
}

void WaterEnemy::Update() {

}

void WaterEnemy::Draw() {
	DrawString(m_x, m_y, "ìG(êÖ)ÅB", GetColor(255, 255, 255));
}