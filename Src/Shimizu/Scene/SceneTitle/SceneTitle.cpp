#include "SceneTitle.h"

#define TITLE_PRESS_PATH		"Data/TitleImage/PressEnter.png"
#define TITLE_BACKGROUND_PATH	"Data/TitleImage/TitleBackGround.png"

// �^�C�g��������
void Title::InitTitle()
{
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


	if (IsKeyPush(KEY_INPUT_RETURN)){
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void Title::DrawTitle()
{
	DrawFormatString(0, 0, GetColor(255, 0, 0), "�^�C�g��");
}

// �^�C�g���I������
void Title::FinTitle()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}