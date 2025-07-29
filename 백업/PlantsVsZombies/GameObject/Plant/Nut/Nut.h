#pragma once
#include "../Plant.h"

class Nut : public Plant
{
protected:
	void CheckHp();
public:
	Nut();
	void Init(Point p_pos);
	void Update();
};