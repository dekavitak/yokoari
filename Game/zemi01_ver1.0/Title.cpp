#include "DxLib.h"
#include "Title.h"


/***************************************
�֐��� : Title()
�T�v   : �R���X�g���N�^
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
Title::Title(ISceneChanger * changer) : SceneTask(changer)
{
}

/***************************************
�֐��� : Initialize()
�T�v   : ����������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �摜�����[�h����
***************************************/
void Title::Initialize()
{
	m_sceneHandle = LoadGraph("");
}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �V�[���̐؂�ւ��Ȃǂ��X�V���ɍs��
***************************************/
void Title::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {      // �X�y�[�X�L�[��������Ă�����
		m_sceneChanger->ChangeScene(eScene_Menu); // �V�[�����^�C�g���ɕύX
	}
}

/***************************************
�֐��� : Draw()
�T�v   :�`�揈��
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : ���[�h�����摜��\��������
***************************************/
void Title::Draw()
{
	SceneTask::Draw(); // �e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "�^�C�g����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "�X�y�[�X�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}

