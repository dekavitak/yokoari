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
	int mHitRight;
	int mHitLeft;
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
int ReturnTruckHitFloor();      // �[�i�҂̔[�i�͈͂̉�����Ԃ�
int ReturnTruckHitLeft();      // �[�i�҂̔[�i�͈͂̍�����Ԃ�
int ReturnTruckHitRight();      // �[�i�҂̔[�i�͈͂̉E����Ԃ�

#endif // !_TRUCK_H_
