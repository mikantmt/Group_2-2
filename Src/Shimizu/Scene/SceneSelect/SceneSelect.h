#pragma once
#include "../../Scene/Scene.h"
#include "../../ShootDown/ShootDown.h"
#include "../../Number/Number.h"

class Select {
private:
	int	AimHandle;		//�G�C���̉摜�n���h��
	int	MouseX, MouseY; //�}�E�X�̍��W

	int ArrowHandle[2];	//���̃n���h��

public:
	Collision collision;
	Number	  number;

	void Init();
	void Step();
	void Draw();
	void Fin();
};