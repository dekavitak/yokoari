
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	int y, add;
	int NowTime;
	int ChangeTime;
	int ScreenMode;

	int x = 0;
	int Handle00;     // �摜�i�[�p�n���h��

					  // ��ʃT�C�Y��768x576 �ɂ��Ă���
	SetGraphMode(768, 576, 32);

	
	ScreenMode = 0;
	SetWindowSize(1156, 576);
	Handle00 = LoadGraph("hako.png"); // �摜�̃��[�h

												  // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {


		DrawGraph(x, 0, Handle00, TRUE); //�摜�̕`��
		x++; // x��1���₷
	}


	// �E�C���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// �E�C���h�E�̃T�C�Y���蓮�ł͂ł����A���E�C���h�E�̃T�C�Y�ɍ��킹�Ċg������Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	

	// �c�w���C�u�����̏�����
	if (DxLib_Init() < 0) return -1;

	// �N�����̎��Ԃ�ۑ����Ă���
	ChangeTime = GetNowCount();

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// ��ʓ������E�Ɉړ�����l�p�̏����̏�����
	y = 0;
	add = 8;

	// ���C�����[�v(�����L�[�������ꂽ�烋�[�v�𔲂���)
	while (ProcessMessage() == 0)
	{
		// ��ʂ̃N���A
		ClearDrawScreen();

		// ��ʓ������E�Ɉړ�����l�p�̏���
		y += add;
		if (y <0 || y >= 540)
		{
			add = -add;
		}
		DrawBox(y, 10, y + 80, 80, GetColor(255, 255, 255), TRUE);

	
		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	


	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}