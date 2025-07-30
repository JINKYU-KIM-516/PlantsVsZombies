#pragma once
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../PlantManager/PlantManager.h"
#include "../ZombieManager/ZombieManager.h"
#include "../BulletManager/BulletManager.h"

class CollisionManager : public BaseManager, public SingletonT<CollisionManager>
{
protected:
	void CheckColliding_BulletAndZombie();
	void CheckColliding_ZombieAndPlant();

public:
	CollisionManager();
	void Init() override;
	void Update() override;
};