#include "MiniGameBase.h"

void MiniGameBase::Init() {
	IsFin = false;
	IsClear = false;
	GamePoint = 0;
}

void MiniGameBase::Play() {
	
}

void MiniGameBase::Draw() {

}

void MiniGameBase::Fin() {

}

void MiniGameBase::CountDown(float limit) {
	//3,2,1のカウントダウン
	if (limit <= LimitTime && limit > LimitTime - _1Frame) {							//3
		DrawFormatString(100, 100, GetColor(0,0,0), "3");
	}
	if (limit <= LimitTime - _1Frame && limit > LimitTime - (_1Frame * 2)) {			//2
		DrawFormatString(100, 100, GetColor(0, 0, 0), "2");
	}
	if (limit <= LimitTime - (_1Frame * 2) && limit > LimitTime - (_1Frame * 3)) {		//1
		DrawFormatString(100, 100, GetColor(0, 0, 0), "1");
	}
	if (limit <= LimitTime - (_1Frame * 3) && limit > 0) {								//start
		DrawFormatString(100, 100, GetColor(0, 0, 0), "start");
	}
}

float MiniGameBase::ScopingRand(float min, float max) {
	float rand;

	rand = GetRand(max);

	if (rand < min) {
		return ScopingRand(min, max);
	}
	else
		return rand;
}

float MiniGameBase::OutRand(float min, float max, float out_min, float out_max) {
	float rand;

	rand = ScopingRand(min, max);

	if (rand > out_min && rand < out_max) {
		return OutRand(min, max,out_min,out_max);
	}
	else
		return rand;

}