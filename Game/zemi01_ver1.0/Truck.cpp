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
	truck.mX = 0;
	truck.mY = 0;
	truck.mCenterX = truck.mX + (TRUCK_WIDTH / 2);
	truck.mCenterY = truck.mY + (TRUCK_HEIGHT / 2);
	truck.mHitCeil = truck.mCenterY - TRUCK_HEIGHT;
	truck.mHitFloor = truck.mCenterY + TRUCK_HEIGHT;
	truck.mDirec = NEUTRAL;
	truck.mSpeed = (int)(720 / DELI_PASS_TIME);
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
			truck.mLivingFlg = false;
			time(&TruckStart);
		}
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

}