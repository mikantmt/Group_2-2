#pragma once
#include "../../Scene/Scene.h"
#include "../../ShootDown/ShootDown.h"
#include "../../Number/Number.h"

const int  Lebel_Max_Num = 3;

class Select {
private:
	int LevelHandle[Lebel_Max_Num];	//難易度画像
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