#pragma once
#include "../../Scene/Scene.h"

class Title{
private:
	int Handle;			//�w�i�摜
	int Click;			//�N���b�N���Ăˉ摜
	int	AimHandle;		//�G�C���̉摜�n���h��
	int MouseX, MouseY; //�}�E�X�̍��W
public:
	Collision collision;

	//PressEnter���ߕϐ�
	int m_BlendAlpha = 255;
	bool m_blendfrag = false;


	// �^�C�g��������
	void InitTitle();

	// �^�C�g���ʏ폈��
	void StepTitle();

	// �^�C�g���`�揈��
	void DrawTitle();

	// �^�C�g���I������
	void FinTitle();
};

