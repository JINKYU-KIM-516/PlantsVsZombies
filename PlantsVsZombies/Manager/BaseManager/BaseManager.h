#pragma once
#include <Windows.h>
//#include "../../CoreFunction/Singleton/SingletonT.h"

//template <typename T>

class BaseManager// : public SingletonT<T>
{
public:
	virtual void Init() {};
	virtual void Update() {};
	virtual void ClickHandle() {};
	virtual void Draw(HDC p_hpc) {};
};