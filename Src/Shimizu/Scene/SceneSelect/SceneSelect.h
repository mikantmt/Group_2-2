#pragma once
#include "../../Scene/Scene.h"
#include "../../ShootDown/ShootDown.h"
#include "../../Number/Number.h"

const int  Lebel_Max_Num = 3;

class Select {
private:
	int LevelHandle[Lebel_Max_Num];	//��Փx�摜
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