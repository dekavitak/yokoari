/***************************************
�N���X�� : ISceneChanger
�쐬��   : ���� �D��
�T�v     : �V�[����ύX���邽�߂̃C���^�[�t�F�[�X�N���X
***************************************/

#pragma once

typedef enum {
	eScene_Title,    // �^�C�g��
	eScene_Menu,     // ���j���[
	eScene_Tutorial, // �`���[�g���A��
	eScene_Config,   // �ݒ�
	eScene_Game,     // �Q�[��
	eScene_Result,   // ���U���g
	eScene_Neutral,  // ����
}eScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;  // �f�X�g���N�^
	virtual void ChangeScene(eScene NextScene) = 0;
};

