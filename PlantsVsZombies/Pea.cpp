#include "Pea.h"

void Pea::SpawnBullet()
{
	return;
}

Pea::Pea(Point p_pos)
	:Plant(p_pos, Size(PLANT_SIZE, PLANT_SIZE), IMAGEPATH_PEA)
{
	m_hp = 150;
}
