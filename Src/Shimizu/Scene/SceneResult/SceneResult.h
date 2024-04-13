#pragma once
#include "../../Scene/Scene.h"
#include "../../Number/Number.h"
#include "../../ShootDown/ShootDown.h"

class Result : public Scene {
private:
	int Handle;			//背景画像
	int	AimHandle;		//エイムの画像ハンドル
	int NextHandle;		//次へ画像ハンドル
	int MouseX, MouseY; //マウスの座標
public:
	Collision collision;
	Number	  number;
	ShootDown shootdown;

	void Init();
	void Step();
	void Draw();
	void Fin();
};