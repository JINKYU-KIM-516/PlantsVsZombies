#include "BulletManager.h"

BulletManager::~BulletManager()
{
	for (auto* b : m_bullets)
		delete b;
}

void BulletManager::Update()
{
	DeleteBullets();
}

void BulletManager::AddBullets(Bullet* p_bullet)
{
	m_bullets.push_back(p_bullet);
}

void BulletManager::DeleteBullets()
{
	for (auto* bullet : m_bullets)
	{
		m_bullets.erase(
			std::remove_if(m_bullets.begin(), m_bullets.end(),
				[](Bullet* bullet) {
					if (bullet->GetLocation().GetX() > (GAMEBOAORD_WIDTH + 1) * TILE_WIDTH) {
						delete bullet; // 메모리 해제
						return true;   // 리스트에서 제거
					}
					return false;
				}),
			m_bullets.end()
		);
	}
}

const vector<Bullet*>& BulletManager::GetBullets() const
{
	return m_bullets;
}
