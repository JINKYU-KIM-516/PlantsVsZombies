#pragma once
#include <windows.h>
#include "GameBoard.h"
#include "PlantManager.h"
#include "SunlightManager.h"
#include "BulletManager.h"
#include "ZombieManager.h"
#include "CollisionManager.h"
#include "Store.h"

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

	Point m_mousePosition;
	bool m_clickOccured;

	HWND m_hWnd;
public:
	MainGame(HWND);
	~MainGame();
	void test();

	void Update();
	void DrawAll(HDC hdc);

	void SetMousePosition(Point p_pos);
	void ClickOccured();
};

//constants �̰� �³��� ��� �� �� define���� �ص� �ǳ���
//Init ��� ������� �𸣰ھ�� �ʱ�ȭ�� �����ڿ� �ص� �Ǵ°� �ƴѰ��� �����ڿ��� ������� ������ �� �ʱ�ȭ�ؾߵǴ°� �ƴѰ���
//update x�� update�� XManager�� �־���µ� MainGame Update���� �ϴ°� �������?