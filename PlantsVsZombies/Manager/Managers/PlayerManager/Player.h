#pragma once
#include <vector>
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../StoreManager/Store.h"
#include "../../../GameObject/Shovel/Shovel.h"

using namespace std;

class Tile;

class Player : public BaseManager, public SingletonT<Player>
{
protected:
	int m_sunlight;
	PlayerState m_state;
	int m_selectedCode;
	PictureBox* m_currentSelectedPlant;
	Shovel* m_shovel;

	Point m_currentTilePos;

	void SpawnPlant(Point p_pos, Tile* p_tile);
	void ClickTile();
	void PreviewPlant();
	void CheckState();
public:
	Player();
	void Init() override;
	void Update() override;
	void ClickHandle() override;
	void Draw(HDC p_hdc) override;

	void SelectPlant(int p_code);
	void SelectShovel();
	void ResetState();

	int GetSunlight();
	PlayerState GetState();
	int GetSelectedCode();

	void SetSunlight(int p_sunlight);
	void SetState(PlayerState p_state);
	void SetSelectedCode(int p_code);
	void SetCurrentTilePos(Point p_pos);
};