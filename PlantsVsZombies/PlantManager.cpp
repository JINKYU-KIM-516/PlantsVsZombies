#include "PlantManager.h"

PlantManager::PlantManager()
{
	m_bulletManager = nullptr;
}

PlantManager::~PlantManager()
{

}

void PlantManager::Init(BulletManager* p_bulletManager)
{
	m_bulletManager = p_bulletManager;
}

void PlantManager::SpawnSunflower(Point p_pos)
{
	Sunflower* sunflower = new Sunflower(p_pos);
	AddPlant(sunflower);
}

void PlantManager::SpawnPea(Point p_pos)
{
	Pea* pea = new Pea(m_bulletManager, p_pos);
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
