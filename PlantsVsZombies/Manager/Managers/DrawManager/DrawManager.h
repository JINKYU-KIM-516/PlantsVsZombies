#pragma once
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../../../CoreFunction/PictureBox/PictureBox.h"
#include <map>

class DrawManager : public BaseManager, public SingletonT<DrawManager>
{
protected:
	map<wstring, PictureBox*> m_imageMap;
public:
	~DrawManager();
	PictureBox* Load(const wstring& path);
};

