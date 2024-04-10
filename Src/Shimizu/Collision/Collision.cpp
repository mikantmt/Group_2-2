#include "Collision.h"

void Collision::Init() {

}


bool Collision::IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh) {
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// 当たっているときの処理
		return true;
	}
	
	return false;
}


bool Collision::IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2){
	//２つの半径の合計
	int sum_radius = r1 + r2;
	sum_radius *= sum_radius;

	//円同士の長さ
	int x_len = x1 - x2;
	x_len *= x_len;

	int y_len = y1 - y2;
	y_len *= y_len;

	//円の当たり判定
	if (sum_radius > x_len + y_len)
	{
		return true;
	}

	return false;
}

bool Collision::RectToMousePointa(float X,float Y,float W,float H) {
	int x = 0;
	int y = 0;

	GetMousePoint(&x, &y);

	if (X + W >= x && X <= x
		&& Y + H >= y && Y <= y) {
		return true;
	}
	else
		return false;
}