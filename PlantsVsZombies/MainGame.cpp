#include "MainGame.h"

MainGame::MainGame(HWND p_hWnd)
{
	m_hWnd = p_hWnd;
	m_player = new Player(this);
	m_gameBoard = new GameBoard();
	m_zombieManager = new ZombieManager();
	m_bulletManager = new BulletManager();

	test();
}

void MainGame::test()
{
	m_player->SpawnSunflower(Point(128,128));
	m_player->SpawnPea(Point(64,64));
}

void MainGame::Update()
{
	for (auto* plant : m_player->GetPlants())
		plant->Update();
	for (auto* bullet : m_bulletManager->GetBullets())
		bullet->Update();
	for (auto* zombie : m_zombieManager->GetZombies())
		zombie->Update();
	m_zombieManager->Update();
	InvalidateRect(m_hWnd, NULL, FALSE);
}

void MainGame::DrawAll(HDC hdc)
{
	if(m_gameBoard)
	{
		for (auto* tile : m_gameBoard->GetTiles())
			tile->Draw(hdc);
	}
	if (m_player)
	{
		for (auto* plant : m_player->GetPlants())
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
