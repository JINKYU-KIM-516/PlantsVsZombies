#pragma once
#include <windows.h>
#include "GameBoard.h"
#include "PlantManager.h"
#include "SunlightManager.h"
#include "BulletManager.h"
#include "ZombieManager.h"
#include "CollisionManager.h"
#include "Store.h"
#include "Player.h"

class MainGame
{
protected:
	GameBoard* m_gameBoard;
	PlantManager* m_plantManager;
	SunlightManager* m_sunlightManager;
	BulletManager* m_bulletManager;
	ZombieManager* m_zombieManager;
	CollisionManager* m_collisionManager;
	Store* m_store;
	Player* m_player;

	Point m_mousePosition;
	bool m_clickOccured;

	HWND m_hWnd;
public:
	MainGame(HWND);
	~MainGame();
	void test();

	void Update();
	void DrawAll(HDC hdc);

	GameBoard* GetGameBoard();
	Player* GetPlayer();
	PlantManager* GetPlantManager();

	Point GetMousePosition();
	bool IsClickOccured();

	void SetMousePosition(Point p_pos);
	void ClickOccured();
};

//constants 이게 맞나요 상수 싹 다 define으로 해도 되나요
//Init 어떻게 써야할지 모르겠어요 초기화는 생성자에 해도 되는거 아닌가요 생성자에서 멤버변수 어차피 다 초기화해야되는거 아닌가요
//update x의 update는 XManager에 넣어놨는데 MainGame Update에서 하는게 나을까요?