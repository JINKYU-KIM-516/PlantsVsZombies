#pragma once
#include <vector>
#include "BulletManager.h"
#include "Sunflower.h"
#include "Pea.h"

using namespace std;

enum PlayerState
{
	Normal, Selecting
};

class Player
{
protected:
	int m_sunlight;
	int m_playerState;
public:
	Player();
	void Init();
};