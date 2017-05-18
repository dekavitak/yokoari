#include "DxLib.h"
#include "Game.h"
#include "Define.h"
#include "Player.h"
#include "Box.h"
#include "Time.h"
#include "Truck.h"



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
	m_sceneHandle = LoadGraph(STAGE_PIC);    // �摜�̃��[�h
	mSoundPlayHandle = LoadSoundMem(GAME_BGM); // �T�E���h�̃��[�h
	PlayerInitialize();               // �v���C���[�̏�����

	for (int i = 0; i < BOX_LENGTH; i++) {
		BoxInitialize(i);                  // �i�{�[���̏�����
	}

	TimerInitialize();      // ���Ԃ̏�����
	TruckInitialize();      // �[�i�҂̏�����

	SetFontSize(16);
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
		m_sceneChanger->ChangeScene(eScene_Result);   // �V�[�������j���[�ɕύX
	}
	if (ReturnDeliveryNum() >= 20 ||
		ReturnTimerFlg() == true) {            // �i�{�[����20�[�i������
		m_sceneChanger->ChangeScene(eScene_Result); // �V�[�������U���g�ɕύX
	}
	enemyMgr.Update();
	enemyMgr.Draw();
	
	// �i�{�[���̓����A�`��
	BoxUpdate();
	BoxRender();

	// �v���C���[�̓����A�`��
	PlayerUpdate();
	PlayerRender();

	// ���Ԃ̕\��
	TimerUpdate();

	// �[�i�҂̕`��
	TruckRender();
	TruckUpdate();
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
	
}