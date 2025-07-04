#pragma once
#include <windows.h>
#include "GameBoard.h"
#include "PlantManager.h"
#include "SunlightManager.h"
#include "BulletManager.h"
#include "ZombieManager.h"
#include "CollisionManager.h"
#include "Store.h"
#include "Player.h"

class MainGame
{
protected:
	GameBoard* m_gameBoard;
	PlantManager* m_plantManager;
	SunlightManager* m_sunlightManager;
	BulletManager* m_bulletManager;
	ZombieManager* m_zombieManager;
	CollisionManager* m_collisionManager;
	Store* m_store;
	Player* m_player;

	Point m_mousePosition;
	bool m_clickOccured;

	int m_debugTextIndex;

	HWND m_hWnd;
public:
	MainGame(HWND);
	~MainGame();

	void test();
	void DebugTextOut(HDC hdc);

	void Update();
	void ClickHandle();
	void DrawAll(HDC hdc);

	GameBoard* GetGameBoard();
	Player* GetPlayer();
	PlantManager* GetPlantManager();

	Point GetMousePosition();
	bool IsClickOccured();

	void SetMousePosition(Point p_pos);
	void ClickOccured();
};

//DrawManager 시도 -> z로 순서 정렬