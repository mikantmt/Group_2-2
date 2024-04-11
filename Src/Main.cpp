//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include "../Src/Common.h"
#include "../Src/Shimizu/Scene/SceneTitle/SceneTitle.h"
#include "../Src/Shimizu/Scene/SceneSelect/SceneSelect.h"
#include "../Src/Shimizu/Scene/ScenePlay/ScenePlay.h"
#include "../Src/Shimizu/Scene/SceneResult/SceneResult.h"

#include "../Src/Shimizu/Input/Input.h"
#include "../Src/Shimizu/ShootDown/ShootDown.h"

SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

int GameMode = 0;
int LimitChange = 60;


// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(false);

	//ウィンドウの背景色を設定
	SetBackgroundColor(255, 255, 255);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	SetMouseDispFlag(true);

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く
	//クラスの宣言
	Title	title;
	Select  select;
	Play	play;
	Result	result;
	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//エスケープキーが押されたら終了
			break;
		}
		SetMouseDispFlag(false);

		//画面に表示されたものを初期化
		ClearDrawScreen();

		StepInput();

		switch (g_CurrentSceneId)
		{

		case SCENE_ID_INIT_TITLE:

			title.InitTitle();

			break;
		case SCENE_ID_LOOP_TITLE:

			title.StepTitle();
			title.DrawTitle();

			break;
		case SCENE_ID_FIN_TITLE:

			title.FinTitle();

			break;

		case SCENE_ID_INIT_SELECT:

			select.Init();

			break;
		case SCENE_ID_LOOP_SELECT:

			select.Step();
			select.Draw();

			break;
		case SCENE_ID_FIN_SELECT:

			select.Fin();

			break;

		case SCENE_ID_INIT_PLAY:

			play.Init();

			break;
		case SCENE_ID_LOOP_PLAY:

			play.Step();
			play.Draw();

			break;
		case SCENE_ID_FIN_PLAY:

			play.Fin();

			break;
		case SCENE_ID_INIT_RESULT:

			result.Init();

			break;
		case SCENE_ID_LOOP_RESULT:

			result.Step();
			result.Draw();

			break;
		case SCENE_ID_FIN_RESULT:

			result.Fin();

			break;
		default:
			break;
		}

		//-----------------------------------------
		//ここからゲームの本体を書くことになる
		//-----------------------------------------


		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

