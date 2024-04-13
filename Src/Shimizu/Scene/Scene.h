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
	// �^�C�g���V�[����ID
	SCENE_ID_INIT_TITLE = 100,	// ������
	SCENE_ID_LOOP_TITLE,		// ���[�v
	SCENE_ID_FIN_TITLE,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_SELECT = 200,	// ������
	SCENE_ID_LOOP_SELECT,			// ���[�v
	SCENE_ID_FIN_SELECT,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_PLAY = 300,	// ������
	SCENE_ID_LOOP_PLAY,			// ���[�v
	SCENE_ID_FIN_PLAY,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_RESULT = 400,	// ������
	SCENE_ID_LOOP_RESULT,		// ���[�v
	SCENE_ID_FIN_RESULT,		// �I��
};

//�@���݂̃V�[��ID
extern SCENE_ID g_CurrentSceneId;

//�Q�[�����[�h�ύX�p
extern int GameMode;
//�I�̏o���^�C���ύX�p
extern int LimitChange;
//���_�ۑ��p
extern int CountPoint;