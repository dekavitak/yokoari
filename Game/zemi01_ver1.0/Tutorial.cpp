#include "DxLib.h"
#include "Tutorial.h"
#include "Define.h"



/***************************************
�֐��� : Config()
�T�v   : �R���X�g���N�^
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/

Tutorial::Tutorial(ISceneChanger * changer) : SceneTask(changer)
{
}

/***************************************
�֐��� : Initialize()
�T�v   : ����������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �摜�����[�h����
***************************************/
void Tutorial::Initialize()
{
	m_sceneHandle = LoadGraph(TUTORIAL_PIC);
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // �T�E���h�̃��[�h
	SetFontSize(32);
}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �V�[���̐؂�ւ��Ȃǂ��X�V���ɍs��
***************************************/
void Tutorial::Update()
{
	Mouse_Input = GetMouseInput();
	GetMousePoint(&Mouse_x, &Mouse_y);
	if (Mouse_Input & MOUSE_INPUT_LEFT) {
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
void Tutorial::Draw()
{
	SceneTask::Draw(); // �e�N���X�̕`�惁�\�b�h���Ă�
	
	DrawString(320, 660, "�N���b�N�Ŗ߂���I", GetColor(0, 0, 0));
}

