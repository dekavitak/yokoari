#include "DxLib.h"
#include "Menu.h"
#include "Define.h"


Menu::Menu(ISceneChanger* changer) : SceneTask(changer) {
}

/***************************************
�֐��� : Initialize()
�T�v   : ����������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void Menu::Initialize() {
	m_sceneHandle = LoadGraph("SCENE_PIC");    // �摜�̃��[�h
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // �T�E���h�̃��[�h
}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void Menu::Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {              // G�L�[��������Ă�����
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Game);     // �V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {              // C�L�[��������Ă�����
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Config);   // �V�[����ݒ��ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {              // T�L�[��������Ă�����
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Tutorial); // �V�[�����`���[�g���A����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {         // Esc�L�[��������Ă�����
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Title);    // �V�[�����^�C�g����ʂɕύX
	}
}

/***************************************
�֐��� : Draw()
�T�v   : �`�揈��
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void Menu::Draw() {
	SceneTask::Draw(); // �e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 40, "C�L�[�������Ɓ@�ݒ��ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 60, "T�L�[�������ƃ`���[�g���A����ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 80, "Esc�L�[�������Ɓ@�^�C�g����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}