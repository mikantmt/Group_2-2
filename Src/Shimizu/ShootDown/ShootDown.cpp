#include "ShootDown.h"
 
void ShootDown::Init() {
	MiniGameBase::Init();
	SetMousePoint(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2);
	Startlimit = 210.0f;//開始まで3秒+START表示の猶予(0.5秒)
	CountPoint = 0;
	time = 600.0f;	//10秒
	IsHit = false;
	RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
	RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");
	Limit = 0.0f;

	MarkHandle[0] = LoadGraph("../Data/PlayScene/target/good2.png");
	MarkHandle[1] = LoadGraph("../Data/PlayScene/target/danger3.png");

	FinHandle = LoadGraph("../Data/PlayScene/Finish/Finish.png");
	NextHandle = LoadGraph("../Data/PlayScene/Finish/Next.png");

	//ゲームモードによって表示する的の種類を変える
	if (GameMode != 2) {//打っていい的だけ
		MarkType = 2;
	}
	else if (GameMode == 2) {//打ってはいけない的もある
		MarkType = ScopingRand(1, 5);
	}

	MouseX = 0;
	MouseY = 0;
}

void ShootDown::Play() {

	Startlimit--;//スタートまでのカウントダウン

	if (Startlimit <= 0) {
		if (GameMode != 3) {//ゲームモード3は制限時間なし
			time--;		//制限時間のカウントダウンを開始
		}
		Limit++;	//リミットのカウント開始
		if (!IsFin) {
			if (MarkType != 1) {
				if (collision.IsClickOnRect(RectX,RectY, Height,Width)) {//指定のキーが押されるたびにカウントをプラス
					IsHit = true;
					CountPoint++;
				}
			}
			else
				if (collision.IsClickOnRect(RectX, RectY, Height, Width)) {//打っちゃいけない的の処理
					IsHit = true;
					CountPoint--;
				}
		}
	}

	//当たっている && リミット時間が過ぎている
	if (IsHit || Limit > LimitChange) {
		//ターゲットの座標更新
		RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
		RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
		//的の種類更新
		if (GameMode != 2) {
			MarkType = 2;
		}
		else if (GameMode == 2) {
			MarkType = ScopingRand(1, 5);
		}

		//当たり判定のリセット
		IsHit = false;

		//リミットのリセット
		Limit = 0.0f;
	}


	if (time <= 0.0f) {//タイムオーバーで終了
		//ゲームの終了
		IsFin = true;
	}

	if (GameMode == 3) {//ゲームモード3は失敗したら終了
		if (Limit >= LimitChange) {
			IsFin = true;
		}
	}

	if (IsFin) {
		if (collision.IsClickOnRect(SCREEN_SIZE_X - 150, SCREEN_SIZE_Y - 150, 150, 150)) {
			g_CurrentSceneId = SCENE_ID_FIN_PLAY;
		}
	}
}

void ShootDown::Draw() {
	CountDown(Startlimit);//カウントダウン表示

	GetMousePoint(&MouseX, &MouseY);//マウスポイントの座標取得

	if (Startlimit <= 0 && time >= 0.0f) {
		//ターゲット表示
		if (!IsFin) {
			if (MarkType != 1) {
				DrawGraph(RectX, RectY, MarkHandle[0], true);
			}
			else
				DrawGraph(RectX, RectY, MarkHandle[1], true);
		}
	}

	if (IsFin) {
		DrawGraph(SCREEN_SIZE_X / 2 - 150, SCREEN_SIZE_Y / 2 - 150, FinHandle, true);
		DrawGraph(SCREEN_SIZE_X - 150, SCREEN_SIZE_Y - 150, NextHandle, true);
	}

	/*DrawFormatString(0, 200, GetColor(0, 0, 0), "%d", GameMode);*/

	//エイミングの画像
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

void ShootDown::Fin() {
	DeleteGraph(AimHandle);
	DeleteGraph(FinHandle);
	DeleteGraph(NextHandle);

	MiniGameBase::Fin();
	for (int i = 0; i < TargetMax; i++) {
		DeleteGraph(MarkHandle[i]);
	}
}

