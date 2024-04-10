#include "DxLib.h"

#ifndef __COLLISION_H__
#define __COLLISION_H__

class Collision {
private:

public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	//��`�Ƃ̓����蔻��
	bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);

	//�~�Ƃ̓����蔻��
	bool IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2);

	//��`�ƃ}�E�X�|�C���^�̓����蔻��
	//����(X���W,Y���W,��,����)
	bool RectToMousePointa(float X, float Y, float W, float H);
};

#endif
