#pragma once
#include <windows.h>
#include <vector>
#include "Sunflower.h"
#include "Pea.h"

class MainGame;

using namespace std;

class Player
{
protected:
	int m_sunlight;
	vector<Plant*> m_plants;
	MainGame* m_mainGameLink;
public:
	Player(MainGame* p_mainGameLink);
	~Player();
	void SpawnSunflower(Point p_pos);
	void SpawnPea(Point p_pos);

	void AddPlants(Plant* p_plant);
	const vector<Plant*>& GetPlants() const;
};