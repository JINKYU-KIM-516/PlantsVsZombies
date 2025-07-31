#pragma once
#include <vector>
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../BulletManager/BulletManager.h"
#include "../../../GameObject/Plant/Sunflower/Sunflower.h"
#include "../../../GameObject/Plant/Pea/Pea.h"
#include "../../../GameObject/Plant/IcePea/IcePea.h"
#include "../../../GameObject/Plant/Nut/Nut.h"

using namespace std;
class MainGame;

class PlantManager :  public BaseManager, public SingletonT<PlantManager>
{
protected:
	vector<Plant*> m_plants;

	void CheckPlantsAlive();
public:
	PlantManager();
	~PlantManager();

	void Init() override;
	void Update() override;
	void Draw(HDC p_hdc) override;

	void SpawnSunflower(Point p_pos, Tile* p_tile);
	void SpawnPea(Point p_pos, Tile* p_tile);
	void SpawnIcePea(Point p_pos, Tile* p_tile);
	void SpawnNut(Point p_pos, Tile* p_tile);

	void AddPlant(Plant* p_plant);
	void DeletePlant(Plant* p_plant);
	const vector<Plant*>& GetPlants() const;
	Plant* GetMouseOverPlant();
};

