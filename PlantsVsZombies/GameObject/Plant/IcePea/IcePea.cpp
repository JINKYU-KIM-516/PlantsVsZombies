#include "IcePea.h"

//protected
void IcePea::SpawnBullet()
{
	IcePeaBullet* bullet = new IcePeaBullet(m_positon + Point(PLANT_WIDTH / 2 + BULLET_WIDTH, PLANT_HEIGHT / 2 - BULLET_HEIGHT));
	bullet->Init(m_attackPower, PEA_BULLET_MOVESPEED);

	m_bulletManager->AddBullets(bullet);
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
	:Plant(DEFAULT_POSITION, PLANT_SIZE, ICEPEA_IMAGEPATH)
{
	m_bulletManager = nullptr;
	m_hp = 150;
	m_attackPower = ICEPEA_ATTACKPOWER;
	m_attackSpeed = ICEPEA_ATTACKSPEED;
	m_attackTimer.Init(m_attackSpeed);
}

IcePea::~IcePea()
{
}

void IcePea::Init(Point p_pos, BulletManager* p_bulletManager)
{
	m_positon = p_pos;
	m_bulletManager = p_bulletManager;
}

void IcePea::Update()
{
	SpawnBulletPeriodically();
	CheckAlive();
}