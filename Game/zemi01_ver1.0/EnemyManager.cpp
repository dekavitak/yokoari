#include "DxLib.h"
#include "EnemyManager.h"
#include "AdultEnemy.h"
#include "KidsEnemy.h"
#include "WaterEnemy.h"


/***************************************
�֐��� : EnemyManager()
�T�v   : �R���X�g���N�^
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
EnemyManager::EnemyManager()
{
	mEnemy[0] = (EnemyTask*) new WaterEnemy;
	mEnemy[1] = (EnemyTask*) new AdultEnemy;
	mEnemy[2] = (EnemyTask*) new KidsEnemy;

}

/***************************************
�֐��� : Initialize()
�T�v   : ����������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void EnemyManager::Initialize() {
	
}

/***************************************
�֐��� : Finalize()
�T�v   : �I������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void EnemyManager::Finalize() {
	delete[] mEnemy;

}

/***************************************
�֐��� : Update()
�T�v   : �X�V����
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void EnemyManager::Update() {
	mEnemy[0]->Update();
	mEnemy[1]->Update();
	mEnemy[2]->Update();
}

/***************************************
�֐��� : Draw()
�T�v   : �`�揈��
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �Ȃ�
***************************************/
void EnemyManager::Draw() {
	mEnemy[0]->Draw();
	mEnemy[1]->Draw();
	mEnemy[2]->Draw();
}

