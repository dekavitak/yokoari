#include "DxLib.h"
#include "SceneTask.h"

/***************************************
�֐��� : SceneTssk()
�T�v   : �R���X�g���N�^
����   : ISceneChanger * changer
�߂�l : �Ȃ�
���l   : �󂯎�����������玟�̃V�[���𔻒f����
***************************************/
SceneTask::SceneTask(ISceneChanger* changer) : m_sceneHandle(0)
{
	m_sceneChanger = changer;
}

/***************************************
�֐��� : Finalize()
�T�v   : �I������
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �V�[���̉摜�I�u�W�F�N�g��j������
***************************************/
void SceneTask::Finalize()
{
	DeleteGraph(m_sceneHandle);
}

/***************************************
�֐��� : Draw()
�T�v   : �`�揈��
����   : �Ȃ�
�߂�l : �Ȃ�
���l   : �V�[���̉摜��\������
***************************************/
void SceneTask::Draw()
{
	DrawGraph(0, 0, m_sceneHandle, FALSE);
}