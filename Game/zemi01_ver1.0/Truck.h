#ifndef _TRUCK_H_
#define _TRUCK_H_

// �[�i�҂̊�{�f�[�^
struct TRUCK {
	int mX;
	int mY;
	int mCenterX;
	int mCenterY;
	int mHitCeil;
	int mHitFloor;
	int mDirec;
	int mSpeed;
	bool mGetFlg;
	bool mLivingFlg;
};

// �[�i�҂̊֐�
void TruckInitialize();         // �[�i�҂̏�����
void TruckMove();              // �[�i�҂̓���
void TruckUpdate();            // �[�i�҂̍X�V
void TruckRender();            // �[�i�҂̕`��
int ReturnTruckHitCeil();      // �[�i�҂̔[�i�͈͂̏����Ԃ�
int ReturnTruckHitCeil();      // �[�i�҂̔[�i�͈͂̉�����Ԃ�

#endif // !_TRUCK_H_
