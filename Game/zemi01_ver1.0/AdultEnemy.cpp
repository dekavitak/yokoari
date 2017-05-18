#include "AdultEnemy.h"
#include "DxLib.h"
#include "Box.h"
#include "Hit.h"
#include "Player.h"
#include "Enum.h"

// 画像ハンドル
int EnemyImage[2];

AdultEnemy::AdultEnemy()
{
	m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
	m_y = 100;
	m_moveCnt = 0;
	m_Flag = ENEMY_RIGHT;
	// 画像のロード
	LoadDivGraph(ADULT_ENEMY, 2, 2, 1, 64, 128, EnemyImage);
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

void AdultEnemy::Draw()
{
	int temp;
	temp = count % 20 / 10;
		if (temp == 2)
			temp = 1;
		DrawGraph(m_x, m_y, EnemyImage[temp], TRUE);

}

