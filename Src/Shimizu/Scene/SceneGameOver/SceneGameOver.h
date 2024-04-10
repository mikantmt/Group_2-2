#pragma once
#include "../MapChip/Mapchip.h"

#define GAMEOVER_BGM_PASS "Data/BGM/GameOver.mp3"
#define ENTER_SOUND_PATH "Data/BGM/Enter.mp3"


class GameOver {
public:

	int m_BackGroundHandle;
	int m_PressEnter;

	//�^�C�g��BGM
	int m_SoundHundle;
	//�I����
	int m_PushSound;

	//PressEnter���ߕϐ�
	int m_BlendAlpha = 255;
	bool m_blendfrag = false;

	// �Q�[���I�[�o�[������
	void InitGameOver();

	// �Q�[���I�[�o�[�ʏ폈��
	void StepGameOver();

	// �Q�[���I�[�o�[�`�揈��
	void DrawGameOver();

	// �Q�[���I�[�o�[�I������
	void FinGameOver();
};

