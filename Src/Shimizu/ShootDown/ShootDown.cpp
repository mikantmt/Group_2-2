#include "ShootDown.h"

void ShootDown::Init() {
	Startlimit = 210.0f;//�J�n�܂�3�b+START�\���̗P�\(0.5�b)

	time = 600.0f;	//10�b
	IsHit = false;
	count = 0;
	RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
	RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
	AimHandle = LoadGraph("Data/PlayScene/Aiming.png");
	Limit = 0.0f;
	GamePoint = 0;

	IsFin = false;

	MarkHandle[0] = LoadGraph("Data/PlayScene/target/good.png");
	MarkHandle[1] = LoadGraph("Data/PlayScene/target/danger.png");

	//�Q�[�����[�h�ɂ���ĕ\������I�̎�ނ�ς���
	if (GameMode == 1) {//�ł��Ă����I����
		MarkType = ScopingRand(2, 5);
	}
	else if (GameMode != 1) {//�ł��Ă͂����Ȃ��I������
		MarkType = ScopingRand(1, 5);
	}

	MouseX = 0;
	MouseY = 0;
}

void ShootDown::Play() {
	Startlimit--;//�X�^�[�g�܂ł̃J�E���g�_�E��

	if (Startlimit <= 0) {//�J�E���g�_�E����0�ȉ��ł����]
		if (GameMode != 3) {
			time--;		//�������Ԃ̃J�E���g�_�E�����J�n
		}
		Limit++;	//���~�b�g�̃J�E���g�J�n
		if (!IsFin) {
			if (MarkType != 1) {
				if (collision.IsClickOnRect(RectX,RectY, Height,Width)) {//�w��̃L�[��������邽�тɃJ�E���g���v���X
					IsHit = true;
					count++;
				}
			}
			else
				if (collision.IsClickOnRect(RectX, RectY, Height, Width)) {//�ł����Ⴂ���Ȃ��I�̏���
					IsHit = true;
					count--;
				}
		}
	}

	//�������Ă��� && ���~�b�g���Ԃ��߂��Ă���
	if (IsHit || Limit >= 50) {
		//�^�[�Q�b�g�̍��W�X�V
		RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
		RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
		//�I�̎�ލX�V
		if (GameMode == 1) {
			MarkType = ScopingRand(2, 5);
		}
		else if (GameMode == 2) {
			MarkType = ScopingRand(1, 5);
		}

		//�����蔻��̃��Z�b�g
		IsHit = false;

		//���~�b�g�̃��Z�b�g
		if (GameMode != 3) {
			Limit = 0.0f;
		}
	}


	if (time <= 0.0f) {//�^�C���I�[�o�[�ŏI��
		GamePoint = GetPoint(count);//�|�C���g�̎擾
		//�Q�[���̏I��
		IsFin = true;
	}

	if (GameMode == 3) {//�Q�[�����[�h3�͎��s������I��
		if (Limit >= 50) {
			IsFin = true;
		}
	}

	if (IsFin) {
		if (collision.IsClickOnRect(0, 0, 100, 100)) {
			g_CurrentSceneId = SCENE_ID_FIN_PLAY;
		}
	}
}

void ShootDown::Draw() {
	CountDown(Startlimit);//�J�E���g�_�E���\��

	GetMousePoint(&MouseX, &MouseY);//�}�E�X�|�C���g�̍��W�擾

	if (Startlimit <= 0 && time >= 0.0f) {
		//�^�[�Q�b�g�\��
		if (MarkType != 1) {
			DrawGraph(RectX, RectY, MarkHandle[0], true);
		}
		else
			DrawGraph(RectX, RectY, MarkHandle[1], true);
	}
	//�G�C�~���O�̉摜
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
	//�|�C���g�\��
	DrawFormatString(0, 0, GetColor(0,0,0), "%d", GamePoint);
	DrawFormatString(0, 16, GetColor(0, 0, 0), "%d", count);

	if (IsFin) {
		DrawBox(0, 0, 100, 100, GetColor(255, 0, 0), true);
	}

	DrawFormatString(0, 200, GetColor(0, 0, 0), "%d", GameMode);
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

