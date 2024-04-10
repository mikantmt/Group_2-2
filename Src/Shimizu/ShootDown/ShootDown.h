#pragma once
#include "../MiniGameBase/MiniGameBase.h"

const int TargetMax = 2;

const int Height = 100, Width = 100;

class ShootDown : public MiniGameBase {
private:
	float time;			//制限時間(10秒くらい)
	bool  IsHit;		//当たっているか
	int	  count;		//撃ち落とした回数
	int	  RectX, RectY; //矩形の座標
	int	  handle;		//エイムの画像ハンドル
	float Limit;	    //表示されてからクリックするまでの猶予

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