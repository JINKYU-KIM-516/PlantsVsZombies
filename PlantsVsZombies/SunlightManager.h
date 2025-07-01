#pragma once
#include <vector>
#include "IntervalTimer.h"
#include "Sunlight.h"

class SunlightManager
{
protected:
	IntervalTimer m_spawnSunlightTimer;

	vector<Sunlight*> m_sunlights;

	void SpawnSunlight(Point p_pos, int p_limitY);
	void SpawnSunlightRandom();
public:
	~SunlightManager();
	void Init();
	void Update();

	void AddSunlight(Sunlight* p_sunlight);
	void DeleteSunlight(Sunlight* p_sunlight);
	const vector<Sunlight*>& GetSunlights() const;
};