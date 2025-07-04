#include "MainGame.h"
#include <stdio.h>

MainGame::MainGame(HWND p_hWnd)
{
	m_hWnd = p_hWnd;

	m_managerManager = new ManagerManager(this);

	m_debugTextIndex = GAMEBOARD_START_Y + (TILE_HEIGHT * GAMEBOARD_HEIGHT);
	test();
}

MainGame::~MainGame()
{
	delete m_managerManager;
}

void MainGame::test()
{
	//m_plantManager->SpawnSunflower(Point(GAMEBOARD_START_X + (8 * TILE_WIDTH), GAMEBOARD_START_Y + (2 * TILE_HEIGHT)));
	//m_plantManager->SpawnPea(Point(GAMEBOARD_START_X + TILE_WIDTH, GAMEBOARD_START_Y + TILE_HEIGHT));
	//m_zombieManager->SpawnZombie(Point(GAMEBOARD_START_X + (10 * TILE_WIDTH), GAMEBOARD_START_Y + (2 * TILE_HEIGHT)));
	//m_zombieManager->SpawnZombie(Point(GAMEBOARD_START_X + (11 * TILE_WIDTH), GAMEBOARD_START_Y + (2 * TILE_HEIGHT)));
}

void MainGame::DebugTextOut(HDC hdc)
{
	int index = GAMEBOARD_START_Y + (TILE_HEIGHT * GAMEBOARD_HEIGHT);
	int interval = 20;
	/*
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
	*/
}

void MainGame::Update()
{
	m_managerManager->Update();
	if (m_clickOccured)
	{
		m_managerManager->ClickHandle();
		m_clickOccured = false;
	}

	InvalidateRect(m_hWnd, NULL, FALSE);
}

void MainGame::ClickHandle()
{

}

void MainGame::DrawAll(HDC hdc)
{

	m_managerManager->Draw(hdc);
	DebugTextOut(hdc);
}

GameBoard* MainGame::GetGameBoard()
{
	
	return dynamic_cast<GameBoard*>(m_managerManager->GetManagers()[GAMEBOARD_INDEX]);
}

Player* MainGame::GetPlayer()
{
	return dynamic_cast<Player*>(m_managerManager->GetManagers()[PLAYER_INDEX]);
}

PlantManager* MainGame::GetPlantManager()
{
	return dynamic_cast<PlantManager*>(m_managerManager->GetManagers()[PLANT_MANAGER_INDEX]);
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