#include "DxLib.h"

#ifndef __COLLISION_H__
#define __COLLISION_H__

class Collision {
private:

public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	//矩形との当たり判定
	bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);

	//円との当たり判定
	bool IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2);

	//矩形とマウスポインタの当たり判定
	//引数(X座標,Y座標,幅,高さ)
	bool RectToMousePointa(float X, float Y, float W, float H);
};

#endif
