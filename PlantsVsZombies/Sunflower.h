#pragma once
#include "Plant.h"
#include "Constants.h"


class Sunflower : public Plant
{
private:
	int m_hp;
public:
	Sunflower(Point p_pos);
};