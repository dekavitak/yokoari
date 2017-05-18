#include "DxLib.h"
#include "Title.h"
#include "Define.h"



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
	SetFontSize(64);
	m_sceneHandle = LoadGraph(TITLE_PIC);
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // �T�E���h�̃��[�h
	
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
	Mouse_Input = GetMouseInput();
	GetMousePoint(&Mouse_x, &Mouse_y);

	if (Mouse_Input & MOUSE_INPUT_LEFT) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
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
	DrawString(160, 500, "�N���b�N�ŃX�^�[�g!!", GetColor(0, 0, 0));
}

