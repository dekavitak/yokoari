#include "DxLib.h"
#include "Player.h"
#include "Define.h"
#include "Enum.h"
#include "Hit.h"
#include "Box.h"

// �\���̃I�u�W�F�N�g�̐���
struct PLAYER player;

// �摜�n���h��
int PlayerImage[4];

// �}�E�X�̍��W���i�[����ϐ�
int Mouse_x, Mouse_y;

/****************************************
�@�\�@�F�v���C���[�֘A�̕ϐ����̏�����
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void PlayerInitialize() {

	// �v���C���[�̏�����
	player.mDirec = NEUTRAL;
	player.mX = 384;
	player.mY = 289;
	player.mCenterX = player.mX + (PLAYER_WIDTH / 2);
	player.mCenterY = player.mY + (PLAYER_HEIGHT / 2);
	player.mSpeed = 5;
	player.mGraphNum = 0;
	player.mAnimationCnt = 0;
	player.mTakeFlg = 0;
	player.mGraphFlg = false;
    InitPlayerHitFlg();

	// �摜�̃��[�h
	LoadDivGraph("img/yokoari.png", 4, 4, 1, 128, 128, PlayerImage);

}

/****************************************
�@�\�@�F�v���C���[�̕`��
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void PlayerView() {

	// �\������摜�̍X�V
	PlayerAnimation();

	// �v���C���[�̕`��
	DrawGraph(player.mX, player.mY, PlayerImage[player.mGraphNum + player.mTakeFlg], TRUE);

}

/****************************************
�@�\�@�F�v���C���[�̑���
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void PlayerController() {

	// �}�E�X�̍��W���擾
	GetMousePoint(&Mouse_x, &Mouse_y);

	// �}�E�X�̍��W�ɂ���Ĉړ���������ύX
	if (player.mCenterX > Mouse_x + player.mSpeed) {
		player.mDirec = LEFT;
	}
	else if (player.mCenterX < Mouse_x - player.mSpeed) {
		player.mDirec = RIGHT;
	}
	else {
		player.mCenterX = Mouse_x;
		player.mDirec = NEUTRAL;
	}

}

/****************************************
�@�\�@�F�v���C���[�̓���
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void PlayerMove() {

	// �v���C���[�̈ړ�����������X�V
	PlayerController();

	// �ړ���������ɂ���ăv���C���[�̍��W�𓮂���
	if (player.mDirec == RIGHT) {
		player.mX += player.mSpeed;
	}
	else if (player.mDirec == LEFT) {
		player.mX -= player.mSpeed;
	}

	// �����̐���
	PlayerMoveLimit();

	// �����Ă����Ԃ̍X�V
	for (int i = 0; i < BOX_LENGTH; i++) {
		// �����Ă���Ȃ�
		if (ReturnBoxTakeFlg(i) == true) {
			// �摜��؂�ւ���t���O��true�ɂ���
			player.mGraphFlg = true;
			break;
		}
		// �����Ă��Ȃ��Ȃ�
		else {
			// �摜��؂�ւ���t���O��false�ɂ���
			player.mGraphFlg = false;
		}
	}
	// �摜��؂�ւ���
	if (player.mGraphFlg == true) {
		player.mTakeFlg = BOX;
	}
	else {
		player.mTakeFlg = NEUTRAL;
	}
	// ���S���W�̍X�V
	player.mCenterX = player.mX + (PLAYER_WIDTH / 2);
}

/****************************************
�@�\�@�F�v���C���[�̓����̐���
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void PlayerMoveLimit() {

	// ��ʊO�ɏo�悤�Ƃ�����
	if (player.mX <= STAGE_LEFT) {
		player.mX = STAGE_LEFT;
	}
	else if (player.mX >= STAGE_RIGHT) {
		player.mX = STAGE_RIGHT;
	}
}

/****************************************
�@�\�@�F�v���C���[�̃A�j���[�V����
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void PlayerAnimation() {

	// ��莞�Ԍo�߂�����
	if (player.mAnimationCnt >= 30) {

		// �`�悷��摜��؂�ւ�
		if (player.mGraphNum == 0) {
			player.mGraphNum = 1;
		}
		else {
			player.mGraphNum = 0;
		}

		// �J�E���g�����Z�b�g
		player.mAnimationCnt = 0;
	}

	// �J�E���g�����Z
	player.mAnimationCnt++;

}

/****************************************
�@�\�@�F�v���C���[�̓����蔻��̉E�[��Ԃ�
�����@�FNone
�Ԃ�l�F�v���C���[�̓����蔻��̉E�[
*****************************************/
int ReturnPlayerRight() {

	return player.mCenterX + (PLAYER_WIDTH / 2);

}

/****************************************
�@�\�@�F�v���C���[�̓����蔻��̍��[��Ԃ�
�����@�FNone
�Ԃ�l�F�v���C���[�̓����蔻��̍��[
*****************************************/
int ReturnPlayerLeft() {

	return player.mCenterX - (PLAYER_WIDTH / 2);

}

/****************************************
�@�\�@�F�v���C���[�̒��Sx���W��Ԃ�
�����@�FNone
�Ԃ�l�Fplayer.mCenterX
*****************************************/
int ReturnPlayerCenterX() {

	return player.mCenterX;

}

/****************************************
�@�\�@�F�v���C���[�̒��Sy���W��Ԃ�
�����@�FNone
�Ԃ�l�Fplayer.mCenterY
*****************************************/
int ReturnPlayerCenterY() {

	return player.mCenterY;

}