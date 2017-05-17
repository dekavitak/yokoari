#include"DxLib.h"
#include"Time.h"
#include<time.h>
#include"Define.h"

time_t LimitStart, Now;  // �J�n���̎���, �o�ߎ���
time_t DeliStart;        // �[�i�҂�����܂ł̌v���J�n����
bool timer_flg;     // �������Ԃ��o�߂������ǂ����̃t���O
bool deli_flg;      // �[�i�ҏ��̕\���̐؂�ւ��t���O

/****************************************
�@�\�@�F�^�C�}�[�̏�����
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void TimerInitialize() {

	time(&LimitStart);
	time(&DeliStart);
	timer_flg = false;
	deli_flg = false;
	
}

/****************************************
�@�\�@�F�^�C�}�[�̍X�V
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void TimerUpdate() {
	
	// �o�ߎ��Ԃ̎擾
	time(&Now);
	// �������Ԃ��߂�����
	if ((LimitStart + MAX_TIME) <= Now) {
		timer_flg = true;
	}
	// �������Ԃ̕\��
	DrawFormatString(0, 130, GetColor(255, 255, 255), "��������:%d�b", (int)((LimitStart + MAX_TIME) - Now));

	time(&Now);
	// �[�i�҂��������Ă��Ȃ��Ȃ�
	if (deli_flg == false) {
		// �����̎��ԂɂȂ�����
		if ((DeliStart + DELI_GET_TIME) <= Now) {
			deli_flg = true;
			time(&DeliStart);
		}
		// ���Ԃ̕\��
		DrawFormatString(0, 170, GetColor(255, 255, 255), "�[�i�҂�����܂�:%d�b", (int)((DeliStart + DELI_GET_TIME) - Now));
	}
	// �������Ă���Ȃ�
	else {
		// �ʂ�߂��鎞�ԂɂȂ�����
		if ((DeliStart + DELI_PASS_TIME) <= Now) {
			deli_flg = false;
			time(&DeliStart);
		}
		// ���Ԃ̕\��
		DrawFormatString(0, 170, GetColor(255, 255, 255), "�[�i�҂��ʉ߂���܂�:%d�b", (int)((DeliStart + DELI_PASS_TIME) - Now));
	}

}

/****************************************
�@�\�@�F�^�C�}�[�̃t���O��Ԃ�
�����@�FNone
�Ԃ�l�FNone
*****************************************/
int ReturnTimerFlg() {

	return timer_flg;

}