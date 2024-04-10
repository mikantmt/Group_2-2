#pragma once
#include "../../Scene/Scene.h"
#include "../../ShootDown/ShootDown.h"

class Select {
private:

public:
	Collision collision;

	void Init();
	void Step();
	void Draw();
	void Fin();
};