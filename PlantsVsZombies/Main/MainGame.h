#pragma once
#include <windows.h>
#include "../Manager/ManagerManager/ManagerManager.h"
#include "../CoreFunction/Singleton/SingletonT.h"

class MainGame : public SingletonT<MainGame>
{
protected:
	ManagerManager* m_managerManager;

	Point m_mousePosition;
	bool m_clickOccured;
	bool m_isGameOver;

	int m_debugTextIndex;

	HWND m_hWnd;
public:
	MainGame();
	MainGame(HWND p_hWnd);
	~MainGame();

	void test();
	void DebugTextOut(HDC hdc);

	void Init(HWND p_hWnd);
	void Link();
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