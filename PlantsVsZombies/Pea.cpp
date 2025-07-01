#include "Pea.h"
#include "MainGame.h"

//protected
void Pea::SpawnBullet()
{
	BulletPea* bulletPea = new BulletPea(m_location + Point(PLANT_WIDTH / 2 + BULLET_WIDTH, PLANT_HEIGHT / 2 - BULLET_HEIGHT));
	bulletPea->Init(m_attackPower, MOVESPEED_BULLET_PEA);

	m_bulletManager->AddBullets(bulletPea);
}

void Pea::SpawnBulletPeriodically()
{
	if (m_attackTimer.HasElapsed())
	{
		SpawnBullet();
		m_attackTimer.Tick();
	}
}


//public
Pea::Pea()
	:Plant(DEFAULT_LOCATION, PLANT_SIZE, IMAGEPATH_PEA)
{
	m_bulletManager = nullptr;
	m_hp = 150;
	m_attackPower = ATTACKPOWER_PEA;
}

Pea::~Pea()
{
}

void Pea::Init(Point p_pos, BulletManager* p_bulletManager)
{
	m_location = p_pos;
	m_bulletManager = p_bulletManager;
	m_attackTimer.Init(INTERVAL_SEC_SPAWN_BULLET_PEA);
}

void Pea::Update()
{
	SpawnBulletPeriodically();
	CheckAlive();
}