/***************************************
�N���X�� : EnemyManager.h
�쐬��   : ���� �D��
�T�v     : �G�Ǘ���
***************************************/


#include "EnemyTask.h"

class EnemyManager : public IEnemy {

private:
	EnemyTask* mEnemy[3];    // �G�Ǘ��ϐ�


public:
	EnemyManager();             // �R���X�g���N�^
	void Initialize() override; // ������
	void Finalize()   override; //�I������
	void Update()     override; //�X�V
	void Draw()       override; //�`��

};