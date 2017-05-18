#include"DxLib.h"
#include"Time.h"
#include<time.h>
#include"Define.h"


time_t start, now;  // �J�n���̎���, �o�ߎ���
bool timer_flg;     // �������Ԃ��o�߂������ǂ����̃t���O

/****************************************
�@�\�@�F�^�C�}�[�̏�����
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void TimerInitialize() {

	time(&start);
	timer_flg = false;
	
}

/****************************************
�@�\�@�F�^�C�}�[�̍X�V
�����@�FNone
�Ԃ�l�FNone
*****************************************/
void TimerUpdate() {
	
	// �o�ߎ��Ԃ̎擾
	time(&now);
	// 60�b�o������
	if ((start + MAX_TIME) <= now) {
		timer_flg = true;
	}
	// �������Ԃ̕\��
	DrawFormatString(0, 130, GetColor(255, 255, 255), "��������:%d", (int)((start + MAX_TIME) - now));

}

/****************************************
�@�\�@�F�^�C�}�[�̃t���O��Ԃ�
�����@�FNone
�Ԃ�l�FNone
*****************************************/
int ReturnTimerFlg() {

	return timer_flg;

}