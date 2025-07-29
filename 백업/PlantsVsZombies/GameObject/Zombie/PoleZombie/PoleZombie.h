#pragma once
#include "../BaseZombie.h"
#include "Pole/Pole.h"

class PoleZombie : public BaseZombie
{
protected:
	Pole* m_pole;

	bool m_hasPole;

	void UpdatePolePos();
	void CheckPole();
public:
	PoleZombie();
	void Update() override;
	void Draw(HDC p_hdc) override;
};

