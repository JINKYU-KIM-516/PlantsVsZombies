#pragma once
#include <windows.h>
#include "Player.h"
#include "Field.h"
#include "ZombieManager.h"

class MainGame
{
protected:
	Player* m_player;
	Field* m_field;
	ZombieManager* m_zombieManager;

	HWND m_hWnd;
public:
	MainGame(HWND);

	void test();

	void Update();
	void DrawAll(HDC hdc);
};