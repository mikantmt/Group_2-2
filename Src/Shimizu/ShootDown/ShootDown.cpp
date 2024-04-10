#include "ShootDown.h"

void ShootDown::Init() {
	Startlimit = 210.0f;//開始まで3秒+START表示の猶予(0.5秒)

	time = 600.0f;	//10秒
	IsHit = false;
	count = 0;
	RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
	RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");
	Limit = 0.0f;

	MarkHandle[0] = LoadGraph("../Data/PlayScene/target/good.png");
	MarkHandle[1] = LoadGraph("../Data/PlayScene/target/danger.png");

	MarkType = ScopingRand(1, 5);

	click_flag = false;
	MouseX = 0;
	MouseY = 0;
}

void ShootDown::Play() {
	Startlimit--;//スタートまでのカウントダウン

	if (Startlimit <= 0) {//カウントダウンが0以下であれば
		time--;		//制限時間のカウントダウンを開始
		Limit++;	//リミットのカウント開始
		if (!IsFin) {
			if (MarkType != 1) {
				if (IsClickOnRect()) {//指定のキーが押されるたびにカウントをプラス
					IsHit = true;
					count++;
				}
			}
			else
				if (IsClickOnRect()) {//打っちゃいけない的の処理
					IsHit = true;
					count--;
				}
		}
	}

	//当たっている && リミット時間が過ぎている
	if (IsHit || Limit >= 50) {
		//ターゲットの座標更新
		RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
		RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
		//的の種類更新
		MarkType = ScopingRand(1, 5);

		//当たり判定のリセット
		IsHit = false;

		//リミットのリセット
		Limit = 0.0f;
	}


	if (time <= 0.0f) {//タイムオーバーで終了
		GamePoint = GetPoint(count);//ポイントの取得
		//ゲームの終了
		IsFin = true;
	}
}

void ShootDown::Draw() {
	CountDown(Startlimit);//カウントダウン表示

	GetMousePoint(&MouseX, &MouseY);//マウスポイントの座標取得

	if (Startlimit <= 0 && time >= 0.0f) {
		//ターゲット表示
		if (MarkType != 1) {
			DrawGraph(RectX, RectY, MarkHandle[0], true);
		}
		else
			DrawGraph(RectX, RectY, MarkHandle[1], true);
	}
	//エイミングの画像
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
	//ポイント表示
	DrawFormatString(0, 0, GetColor(0,0,0), "%d", GamePoint);
	DrawFormatString(0, 16, GetColor(0, 0, 0), "%d", count);
}

void ShootDown::Fin() {
	/*DeleteGraph();*/
}

int ShootDown::GetPoint(int count) {
	int point = 0;

	if (count >= 20) {
		point = 100;
	}
	if (count < 20 && count >= 15) {
		point = 75;
	}
	if (count < 15 && count >= 10) {
		point = 50;
	}
	if (count < 10 && count >= 5) {
		point = 25;
	}
	if (count < 5 && count >= 1) {
		point = 10;
	}
	if (count <= 0) {
		point = 0;
	}

	return point;
}


bool ShootDown::IsClickOnRect()
{
	//矩形の中にある
	
	if (RectToMousePointa()) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//押されている
			if (click_flag == false)
			{
				//押されつづけていない
				click_flag = true;
				return true;
			}
			return false;
		}
		else
		{
			//押されていない
			click_flag = false;
			return false;
		}
	}
	else
		return false;
}

bool ShootDown::RectToMousePointa() {
	int x = 0;
	int y = 0;

	GetMousePoint(&x, &y);
	
	if (RectX + Width >= x && RectX <= x
		&& RectY + Height >= y && RectY <= y) {
		return true;
	}
	else
		return false;
}

