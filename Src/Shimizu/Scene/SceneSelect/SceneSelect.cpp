#include "../../Scene/SceneSelect/SceneSelect.h"

void Select::Init() {


	// タイトルのループ処理へ遷移
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
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}