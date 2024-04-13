#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Collision/Collision.h"

class Scene {
	public:
		int ClickSound;
		int GameBGM;

		void Init() {
			ClickSound = LoadSoundMem("../Sound/Click.mp3");
			GameBGM = LoadSoundMem("../Sound/GameBGM.mp3");
		}

		void Fin() {
			DeleteSoundMem(GameBGM);
		}
};

enum SCENE_ID
{
	// タイトルシーンのID
	SCENE_ID_INIT_TITLE = 100,	// 初期化
	SCENE_ID_LOOP_TITLE,		// ループ
	SCENE_ID_FIN_TITLE,			// 終了

	// シーンの情報
	SCENE_ID_INIT_SELECT = 200,	// 初期化
	SCENE_ID_LOOP_SELECT,			// ループ
	SCENE_ID_FIN_SELECT,			// 終了

	// シーンの情報
	SCENE_ID_INIT_PLAY = 300,	// 初期化
	SCENE_ID_LOOP_PLAY,			// ループ
	SCENE_ID_FIN_PLAY,			// 終了

	// シーンの情報
	SCENE_ID_INIT_RESULT = 400,	// 初期化
	SCENE_ID_LOOP_RESULT,		// ループ
	SCENE_ID_FIN_RESULT,		// 終了
};

//　現在のシーンID
extern SCENE_ID g_CurrentSceneId;

//ゲームモード変更用
extern int GameMode;
//的の出現タイム変更用
extern int LimitChange;
//得点保存用
extern int CountPoint;