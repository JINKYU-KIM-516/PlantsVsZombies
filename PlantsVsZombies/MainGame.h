#pragma once
#include <windows.h>
#include "Player.h"
#include "GameBoard.h"
#include "ZombieManager.h"
#include "BulletManager.h"

class MainGame
{
protected:
	Player* m_player;
	GameBoard* m_gameBoard;
	ZombieManager* m_zombieManager;
	BulletManager* m_bulletManager;

	HWND m_hWnd;
public:
	MainGame(HWND);

	void test();

	void Update();
	void DrawAll(HDC hdc);
	BulletManager* GetBulletManager();
};