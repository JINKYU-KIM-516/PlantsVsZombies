#pragma once
#include "Plant.h"
#include "SunlightManager.h"

class Sunflower : public Plant
{
protected:
	SunlightManager* m_sunlightManager;
	void SpawnSunlight();
public:
	Sunflower();
	void Init(Point p_pos, SunlightManager* p_sunlightManager);
	void Update();
};