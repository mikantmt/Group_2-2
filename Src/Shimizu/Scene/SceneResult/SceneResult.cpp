#include "../../Scene/SceneResult/SceneResult.h"

void Result::Init() {
	Handle = LoadGraph("../Data/ResultScene/Score.png");
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");
	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

void Result::Step() {

	if (collision.IsClickOnRect(SCREEN_SIZE_X - 100, SCREEN_SIZE_Y - 100, 100, 100)) {
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

void Result::Draw() {
	DrawGraph(0, 0, Handle, true);

	DrawBox(SCREEN_SIZE_X - 100, SCREEN_SIZE_Y - 100, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(255, 0, 0), true);

	GetMousePoint(&MouseX, &MouseY);//�}�E�X�|�C���g�̍��W�擾
	//�G�C�~���O�̉摜
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

void Result::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}
