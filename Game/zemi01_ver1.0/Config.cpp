#include "DxLib.h"
#include "Config.h"
#include "Define.h"


/***************************************
�֐��� : Config()
�T�v   : �R���X�g���N�^
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/

Config::Config(ISceneChanger * changer) : SceneTask(changer)
{
}

/***************************************
�֐��� : Initialize()
�T�v   : ����������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �摜�����[�h����
***************************************/
void Config::Initialize()
{
	m_sceneHandle = LoadGraph("");
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); //�T�E���h�̃��[�h
}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �V�[���̐؂�ւ��Ȃǂ��X�V���ɍs��
***************************************/
void Config::Update()
{
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {      // Esc�L�[��������Ă�����
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Menu); // �V�[�������j���[�ɕύX
	}
}

/***************************************
�֐��� : Draw()
�T�v   :�`�揈��
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : ���[�h�����摜��\��������
***************************************/
void Config::Draw()
{
	SceneTask::Draw(); // �e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "�ݒ��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}

