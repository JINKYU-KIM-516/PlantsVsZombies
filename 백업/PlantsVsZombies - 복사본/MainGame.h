#pragma once
#include <windows.h>
#include "ManagerManager.h"

class MainGame
{
protected:
	ManagerManager* m_managerManager;

	Point m_mousePosition;
	bool m_clickOccured;
	bool m_isGameOver;

	int m_debugTextIndex;

	HWND m_hWnd;
public:
	MainGame(HWND);
	~MainGame();

	void test();
	void DebugTextOut(HDC hdc);

	void Update();
	void ClickHandle();
	void Draw(HWND p_hWnd);

	void GameOver(LPCWSTR p_reason);

	GameBoard* GetGameBoard();
	PlantManager* GetPlantManager();
	Player* GetPlayer();
	Point GetMousePosition();
	bool IsClickOccured();
	bool IsGameOver();

	void SetMousePosition(Point p_pos);
	void ClickOccured();
};

//DrawManager 시도 -> z로 순서 정렬