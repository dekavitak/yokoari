/***************************************
�N���X�� : Title
�쐬��   : ���� �D��
�T�v     : �^�C�g�����
***************************************/


#include "SceneTask.h"

class  Title : public SceneTask
{
public:
	Title(ISceneChanger * changer); // �R���X�g���N�^
	void Initialize() override;      // �������������I�[�o�[���C�h
	void Update()     override;      // �X�V�������I�[�o�[���C�h
	void Draw()       override;      // �`�揈�����I�[�o�[���C�h

private:
	int Mouse_x;
	int Mouse_y;
	int Mouse_Input;

};

