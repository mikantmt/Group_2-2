#include "ShootDown.h"
 
void ShootDown::Init() {
	MiniGameBase::Init();
	SetMousePoint(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2);
	Startlimit = 210.0f;//�J�n�܂�3�b+START�\���̗P�\(0.5�b)
	CountPoint = 0;
	time = 600.0f;	//10�b
	IsHit = false;
	RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
	RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
	AimHandle = LoadGraph("../Data/PlayScene/Aiming.png");
	Limit = 0.0f;

	MarkHandle[0] = LoadGraph("../Data/PlayScene/target/good2.png");
	MarkHandle[1] = LoadGraph("../Data/PlayScene/target/danger3.png");

	FinHandle = LoadGraph("../Data/PlayScene/Finish/Finish.png");
	NextHandle = LoadGraph("../Data/PlayScene/Finish/Next.png");

	//�Q�[�����[�h�ɂ���ĕ\������I�̎�ނ�ς���
	if (GameMode != 2) {//�ł��Ă����I����
		MarkType = 2;
	}
	else if (GameMode == 2) {//�ł��Ă͂����Ȃ��I������
		MarkType = ScopingRand(1, 5);
	}

	MouseX = 0;
	MouseY = 0;
}

void ShootDown::Play() {

	Startlimit--;//�X�^�[�g�܂ł̃J�E���g�_�E��

	if (Startlimit <= 0) {
		if (GameMode != 3) {//�Q�[�����[�h3�͐������ԂȂ�
			time--;		//�������Ԃ̃J�E���g�_�E�����J�n
		}
		Limit++;	//���~�b�g�̃J�E���g�J�n
		if (!IsFin) {
			if (MarkType != 1) {
				if (collision.IsClickOnRect(RectX,RectY, Height,Width)) {//�w��̃L�[��������邽�тɃJ�E���g���v���X
					IsHit = true;
					CountPoint++;
				}
			}
			else
				if (collision.IsClickOnRect(RectX, RectY, Height, Width)) {//�ł����Ⴂ���Ȃ��I�̏���
					IsHit = true;
					CountPoint--;
				}
		}
	}

	//�������Ă��� && ���~�b�g���Ԃ��߂��Ă���
	if (IsHit || Limit > LimitChange) {
		//�^�[�Q�b�g�̍��W�X�V
		RectX = ScopingRand(0, SCREEN_SIZE_X - Width);
		RectY = ScopingRand(0, SCREEN_SIZE_Y - Height);
		//�I�̎�ލX�V
		if (GameMode != 2) {
			MarkType = 2;
		}
		else if (GameMode == 2) {
			MarkType = ScopingRand(1, 5);
		}

		//�����蔻��̃��Z�b�g
		IsHit = false;

		//���~�b�g�̃��Z�b�g
		Limit = 0.0f;
	}


	if (time <= 0.0f) {//�^�C���I�[�o�[�ŏI��
		//�Q�[���̏I��
		IsFin = true;
	}

	if (GameMode == 3) {//�Q�[�����[�h3�͎��s������I��
		if (Limit >= LimitChange) {
			IsFin = true;
		}
	}

	if (IsFin) {
		if (collision.IsClickOnRect(SCREEN_SIZE_X - 150, SCREEN_SIZE_Y - 150, 150, 150)) {
			g_CurrentSceneId = SCENE_ID_FIN_PLAY;
		}
	}
}

void ShootDown::Draw() {
	CountDown(Startlimit);//�J�E���g�_�E���\��

	GetMousePoint(&MouseX, &MouseY);//�}�E�X�|�C���g�̍��W�擾

	if (Startlimit <= 0 && time >= 0.0f) {
		//�^�[�Q�b�g�\��
		if (!IsFin) {
			if (MarkType != 1) {
				DrawGraph(RectX, RectY, MarkHandle[0], true);
			}
			else
				DrawGraph(RectX, RectY, MarkHandle[1], true);
		}
	}

	if (IsFin) {
		DrawGraph(SCREEN_SIZE_X / 2 - 150, SCREEN_SIZE_Y / 2 - 150, FinHandle, true);
		DrawGraph(SCREEN_SIZE_X - 150, SCREEN_SIZE_Y - 150, NextHandle, true);
	}

	/*DrawFormatString(0, 200, GetColor(0, 0, 0), "%d", GameMode);*/

	//�G�C�~���O�̉摜
	DrawRotaGraph(MouseX, MouseY, 1.0f, 0.0f, AimHandle, true);
}

void ShootDown::Fin() {
	DeleteGraph(AimHandle);
	DeleteGraph(FinHandle);
	DeleteGraph(NextHandle);

	MiniGameBase::Fin();
	for (int i = 0; i < TargetMax; i++) {
		DeleteGraph(MarkHandle[i]);
	}
}

