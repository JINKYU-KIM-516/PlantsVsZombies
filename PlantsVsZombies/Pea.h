#pragma once
#include "Plant.h"

class Pea : public Plant
{
protected:
	void SpawnBullet();
public:
	Pea(Point p_pos);
};

