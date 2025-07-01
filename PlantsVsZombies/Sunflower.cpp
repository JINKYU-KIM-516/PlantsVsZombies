#include "Sunflower.h"
#include "SunlightManager.h"

//protected
void Sunflower::SpawnSunlight()
{
    if (m_spawnSunlightTimer.HasElapsed())
    {
        int x = m_location.GetX() + (rand() % (PLANT_WIDTH - SUNLIGHT_WIDTH));
        int y = m_location.GetY();
        int limitY = m_location.GetY() + (PLANT_HEIGHT - SUNLIGHT_HEIGHT);
        Sunlight* sunlight = new Sunlight();
        sunlight->Init(Point(x, y), limitY);
        m_sunlightManager->AddSunlight(sunlight);
        m_spawnSunlightTimer.Tick();
    }
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
    m_spawnSunlightTimer.Init(INTERVAL_SEC_SPAWN_SUNLIGHT);
}

void Sunflower::Update()
{
    CheckAlive();
    SpawnSunlight();
}