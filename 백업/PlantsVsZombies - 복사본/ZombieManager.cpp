#include "ZombieManager.h"
#include "MainGame.h"

//protected
void ZombieManager::SpawnZombie(Point p_pos)
{
    Zombie* zombie = new Zombie();
    zombie->Init(p_pos);
    AddZombie(zombie);
}

void ZombieManager::SpawnZombieRandom()
{
    if (m_spawnTimer.HasElapsed())
    {
        int row = rand() % GAMEBOARD_HEIGHT;
        int x = GAMEBOARD_START_X + (TILE_WIDTH * GAMEBOARD_WIDTH);
        int y = GAMEBOARD_START_Y + (TILE_HEIGHT * row);
        SpawnZombie(Point(x, y));
        m_spawnTimer.Tick();
    }
}

void ZombieManager::CheckZombiesAlive()
{
    for (auto* zombie : m_zombies)
        if (!zombie->IsAlive())
            DeleteZombie(zombie);
}

void ZombieManager::CheckZombiesInHome()
{
    if (m_mainGame->IsGameOver())
        return;
    for (auto* zombie : m_zombies)
        if (zombie->GetPos().GetX() <= GAMEBOARD_START_X - TILE_WIDTH)
        {
            m_mainGame->GameOver(L"좀비가 집에 들어와버렸습니다..");
            return;
        }
}

//public
ZombieManager::ZombieManager()
{
    Init();
}

ZombieManager::~ZombieManager()
{
    for (auto* zombie : m_zombies)
        delete zombie;
}

void ZombieManager::Update()
{
    for (auto* zombie : m_zombies)
        zombie->Update();
    SpawnZombieRandom();
    CheckZombiesAlive();
    CheckZombiesInHome();
}

void ZombieManager::Init()
{
    m_spawnTimer.Init(INTERVAL_SEC_SPAWN_ZOMBIE);
}

void ZombieManager::Link(MainGame* p_mainGame)
{
    m_mainGame = p_mainGame;
}

void ZombieManager::Draw(HDC p_hdc)
{
    for (auto* zombie : m_zombies)
        zombie->Draw(p_hdc);
}

void ZombieManager::AddZombie(Zombie* p_zombie)
{
    m_zombies.push_back(p_zombie);
}

void ZombieManager::DeleteZombie(Zombie* p_zombie)
{
    m_zombies.erase(remove(m_zombies.begin(), m_zombies.end(), p_zombie), m_zombies.end());
    delete p_zombie;
}

const vector<Zombie*>& ZombieManager::GetZombies() const
{
    return m_zombies;
}