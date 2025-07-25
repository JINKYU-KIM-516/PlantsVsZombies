#include "ZombieManager.h"
#include "../../../Main/MainGame.h"

//protected
void ZombieManager::SpawnZombieRandom()
{
    if (m_spawnTimer.HasElapsed())
    {
        int row = rand() % GAMEBOARD_HEIGHT;
        int x = GAMEBOARD_START_X + (TILE_WIDTH * GAMEBOARD_WIDTH);
        int y = GAMEBOARD_START_Y + (TILE_HEIGHT * row);
        if (m_spawnCount == 1)
        {
            SpawnZombie(Point(x, y));
            m_spawnCount--;
        }
        else if (m_spawnCount == 0)
        {
            SpawnFunnelZombie(Point(x, y));
            m_spawnCount++;
        }
        else
        {
            SpawnZombie(Point(x, y));
            m_spawnCount = 1;
        }
            
        
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

void ZombieManager::Init()
{
    m_spawnCount = 1;
    m_spawnTimer.Init(INTERVAL_SPAWN_ZOMBIE);
}

void ZombieManager::Update()
{
    for (auto* zombie : m_zombies)
        zombie->Update();
    SpawnZombieRandom();
    CheckZombiesAlive();
    CheckZombiesInHome();
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

void ZombieManager::SpawnZombie(Point p_pos)
{
    Zombie* zombie = new Zombie();
    zombie->Init(p_pos);
    AddZombie(zombie);
}

void ZombieManager::SpawnFunnelZombie(Point p_pos)
{
    FunnelZombie* zombie = new FunnelZombie();
    zombie->Init(p_pos);
    AddZombie(zombie);
}

void ZombieManager::SpawnPoleZombie(Point p_pos)
{
    PoleZombie* zombie = new PoleZombie();
    zombie->Init(p_pos);
    AddZombie(zombie);
}

void ZombieManager::AddZombie(BaseZombie* p_zombie)
{
    m_zombies.push_back(p_zombie);
}

void ZombieManager::DeleteZombie(BaseZombie* p_zombie)
{
    m_zombies.erase(remove(m_zombies.begin(), m_zombies.end(), p_zombie), m_zombies.end());
    delete p_zombie;
}

const vector<BaseZombie*>& ZombieManager::GetZombies() const
{
    return m_zombies;
}