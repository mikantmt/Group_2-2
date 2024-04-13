#pragma once
#include "../../Scene/Scene.h"

class Title{
private:
	int Handle;			//背景画像
	int Click;			//クリックしてね画像
	int	AimHandle;		//エイムの画像ハンドル
	int MouseX, MouseY; //マウスの座標
public:
	Collision collision;

	//PressEnter透過変数
	int m_BlendAlpha = 255;
	bool m_blendfrag = false;


	// タイトル初期化
	void InitTitle();

	// タイトル通常処理
	void StepTitle();

	// タイトル描画処理
	void DrawTitle();

	// タイトル終了処理
	void FinTitle();
};

