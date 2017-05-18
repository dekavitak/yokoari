#include "KidsEnemy.h"
#include "DxLib.h"
#include "Define.h"
#include "Box.h"
#include "Hit.h"
#include "Player.h"
#include "Enum.h"


KidsEnemy::KidsEnemy()
{
	m_x = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
	m_y = 100;
	// 画像のロード
	LoadDivGraph(KIDS_ENEMY, 2, 2, 1, 128, 128, EnemyImage);
	count = 0;
}


void KidsEnemy::Initialize()
{

}

void KidsEnemy::Update()
{
	count++;
	m_y+=5;
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
		
		ResetTakeCnt();
		// 当たり判定の初期化
		InitBoxHitFlg();
	}
}

void KidsEnemy::Draw()
{
	int temp;
	temp = count % 20 / 10;
	if (temp == 2)
		temp = 1;
	
	DrawGraph(m_x, m_y, EnemyImage[temp], TRUE);
}

