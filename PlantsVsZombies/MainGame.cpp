#include "MainGame.h"

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

	m_plantManager->Init(m_sunlightManager ,m_bulletManager);
	m_sunlightManager->Init();
	m_collisionManager->Init(m_plantManager, m_zombieManager, m_bulletManager);
	m_store->Init();

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
}

void MainGame::test()
{
	m_plantManager->SpawnSunflower(Point(GAMEBOARD_START_X + (8 * TILE_WIDTH), GAMEBOARD_START_Y + (2 * TILE_HEIGHT)));
	m_plantManager->SpawnPea(Point(GAMEBOARD_START_X + TILE_WIDTH, GAMEBOARD_START_Y + TILE_HEIGHT));
}

void MainGame::Update()
{
	m_plantManager->Update();
	m_sunlightManager->Update();
	m_bulletManager->Update();
	m_zombieManager->Update();
	m_collisionManager->Update();
	m_store->Update();

	InvalidateRect(m_hWnd, NULL, FALSE);
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
}

void MainGame::SetMousePosition(Point p_pos)
{
	m_mousePosition = p_pos;
}

void MainGame::ClickOccured()
{
	m_clickOccured = true;
}