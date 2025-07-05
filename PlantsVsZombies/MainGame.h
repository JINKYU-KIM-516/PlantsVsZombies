#pragma once
#include <windows.h>
#include "ManagerManager.h"

class MainGame
{
protected:
	ManagerManager* m_managerManager;

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
	void Draw(HWND p_hWnd);

	GameBoard* GetGameBoard();
	PlantManager* GetPlantManager();

	Player* GetPlayer();

	Point GetMousePosition();
	bool IsClickOccured();

	void SetMousePosition(Point p_pos);
	void ClickOccured();
};

//DrawManager 시도 -> z로 순서 정렬