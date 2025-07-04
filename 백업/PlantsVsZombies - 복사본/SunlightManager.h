#pragma once
#include <vector>
#include "IntervalTimer.h"
#include "Sunlight.h"

class MainGame;

class SunlightManager
{
protected:
	MainGame* m_mainGame;
	IntervalTimer m_spawnSunlightTimer;

	vector<Sunlight*> m_sunlights;

	void SpawnSunlight(Point p_pos, int p_limitY);
	void SpawnSunlightRandom();
	void ClickSunlight();
public:
	SunlightManager();
	~SunlightManager();
	void Init();
	void Link(MainGame* p_mainGame);
	void Update();
	void ClickHandle();

	void AddSunlight(Sunlight* p_sunlight);
	void DeleteSunlight(Sunlight* p_sunlight);
	const vector<Sunlight*>& GetSunlights() const;
};