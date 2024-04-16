#include "../Number/Number.h"

void Number::Init(int type,int Xsize,int Ysize) {
	LoadDivGraph(NumberPath[type], 10, 10, 1, Xsize, Ysize, handle);
}

void Number::SetPos(int num1, int num2) {
	numberX = num1;
	numberY = num2;
}

void Number::DrawFont(int number, int Xsize) {

	Digit_1 = number % 10;//ˆêŒ…–Ú


	Digit_2 = number / 10 % 10;//“ñŒ…–Ú
	Digit_3 = number / 100;	   //ŽOŒ…–Ú

	DrawGraph(numberX, numberY, handle[Digit_1], true);

	DrawGraph(numberX - Xsize, numberY, handle[Digit_2], true);

	if (Digit_3 != 0) {
		DrawGraph(numberX - Xsize * 2, numberY, handle[Digit_3], true);
	}
}

void Number::Fin() {
	for (int i = 0; i < 10; i++) {
		DeleteGraph(handle[i]);
	}
}
