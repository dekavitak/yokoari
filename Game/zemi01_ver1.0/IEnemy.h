/***************************************
�N���X�� : IEnemy
�쐬��   : ���� �D��
�T�v     : �G�֘A�N���X�͂��̃N���X���p������
***************************************/


#pragma once

class IEnemy {

public:
	virtual ~IEnemy() {}          // �f�X�g���N�^
	virtual void Initialize() {}  // ����������
	virtual void Finalize() {}    // �I������
	virtual void Update() = 0;    // �X�V����
	virtual void Draw() = 0;      // �`�揈��
};