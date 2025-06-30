#include "SunlightManager.h"

//protected
void SunlightManager::SpawnSunlight(Point p_pos)
{
    Sunlight* sunlight = new Sunlight();
    sunlight->Init(p_pos);
    AddSunlight(sunlight);
}

//public
SunlightManager::~SunlightManager()
{
    for (auto* sunlight : m_sunlights)
        delete sunlight;
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