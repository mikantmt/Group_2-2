#pragma once
#include "../GameBase/MiniGameBase.h"
#include "../Collision/Collision.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneSelect/SceneSelect.h"

const int TargetMax = 2;

const int Height = 100, Width = 100;

class ShootDown : public MiniGameBase {
private:
	float time;			//制限時間(10秒くらい)
	bool  IsHit;		//当たっているか
	int	  RectX, RectY; //矩形の座標
	int	  AimHandle;	//エイムの画像ハンドル
	int   MarkHandle[TargetMax];	//的の画像ハンドル
	int	  FinHandle;	//終了画像ハンドル
	int   NextHandle;	//次へ画像ハンドル
	float Limit;	    //表示されてからクリックするまでの猶予

	int   MarkType;		//打っていい的と打っては駄目な的
	int   BeforeMarkType;

	int ClickSound;
	int MissSound;
	int TrueSound;
	int PlayBGM;

	int	MouseX, MouseY; //マウスの座標

	int NextMouseX, NextMouseY;

	int diffX, diffY;
public:
	Collision collision;
	Scene scene;

	void Init();
	void Play();
	void Draw();
	void Fin();
};