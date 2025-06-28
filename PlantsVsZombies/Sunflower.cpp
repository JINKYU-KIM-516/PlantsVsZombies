#include "Sunflower.h"

Sunflower::Sunflower(Point p_pos)
    :Plant(p_pos, Size(PLANT_SIZE, PLANT_SIZE), IMAGEPATH_SUNFLOWER)
{
	m_hp = 100;
}