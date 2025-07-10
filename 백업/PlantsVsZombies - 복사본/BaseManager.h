#pragma once
#include <Windows.h>

class MainGame;

class BaseManager
{
public:
	virtual void Init() {};
	virtual void Link() {};
	virtual void Update() {};
	virtual void ClickHandle() {};
	virtual void Draw(HDC p_hpc) {};
};