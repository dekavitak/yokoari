#ifndef _PLAYER_H_
#define _PLAYER_H_

// �v���C���[�̊�{�f�[�^
struct PLAYER {
	int mX;				 // x���W
	int mY;				 // y���W
	int mCenterX;		 // ���S��x���W
	int mCenterY;        // ���S��y���W
	int mSpeed;		     // �ړ����x
	int mDirec;          // �ړ��������
	int mGraphNum;       // �\������摜�̔ԍ�
	int mAnimationCnt;   // �A�j���[�V�����̃J�E���g
	int mTakeFlg;        // ���������Ă��邩�ǂ����̃t���O
	bool mGraphFlg;      // �摜�؂�ւ��̃t���O
};


// �v���C���[�̊֐�

void PlayerInitialize();    // ������
void PlayerRender();          // �v���C���[�̕`��
void PlayerController();    // ����
void PlayerMove();          // �v���C���[�̓���
void PlayerUpdate();        // �v���C���[�̍X�V
void PlayerMoveLimit();     // �v���C���[�̓����̐���
void PlayerAnimation();     // �v���C���[�̃A�j���[�V����
int ReturnPlayerRight();    // �v���C���[�̓����蔻��̉E�[��Ԃ�
int ReturnPlayerLeft();     // �v���C���[�̓����蔻��̍��[��Ԃ�
int ReturnPlayerCenterX();  // �v���C���[�̒��Sx���W��Ԃ�
int ReturnPlayerCenterY();  // �v���C���[�̒��Sy���W�Ԃ�

#endif // !_PLAYER_H_