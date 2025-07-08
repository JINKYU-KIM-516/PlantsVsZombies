#pragma once
#include <vector>
#include "BaseManager.h"
#include "Store.h"

using namespace std;

class Player : public BaseManager
{
protected:
	MainGame* m_mainGame;

	int m_sunlight;
	int m_state;
	int m_selectedCode;
	PictureBox* m_currentSelectedPlant;

	Point m_currentTilePos;

	void SpawnPlant(Point p_pos);
	void ClickTile();
	void PreviewPlant();
public:
	Player();
	void Init() override;
	void Link(MainGame* p_mainGame);
	void Update() override;
	void ClickHandle() override;
	void Draw(HDC p_hdc) override;

	void SelectPlant(int p_code);
	void ResetState();

	int GetSunlight();
	int GetState();
	int GetSelectedCode();

	void SetSunlight(int p_sunlight);
	void SetState(int p_state);
	void SetSelectedCode(int p_code);
	void SetCurrentTilePos(Point p_pos);
};