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
	m_sceneHandle = LoadGraph(SCENE_PIC);    // �摜�̃��[�h
	m_tutorialHandle = LoadGraph(TUTORIAL_BUTTON);
	m_gameHandle = LoadGraph(START_BUTTON);
	m_configHandle = LoadGraph(MENU_BUTTON);
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // �T�E���h�̃��[�h

	SetFontSize(32);

}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void Menu::Update() {

	Mouse_Input = GetMouseInput();
	GetMousePoint(&Mouse_x, &Mouse_y);
	
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {         // Esc�L�[��������Ă�����
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Title);    // �V�[�����^�C�g����ʂɕύX
		DeleteGraph(m_tutorialHandle);
		DeleteGraph(m_gameHandle);
		DeleteGraph(m_configHandle);
	}


	if (Mouse_Input & MOUSE_INPUT_LEFT && Mouse_x >= 200 && Mouse_x <= 420&& Mouse_y >=300 && Mouse_y <= 420) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Tutorial); // �V�[�����`���[�g���A����ʂɕύX
		DeleteGraph(m_tutorialHandle);
		DeleteGraph(m_gameHandle);
		DeleteGraph(m_configHandle);
	}
	if (Mouse_Input & MOUSE_INPUT_LEFT && Mouse_x >= 460 && Mouse_x <= 680 && Mouse_y >= 300 && Mouse_y <= 420) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Game); // �V�[�����Q�[����ʂɕύX
		DeleteGraph(m_tutorialHandle);
		DeleteGraph(m_gameHandle);
		DeleteGraph(m_configHandle);
	}
	if (Mouse_Input & MOUSE_INPUT_LEFT && Mouse_x >= 720 && Mouse_x <= 920 && Mouse_y >= 300 && Mouse_y <= 420) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Config); // �V�[����ݒ��ʂɕύX
		DeleteGraph(m_tutorialHandle);
		DeleteGraph(m_gameHandle);
		DeleteGraph(m_configHandle);
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

	DrawExtendGraph(200, 300, 420, 420, m_tutorialHandle, TRUE);
	DrawExtendGraph(460, 300, 680, 420, m_gameHandle, TRUE);
	DrawExtendGraph(720, 300, 920, 420, m_configHandle, TRUE);

	DrawString(400, 200, "���[�h��I��ł�", GetColor(0, 0, 0));
	
}