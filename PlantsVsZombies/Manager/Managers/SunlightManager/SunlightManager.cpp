#include "SunlightManager.h"
#include "../../../Main/MainGame.h"

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
        int x = GAMEBOARD_START_X + (rand() % ((GAMEBOARD_WIDTH - 1) * TILE_WIDTH));
        int y = GAMEBOARD_START_Y;
        int limitY = GAMEBOARD_START_Y + (rand() % ((GAMEBOARD_HEIGHT * TILE_HEIGHT) - SUNLIGHT_HEIGHT));
        SpawnSunlight(Point(x, y), limitY);
        m_spawnSunlightTimer.Tick();
    }
}

void SunlightManager::ClickSunlight()
{
    auto pos = m_mainGame->GetMousePosition();
    for (auto itr = m_sunlights.rbegin(); itr != m_sunlights.rend(); ++itr)
    {
        Sunlight* sunlight = *itr;
        if (sunlight->Contains(pos))
        {
            Player::GetI()->SetSunlight(Player::GetI()->GetSunlight() + 50);
            DeleteSunlight(sunlight);
            return;
        }
    }
}

//public
SunlightManager::SunlightManager()
{
    Init();
}

SunlightManager::~SunlightManager()
{
    for (auto* sunlight : m_sunlights)
        delete sunlight;
}

void SunlightManager::Init()
{
    m_mainGame = nullptr;
    m_spawnSunlightTimer.Init(INTERVAL_SPAWN_SUNLIGHT_BY_NATURAL);
}

void SunlightManager::Link(MainGame* p_mainGame)
{
    m_mainGame = p_mainGame;
}

void SunlightManager::Update()
{
    for (auto* sunlight : m_sunlights)
        sunlight->Update();
    SpawnSunlightRandom();
}

void SunlightManager::ClickHandle()
{
    ClickSunlight();
}

void SunlightManager::Draw(HDC p_hdc)
{
    for (auto* sunlight : m_sunlights)
        sunlight->Draw(p_hdc);
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