#include "BulletManager.h"

BulletManager::~BulletManager()
{
	for (auto* b : m_bullets)
		delete b;
}

void BulletManager::AddBullets(Bullet* p_bullet)
{
	m_bullets.push_back(p_bullet);
}

const vector<Bullet*>& BulletManager::GetBullets() const
{
	return m_bullets;
}
