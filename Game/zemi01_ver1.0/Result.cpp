#include "DxLib.h"
#include "Result.h"
#include "Define.h"
#include "Time.h"


/***************************************
�֐��� : Result()
�T�v   : �R���X�g���N�^
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/

Result::Result(ISceneChanger * changer) : SceneTask(changer)
{
}

/***************************************
�֐��� : Initialize()
�T�v   : ����������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �摜�����[�h����
***************************************/
void Result::Initialize()
{
	m_clearTime = ClearTime();
	m_sceneHandle = LoadGraph(SCENE_PIC);
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
void Result::Update()
{
	Mouse_Input = GetMouseInput();
	GetMousePoint(&Mouse_x, &Mouse_y);
	if (Mouse_Input & MOUSE_INPUT_LEFT) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Title); // �V�[�������j���[�ɕύX
	}
}

/***************************************
�֐��� : Draw()
�T�v   :�`�揈��
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : ���[�h�����摜��\��������
***************************************/
void Result::Draw()
{
	
	SceneTask::Draw(); // �e�N���X�̕`�惁�\�b�h���Ă�
	DrawFormatString(320, 250,GetColor(0, 0, 0),"%d", ClearTime());
	DrawString(320, 660, "�N���b�N�Ŗ߂���I", GetColor(0, 0, 0));
}

