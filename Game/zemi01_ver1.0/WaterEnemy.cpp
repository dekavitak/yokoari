#include "WaterEnemy.h"
#include "DxLib.h"
#include "Define.h"
#include "Player.h"
#include "Hit.h"
#include "Box.h"
#include "Enum.h"



WaterEnemy::WaterEnemy()
{
	m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
	m_y = 100;
	m_CenterX = m_x + (ENEMY_WIDTH  / 2);
	m_CenterY = m_y + (ENEMY_HEIGHT / 2);
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

	// プレイヤーのいる高さに敵がいるなら
	if ((m_y + BOX_HEIGHT) >= PLAYER_HIT_CEIL &&
		m_y <= PLAYER_HIT_FLOOR) {

		// 当たり判定を行う
		EnemyAndPlayerHit(ReturnPlayerRight(), ReturnPlayerLeft(),
			m_CenterX + (PLAYER_WIDTH / 2), m_CenterX - (BOX_WIDTH / 2));
	}

	// 敵がプレイヤーに触れたなら
	if (ReturnPlayerHitFlg() == ENEMY) {
		DrawString(100, 100, "Hit", GetColor(255, 255, 255));
		ResetTakeCnt();
		// 当たり判定の初期化
		InitBoxHitFlg();
	}
	
}

void WaterEnemy::Draw()
{
	DrawString(m_x, m_y, "水", GetColor(255, 255, 255));
}

