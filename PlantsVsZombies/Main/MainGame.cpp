#include "MainGame.h"
#include <stdio.h>

MainGame::MainGame(HWND p_hWnd)
{
	m_hWnd = p_hWnd;
	m_managerManager = new ManagerManager(this);
	m_debugTextIndex = GAMEBOARD_START_Y + (TILE_HEIGHT * GAMEBOARD_HEIGHT);
	m_isGameOver = false;
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
	//dynamic_cast<ZombieManager*>(m_managerManager->GetManagers()[ZOMBIE_MANAGER_INDEX])->SpawnFunnelZombie(Point(GAMEBOARD_START_X + 256, GAMEBOARD_START_Y));
}

void MainGame::DebugTextOut(HDC hdc)
{
	int index = GAMEBOARD_START_Y + (TILE_HEIGHT * GAMEBOARD_HEIGHT);
	int interval = 20;
	Player* player = dynamic_cast<Player*>(m_managerManager->GetManagers()[PLAYER_INDEX]);
	
	TCHAR str[20];
	wsprintf(str, TEXT("햇빛 : %d"), player->GetSunlight());
	TextOut(hdc, 0, index, str, lstrlen(str));
	index += interval;

	TCHAR str1[30];
	wsprintf(str1, TEXT("플레이어 상태 : %d"), player->GetState());
	TextOut(hdc, 0, index, str1, lstrlen(str1));
	index += interval;

	TCHAR str2[30];
	wsprintf(str2, TEXT("고른 식물 : %d"), player->GetSelectedCode());
	TextOut(hdc, 0, index, str2, lstrlen(str2));
	index += interval;
}

void MainGame::Update()
{
	m_managerManager->Update();
	ClickHandle();
	InvalidateRect(m_hWnd, NULL, FALSE);
}

void MainGame::ClickHandle()
{
	if (m_clickOccured)
	{
		m_managerManager->ClickHandle();
		m_clickOccured = false;
	}
}

void MainGame::Draw(HWND p_hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(p_hWnd, &ps);

	// 1. 메모리 DC 생성
	HDC memDC = CreateCompatibleDC(hdc);
	RECT rect;
	GetClientRect(p_hWnd, &rect);
	int width = rect.right;
	int height = rect.bottom;

	// 2. 버퍼용 비트맵 생성 및 선택
	HBITMAP bufferBmp = CreateCompatibleBitmap(hdc, width, height);
	HBITMAP oldBmp = (HBITMAP)SelectObject(memDC, bufferBmp);

	// 3. 배경 지우기
	FillRect(memDC, &rect, (HBRUSH)(COLOR_WINDOW + 1));

	// 4. 메모리 DC에 그리기
	m_managerManager->Draw(memDC);
	DebugTextOut(memDC);


	// 5. 실제 화면에 한 번에 출력
	BitBlt(hdc, 0, 0, width, height, memDC, 0, 0, SRCCOPY);

	// 6. 자원 정리
	SelectObject(memDC, oldBmp);
	DeleteObject(bufferBmp);
	DeleteDC(memDC);

	EndPaint(p_hWnd, &ps);
	m_managerManager->Draw(hdc);
}

void MainGame::GameOver(LPCWSTR p_reason)
{
	m_isGameOver = true;
	KillTimer(m_hWnd, 1);
	MessageBoxW(m_hWnd, p_reason, L"게임 오버", MB_OK);
	DestroyWindow(m_hWnd);
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

bool MainGame::IsGameOver()
{
	return m_isGameOver;
}

void MainGame::SetMousePosition(Point p_pos)
{
	m_mousePosition = p_pos;
}

void MainGame::ClickOccured()
{
	m_clickOccured = true;
}