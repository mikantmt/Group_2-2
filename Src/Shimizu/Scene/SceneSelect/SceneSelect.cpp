#include "../../Scene/SceneSelect/SceneSelect.h"

void Select::Init() {


	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_SELECT;
}

void Select::Step() {


	if (collision.IsClickOnRect(0, 0, 100, 100)) {
		g_CurrentSceneId = SCENE_ID_FIN_SELECT;
	}
}

void Select::Draw() {
	DrawBox(0, 0, 100, 100, GetColor(255, 0, 0), true);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 0, 0), "Select");
}

void Select::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}