#include "../../Scene/SceneResult/SceneResult.h"

void Result::Init() {
	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

void Result::Step() {

	if (collision.IsClickOnRect(0, 0, 100, 100)) {
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

void Result::Draw() {
	DrawBox(0, 0, 100, 100, GetColor(255, 0, 0), true);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 0, 0), "���U���g");
}

void Result::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}
