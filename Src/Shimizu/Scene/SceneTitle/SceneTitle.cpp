#include "SceneTitle.h"


// �^�C�g��������
void Title::InitTitle()
{
	Handle = LoadGraph("../Data/TitleScene/AIMLAB.png");
	Click = LoadGraph("../Data/TitleScene/Clicksta.png");
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");
	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
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


	if (collision.IsClickOnRect(0,0, SCREEN_SIZE_X, SCREEN_SIZE_Y)){//�͈͓��ŃN���b�N������
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void Title::DrawTitle()
{
	DrawGraph(0, 0, Handle, true);

	DrawGraph(SCREEN_SIZE_X / 2 - 150, SCREEN_SIZE_Y - 300, Click, true);

	GetMousePoint(&MouseX, &MouseY);//�}�E�X�|�C���g�̍��W�擾
	//�G�C�~���O�̉摜
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

// �^�C�g���I������
void Title::FinTitle()
{
	DeleteGraph(Handle);
	DeleteGraph(Click);
	DeleteGraph(AimHandle);
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}