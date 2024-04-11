#pragma once
#include "../../Scene/Scene.h"
#include "../../ShootDown/ShootDown.h"

class Select {
private:
	int	  AimHandle;	//エイムの画像ハンドル
	int MouseX, MouseY; //マウスの座標

public:
	Collision collision;

	void Init();
	void Step();
	void Draw();
	void Fin();
};