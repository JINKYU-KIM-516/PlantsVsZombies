#pragma once
#include "Plant.h"

class Sunflower : public Plant
{
protected:
	void SpawnSunlight();
public:
	Sunflower(Point p_pos);
};