#include "SceneTitle.h"

#define TITLE_PRESS_PATH		"Data/TitleImage/PressEnter.png"
#define TITLE_BACKGROUND_PATH	"Data/TitleImage/TitleBackGround.png"

// タイトル初期化
void Title::InitTitle()
{
	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void Title::StepTitle()
{
	if (m_blendfrag){
		m_BlendAlpha+=3;
	}
	else{
		m_BlendAlpha-=3;
	}

	if (m_BlendAlpha < 0){
		m_blendfrag = true;
	}
	if (m_BlendAlpha > 255){
		m_blendfrag = false;
	}


	if (IsKeyPush(KEY_INPUT_RETURN)){
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void Title::DrawTitle()
{
	DrawFormatString(0, 0, GetColor(255, 0, 0), "タイトル");
}

// タイトル終了処理
void Title::FinTitle()
{
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}