#pragma once
#include <vector>
#include "Zombie.h"
#include <chrono>

class ZombieManager
{
private:
    vector<Zombie*> m_zombies;
    chrono::steady_clock::time_point m_lastSpawnTime;

public:
    void Update();
    void Draw(HDC hdc);
    void Init();  // �ʱ�ȭ��
    const std::vector<Zombie*>& GetZombies() const;
    ~ZombieManager();
};
