/***************************************
�N���X�� : Result
�쐬��   : ���� �D��
�T�v     : ���U���g���
***************************************/

#include "SceneTask.h"

class Result : public SceneTask
{

public:
	Result(ISceneChanger * changer); // �R���X�g���N�^
	void Initialize() override;      // �������������I�[�o�[���C�h
	void Update()     override;      // �X�V�������I�[�o�[���C�h
	void Draw()       override;      // �`�揈�����I�[�o�[���C�h
private:
	int Mouse_x;
	int Mouse_y;
	int Mouse_Input;
	int m_clearTime;

};

