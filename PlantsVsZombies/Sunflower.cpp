#include "Sunflower.h"

Sunflower::Sunflower(Point p_pos)
    :PictureBox(p_pos, Size(PLANT_SIZE, PLANT_SIZE), IMAGEPATH_SUNFLOWER)
{
	m_hp = 100;
}


void Sunflower::Init()
{

}