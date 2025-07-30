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

void CollisionManager::CheckColliding_LawnMowerAndZombie()
{
    // LawnMower vs Zombie
    for (auto* mower : LawnMowerManager::GetI()->GetLawnMowers())
    {
        for (auto* zombie : ZombieManager::GetI()->GetZombies())
        {
            if (mower->IsCollided(zombie))
            {
                mower->StartActiving();
                zombie->TakeDamage(99999);
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

}

void CollisionManager::Update()
{
    CheckColliding_BulletAndZombie();
    CheckColliding_ZombieAndPlant();
    CheckColliding_LawnMowerAndZombie();
}