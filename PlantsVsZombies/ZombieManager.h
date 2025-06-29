#pragma once
#include <vector>
#include "Zombie.h"
#include "IntervalTimer.h"

class ZombieManager
{
private:
    IntervalTimer m_spawnTimer{ INTERVAL_SEC_SPAWN_ZOMBIE };
    vector<Zombie*> m_zombies;

public:
    ~ZombieManager();
    void Update();

    void SpawnZombieRandomRow();
    void SpawnZombie(Point p_pos);
    void AddZobies(Zombie* p_zombie);
    const vector<Zombie*>& GetZombies() const;
};