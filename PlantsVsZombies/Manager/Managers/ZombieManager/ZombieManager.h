#pragma once
#include <vector>
#include "../../BaseManager/BaseManager.h"
#include "../../../GameObject/Zombie/Zombie.h"
#include "../../../CoreFunction/IntervalTimer/IntervalTimer.h"

class ZombieManager : public BaseManager
{
protected:
    MainGame* m_mainGame;

    IntervalTimer m_spawnTimer;
    vector<Zombie*> m_zombies;

    void SpawnZombieRandom();
    void CheckZombiesAlive();
    void CheckZombiesInHome();
public:
    ZombieManager();
    ~ZombieManager();
    void Update() override;
    void Init() override;
    void Link(MainGame* p_mainGame);
    void Draw(HDC p_hdc) override;

    void SpawnZombie(Point p_pos);
    void AddZombie(Zombie* p_zombie);
    void DeleteZombie(Zombie* p_zombie);
    const vector<Zombie*>& GetZombies() const;
};