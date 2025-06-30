#include "Sunflower.h"
#include "SunlightManager.h"

//protected
void Sunflower::SpawnSunlight()
{
    return;
}

//public
Sunflower::Sunflower(Point p_pos)
    :Plant(p_pos, PLANT_SIZE, IMAGEPATH_SUNFLOWER)
{
    m_hp = 100;
}