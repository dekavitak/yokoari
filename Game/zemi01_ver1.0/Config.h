/***************************************
�N���X�� : Config
�쐬��   : ���� �D��
�T�v     : �ݒ���
***************************************/

#include "SceneTask.h"

class Config : public SceneTask
{
public:
	Config(ISceneChanger * changer); // �R���X�g���N�^
	void Initialize() override;      // �������������I�[�o�[���C�h
	void Update()     override;      // �X�V�������I�[�o�[���C�h
	void Draw()       override;      // �`�揈�����I�[�o�[���C�h

};

