#pragma once
#include "DxLib.h"

class Number {
private:
	int   handle[10];
	float numberX, numberY;
	
public:
	int Digit_1 = -1;
	int Digit_2 = -1;
	int Digit_3 = -1;

	void Init(int type, int Xsize, int Ysize);

	void SetPos(int num1, int num2);

	void DrawFont(int number, int Xsize);

	void Fin();
};

enum NumberType {
	NO_IMAGE = 0,

	Normal,
	Big,

	NumberTypeNum,
};

const char NumberPath[NumberTypeNum][256]{
	"../Data/Number/number16x32_07.png",
	"../Data/Number/number.png",
};