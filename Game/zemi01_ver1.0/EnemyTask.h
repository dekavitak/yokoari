/***************************************
�N���X�� : EnemyTask.h
�쐬��   : ���� �D��
�T�v     : �G�̊��N���X
***************************************/


#pragma once
#include "IEnemy.h"

class EnemyTask : public IEnemy {


public:
	EnemyTask();							 // �R���X�g���N�^	
	virtual ~EnemyTask() {}               // �f�X�g���N�^
	virtual void Initialize() override {}    // �������������I�[�o�[���C�h
	virtual void Finalize()   override;      // �I���������I�[�o�[���C�h
	virtual void Update()     override {}	 // �X�V�������I�[�o�[���C�h
	virtual void Draw()       override;		 // �`�揈�����I�[�o�[���C�h


};