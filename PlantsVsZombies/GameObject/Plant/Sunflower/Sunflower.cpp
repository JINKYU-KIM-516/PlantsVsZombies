#include "Sunflower.h"
#include "../../../Manager/Managers/SunlightManager/SunlightManager.h"

//protected
void Sunflower::SpawnSunlight()
{
    if (m_spawnSunlightTimer.HasElapsed())
    {
        int x = m_positon.GetX() + (rand() % (PLANT_WIDTH - SUNLIGHT_WIDTH));
        int y = m_positon.GetY();
        int limitY = m_positon.GetY() + (PLANT_HEIGHT - SUNLIGHT_HEIGHT);
        Sunlight* sunlight = new Sunlight();
        sunlight->Init(Point(x, y), limitY);
        m_sunlightManager->AddSunlight(sunlight);
        m_spawnSunlightTimer.Tick();
    }
}

//public
Sunflower::Sunflower()
    :Plant(DEFAULT_POSITION, PLANT_SIZE, IMAGEPATH_SUNFLOWER)
{
    m_sunlightManager = nullptr;
    m_hp = 100;
    m_spawnSunlightTimer.Init(INTERVAL_SEC_SPAWN_SUNLIGHT);
}

void Sunflower::Init(Point p_pos, SunlightManager* p_sunlightManager)
{
    m_positon = p_pos;
    m_sunlightManager = p_sunlightManager;
}

void Sunflower::Update()
{
    CheckAlive();
    SpawnSunlight();
}