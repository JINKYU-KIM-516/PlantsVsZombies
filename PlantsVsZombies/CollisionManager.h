#pragma once
#include "PlantManager.h"
#include "ZombieManager.h"
#include "BulletManager.h"

class CollisionManager
{
protected:
	PlantManager* m_plantManager;
	ZombieManager* m_zombieManager;
	BulletManager* m_bulletManager;

	void CheckColliding_BulletAndZombie();
	void CheckColliding_ZombieAndPlant();

public:
	CollisionManager();
	void Init();
	void Link(PlantManager* p_plantManager, ZombieManager* p_zombieManager, BulletManager* p_bulletManager);
	void Update();
};