#include "../../Scene/SceneSelect/SceneSelect.h"

void Select::Init() {
	LevelHandle[0] = LoadGraph("../Data/SelectScene/easy.png");
	LevelHandle[1] = LoadGraph("../Data/SelectScene/normal.png");
	LevelHandle[2] = LoadGraph("../Data/SelectScene/endless.png");

	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");

	ArrowHandle[0] = LoadGraph("../Data/SelectScene/LeftArrow.png");
	ArrowHandle[1] = LoadGraph("../Data/SelectScene/RightArrow.png");
	ArrowHandle[2] = LoadGraph("../Data/SelectScene/LeftArrow.png");
	ArrowHandle[3] = LoadGraph("../Data/SelectScene/RightArrow.png");
	ArrowHandle[4] = LoadGraph("../Data/SelectScene/LeftArrow1.png");
	ArrowHandle[5] = LoadGraph("../Data/SelectScene/RightArrow1.png");

	ClickSound2 = LoadSoundMem("../Sound/Click2.mp3");
	Scene::Init();
	PlaySoundMem(GameBGM, DX_PLAYTYPE_LOOP);
	number.Init(0,16,32);

	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_SELECT;
}

void Select::Step() {

	for (int i = 0; i < Lebel_Max_Num; i++) {
		if (collision.IsClickOnRect((300 * i) + 100 * i + 90, SCREEN_SIZE_Y / 2 - 150, 300, 300, MouseX, MouseY)) {
			PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
			GameMode = i + 1;
			g_CurrentSceneId = SCENE_ID_FIN_SELECT;
		}
	}

	//出現速度変更
	if (collision.IsClickOnRect(0, SCREEN_SIZE_Y - 128, 32, 64, MouseX, MouseY)) {
		PlaySoundMem(ClickSound2, DX_PLAYTYPE_BACK);
		LimitChange -= 5;
	}
	if (collision.IsClickOnRect(96, SCREEN_SIZE_Y - 128, 32, 64, MouseX, MouseY)) {
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
		number.SetPos(68, SCREEN_SIZE_Y - 116);
	}
	else					  //三桁の時の座標
		number.SetPos(76, SCREEN_SIZE_Y - 116);


	//マウス感度変更
	if (collision.IsClickOnRect(0, SCREEN_SIZE_Y - 64, 32, 64, MouseX, MouseY)) {
		PlaySoundMem(ClickSound2, DX_PLAYTYPE_BACK);
		MouseSens -= 1;
	}
	if (collision.IsClickOnRect(152, SCREEN_SIZE_Y - 64, 32, 64, MouseX, MouseY)) {
		PlaySoundMem(ClickSound2, DX_PLAYTYPE_BACK);
		MouseSens += 1;
	}
	if (collision.IsClickOnRect(60, SCREEN_SIZE_Y - 64, 16, 64, MouseX, MouseY)) {
		PlaySoundMem(ClickSound2, DX_PLAYTYPE_BACK);
		MouseSens -= 0.01;
	}
	if (collision.IsClickOnRect(116, SCREEN_SIZE_Y - 64, 16, 64, MouseX, MouseY)) {
		PlaySoundMem(ClickSound2, DX_PLAYTYPE_BACK);
		MouseSens += 0.01;
	}

	if (MouseSens < 0.01f) {
		MouseSens = 0.01f;
	}
}

void Select::Draw() {
	for (int i = 0; i < Lebel_Max_Num; i++) {
		DrawGraph((300 * i) + 100 * i + 90, SCREEN_SIZE_Y / 2 - 150, LevelHandle[i], true);
	}
	//出現速度変更
	DrawGraph(0, SCREEN_SIZE_Y - 128, ArrowHandle[0], true);
	DrawGraph(96, SCREEN_SIZE_Y - 128, ArrowHandle[1], true);

	//マウス感度変更
	DrawGraph(0, SCREEN_SIZE_Y - 64, ArrowHandle[2], true);
	DrawGraph(152, SCREEN_SIZE_Y - 64, ArrowHandle[3], true);
	DrawGraph(60, SCREEN_SIZE_Y - 64, ArrowHandle[4], true);
	DrawGraph(116, SCREEN_SIZE_Y - 64, ArrowHandle[5], true);

	number.DrawFont(LimitChange, 16);

	DrawFormatString(76, SCREEN_SIZE_Y - 36, GetColor(0, 0, 0), "%.2f", MouseSens);

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
	for (int i = 0; i < Arrow_Max_Num; i++) {
		DeleteGraph(ArrowHandle[i]);
	}

	Scene::Fin();
	number.Fin();

	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}