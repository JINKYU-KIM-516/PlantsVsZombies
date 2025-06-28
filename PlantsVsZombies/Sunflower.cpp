#include "Sunflower.h"

void Sunflower::SpawnSunlight()
{
    return;
}

Sunflower::Sunflower(Point p_pos)
    :Plant(p_pos, Size(PLANT_SIZE, PLANT_SIZE), IMAGEPATH_SUNFLOWER)
{
}