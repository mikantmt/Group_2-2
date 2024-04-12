#include "../Number/Number.h"

void Number::Init() {
	LoadDivGraph("../Data/Number/number16x32_07.png", 10, 10, 1, 16, 32, handle);
}

void Number::SetPos(int num1, int num2) {
	numberX = num1;
	numberY = num2;
}

void Number::DrawFont(int number) {

	Digit_1 = number % 10;//ˆêŒ…–Ú


	Digit_2 = number / 10 % 10;//“ñŒ…–Ú
	Digit_3 = number / 100;	   //OŒ…–Ú
	
	DrawGraph(numberX, numberY, handle[Digit_1], true);
	
	DrawGraph(numberX - 16, numberY, handle[Digit_2], true);

	if (Digit_3 != 0) {
		DrawGraph(numberX - 32, numberY, handle[Digit_3], true);
	}
}
	
