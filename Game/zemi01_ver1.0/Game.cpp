#include "DxLib.h"
#include "Game.h"
#include "Define.h"
#include "Player.h"
#include "Box.h"
#include "Time.h"


Game::Game(ISceneChanger* changer) : SceneTask(changer) {
}

/***************************************
�֐��� : Initialize()
�T�v   :����������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/

void Game::Initialize() {
	m_sceneHandle = LoadGraph("");    // �摜�̃��[�h
	mSoundPlayHandle = LoadSoundMem(GAME_BGM); // �T�E���h�̃��[�h
	PlayerInitialize();               // �v���C���[�̏�����
	BoxInitialize();                  // �i�{�[���̏�����
	TimerInitialize();

}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/

void Game::Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {       // Esc�L�[��������Ă�����
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SE�̍Đ�
		m_sceneChanger->ChangeScene(eScene_Menu);   // �V�[�������j���[�ɕύX
	}
	if (ReturnDeliveryNum() >= 20 ||
		ReturnTimerFlg() == true) {            // �i�{�[����20�[�i������
		m_sceneChanger->ChangeScene(eScene_Result); // �V�[�������U���g�ɕύX
	}
	
	
	// �i�{�[���̓����A�`��
	BoxMove();
	BoxView();

	// �v���C���[�̓����A�`��
	PlayerMove();
	PlayerView();

	TimerUpdate();
}

/***************************************
�֐��� : Draw()
�T�v   : �`�揈��
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/

void Game::Draw() {
	SceneTask::Draw(); // �e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
	DrawString(0, 40, "R�L�[�������ƃ��U���g��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}