#include "SceneTitle.h"


// タイトル初期化
void Title::InitTitle()
{
	Handle = LoadGraph("../Data/TitleScene/AIMLAB.png");
	Click = LoadGraph("../Data/TitleScene/Clicksta.png");
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");
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


	if (collision.IsClickOnRect(0,0, SCREEN_SIZE_X, SCREEN_SIZE_Y)){//範囲内でクリックしたら
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void Title::DrawTitle()
{
	DrawGraph(0, 0, Handle, true);

	DrawGraph(SCREEN_SIZE_X / 2 - 150, SCREEN_SIZE_Y - 300, Click, true);

	GetMousePoint(&MouseX, &MouseY);//マウスポイントの座標取得
	//エイミングの画像
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

// タイトル終了処理
void Title::FinTitle()
{
	DeleteGraph(Handle);
	DeleteGraph(Click);
	DeleteGraph(AimHandle);
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}