/***************************************
�N���X�� : Menu
�쐬��   : ���� �D��
�T�v     : ���j���[���
***************************************/

#include "SceneTask.h"

class Menu : public SceneTask {

public:
	Menu(ISceneChanger* changer);
	void Initialize() override;    // �������������I�[�o�[���C�h�B
	void Update()     override;    // �X�V�������I�[�o�[���C�h�B
	void Draw()       override;    // �`�揈�����I�[�o�[���C�h�B

};