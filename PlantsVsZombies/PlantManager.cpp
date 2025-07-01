#include "PlantManager.h"

//protected
void PlantManager::CheckPlantsAlive()
{
	for (auto* plant : m_plants)
		if (!plant->IsAlive())
			DeletePlant(plant);
}

//public
PlantManager::PlantManager()
{
	m_sunlightManager = nullptr;
	m_bulletManager = nullptr;
}

PlantManager::~PlantManager()
{
	for (auto* plant : m_plants)
		delete plant;
}

void PlantManager::Init(SunlightManager* p_sunlightManager, BulletManager* p_bulletManager)
{
	m_sunlightManager = p_sunlightManager;
	m_bulletManager = p_bulletManager;
}

void PlantManager::Update()
{
	for (auto* plant : m_plants)
		plant->Update();
	CheckPlantsAlive();
}

void PlantManager::SpawnSunflower(Point p_pos)
{
	Sunflower* sunflower = new Sunflower();
	sunflower->Init(p_pos, m_sunlightManager);
	AddPlant(sunflower);
}

void PlantManager::SpawnPea(Point p_pos)
{
	Pea* pea = new Pea();
	pea->Init(p_pos, m_bulletManager);
	AddPlant(pea);
}

void PlantManager::AddPlant(Plant* p_plant)
{
	m_plants.push_back(p_plant);
}

void PlantManager::DeletePlant(Plant* p_plant)
{
	m_plants.erase(remove(m_plants.begin(), m_plants.end(), p_plant), m_plants.end());
	delete p_plant;
}

const vector<Plant*>& PlantManager::GetPlants() const
{
	return m_plants;
}
