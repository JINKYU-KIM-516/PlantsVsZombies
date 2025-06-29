#include "Pea.h"
#include "MainGame.h"

void Pea::SpawnBullet()
{
	BulletPea* bulletPea = new BulletPea(m_location + Point(PLANT_WIDTH / 2, PLANT_HEIGHT / 2) - Point(BULLET_WIDTH, BULLET_HEIGHT));
	bulletPea->Init(m_attackPower, MOVESPEED_BULLET_PEA);

	m_mainGameLink->GetBulletManager()->AddBullets(bulletPea);
}

Pea::Pea(MainGame* p_mainGameLink, Point p_pos)
	:Plant(p_pos, PLANT_SIZE, IMAGEPATH_PEA), m_mainGameLink(p_mainGameLink)
{
	m_hp = 150;
	m_attackPower = ATTACKPOWER_PEA;
}

Pea::~Pea()
{
}

void Pea::Update()
{
	if (m_attackTimer.HasElapsed())
	{
		SpawnBullet();
		m_attackTimer.Tick();
	}
}