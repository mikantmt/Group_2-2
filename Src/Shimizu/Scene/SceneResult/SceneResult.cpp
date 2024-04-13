#include "../../Scene/SceneResult/SceneResult.h"

void Result::Init() {
	Handle = LoadGraph("../Data/ResultScene/Good.png");
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");
	NextHandle = LoadGraph("../Data/PlayScene/Finish/Next.png");

	Scene::Init();
	PlaySoundMem(GameBGM, DX_PLAYTYPE_LOOP);
	number.Init(1, 64, 128);

	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

void Result::Step() {

	number.SetPos(SCREEN_SIZE_X - 320, SCREEN_SIZE_Y / 2 + 48);

	if (CountPoint > 999) {
		CountPoint = 999;
	}

	if (collision.IsClickOnRect(SCREEN_SIZE_X - 150, SCREEN_SIZE_Y - 150, 150, 150)) {
		PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

void Result::Draw() {
	DrawGraph(0, 0, Handle, true);

	DrawGraph(SCREEN_SIZE_X - 150, SCREEN_SIZE_Y - 150, NextHandle, true);

	number.DrawFont(CountPoint, 64);

	GetMousePoint(&MouseX, &MouseY);//マウスポイントの座標取得
	//エイミングの画像
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

void Result::Fin()
{
	DeleteGraph(Handle);
	DeleteGraph(AimHandle);
	DeleteGraph(NextHandle);

	DeleteSoundMem(GameBGM);

	number.Fin();
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}
