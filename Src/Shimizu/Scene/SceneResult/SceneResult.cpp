#include "../../Scene/SceneResult/SceneResult.h"

void Result::Init() {


	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

void Result::Step() {


	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

void Result::Draw() {
	DrawFormatString(0, 0, GetColor(255, 0, 0), "���U���g");
}

void Result::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}
