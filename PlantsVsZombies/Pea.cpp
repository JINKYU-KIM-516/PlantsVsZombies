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
Pea::Pea(BulletManager* p_bulletManager, Point p_pos)
	:Plant(p_pos, PLANT_SIZE, IMAGEPATH_PEA), m_bulletManager(p_bulletManager)
{
	m_hp = 150;
	m_attackPower = ATTACKPOWER_PEA;
}

Pea::~Pea()
{
}

void Pea::Update()
{
	SpawnBulletPeriodically();
	CheckAlive();
}