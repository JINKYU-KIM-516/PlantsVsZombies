#pragma once
#include "../Plant.h"
#include "../../../CoreFunction/IntervalTimer/IntervalTimer.h"
#include "../../Bullet/IcePeaBullet/IcePeaBullet.h"
#include "../../../Manager/Managers/BulletManager/BulletManager.h"

class IcePea : public Plant
{
protected:
	BulletManager* m_bulletManager;

	IntervalTimer m_attackTimer;
	int m_attackPower;
	int m_attackSpeed;

	void SpawnBullet();
	void SpawnBulletPeriodically();
public:
	IcePea();
	~IcePea();
	void Init(Point p_pos);
	void Init(Point p_pos, BulletManager* p_bulletManager);
	void Update() override;
};