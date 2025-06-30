#pragma once
#include <vector>
#include "BulletManager.h"
#include "Sunflower.h"
#include "Pea.h"

using namespace std;

class PlantManager
{
protected:
	BulletManager* m_bulletManager;
	vector<Plant*> m_plants;

	void CheckPlantsAlive();
public:
	PlantManager();
	~PlantManager();
	void Init(BulletManager* p_bulletManager);
	void Update();

	void SpawnSunflower(Point p_pos);
	void SpawnPea(Point p_pos);

	void AddPlant(Plant* p_plant);
	void DeletePlant(Plant* p_plant);
	const vector<Plant*>& GetPlants() const;
};

