#pragma once
#include <vector>
#include "Zombie.h"
#include "IntervalTimer.h"

class ZombieManager
{
protected:
    IntervalTimer m_spawnTimer;
    vector<Zombie*> m_zombies;

    void SpawnZombie(Point p_pos);
    void SpawnZombieRandom();
    void CheckZombiesAlive();
public:
    ZombieManager();
    ~ZombieManager();
    void Update();

    void AddZombie(Zombie* p_zombie);
    void DeleteZombie(Zombie* p_zombie);
    const vector<Zombie*>& GetZombies() const;
};