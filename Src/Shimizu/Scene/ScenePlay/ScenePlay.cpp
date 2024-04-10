#include "../../Scene/ScenePlay/ScenePlay.h"

ShootDown shootdown;

void Play::Init() {
	shootdown.Init();

	// タイトルのループ処理へ遷移
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
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}
