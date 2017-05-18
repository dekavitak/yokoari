#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H
/***************************************
�N���X�� : SystemManager
�쐬��   : ���� �D��
�T�v     : �V�X�e���̍�����S���N���X
***************************************/

#include "SceneManager.h"



class SystemManager
{
public:
	SystemManager();  // �R���X�g���N�^
	~SystemManager(); // �f�X�g���N�^

	SceneManager sceneMgr; // �V�[���}�l�[�W���[�N���X

	int Update();     // �X�V����

private:
	void GameIsInit();            // �Q�[���̏�����
	void GameIsEnd();             // �Q�[���̏C������
	void GetWindowMode(int, int); // �E�B���h�E�T�C�Y�w��
};

#endif //SYSTEM_MANAGER_H