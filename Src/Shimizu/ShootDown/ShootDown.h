#pragma once
#include "../GameBase/MiniGameBase.h"

const int TargetMax = 2;

const int Height = 100, Width = 100;

class ShootDown : public MiniGameBase {
private:
	float time;			//制限時間(10秒くらい)
	bool  IsHit;		//当たっているか
	int	  count;		//撃ち落とした回数
	int	  RectX, RectY; //矩形の座標
	int	  AimHandle;	//エイムの画像ハンドル
	int   MarkHandle[TargetMax];	//的の画像ハンドル
	float Limit;	    //表示されてからクリックするまでの猶予

	int   MarkType;		//打っていい的と打っては駄目な的

	bool  click_flag;	//クリックしたかフラグ(初期値はfalse)
	int MouseX, MouseY; //マウスの座標
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	int  GetPoint(int count);//ポイント取得関数
	bool IsClickOnRect();
	bool RectToMousePointa();
};