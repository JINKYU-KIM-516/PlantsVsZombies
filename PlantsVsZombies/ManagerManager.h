#pragma once
#include "GameBoard.h"
#include "PlantManager.h"
#include "SunlightManager.h"
#include "BulletManager.h"
#include "ZombieManager.h"
#include "CollisionManager.h"
#include "Store.h"
#include "Player.h"

class MainGame;

class ManagerManager// : public BaseManager
{
protected:
	MainGame* m_mainGame;
	vector<BaseManager*> m_managers;
public:
	ManagerManager(MainGame* p_mainGame);
	~ManagerManager();
	void Init();
	void Link(MainGame* p_mainGame);
	void Update();
	void ClickHandle();
	void Draw(HDC p_hdc);

	void AddManager(BaseManager* p_manager);
	const vector<BaseManager*>& GetManagers() const;
};