#include "Shovel.h"
Shovel::Shovel()
	:PictureBox(DEFAULT_POSITION, PLANT_SIZE, SHOVEL_IMAGEPATH)
{
	Init(DEFAULT_POSITION);
}

void Shovel::Init(Point p_pos)
{
	m_position = p_pos;
}

void Shovel::Update(Point p_pos)
{
	m_position = p_pos;
}
