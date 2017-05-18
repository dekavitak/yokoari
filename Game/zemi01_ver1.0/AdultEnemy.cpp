#include "AdultEnemy.h"
#include "DxLib.h"
#include "Box.h"
#include "Hit.h"
#include "Player.h"
#include "Enum.h"



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

	// �v���C���[�̂��鍂���ɓG������Ȃ�
	if ((m_y + BOX_HEIGHT) >= PLAYER_HIT_CEIL &&
		m_y <= PLAYER_HIT_FLOOR) {

		// �����蔻����s��
		EnemyAndPlayerHit(ReturnPlayerRight(), ReturnPlayerLeft(),
			m_CenterX + (PLAYER_WIDTH / 2), m_CenterX - (BOX_WIDTH / 2));
	}

	// �G���v���C���[�ɐG�ꂽ�Ȃ�
	if (ReturnPlayerHitFlg() == ENEMY) {
		DrawString(100, 100, "Hit", GetColor(255, 255, 255));
		ResetTakeCnt();
		// �����蔻��̏�����
		InitBoxHitFlg();
	}
}

void AdultEnemy::Draw()
{
	DrawString(m_x, m_y, "��l", GetColor(255, 255, 255));
}
