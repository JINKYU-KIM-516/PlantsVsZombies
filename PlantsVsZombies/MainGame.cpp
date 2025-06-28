#include "MainGame.h"

MainGame::MainGame(HWND p_hWnd)
{
	m_hWnd = p_hWnd;
	m_player = new Player();
	m_field = new Field();
	m_zombieManager = new ZombieManager();

	test();
}

void MainGame::test()
{
	m_player->SpawnSunflower();
	m_player->SpawnPea();
	InvalidateRect(m_hWnd, NULL, TRUE);
}

void MainGame::Update()
{
	m_zombieManager->Update();
	InvalidateRect(m_hWnd, NULL, TRUE);
}

void MainGame::DrawAll(HDC hdc)
{
	for (auto* tile : m_field->GetTiles())
		tile->Draw(hdc);
	for (auto* plant : m_player->GetPlants())
		plant->Draw(hdc);
	for (auto* zombie: m_zombieManager->GetZombies())
		zombie->Draw(hdc);
}