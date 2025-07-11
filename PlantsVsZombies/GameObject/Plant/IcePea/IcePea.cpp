#include "IcePea.h"

//protected
void IcePea::SpawnBullet()
{
	BulletPea* bulletPea = new BulletPea(m_positon + Point(PLANT_WIDTH / 2 + BULLET_WIDTH, PLANT_HEIGHT / 2 - BULLET_HEIGHT));
	bulletPea->Init(m_attackPower, MOVESPEED_BULLET_PEA);

	m_bulletManager->AddBullets(bulletPea);
}

void IcePea::SpawnBulletPeriodically()
{
	if (m_attackTimer.HasElapsed())
	{
		SpawnBullet();
		m_attackTimer.Tick();
	}
}


//public
IcePea::IcePea()
	:Plant(DEFAULT_POSITION, PLANT_SIZE, IMAGEPATH_ICEPEA)
{
	m_bulletManager = nullptr;
	m_hp = 150;
	m_attackPower = ATTACKPOWER_PEA;
}

IcePea::~IcePea()
{
}

void IcePea::Init(Point p_pos, BulletManager* p_bulletManager)
{
	m_positon = p_pos;
	m_bulletManager = p_bulletManager;
	m_attackTimer.Init(INTERVAL_SEC_SPAWN_BULLET_PEA);
}

void IcePea::Update()
{
	SpawnBulletPeriodically();
	CheckAlive();
}