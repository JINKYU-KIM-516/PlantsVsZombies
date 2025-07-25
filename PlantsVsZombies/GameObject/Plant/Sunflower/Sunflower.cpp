#include "Sunflower.h"
#include "../../../Manager/Managers/SunlightManager/SunlightManager.h"

//protected
void Sunflower::SpawnSunlight()
{
    if (m_spawnSunlightTimer.HasElapsed())
    {
        int x = m_position.GetX() + (rand() % (PLANT_WIDTH - SUNLIGHT_WIDTH));
        int y = m_position.GetY();
        int limitY = m_position.GetY() + (PLANT_HEIGHT - SUNLIGHT_HEIGHT);
        Sunlight* sunlight = new Sunlight();
        sunlight->Init(Point(x, y), limitY);
        SunlightManager::GetI()->AddSunlight(sunlight);
        m_spawnSunlightTimer.Tick();
    }
}

//public
Sunflower::Sunflower()
    :Plant(DEFAULT_POSITION, PLANT_SIZE, SUNFLOWER_IMAGEPATH)
{
    m_sunlightManager = nullptr;
    m_hp = SUNFLOWER_HEALTHPOINT;
    m_spawnSunlightTimer.Init(INTERVAL_SPAWN_SUNLIGHT_BY_SUNFLOWER);
}

void Sunflower::Init(Point p_pos)
{
    m_position = p_pos;
}

void Sunflower::Init(Point p_pos, SunlightManager* p_sunlightManager)
{
    m_position = p_pos;
    m_sunlightManager = p_sunlightManager;
}

void Sunflower::Update()
{
    CheckAlive();
    SpawnSunlight();
}