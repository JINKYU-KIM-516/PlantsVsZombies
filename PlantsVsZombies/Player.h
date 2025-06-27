#pragma once
#include <windows.h>
#include <vector>
#include "Sunflower.h"
class Player
{
protected:
	int m_sunlight;
	std::vector<Sunflower*> m_sunflowers;

public:
	Player();
	void SpawnSunflower();

	vector<Sunflower*> GetSunflowers();
};