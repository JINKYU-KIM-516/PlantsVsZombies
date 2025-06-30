#include "CollisionManager.h"

//protected
void CollisionManager::CheckColliding_BulletAndZombie()
{
    // Bullet vs Zombie
    for (auto* bullet : m_bulletManager->GetBullets())
    {
        for (auto* zombie : m_zombieManager->GetZombies())
        {
            if (bullet->IsCollided(zombie))
            {
                zombie->TakeDamage(bullet->GetAttackPower());
                m_bulletManager->DeleteBullet(bullet);
            }
        }
    }
}

void CollisionManager::CheckColliding_ZombieAndPlant()
{
    // Zombie vs Plant
    for (auto* zombie : m_zombieManager->GetZombies())
    {
        for (auto* plant : m_plantManager->GetPlants())
        {
            if (zombie->IsCollided(plant))
            {
                plant->TakeDamage(zombie->GetAttackPower());
            }
        }
    }
}

//public
CollisionManager::CollisionManager()
{
    m_plantManager = nullptr;
    m_zombieManager = nullptr;
    m_bulletManager = nullptr;
}

void CollisionManager::Init(PlantManager* p_plantManager, ZombieManager* p_zombieManager, BulletManager* p_bulletManager)
{
    m_plantManager = p_plantManager;
    m_zombieManager = p_zombieManager;
    m_bulletManager = p_bulletManager;
}

void CollisionManager::Update()
{
    CheckColliding_BulletAndZombie();
    CheckColliding_ZombieAndPlant();
}