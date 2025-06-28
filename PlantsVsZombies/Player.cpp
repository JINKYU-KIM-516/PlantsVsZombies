#include "Player.h"

Player::Player()
{
	m_sunlight = 0;
}

void Player::SpawnSunflower()
{
	Sunflower* sunflower = new Sunflower(Point(128, 128));

	//m_sunflowers.push_back(sunflower);
	m_plants.push_back(sunflower);
}

void Player::SpawnPea()
{
	Pea* pea = new Pea(Point(256, 256));
	m_plants.push_back(pea);
}


vector<Sunflower*> Player::GetSunflowers()
{
	return m_sunflowers;
}

vector<Plant*> Player::GetPlants()
{
	return m_plants;
}
