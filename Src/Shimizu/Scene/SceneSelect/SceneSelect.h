#pragma once
#include "../../Scene/Scene.h"
#include "../../ShootDown/ShootDown.h"

class Select {
private:
	int	  AimHandle;	//�G�C���̉摜�n���h��
	int MouseX, MouseY; //�}�E�X�̍��W

public:
	Collision collision;

	void Init();
	void Step();
	void Draw();
	void Fin();
};