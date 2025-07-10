#pragma once
#include "Plant.h"
#include "IntervalTimer.h"
#include "SunlightManager.h"

class Sunflower : public Plant
{
protected:
	IntervalTimer m_spawnSunlightTimer;

	SunlightManager* m_sunlightManager;

	void SpawnSunlight();
public:
	Sunflower();
	void Init(Point p_pos, SunlightManager* p_sunlightManager);
	void Update();
};