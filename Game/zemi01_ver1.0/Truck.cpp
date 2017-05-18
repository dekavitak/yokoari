#include "DxLib.h"
#include "Truck.h"
#include <time.h>
#include "Define.h"
#include "Enum.h"

// �\���̃I�u�W�F�N�g�̐���
struct TRUCK truck;
time_t TruckStart, TruckNow;        // �[�i�҂�����܂ł̌v���J�n���Ԃƌo�ߎ���

// �摜�n���h��
int TruckImage[2];


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
	truck.mY = 0;
	truck.mCenterX = truck.mX + (TRUCK_WIDTH / 2);
	truck.mCenterY = truck.mY + (TRUCK_HEIGHT / 2);
	truck.mHitCeil = truck.mCenterY - TRUCK_HEIGHT;
	truck.mHitFloor = truck.mCenterY + TRUCK_HEIGHT;
	truck.mHitLeft = truck.mCenterX - TRUCK_WIDTH;
	truck.mHitRight = truck.mCenterX + TRUCK_WIDTH;
	truck.mSpeed = (int)(TRUCK_MOVE_HEIGHT / (DELI_PASS_TIME * 60));
	truck.mGetFlg = false;
	truck.mLivingFlg = false;

	// ���Ԏ擾
	time(&TruckStart);

	// �摜�̃��[�h
	LoadDivGraph(TRUCK_OBJECT, 2, 2, 1, TRUCK_WIDTH, TRUCK_HEIGHT, TruckImage);
}

/***************************************************
�@�\�@�F�[�i�҂̓���
�����@�FNone
�Ԃ�l�FNone
***************************************************/
void TruckMove() {

	// �[�i�҂𓮂���
	truck.mY += truck.mSpeed;
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
			// ������
			TruckInitialize();
			time(&TruckStart);
		}
	}

	// �[�i�҂�����Ȃ�
	if (truck.mLivingFlg == true) {
		TruckMove();
	}

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

	// �[�i�҂����݂��Ă���Ȃ�
	if (truck.mLivingFlg == true) {
		DrawGraph(truck.mX, truck.mY, TruckImage[0], TRUE);
	}

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