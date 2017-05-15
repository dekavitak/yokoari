#include"DxLib.h"
#include"Hit.h"
#include"Define.h"
#include"Enum.h"

// �\���̃I�u�W�F�N�g�̐���
struct Hit box;
struct Hit player;

/*******************************************
�@�\�@�F�i�{�[���̓����蔻��t���O�̏�����
�����@�FNone
�Ԃ�l�FNone
*******************************************/
void InitBoxHitFlg() {
	box.mHitFlg = NEUTRAL;
}

/*******************************************
�@�\�@�F�v���C���[�̓����蔻��t���O�̏�����
�����@�FNone
�Ԃ�l�FNone
*******************************************/
void InitPlayerHitFlg() {
	player.mHitFlg = NEUTRAL;
}

/*******************************************
�@�\�@�F�i�{�[���̓����蔻��t���O��Ԃ�
�����@�FNone
�Ԃ�l�Fbox.mHitFlg
box.mHitFlg�@�F�i�{�[���̓����蔻��t���O
*******************************************/
int ReturnBoxHitFlg() {
	return box.mHitFlg;
}

/*******************************************
�@�\�@�F�v���C���[�̓����蔻��t���O��Ԃ�
�����@�FNone
�Ԃ�l�Fplayer.mHitFlg
player.mHitFlg�@�F�v���C���[�̓����蔻��t���O
*******************************************/
int ReturnPlayerHitFlg() {
	return player.mHitFlg;
}

/******************************************
�@�\�@�F�i�{�[���ƃv���C���[�̓����蔻��
�����@�F�v���C���[�ƒi�{�[���̓�����͈͂̏��
�Ԃ�l�FNone
******************************************/
void BoxAndPlayerHit(int player_right, int player_left, int box_right, int box_left) {

	if (player_right >= box_left &&
		player_left <= box_right) {

		player.mHitFlg = BOX;
		box.mHitFlg = PLAYER;
	}
}