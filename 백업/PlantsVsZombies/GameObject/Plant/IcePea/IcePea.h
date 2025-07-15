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
	float m_attackPower;
	float m_attackSpeed;

	void SpawnBullet();
	void SpawnBulletPeriodically();
public:
	IcePea();
	~IcePea();
	void Init(Point p_pos, BulletManager* p_bulletManager);
	void Update() override;
};