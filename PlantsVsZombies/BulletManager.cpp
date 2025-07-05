#include "BulletManager.h"

//protected
void BulletManager::CheckBulletsInScreen()
{
	for (auto* bullet : m_bullets)
	{
		if (bullet->GetPos().GetX() > (GAMEBOARD_WIDTH + 1) * TILE_WIDTH)
		{
			DeleteBullet(bullet);
		}
	}
}

//public
BulletManager::~BulletManager()
{
	for (auto* bullet : m_bullets)
		delete bullet;
}

void BulletManager::Update()
{
	for (auto* bullet : m_bullets)
		bullet->Update();
	CheckBulletsInScreen();
}

void BulletManager::Draw(HDC p_hdc)
{
	for (auto* bullet : m_bullets)
		bullet->Draw(p_hdc);
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

const vector<Bullet*>& BulletManager::GetBullets() const
{
	return m_bullets;
}
