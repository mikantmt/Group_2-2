#pragma once
#include "../../Scene/Scene.h"

class Result {
private:
	int Handle;			//�w�i�摜
	int	AimHandle;		//�G�C���̉摜�n���h��
	int MouseX, MouseY; //�}�E�X�̍��W
public:
	Collision collision;

	void Init();
	void Step();
	void Draw();
	void Fin();
};