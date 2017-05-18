/***************************************
�N���X�� : Game
�쐬��   : ���� �D��
�T�v     : ���C���Q�[���̏����������ɏ����Ă���
***************************************/

#include "SceneTask.h"
#include "ISceneChanger.h"
#include "EnemyManager.h"



//�Q�[����ʃN���X
class Game : public SceneTask {

public:
	Game::Game(ISceneChanger* changer);
	void Initialize() override;    // �������������I�[�o�[���C�h�B
	void Update()     override;    // �X�V�������I�[�o�[���C�h�B
	void Draw()       override;    // �`�揈�����I�[�o�[���C�h�B
	EnemyManager enemyMgr;




};