#pragma once
#include "Plant.h"
#include "IntervalTimer.h"
#include "BulletPea.h"
#include "BulletManager.h"

class MainGame;

class Pea : public Plant
{
protected:
	MainGame* m_mainGameLink;

	IntervalTimer m_attackTimer{ INTERVAL_SEC_SPAWN_BULLET_PEA };
	int m_attackPower;

	void SpawnBullet();
public:
	Pea(MainGame* p_mainGameLink, Point p_pos);
	~Pea();
	void Update() override;
};