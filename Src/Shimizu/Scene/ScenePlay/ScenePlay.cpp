#include "../../Scene/ScenePlay/ScenePlay.h"

ShootDown shootdown;

void Play::Init() {
	shootdown.Init();

	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

void Play::Step() {
	shootdown.Play();
}

void Play::Draw() {
	shootdown.Draw();
}

void Play::Fin()
{
	shootdown.Fin();
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}
