/***************************************
�N���X�� : SceneManager.h
�쐬��   : ���� �D��
�T�v     : �V�[���Ǘ���
***************************************/

#include "ISceneChanger.h"
#include "SceneTask.h"

class SceneManager : public ISceneChanger, IScene {
	

private:
	SceneTask* mScene;    // �V�[���Ǘ��ϐ�
	eScene mNextScene;    // ���̃V�[���Ǘ��ϐ�

public:
	SceneManager();             // �R���X�g���N�^
	void Initialize() override; // ������
	void Finalize()   override; //�I������
	void Update()     override; //�X�V
	void Draw()       override; //�`��

								// ���� nextScene �ɃV�[����ύX����					 
	void ChangeScene(eScene NextScene) override;

};