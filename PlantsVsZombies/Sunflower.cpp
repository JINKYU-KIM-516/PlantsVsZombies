#include "Sunflower.h"
#include "SunlightManager.h"

//protected
void Sunflower::SpawnSunlight()
{
    return;
}

//public
Sunflower::Sunflower()
    :Plant(DEFAULT_LOCATION, PLANT_SIZE, IMAGEPATH_SUNFLOWER)
{
    m_sunlightManager = nullptr;
    m_hp = 100;
}

void Sunflower::Init(Point p_pos, SunlightManager* p_sunlightManager)
{
    m_location = p_pos;
    m_sunlightManager = p_sunlightManager;
}

void Sunflower::Update()
{
    CheckAlive();
}