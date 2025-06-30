#pragma once
#include "Player.h"
#include "ZombieManager.h"
#include "BulletManager.h"

class CollisionManager
{
protected:
	Player* m_player;
	ZombieManager* m_zombieManager;
	BulletManager* m_bulletManager;

	void CheckColliding_BulletAndZombie();
	void CheckColliding_ZombieAndPlant();

public:
	CollisionManager(Player* player, ZombieManager* zombieManager, BulletManager* bulletManager);
	void Update();
};