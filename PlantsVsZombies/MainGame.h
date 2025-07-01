#pragma once
#include <windows.h>
#include "GameBoard.h"
#include "PlantManager.h"
#include "SunlightManager.h"
#include "BulletManager.h"
#include "ZombieManager.h"
#include "CollisionManager.h"

class MainGame
{
protected:
	GameBoard* m_gameBoard;
	PlantManager* m_plantManager;
	SunlightManager* m_sunlightManager;
	BulletManager* m_bulletManager;
	ZombieManager* m_zombieManager;
	CollisionManager* m_collisionManager;

	HWND m_hWnd;
public:
	MainGame(HWND);
	~MainGame();
	void test();

	void Update();
	void DrawAll(HDC hdc);
	BulletManager* GetBulletManager();
};

//constants 이게 맞나요 상수 싹 다 define으로 해도 되나요
//Init 어떻게 써야할지 모르겠어요 초기화는 생성자에 해도 되는거 아닌가요 생성자에서 멤버변수 어차피 다 초기화해야되는거 아닌가요