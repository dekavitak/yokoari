#include "EnemyTask.h"
#include "Define.h"


class AdultEnemy : public EnemyTask
{
public:
	AdultEnemy();
	void Initialize() override;      // �������������I�[�o�[���C�h
	void Update()     override;      // �X�V�������I�[�o�[���C�h
	void Draw()       override;      // �`�揈�����I�[�o�[���C�h

private:
	int m_x;
	int m_y;
	int m_CenterX;
	int m_CenterY;
	int m_moveCnt = 0;
	int m_Flag = ENEMY_RIGHT;
	int count;
	// �摜�n���h��
	int EnemyImage[2];
	
};

