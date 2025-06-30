#pragma once
#include <vector>
#include "Sunlight.h"

class SunlightManager
{
protected:
	vector<Sunlight*> m_sunlights;

	void SpawnSunlight(Point p_pos);
public:
	~SunlightManager();
	void Update();

	void AddSunlight(Sunlight* p_sunlight);
	void DeleteSunlight(Sunlight* p_sunlight);
	const vector<Sunlight*>& GetSunlights() const;
};