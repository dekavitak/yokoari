#ifndef _HIT_H_
#define _HIT_H_

// �L�����Ȃǂ̓����蔻��t���O
struct Hit {
	int mHitFlg;
};

// �����蔻��̊֐�
void InitBoxHitFlg();    // �i�{�[���̓����蔻��t���O�̏�����
void InitPlayerHitFlg(); // �v���C���[�̓����蔻��t���O�̏�����
int ReturnBoxHitFlg();      // �i�{�[���̓����蔻��t���O��Ԃ�	
int ReturnPlayerHitFlg();   // �v���C���[�̓����蔻��t���O��Ԃ�
void BoxAndPlayerHit(int, int, int, int);  // �i�{�[���ƃv���C���[�̓����蔻��


#endif _HIT_H_