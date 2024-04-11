#pragma once
#include "../../Scene/Scene.h"

class Result {
private:
	int Handle;			//背景画像
	int	AimHandle;		//エイムの画像ハンドル
	int MouseX, MouseY; //マウスの座標
public:
	Collision collision;

	void Init();
	void Step();
	void Draw();
	void Fin();
};