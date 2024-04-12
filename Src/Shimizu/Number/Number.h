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

	void Init();

	void SetPos(int num1, int num2);

	void DrawFont(int number);
};