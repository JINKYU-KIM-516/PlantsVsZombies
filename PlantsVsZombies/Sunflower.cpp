#include "Sunflower.h"

void Sunflower::SpawnSunlight()
{
    return;
}

Sunflower::Sunflower(Point p_pos)
    :Plant(p_pos, PLANT_SIZE, IMAGEPATH_SUNFLOWER)
{
    m_hp = 100;
}