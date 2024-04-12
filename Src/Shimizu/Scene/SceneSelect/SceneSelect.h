#pragma once
#include "../../Scene/Scene.h"
#include "../../ShootDown/ShootDown.h"
#include "../../Number/Number.h"

class Select {
private:
	int	AimHandle;		//エイムの画像ハンドル
	int	MouseX, MouseY; //マウスの座標

	int ArrowHandle[2];	//矢印のハンドル

public:
	Collision collision;
	Number	  number;

	void Init();
	void Step();
	void Draw();
	void Fin();
};