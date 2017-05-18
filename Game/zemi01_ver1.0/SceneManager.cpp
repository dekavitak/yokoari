#include "DxLib.h"
#include "Title.h"
#include "Menu.h"
#include "Tutorial.h"
#include "Config.h"
#include "Game.h"
#include "Result.h"
#include "SceneManager.h"

/***************************************
�֐��� : SceneManager()
�T�v   : �R���X�g���N�^
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �ŏ��̉�ʂ�\��(�^�C�g��)
***************************************/
SceneManager::SceneManager() : mNextScene(eScene_Neutral) // ���̃V�[���Ǘ��ϐ�
{

	mScene = (SceneTask*) new Title(this);
}

/***************************************
�֐��� : Initialize()
�T�v   : ����������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void SceneManager::Initialize() {
	mScene->Initialize();
}

/***************************************
�֐��� : Finalize()
�T�v   : �I������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void SceneManager::Finalize() {
	mScene->Finalize();
}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void SceneManager::Update() {
	if (mNextScene != eScene_Neutral) {    // ���̃V�[�����Z�b�g����Ă�����
		mScene->Finalize();                // ���݂̃V�[���̏I�����������s
		delete mScene;
		switch (mNextScene) {       // �V�[���ɂ���ď����𕪊�
		case eScene_Menu:           // ���̉�ʂ����j���[�Ȃ�
			mScene = (SceneTask*) new Menu(this);   //���j���[��ʂ̃C���X�^���X�𐶐�����
			break; // �ȉ���
		case eScene_Game:
			mScene = (SceneTask*) new Game(this);
			break;
		case eScene_Config:
			mScene = (SceneTask*) new Config(this);
			break;
		case eScene_Title:
			mScene = (SceneTask*) new Title(this);
			break;
		case eScene_Tutorial:
			mScene = (SceneTask*) new Tutorial(this);
			break;
		case eScene_Result:
			mScene = (SceneTask*) new Result(this);
			break;
		}
		mNextScene = eScene_Neutral;    // ���̃V�[�������N���A
		mScene->Initialize();           // �V�[����������
	}

	mScene->Update(); // �V�[���̍X�V
}

/***************************************
�֐��� : Draw()
�T�v   : �`�揈��
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void SceneManager::Draw() {
	mScene->Draw(); // �V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void SceneManager::ChangeScene(eScene NextScene) {
	mNextScene = NextScene;    // ���̃V�[�����Z�b�g����
}