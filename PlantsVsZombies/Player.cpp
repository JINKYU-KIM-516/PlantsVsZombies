#include "Player.h"

Player::Player()
{
	m_sunlight = 0;
}

void Player::SpawnSunflower()
{
	Sunflower* sunflower = new Sunflower(Point(128, 128));

	m_sunflowers.push_back(sunflower);
}


vector<Sunflower*> Player::GetSunflowers()
{
	return m_sunflowers;
}