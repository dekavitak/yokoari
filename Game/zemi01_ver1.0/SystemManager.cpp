#include "DxLib.h"
#include "SystemManager.h"


/***************************************
�֐��� : SystemManager()
�T�v   : �R���X�g���N�^
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
SystemManager::SystemManager()
{
	this->GameIsInit();
}

/***************************************
�֐��� : ~SystemManager()
�T�v   : �f�X�g���N�^
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
SystemManager::~SystemManager()
{
	this->GameIsEnd();
}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
int SystemManager::Update()
{
	sceneMgr.Initialize(); // �V�[���̏������������Ăяo��

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

		sceneMgr.Update();  // �X�V�������Ăяo��
		sceneMgr.Draw();    // �`�揈�����Ăяo��

	}

	sceneMgr.Finalize(); // �I���������Ăяo��

	return 0;
}

/***************************************
�֐��� : GameIsInit
�T�v   : �Q�[���̏�����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �R���X�g���N�^���Ă΂ꂽ���ɌĂ΂��
***************************************/
void SystemManager::GameIsInit()
{

	//width height
	this->GetWindowMode(1280, 720);

	//�E�C���h�E�̖��O��ݒ肷��
	SetMainWindowText("�����I���R�A������I");

	//�E�C���h�E�̓�d�������ł��邩��ݒ肷��@TRUE�F�\�@FALSE�F�s�\
	SetDoubleStartValidFlag(FALSE);

	//����ʂ̃Z�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {

		return;
	}

}

/***************************************
�֐��� : GameIsEnd
�T�v   : �Q�[���̏I������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �f�X�g���N�^���Ă΂ꂽ���ɌĂ΂��
***************************************/
void SystemManager::GameIsEnd()
{
	DxLib_End();

	return;
}

/***************************************
�֐��� : GetWindowMode
�T�v   : �E�B���h�E�̃T�C�Y�w��
����   : int width int height
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void SystemManager::GetWindowMode(int width, int height)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(width, height, 32);
}