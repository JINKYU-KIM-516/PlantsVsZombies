#pragma once
#include <vector>
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../../../CoreFunction/IntervalTimer/IntervalTimer.h"
#include "../../../GameObject/Sunlight/Sunlight.h"

class MainGame;

class SunlightManager : public BaseManager, public SingletonT<SunlightManager>
{
protected:
	IntervalTimer m_spawnSunlightTimer;

	vector<Sunlight*> m_sunlights;

	void SpawnSunlight(Point p_pos, int p_limitY);
	void SpawnSunlightRandom();
	void ClickSunlight();
public:
	SunlightManager();
	~SunlightManager();
	void Init() override;
	void Update() override;
	void ClickHandle() override;
	void Draw(HDC p_hdc) override;

	void AddSunlight(Sunlight* p_sunlight);
	void DeleteSunlight(Sunlight* p_sunlight);
	const vector<Sunlight*>& GetSunlights() const;
};