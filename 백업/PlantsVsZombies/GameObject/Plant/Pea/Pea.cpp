#include "Pea.h"

//protected
void Pea::SpawnBullet()
{
	PeaBullet* bullet = new PeaBullet(m_position + Point(PLANT_WIDTH / 2 + BULLET_WIDTH, PLANT_HEIGHT / 2 - BULLET_HEIGHT));
	bullet->Init(m_attackPower, PEA_BULLET_MOVESPEED);
	BulletManager::GetI()->AddBullets(bullet);
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
	:Plant(DEFAULT_POSITION, PLANT_SIZE, PEA_IMAGEPATH)
{
	m_bulletManager = nullptr;
	m_hp = PEA_HEALTHPOINT;
	m_attackPower = PEA_ATTACKPOWER;
	m_attackSpeed = PEA_ATTACKSPEED;
	m_attackTimer.Init(m_attackSpeed);
}

Pea::~Pea()
{
}

void Pea::Init(Point p_pos)
{
	m_position = p_pos;
}

void Pea::Init(Point p_pos, BulletManager* p_bulletManager)
{
	m_position = p_pos;
	m_bulletManager = p_bulletManager;
}

void Pea::Update()
{
	SpawnBulletPeriodically();
	CheckAlive();
}