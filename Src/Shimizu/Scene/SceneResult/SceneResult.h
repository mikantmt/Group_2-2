#pragma once
#include "../../Scene/Scene.h"

class Result {
private:

public:
	Collision collision;

	void Init();
	void Step();
	void Draw();
	void Fin();
};