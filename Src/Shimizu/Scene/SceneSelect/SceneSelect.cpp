#include "../../Scene/SceneSelect/SceneSelect.h"

void Select::Init() {
	LevelHandle[0] = LoadGraph("../Data/SelectScene/easy.png");
	LevelHandle[1] = LoadGraph("../Data/SelectScene/normal.png");
	LevelHandle[2] = LoadGraph("../Data/SelectScene/endless.png");

	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");

	ArrowHandle[0] = LoadGraph("../Data/SelectScene/LeftArrow.png");
	ArrowHandle[1] = LoadGraph("../Data/SelectScene/RightArrow.png");

	ClickSound2 = LoadSoundMem("../Sound/Click2.mp3");
	Scene::Init();
	PlaySoundMem(GameBGM, DX_PLAYTYPE_LOOP);
	number.Init(0,16,32);

	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_SELECT;
}

void Select::Step() {

	for (int i = 0; i < Lebel_Max_Num; i++) {
		if (collision.IsClickOnRect((300 * i) + 100 * i + 90, SCREEN_SIZE_Y / 2 - 150, 300, 300)) {
			PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
			GameMode = i + 1;
			g_CurrentSceneId = SCENE_ID_FIN_SELECT;
		}
	}

	//出現速度変更
	if (collision.IsClickOnRect(0, SCREEN_SIZE_Y - 64, 32, 64)) {
		PlaySoundMem(ClickSound2, DX_PLAYTYPE_BACK);
		LimitChange -= 5;
	}
	if (collision.IsClickOnRect(96, SCREEN_SIZE_Y - 64, 32, 64)) {
		PlaySoundMem(ClickSound2, DX_PLAYTYPE_BACK);
		LimitChange += 5;
	}
	if (LimitChange < 5) {
		LimitChange = 300;
	}

	if (LimitChange > 300) {
		LimitChange = 5;
	}

	if (number.Digit_3 == 0) {//二桁の時の座標と
		number.SetPos(68, SCREEN_SIZE_Y - 48);
	}
	else					  //三桁の時の座標
		number.SetPos(76, SCREEN_SIZE_Y - 48);
}

void Select::Draw() {
	for (int i = 0; i < Lebel_Max_Num; i++) {
		DrawGraph((300 * i) + 100 * i + 90, SCREEN_SIZE_Y / 2 - 150, LevelHandle[i], true);
	}

	DrawGraph(0, SCREEN_SIZE_Y - 64, ArrowHandle[0], true);
	DrawGraph(96, SCREEN_SIZE_Y - 64, ArrowHandle[1], true);

	number.DrawFont(LimitChange,16);

	GetMousePoint(&MouseX, &MouseY);//マウスポイントの座標取得
	//エイミングの画像
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

void Select::Fin()
{
	DeleteGraph(AimHandle);
	for (int i = 0; i < Lebel_Max_Num; i++) {
		DeleteGraph(LevelHandle[i]);
	}
	for (int i = 0; i < 2; i++) {
		DeleteGraph(ArrowHandle[i]);
	}

	Scene::Fin();
	number.Fin();

	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}