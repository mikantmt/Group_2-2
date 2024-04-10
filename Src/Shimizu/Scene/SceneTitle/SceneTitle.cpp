#include "SceneTitle.h"


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


	if (collision.IsClickOnRect(0,0,100,100)){//�͈͓��ŃN���b�N������
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void Title::DrawTitle()
{
	DrawBox(0, 0, 100, 100, GetColor(255, 0, 0), true);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 0, 0), "�^�C�g��");
}

// �^�C�g���I������
void Title::FinTitle()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_SELECT;
}