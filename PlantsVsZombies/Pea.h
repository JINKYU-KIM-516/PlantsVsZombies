#pragma once
#include "Plant.h"
#include "IntervalTimer.h"
#include "BulletPea.h"
#include "BulletManager.h"

class Pea : public Plant
{
protected:
	BulletManager* m_bulletManager;

	IntervalTimer m_attackTimer{ INTERVAL_SEC_SPAWN_BULLET_PEA };
	int m_attackPower;

	void SpawnBullet();
	void SpawnBulletPeriodically();
public:
	Pea(BulletManager* p_bulletManager, Point p_pos);
	~Pea();
	void Update() override;
};