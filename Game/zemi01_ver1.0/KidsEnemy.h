
#include "EnemyTask.h"


class KidsEnemy : public EnemyTask
{
public:
	KidsEnemy();
	void Initialize() override;      // �������������I�[�o�[���C�h
	void Update()     override;      // �X�V�������I�[�o�[���C�h
	void Draw()       override;      // �`�揈�����I�[�o�[���C�h
	
private:
	int m_x;
	int m_y;
	int m_CenterX;
	int m_CenterY;
};

