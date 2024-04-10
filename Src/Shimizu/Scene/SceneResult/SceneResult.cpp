#include "../../Scene/SceneResult/SceneResult.h"

void Result::Init() {


	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

void Result::Step() {


	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

void Result::Draw() {
	DrawFormatString(0, 0, GetColor(255, 0, 0), "リザルト");
}

void Result::Fin()
{
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}
