#include "ZombieManager.h"

//protected
void ZombieManager::SpawnZombie(Point p_pos)
{
    Zombie* zombie = new Zombie();
    zombie->Init(p_pos);
    AddZombie(zombie);
}

void ZombieManager::SpawnZombieRandomRow()
{
    if (m_spawnTimer.HasElapsed())
    {
        int row = rand() % GAMEBOAORD_HEIGHT;
        int x = TILE_WIDTH * GAMEBOAORD_WIDTH; // 예: 오른쪽 끝 위치
        int y = TILE_HEIGHT * row;
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

ZombieManager::ZombieManager()
{
    m_spawnTimer.Init(INTERVAL_SEC_SPAWN_ZOMBIE);
}

//public
ZombieManager::~ZombieManager()
{
    for (auto* zombie : m_zombies)
        delete zombie;
}

void ZombieManager::Update()
{
    SpawnZombieRandomRow();
    CheckZombiesAlive();
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
