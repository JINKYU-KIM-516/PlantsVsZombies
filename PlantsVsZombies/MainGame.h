#pragma once
#include <windows.h>
#include "GameBoard.h"
#include "Player.h"
#include "ZombieManager.h"
#include "BulletManager.h"
#include "CollisionManager.h"

class MainGame
{
protected:
	GameBoard* m_gameBoard;
	Player* m_player;
	ZombieManager* m_zombieManager;
	BulletManager* m_bulletManager;
	CollisionManager* m_collisionManager;

	HWND m_hWnd;
public:
	MainGame(HWND);

	void test();

	void Update();
	void DrawAll(HDC hdc);
	BulletManager* GetBulletManager();
};