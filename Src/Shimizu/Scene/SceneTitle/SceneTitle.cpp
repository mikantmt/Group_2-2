#include "SceneTitle.h"


// タイトル初期化
void Title::InitTitle()
{
	Handle = LoadGraph("../Data/TitleScene/AIMLAB.png");
	Click = LoadGraph("../Data/TitleScene/Clicksta.png");
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");

	Scene::Init();

	PlaySoundMem(GameBGM, DX_PLAYTYPE_LOOP);
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


	if (collision.IsClickOnRect(0,0, SCREEN_SIZE_X, SCREEN_SIZE_Y, MouseX, MouseY)){//範囲内でクリックしたら
		PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void Title::DrawTitle()
{
	DrawGraph(0, 0, Handle, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);
	DrawGraph(SCREEN_SIZE_X / 2 - 150, SCREEN_SIZE_Y - 300, Click, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

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

	DeleteSoundMem(GameBGM);

	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}