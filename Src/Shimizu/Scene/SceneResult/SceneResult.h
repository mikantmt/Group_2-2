#pragma once
#include "../../Scene/Scene.h"
#include "../../Number/Number.h"
#include "../../ShootDown/ShootDown.h"

class Result : public Scene {
private:
	int Handle;			//�w�i�摜
	int	AimHandle;		//�G�C���̉摜�n���h��
	int NextHandle;		//���։摜�n���h��
	int MouseX, MouseY; //�}�E�X�̍��W
public:
	Collision collision;
	Number	  number;
	ShootDown shootdown;

	void Init();
	void Step();
	void Draw();
	void Fin();
};