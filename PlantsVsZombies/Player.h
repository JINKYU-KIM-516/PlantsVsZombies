#pragma once
#include <vector>
#include "Store.h"

using namespace std;

class Player
{
protected:
	MainGame* m_mainGame;

	int m_sunlight;
	int m_state;
	int m_selectedCode;

	Point m_currentTilePos;

	void SpawnPlant(Point p_pos);
	void ResetState();
public:
	Player();
	void Init();
	void Link(MainGame* p_mainGame);
	void Update();
	void ClickHandle();

	int GetSunlight();

	void SetSunlight(int p_sunlight);
	void SetState(int p_state);
	void SetSelectedCode(int p_code);
	void SetCurrentTilePos(Point p_pos);
};