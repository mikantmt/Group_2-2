#include "../../Scene/SceneSelect/SceneSelect.h"

void Select::Init() {


	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_SELECT;
}

void Select::Step() {


	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneId = SCENE_ID_FIN_SELECT;
	}
}

void Select::Draw() {
	DrawFormatString(0, 0, GetColor(255, 0, 0), "Select");
}

void Select::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}