#include "../../Scene/SceneResult/SceneResult.h"

void Result::Init() {
	Handle = LoadGraph("../Data/ResultScene/Good.png");
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");
	NextHandle = LoadGraph("../Data/PlayScene/Finish/Next.png");
	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

void Result::Step() {

	if (collision.IsClickOnRect(SCREEN_SIZE_X - 150, SCREEN_SIZE_Y - 150, 150, 150)) {
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

void Result::Draw() {
	DrawGraph(0, 0, Handle, true);

	DrawGraph(SCREEN_SIZE_X - 150, SCREEN_SIZE_Y - 150, NextHandle, true);

	GetMousePoint(&MouseX, &MouseY);//マウスポイントの座標取得
	//エイミングの画像
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

void Result::Fin()
{
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}
