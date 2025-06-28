#pragma once
#include <windows.h>
#include <vector>
#include "Sunflower.h"
#include "Pea.h"

using namespace std;

class Player
{
protected:
	int m_sunlight;
	vector<Sunflower*> m_sunflowers;
	vector<Plant*> m_plants;
public:
	Player();
	void SpawnSunflower();
	void SpawnPea();

	vector<Sunflower*> GetSunflowers();
	vector<Plant*> GetPlants();
};