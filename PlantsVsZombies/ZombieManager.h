#pragma once
#include <vector>
#include "Zombie.h"
#include "IntervalTimer.h"

class ZombieManager
{
protected:
    IntervalTimer m_spawnTimer{ INTERVAL_SEC_SPAWN_ZOMBIE };
    vector<Zombie*> m_zombies;

    void SpawnZombie(Point p_pos);
    void SpawnZombieRandomRow();
    void CheckZombiesAlive();
public:
    ~ZombieManager();
    void Update();

    void AddZombie(Zombie* p_zombie);
    void DeleteZombie(Zombie* p_zombie);
    const vector<Zombie*>& GetZombies() const;
};