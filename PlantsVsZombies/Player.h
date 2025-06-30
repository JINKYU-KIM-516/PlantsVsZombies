#pragma once
#include <vector>
#include "BulletManager.h"
#include "Sunflower.h"
#include "Pea.h"

using namespace std;

class Player
{
protected:
	int m_sunlight;
public:
	Player();
	void Init();
};