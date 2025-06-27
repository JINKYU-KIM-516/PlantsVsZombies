#pragma once
#include <windows.h>
#include "Player.h"
#include "Field.h"
class MainGame
{
protected:
	Player* m_player;
	Field* m_field;

	HWND m_hWnd;
public:
	MainGame(HWND);

	void test();

	void DrawAll(HDC hdc);
};