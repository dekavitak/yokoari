#include "DxLib.h"
#include "Truck.h"
#include "Player.h"
#include <time.h>
#include "Define.h"
#include "Enum.h"

// �\���̃I�u�W�F�N�g�̐���
struct TRUCK truck;
time_t TruckStart, TruckNow;        // �[�i�҂�����܂ł̌v���J�n���Ԃƌo�ߎ���

// �摜�n���h��
int TruckImage;

// �v���C���[�Ɣ[�i�҂̋������i�[����ϐ�
int Len;


/**************************************************
�@�\�@�F�[�i�҂̏�����
�����@�FNone
�Ԃ�l�FNone
**************************************************/
void TruckInitialize() {

	// �ϐ��Ȃǂ̏�����
	truck.mDirec = GetRand(1) + 1;

	// �����ɂ��`�悷��x���W��ς���
	if (truck.mDirec == RIGHT) {
		truck.mX = TRUCK_SPAWN_RIGHT;
	}
	else {
		truck.mX = TRUCK_SPAWN_LEFT;
	}
	truck.mY = 750;
	truck.mCenterX = truck.mX + (TRUCK_WIDTH / 2);
	truck.mCenterY = truck.mY + (TRUCK_HEIGHT / 2);
	truck.mHitCeil = truck.mCenterY - TRUCK_HEIGHT;
	truck.mHitFloor = truck.mCenterY + TRUCK_HEIGHT;
	truck.mHitLeft = truck.mCenterX - TRUCK_WIDTH;
	truck.mHitRight = truck.mCenterX + TRUCK_WIDTH;
	truck.mGetFlg = false;
	truck.mLivingFlg = true;
	// �v���C���[�Ɣ[�i�҂̋������Z�o
	Len = ReturnPlayerCenterY() - truck.mCenterY;

	truck.mSpeed = (int)(Len / (DELI_GET_TIME * 60));
	// ���Ԏ擾
	time(&TruckStart);

	// �摜�̃��[�h
	TruckImage = LoadGraph(TRUCK_OBJECT);
}

/***************************************************
�@�\�@�F�[�i�҂̓���
�����@�FNone
�Ԃ�l�FNone
***************************************************/
void TruckMove() {

	// �[�i�҂𓮂���
	if (truck.mGetFlg == false) {
		truck.mY--;
	}
	else{
		truck.mY++;
    }

	// �~�߂�
	if (truck.mY < 300) {
		truck.mY = 300;
	}
	truck.mCenterY = truck.mY + (TRUCK_HEIGHT / 2);
	truck.mHitCeil = truck.mCenterY - TRUCK_HEIGHT;
	truck.mHitFloor = truck.mCenterY + TRUCK_HEIGHT;

}

/***************************************************
�@�\�@�F�[�i�҂̍X�V
�����@�FNone
�Ԃ�l�FNone
***************************************************/
void TruckUpdate() {

	time(&TruckNow);
	// �[�i�҂��������Ă��Ȃ��Ȃ�
	if (truck.mGetFlg == false) {
		// �����̎��ԂɂȂ�����
		if ((TruckStart + DELI_GET_TIME) <= TruckNow) {
			truck.mGetFlg = true;
			truck.mLivingFlg = true;
			time(&TruckStart);
		}
	}
	// �������Ă���Ȃ�
	else {
		// �ʂ�߂��鎞�ԂɂȂ�����
		if ((TruckStart + DELI_PASS_TIME) <= TruckNow) {
			truck.mGetFlg = false;
			time(&TruckStart);
		}
	}

	TruckMove();

}

/***************************************************
�@�\�@�F�[�i�҂̕`��
�����@�FNone
�Ԃ�l�FNone
***************************************************/
void TruckRender() {

	time(&TruckNow);
	// �[�i�҂��������Ă��Ȃ��Ȃ�
	if (truck.mGetFlg == false) {
		// ���Ԃ̕\��
		DrawFormatString(0, 170, GetColor(255, 255, 255), "�[�i�҂�����܂�:%d�b", (int)((TruckStart + DELI_GET_TIME) - TruckNow));
	}
	// �������Ă���Ȃ�
	else {
		// ���Ԃ̕\��
		DrawFormatString(0, 170, GetColor(255, 255, 255), "�[�i�҂��ʉ߂���܂�:%d�b", (int)((TruckStart + DELI_PASS_TIME) - TruckNow));
	}

	DrawGraph(truck.mX, truck.mY, TruckImage, TRUE);
}

/****************************************
�@�\�@�F�[�i�҂̔[�i�͈͂̏����Ԃ�
�����@�FNone
�Ԃ�l�Ftruck.mHitCeil
*****************************************/
int ReturnTruckHitCeil() {

	return truck.mHitCeil;

}

/****************************************
�@�\�@�F�[�i�҂̔[�i�͈͂̉�����Ԃ�
�����@�FNone
�Ԃ�l�Ftruck.mHitFloor
*****************************************/
int ReturnTruckHitFloor() {

	return truck.mHitFloor;

}

/****************************************
�@�\�@�F�[�i�҂̔[�i�͈͂̍�����Ԃ�
�����@�FNone
�Ԃ�l�Ftruck.mHitLeft
*****************************************/
int ReturnTruckHitLeft() {

	return truck.mHitLeft;

}

/****************************************
�@�\�@�F�[�i�҂̔[�i�͈͂̉E����Ԃ�
�����@�FNone
�Ԃ�l�Ftruck.mHitRight
*****************************************/
int ReturnTruckHitRight() {

	return truck.mHitRight;

}