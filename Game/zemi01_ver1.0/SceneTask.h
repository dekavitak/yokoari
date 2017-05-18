/***************************************
�N���X�� : SceneTask
�쐬��   : ���� �D��
�T�v     : �V�[���̊��N���X
***************************************/

#pragma once

#include "IScene.h"
#include "ISceneChanger.h"

class SceneTask : public IScene
{

protected:
	int m_sceneHandle;             // �V�[���摜�n���h���i�[�p�ϐ�
	int mSoundPlayHandle;          // �T�E���h�i�[�p�ϐ�
	int mSoundPlayFlag = 0;        // �T�E���h�Đ��t���O
	ISceneChanger* m_sceneChanger; // �N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�[�X

public:
	SceneTask(ISceneChanger* changer);   // �R���X�g���N�^	
	virtual ~SceneTask() {}               // �f�X�g���N�^
	virtual void Initialize() override {} // �������������I�[�o�[���C�h
	virtual void Finalize()   override;  // �I���������I�[�o�[���C�h
	virtual void Update()     override {} // �X�V�������I�[�o�[���C�h
	virtual void Draw()       override;  // �`�揈�����I�[�o�[���C�h

};

