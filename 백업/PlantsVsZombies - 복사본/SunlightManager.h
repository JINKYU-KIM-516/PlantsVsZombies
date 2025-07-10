#pragma once
#include <vector>
#include "BaseManager.h"
#include "IntervalTimer.h"
#include "Sunlight.h"

class MainGame;

class SunlightManager : public BaseManager
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
	void Init() override;
	void Link(MainGame* p_mainGame);
	void Update() override;
	void ClickHandle() override;
	void Draw(HDC p_hdc) override;

	void AddSunlight(Sunlight* p_sunlight);
	void DeleteSunlight(Sunlight* p_sunlight);
	const vector<Sunlight*>& GetSunlights() const;
};