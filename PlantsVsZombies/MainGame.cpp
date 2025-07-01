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

	m_plantManager->Init(m_sunlightManager ,m_bulletManager);
	m_collisionManager->Init(m_plantManager, m_zombieManager, m_bulletManager);

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
}

void MainGame::test()
{
	m_plantManager->SpawnSunflower(Point(8 * TILE_WIDTH, 2 * TILE_HEIGHT));
	m_plantManager->SpawnPea(Point(TILE_WIDTH, TILE_HEIGHT));
}

void MainGame::Update()
{
	for (auto* plant : m_plantManager->GetPlants())
		plant->Update();
	for (auto* bullet : m_bulletManager->GetBullets())
		bullet->Update();
	for (auto* zombie : m_zombieManager->GetZombies())
		zombie->Update();
	
	m_plantManager->Update();
	m_bulletManager->Update();
	m_zombieManager->Update();
	m_collisionManager->Update();

	InvalidateRect(m_hWnd, NULL, FALSE);
}

void MainGame::DrawAll(HDC hdc)
{
	if(m_gameBoard)
	{
		for (auto* tile : m_gameBoard->GetTiles())
			tile->Draw(hdc);
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
}

BulletManager* MainGame::GetBulletManager()
{
	return m_bulletManager;
}
