#ifndef _BOX_H_
#define _BOX_H_

// �i�{�[���̊�{�f�[�^
struct Box {
	bool mLivingFlg; // �i�{�[���̃A�N�e�B�u���
	bool mTakeFlg;   // �i�{�[����������Ă��邩�̃t���O
	int mX;          // �i�{�[����x���W
	int mY;          // �i�{�[����y���W
	int mCenterX;    // �i�{�[���̒��Sx���W
	int mCenterY;    // �i�{�[���̒��Sy���W
};

// �i�{�[���̊֐�
void BoxInitialize(); // �i�{�[���̏�����
void BoxView();       // �i�{�[���̕`��
void BoxMove();       // �i�{�[���̓���
void BoxMoveLimit(int);     // �i�{�[���̓����̐���
int ReturnBoxRight(int);    // �i�{�[���̓����蔻��̉E�[��Ԃ�
int ReturnBoxLeft(int);     // �i�{�[���̓����蔻��̍��[��Ԃ�
int ReturnBoxTakeFlg(int);     // �i�{�[���̎�����Ă���t���O��Ԃ�


#endif // !_BOX_H_