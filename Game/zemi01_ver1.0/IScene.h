/***************************************
�N���X�� : IScene
�쐬��   : ���� �D��
�T�v     : �V�[���֘A�N���X�͂��̃N���X���p������
***************************************/

#pragma once

class IScene {

public:
	virtual ~IScene() {}          // �f�X�g���N�^
	virtual void Initialize() {}  // ����������
	virtual void Finalize() {}    // �I������
	virtual void Update() = 0;   // �X�V����
	virtual void Draw() = 0;     // �`�揈��
};