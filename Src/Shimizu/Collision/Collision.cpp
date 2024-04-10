#include "Collision.h"

void Collision::Init() {

}


bool Collision::IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh) {
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// “–‚½‚Á‚Ä‚¢‚é‚Æ‚«‚Ìˆ—
		return true;
	}
	
	return false;
}


bool Collision::IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2){
	//‚Q‚Â‚Ì”¼Œa‚Ì‡Œv
	int sum_radius = r1 + r2;
	sum_radius *= sum_radius;

	//‰~“¯Žm‚Ì’·‚³
	int x_len = x1 - x2;
	x_len *= x_len;

	int y_len = y1 - y2;
	y_len *= y_len;

	//‰~‚Ì“–‚½‚è”»’è
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