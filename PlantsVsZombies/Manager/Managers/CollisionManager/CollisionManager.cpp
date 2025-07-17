#include "CollisionManager.h"

//protected
void CollisionManager::CheckColliding_BulletAndZombie()
{
    // Bullet vs Zombie
    for (auto* bullet : BulletManager::GetI()->GetBullets())
    {
        for (auto* zombie : ZombieManager::GetI()->GetZombies())
        {
            if (bullet->IsCollided(zombie))
            {
                zombie->TakeDamage(bullet->GetAttackPower());
                bullet->Active(zombie);
                BulletManager::GetI()->DeleteBullet(bullet);
            }
        }
    }
}

void CollisionManager::CheckColliding_ZombieAndPlant()
{
    // Zombie vs Plant
    for (auto* zombie : ZombieManager::GetI()->GetZombies())
    {
        for (auto* plant : PlantManager::GetI()->GetPlants())
        {
            if (zombie->IsCollided(plant))
            {
                if (!zombie->IsAttacking())
                    zombie->Target(plant);
            }
        }
    }
}

//public
CollisionManager::CollisionManager()
{
    Init();
}

void CollisionManager::Init()
{
    m_plantManager = nullptr;
    m_zombieManager = nullptr;
    m_bulletManager = nullptr;
}

void CollisionManager::Link(PlantManager* p_plantManager, ZombieManager* p_zombieManager, BulletManager* p_bulletManager)
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