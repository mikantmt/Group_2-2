//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
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


// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(false);

	//�E�B���h�E�̔w�i�F��ݒ�
	SetBackgroundColor(255, 255, 255);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	SetMouseDispFlag(true);

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	//�N���X�̐錾
	Title	title;
	Select  select;
	Play	play;
	Result	result;
	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}
		SetMouseDispFlag(false);

		//��ʂɕ\�����ꂽ���̂�������
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
		//��������Q�[���̖{�̂��������ƂɂȂ�
		//-----------------------------------------


		//-----------------------------------------
		//���[�v�̏I����
		//�t���b�v�֐�
		ScreenFlip();

	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

