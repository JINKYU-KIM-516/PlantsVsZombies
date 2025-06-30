#pragma once
#include <windows.h>
#include "GameBoard.h"
#include "PlantManager.h"
#include "SunlightManager.h"
#include "BulletManager.h"
#include "ZombieManager.h"
#include "CollisionManager.h"

class MainGame
{
protected:
	GameBoard* m_gameBoard;
	PlantManager* m_plantManager;
	SunlightManager* m_sunlightManager;
	BulletManager* m_bulletManager;
	ZombieManager* m_zombieManager;
	CollisionManager* m_collisionManager;

	HWND m_hWnd;
public:
	MainGame(HWND);
	~MainGame();
	void test();

	void Update();
	void DrawAll(HDC hdc);
	BulletManager* GetBulletManager();
};