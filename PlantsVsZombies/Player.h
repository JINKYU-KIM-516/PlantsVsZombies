#pragma once
#include <vector>
#include "PlantManager.h"
#include "Store.h"

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
	void Update();
};