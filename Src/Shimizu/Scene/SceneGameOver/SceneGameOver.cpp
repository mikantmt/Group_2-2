#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

#define PRESS_PATH		"Data/TitleImage/PressEnter.png"
#define GAMEOVER_BACKGROUND_PATH	"Data/GameOverImage/GameOver.png"


// ゲームオーバー初期化
void GameOver::InitGameOver()
{
	// ゲームオーバー画像の読み込み
	m_BackGroundHandle = LoadGraph(GAMEOVER_BACKGROUND_PATH);
	m_PressEnter = LoadGraph(PRESS_PATH);

	// タイトルBGMの読み込み
	m_SoundHundle = LoadSoundMem(GAMEOVER_BGM_PASS);
	// タイトルのBGM
	PlaySoundMem(m_SoundHundle, DX_PLAYTYPE_LOOP, true);

	m_PushSound = LoadSoundMem(ENTER_SOUND_PATH);

	// ゲームオーバーのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_GAMEOVER;
}

// ゲームオーバー通常処理
void GameOver::StepGameOver()
{
	if (m_blendfrag)
	{
		m_BlendAlpha += 3;
	}
	else
	{
		m_BlendAlpha -= 3;
	}


	if (m_BlendAlpha < 0)
	{
		m_blendfrag = true;
	}
	if (m_BlendAlpha > 255)
	{
		m_blendfrag = false;
	}

	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		PlaySoundMem(m_PushSound, DX_PLAYTYPE_NORMAL, true);
		// タイトルシーンに遷移
		g_CurrentSceneId = SCENE_ID_FIN_GAMEOVER;
	}
}

// ゲームオーバー描画処理
void GameOver::DrawGameOver()
{
	DrawGraph(0, 0, m_BackGroundHandle, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);
	DrawRotaGraph(640, 560, 1.0f, 0.0f, m_PressEnter, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// ゲームオーバー終了処理
void GameOver::FinGameOver()
{
	//サウンドを削除
	DeleteSoundMem(m_SoundHundle);
	DeleteSoundMem(m_PushSound);
	NextStageID = WORLD;

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}