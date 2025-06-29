#include "Player.h"

Player::Player(MainGame* p_mainGameLink)
	:m_mainGameLink(p_mainGameLink)
{
	m_sunlight = 0;
}

Player::~Player()
{

}

void Player::SpawnSunflower(Point p_pos)
{
	Sunflower* sunflower = new Sunflower(p_pos);
	AddPlants(sunflower);
}

void Player::SpawnPea(Point p_pos)
{
	Pea* pea = new Pea(m_mainGameLink, p_pos);
	AddPlants(pea);
}

void Player::AddPlants(Plant* p_plant)
{
	m_plants.push_back(p_plant);
}

const vector<Plant*>& Player::GetPlants() const
{
	return m_plants;
}
