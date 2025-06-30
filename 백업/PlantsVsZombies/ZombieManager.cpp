#include "ZombieManager.h"

ZombieManager::~ZombieManager()
{
    for (auto* z : m_zombies)
        delete z;
}

void ZombieManager::Update()
{
    if (m_spawnTimer.HasElapsed())
    {
        SpawnZombieRandomRow();
        m_spawnTimer.Tick();
    }
}

void ZombieManager::SpawnZombieRandomRow()
{
    int row = rand() % 5;
    int x = TILE_WIDTH * GAMEBOAORD_WIDTH; // 예: 오른쪽 끝 위치
    int y = TILE_HEIGHT * row;
    SpawnZombie(Point(x, y));
}


void ZombieManager::SpawnZombie(Point p_pos)
{
    Zombie* zombie = new Zombie(p_pos);
    AddZobies(zombie);
}

void ZombieManager::AddZobies(Zombie* p_zombie)
{
    m_zombies.push_back(p_zombie);
}

const vector<Zombie*>& ZombieManager::GetZombies() const
{
    return m_zombies;
}
