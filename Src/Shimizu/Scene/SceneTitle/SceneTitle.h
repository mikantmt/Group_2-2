#pragma once
#include "../../Scene/Scene.h"

class Title{
public:

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

