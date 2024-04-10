#pragma once
#include "../MapChip/Mapchip.h"

#define GAMEOVER_BGM_PASS "Data/BGM/GameOver.mp3"
#define ENTER_SOUND_PATH "Data/BGM/Enter.mp3"


class GameOver {
public:

	int m_BackGroundHandle;
	int m_PressEnter;

	//タイトルBGM
	int m_SoundHundle;
	//選択音
	int m_PushSound;

	//PressEnter透過変数
	int m_BlendAlpha = 255;
	bool m_blendfrag = false;

	// ゲームオーバー初期化
	void InitGameOver();

	// ゲームオーバー通常処理
	void StepGameOver();

	// ゲームオーバー描画処理
	void DrawGameOver();

	// ゲームオーバー終了処理
	void FinGameOver();
};

