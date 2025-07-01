#include "SunlightManager.h"

//protected
void SunlightManager::SpawnSunlight(Point p_pos, int p_limitY)
{
    Sunlight* sunlight = new Sunlight();
    sunlight->Init(p_pos, p_limitY);
    AddSunlight(sunlight);
}

void SunlightManager::SpawnSunlightRandom()
{
    if (m_spawnSunlightTimer.HasElapsed())
    {
        int x = rand() % ((GAMEBOAORD_WIDTH - 1) * TILE_WIDTH);
        int limitY = rand() % ((GAMEBOAORD_HEIGHT * TILE_HEIGHT) - SUNLIGHT_HEIGHT);
        SpawnSunlight(Point(x, 0), limitY);
        m_spawnSunlightTimer.Tick();
    }
}

//public
SunlightManager::~SunlightManager()
{
    for (auto* sunlight : m_sunlights)
        delete sunlight;
}

void SunlightManager::Init()
{
    m_spawnSunlightTimer.Init(INTERVAL_SEC_SPAWN_SUNLIGHT);
}

void SunlightManager::Update()
{
    SpawnSunlightRandom();
}

void SunlightManager::AddSunlight(Sunlight* p_sunlight)
{
    m_sunlights.push_back(p_sunlight);
}

void SunlightManager::DeleteSunlight(Sunlight* p_sunlight)
{
    m_sunlights.erase(remove(m_sunlights.begin(), m_sunlights.end(), p_sunlight), m_sunlights.end());
    delete p_sunlight;
}

const vector<Sunlight*>& SunlightManager::GetSunlights() const
{
    return m_sunlights;
}