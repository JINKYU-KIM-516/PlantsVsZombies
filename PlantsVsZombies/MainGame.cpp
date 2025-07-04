#include "MainGame.h"
#include <stdio.h>

MainGame::MainGame(HWND p_hWnd)
{
	m_hWnd = p_hWnd;
	m_gameBoard = new GameBoard();
	m_plantManager = new PlantManager();
	m_sunlightManager = new SunlightManager();
	m_bulletManager = new BulletManager();
	m_zombieManager = new ZombieManager();
	m_collisionManager = new CollisionManager();
	m_store = new Store();
	m_player = new Player();

	m_gameBoard->Link(this);
	m_plantManager->Link(m_sunlightManager ,m_bulletManager);
	m_sunlightManager->Link(this);
	m_collisionManager->Link(m_plantManager, m_zombieManager, m_bulletManager);
	m_store->Link(this);
	m_player->Link(this);

	m_debugTextIndex = GAMEBOARD_START_Y + (TILE_HEIGHT * GAMEBOARD_HEIGHT);
	test();
}

MainGame::~MainGame()
{
	delete m_gameBoard;
	delete m_plantManager;
	delete m_sunlightManager;
	delete m_bulletManager;
	delete m_zombieManager;
	delete m_collisionManager;
	delete m_store;
	delete m_player;
}

void MainGame::test()
{
	m_plantManager->SpawnSunflower(Point(GAMEBOARD_START_X + (8 * TILE_WIDTH), GAMEBOARD_START_Y + (2 * TILE_HEIGHT)));
	m_plantManager->SpawnPea(Point(GAMEBOARD_START_X + TILE_WIDTH, GAMEBOARD_START_Y + TILE_HEIGHT));
	//m_zombieManager->SpawnZombie(Point(GAMEBOARD_START_X + (10 * TILE_WIDTH), GAMEBOARD_START_Y + (2 * TILE_HEIGHT)));
	//m_zombieManager->SpawnZombie(Point(GAMEBOARD_START_X + (11 * TILE_WIDTH), GAMEBOARD_START_Y + (2 * TILE_HEIGHT)));
}

void MainGame::DebugTextOut(HDC hdc)
{
	int index = GAMEBOARD_START_Y + (TILE_HEIGHT * GAMEBOARD_HEIGHT);
	int interval = 20;

	TCHAR str[20];
	wsprintf(str, TEXT("햇빛 : %d"), m_player->GetSunlight());
	TextOut(hdc, 0, index, str, lstrlen(str));
	index += interval;

	TCHAR str1[30];
	wsprintf(str1, TEXT("플레이어 상태 : %d"), m_player->GetState());
	TextOut(hdc, 0, index, str1, lstrlen(str1));
	index += interval;

	TCHAR str2[30];
	wsprintf(str2, TEXT("고른 식물 : %d"), m_player->GetSelectedCode());
	TextOut(hdc, 0, index, str2, lstrlen(str2));
	index += interval;
}

void MainGame::Update()
{
	m_plantManager->Update();
	m_sunlightManager->Update();
	m_bulletManager->Update();
	m_zombieManager->Update();
	m_collisionManager->Update();
	m_store->Update();
	m_player->Update();

	if (m_clickOccured)
	{
		ClickHandle();
		m_clickOccured = false;
	}

	InvalidateRect(m_hWnd, NULL, FALSE);
}

void MainGame::ClickHandle()
{
	m_sunlightManager->ClickHandle();
	m_player->ClickHandle();
	m_store->ClickHandle();
}

void MainGame::DrawAll(HDC hdc)
{
	if(m_gameBoard)
	{
		for (auto* tile : m_gameBoard->GetTiles())
			tile->Draw(hdc);
	}
	if (m_store)
	{
		for (auto* image : m_store->GetImages())
			image->Draw(hdc);
	}
	if (m_plantManager)
	{
		for (auto* plant : m_plantManager->GetPlants())
			plant->Draw(hdc);
	}
	if (m_bulletManager)
	{
		for (auto* bullet : m_bulletManager->GetBullets())
			bullet->Draw(hdc);
	}
	if (m_zombieManager)
	{
		for (auto* zombie : m_zombieManager->GetZombies())
			zombie->Draw(hdc);
	}
	if (m_sunlightManager)
	{
		for (auto* sunlight : m_sunlightManager->GetSunlights())
			sunlight->Draw(hdc);
	}
	DebugTextOut(hdc);
}

GameBoard* MainGame::GetGameBoard()
{
	return m_gameBoard;
}

Player* MainGame::GetPlayer()
{
	return m_player;
}

PlantManager* MainGame::GetPlantManager()
{
	return m_plantManager;
}

Point MainGame::GetMousePosition()
{
	return m_mousePosition;
}

bool MainGame::IsClickOccured()
{
	return m_clickOccured;
}

void MainGame::SetMousePosition(Point p_pos)
{
	m_mousePosition = p_pos;
}

void MainGame::ClickOccured()
{
	m_clickOccured = true;
}