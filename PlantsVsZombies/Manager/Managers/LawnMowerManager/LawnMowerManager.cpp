#include "LawnMowerManager.h"

//protected
void LawnMowerManager::CreateLawnMower()
{
	for (int i = 0; i < GAMEBOARD_HEIGHT; i++)
	{
		SpawnLawnMower(Point(GAMEBOARD_START_X - LAWNMOWER_WIDTH, GAMEBOARD_START_Y + ((TILE_HEIGHT - LAWNMOWER_HEIGHT) / 2) + (TILE_HEIGHT * i)));
	}
	
}

//public
LawnMowerManager::LawnMowerManager()
{
	Init();
	CreateLawnMower();
}

LawnMowerManager::~LawnMowerManager()
{
	for (auto* mower : m_lawnMowers)
		delete mower;
}

void LawnMowerManager::Update()
{
	for (auto* mower : m_lawnMowers)
		mower->Update();
}

void LawnMowerManager::Init()
{
}

void LawnMowerManager::Draw(HDC p_hdc)
{
	for (auto* mower : m_lawnMowers)
		mower->Draw(p_hdc);
}

void LawnMowerManager::SpawnLawnMower(Point p_pos)
{
	LawnMower* mower = new LawnMower();
	mower->Init(p_pos);
	AddLawnMower(mower);
}

void LawnMowerManager::AddLawnMower(LawnMower* p_mower)
{
	m_lawnMowers.push_back(p_mower);
}

void LawnMowerManager::DeleteLawnMower(LawnMower* p_mower)
{
	m_lawnMowers.erase(remove(m_lawnMowers.begin(), m_lawnMowers.end(), p_mower), m_lawnMowers.end());
	delete p_mower;
}

const vector<LawnMower*>& LawnMowerManager::GetLawnMowers() const
{
	return m_lawnMowers;
}
