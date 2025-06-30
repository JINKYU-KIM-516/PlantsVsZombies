#include "BulletManager.h"

BulletManager::~BulletManager()
{
	for (auto* b : m_bullets)
		delete b;
}

void BulletManager::Update()
{
	CheckBullets();
}

void BulletManager::AddBullets(Bullet* p_bullet)
{
	m_bullets.push_back(p_bullet);
}

void BulletManager::DeleteBullet(Bullet* p_bullet)
{
	m_bullets.erase(remove(m_bullets.begin(), m_bullets.end(), p_bullet), m_bullets.end());
	delete p_bullet;
}

void BulletManager::CheckBullets()
{
	for (auto* bullet : m_bullets)
	{
		if (bullet->GetLocation().GetX() > (GAMEBOAORD_WIDTH + 1) * TILE_WIDTH)
		{
			DeleteBullet(bullet);
		}
	}
}

const vector<Bullet*>& BulletManager::GetBullets() const
{
	return m_bullets;
}
