#include "../../Scene/SceneSelect/SceneSelect.h"

void Select::Init() {
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");

	ArrowHandle[0] = LoadGraph("../Data/SelectScene/LeftArrow.png");
	ArrowHandle[1] = LoadGraph("../Data/SelectScene/RightArrow.png");

	number.Init();

	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_SELECT;
}

void Select::Step() {

	if (collision.IsClickOnRect(0, 0, 100, 100)) {
		g_CurrentSceneId = SCENE_ID_FIN_SELECT;
		GameMode = 1;
	}

	if (collision.IsClickOnRect(100, 0, 100, 100)) {
		g_CurrentSceneId = SCENE_ID_FIN_SELECT;
		GameMode = 2;
	}

	if (collision.IsClickOnRect(200, 0, 100, 100)) {
		g_CurrentSceneId = SCENE_ID_FIN_SELECT;
		GameMode = 3;
	}


	//出現速度変更
	if (collision.IsClickOnRect(SCREEN_SIZE_X - 132, SCREEN_SIZE_Y - 64, 32, 64)) {
		LimitChange -= 5;
	}
	if (collision.IsClickOnRect(SCREEN_SIZE_X - 32, SCREEN_SIZE_Y - 64, 32, 64)) {
		LimitChange += 5;
	}
	if (LimitChange < 0) {
		LimitChange = 0;
	}

	if (number.Digit_3 == 0) {//二桁の時の座標と
		number.SetPos(SCREEN_SIZE_X - 64, SCREEN_SIZE_Y - 48);
	}
	else					  //三桁の時の座標と
		number.SetPos(SCREEN_SIZE_X - 56, SCREEN_SIZE_Y - 48);
}

void Select::Draw() {
	DrawBox(0, 0, 100, 100, GetColor(255, 0, 0), true);

	DrawBox(100, 0, 200, 100, GetColor(0, 255, 0), true);

	DrawBox(200, 0, 300, 100, GetColor(0, 0, 255), true);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 0, 0), "Select");


	DrawGraph(SCREEN_SIZE_X - 132, SCREEN_SIZE_Y - 64, ArrowHandle[0], true);
	DrawGraph(SCREEN_SIZE_X - 32, SCREEN_SIZE_Y - 64, ArrowHandle[1], true);

	number.DrawFont(LimitChange);

	GetMousePoint(&MouseX, &MouseY);//マウスポイントの座標取得
	//エイミングの画像
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

void Select::Fin()
{
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}