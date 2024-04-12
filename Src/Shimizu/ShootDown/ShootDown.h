#pragma once
#include "../GameBase/MiniGameBase.h"
#include "../Collision/Collision.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneSelect/SceneSelect.h"

const int TargetMax = 2;

const int Height = 100, Width = 100;

class ShootDown : public MiniGameBase {
private:
	float time;			//��������(10�b���炢)
	bool  IsHit;		//�������Ă��邩
	int	  count;		//�������Ƃ�����
	int	  RectX, RectY; //��`�̍��W
	int	  AimHandle;	//�G�C���̉摜�n���h��
	int   MarkHandle[TargetMax];	//�I�̉摜�n���h��
	float Limit;	    //�\������Ă���N���b�N����܂ł̗P�\

	int   MarkType;		//�ł��Ă����I�Ƒł��Ă͑ʖڂȓI
	int   BeforeMarkType;

	int	MouseX, MouseY; //�}�E�X�̍��W
public:
	Collision collision;

	void Init();
	void Play();
	void Draw();
	void Fin();

	int  GetPoint(int count);//�|�C���g�擾�֐�
};