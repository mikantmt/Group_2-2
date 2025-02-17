#include "Collision.h"

void Collision::Init() {
	click_flag = false;
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

bool Collision::IsHitBox(VECTOR Obj1, VECTOR Size1, VECTOR Obj2, VECTOR Size2) {
	if (Obj2.x < Obj1.x + Size1.x &&
		Obj2.x + Size2.x > Obj1.x &&
		Obj2.y + Size2.y > Obj1.y &&
		Obj2.y < Obj1.y + Size1.y &&
		Obj2.z < Obj1.z + Size1.z &&
		Obj2.z + Size2.z > Obj1.z)
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

//IsHitCircleの定義
bool Collision::IsHitSphere(VECTOR Obj1, float radius1, VECTOR Obj2, float radius2)
{
	//２つの半径の合計
	int sum_radius = radius1 + radius2;
	sum_radius *= sum_radius;

	//球同士の長さ
	int x_len = Obj1.x - Obj2.x;
	x_len *= x_len;

	int y_len = Obj1.y - Obj2.y;
	y_len *= y_len;

	int z_len = Obj1.z - Obj2.z;
	z_len *= z_len;

	//球の当たり判定
	if (sum_radius > x_len + y_len + z_len)
	{
		return true;
	}

	return false;
}

bool Collision::RectToMousePointa(float X,float Y,float W,float H, int mouseX, int mouseY) {

	if (X + W >= mouseX && X <= mouseX
		&& Y + H >= mouseY && Y <= mouseY) {
		return true;
	}
	else
		return false;
}

bool Collision::IsClickOnRect(float X, float Y, float W, float H, int mouseX, int mouseY)
{
	//矩形の中にある

	if (RectToMousePointa(X,Y,W,H, mouseX, mouseY)) {
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