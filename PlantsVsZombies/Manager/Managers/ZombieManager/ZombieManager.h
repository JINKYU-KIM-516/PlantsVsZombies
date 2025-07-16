#pragma once
#include <vector>
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/IntervalTimer/IntervalTimer.h"
#include "../../../GameObject/Zombie/BaseZombie.h"
#include "../../../GameObject/Zombie/Zombie/Zombie.h"
#include "../../../GameObject/Zombie/FunnelZombie/FunnelZombie.h"

class ZombieManager : public BaseManager
{
protected:
    MainGame* m_mainGame;

    IntervalTimer m_spawnTimer;
    vector<BaseZombie*> m_zombies;

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
    void AddZombie(BaseZombie* p_zombie);
    void DeleteZombie(BaseZombie* p_zombie);
    const vector<BaseZombie*>& GetZombies() const;
};