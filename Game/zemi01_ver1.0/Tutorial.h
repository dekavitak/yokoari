/***************************************
�N���X�� : Tutorial
�쐬��   : ���� �D��
�T�v     : �`���[�g���A�����
***************************************/

#include "SceneTask.h"


class Tutorial : public SceneTask
{
public:
	Tutorial(ISceneChanger * changer); // �R���X�g���N�^
	void Initialize() override;      // �������������I�[�o�[���C�h
	void Update()     override;      // �X�V�������I�[�o�[���C�h
	void Draw()       override;      // �`�揈�����I�[�o�[���C�h

private:
	int Mouse_x;
	int Mouse_y;
	int Mouse_Input;

};

