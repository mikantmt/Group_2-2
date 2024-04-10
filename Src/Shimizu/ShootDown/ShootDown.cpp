#include "ShootDown.h"

void ShootDown::Init() {
	Startlimit = 210.0f;//�J�n�܂�3�b+START�\���̗P�\(0.5�b)

	time = 600.0f;	//10�b
	IsHit = false;
	count = 0;
	RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
	RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
	handle = LoadGraph("Data/MiniGame/Aiming.png");
	Limit = 0.0f;

	click_flag = false;
	MouseX = 0;
	MouseY = 0;
}

void ShootDown::Play() {
	Startlimit--;//�X�^�[�g�܂ł̃J�E���g�_�E��

	if (Startlimit <= 0) {//�J�E���g�_�E����0�ȉ��ł����
		time--;		//�������Ԃ̃J�E���g�_�E�����J�n
		Limit++;	//���~�b�g�̃J�E���g�J�n
		if (!IsFin) {
			if (IsClickOnRect()) {//�w��̃L�[��������邽�тɃJ�E���g���v���X
				IsHit = true;
				count++;
			}
		}
	}

	//�������Ă��� && ���~�b�g���Ԃ��߂��Ă���
	if (IsHit || Limit >= 50) {
		//�^�[�Q�b�g�̍��W�X�V
		RectX = ScopingRand(0, 640 - Width);
		RectY = ScopingRand(0, 480 - Height);

		//�����蔻��̃��Z�b�g
		IsHit = false;

		//���~�b�g�̃��Z�b�g
		Limit = 0.0f;
	}


	if (time <= 0.0f) {//�^�C���I�[�o�[�ŏI��
		GamePoint = GetPoint(count);//�|�C���g�̎擾
		//�Q�[���̏I��
		IsFin = true;
	}
}

void ShootDown::Draw() {
	CountDown(Startlimit);//�J�E���g�_�E���\��

	GetMousePoint(&MouseX, &MouseY);//�}�E�X�|�C���g�̍��W�擾

	if (Startlimit <= 0 && time >= 0.0f) {
		//�^�[�Q�b�g�\��
		DrawBox(RectX, RectY, RectX + Width, RectY + Height, GetColor(0,0,0), true);
	}
	//�G�C�~���O�̉摜
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, handle, true);
	//�|�C���g�\��
	DrawFormatString(0, 0, GetColor(0,0,0), "%d", GamePoint);
}

void ShootDown::Fin() {
	/*DeleteGraph();*/
}

int ShootDown::GetPoint(int count) {
	int point = 0;

	if (count >= 20) {
		point = 100;
	}
	if (count < 20 && count >= 15) {
		point = 75;
	}
	if (count < 15 && count >= 10) {
		point = 50;
	}
	if (count < 10 && count >= 5) {
		point = 25;
	}
	if (count < 5 && count >= 1) {
		point = 10;
	}
	if (count <= 0) {
		point = 0;
	}

	return point;
}


bool ShootDown::IsClickOnRect()
{
	//��`�̒��ɂ���
	
	if (RectToMousePointa()) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//������Ă���
			if (click_flag == false)
			{
				//������Â��Ă��Ȃ�
				click_flag = true;
				return true;
			}
			return false;
		}
		else
		{
			//������Ă��Ȃ�
			click_flag = false;
			return false;
		}
	}
	else
		return false;
}

bool ShootDown::RectToMousePointa() {
	int x = 0;
	int y = 0;

	GetMousePoint(&x, &y);
	
	for (int i = 0; i < TargetMax; i++) {
		if (RectX + Width >= x && RectX <= x
			&& RectY + Height >= y && RectY <= y) {
			return true;
		}
		else
			return false;
	}
}

