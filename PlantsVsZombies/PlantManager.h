#pragma once
#include <vector>
#include "BaseManager.h"
#include "BulletManager.h"
#include "Sunflower.h"
#include "Pea.h"

using namespace std;

class PlantManager : public BaseManager
{
protected:
	MainGame* m_mainGame;
	SunlightManager* m_sunlightManager;
	BulletManager* m_bulletManager;
	vector<Plant*> m_plants;

	void CheckPlantsAlive();
public:
	PlantManager();
	~PlantManager();

	void Init() override;
	void Link(SunlightManager* p_sunlightManager, BulletManager* p_bulletManager);
	void Update() override;
	void Draw(HDC p_hdc) override;

	void SpawnSunflower(Point p_pos);
	void SpawnPea(Point p_pos);

	void AddPlant(Plant* p_plant);
	void DeletePlant(Plant* p_plant);
	const vector<Plant*>& GetPlants() const;
};

