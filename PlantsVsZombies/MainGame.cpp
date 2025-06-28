#include "MainGame.h"

MainGame::MainGame(HWND p_hWnd)
{
	m_hWnd = p_hWnd;
	m_player = new Player();
	m_field = new Field();

	test();
}

void MainGame::test()
{
	m_player->SpawnSunflower();
	InvalidateRect(m_hWnd, NULL, TRUE);
}


void MainGame::DrawAll(HDC hdc)
{
	for (auto* tile : m_field->GetTiles())
		tile->Draw(hdc);
	for (auto* sunflower : m_player->GetSunflowers())
		sunflower->Draw(hdc);
}