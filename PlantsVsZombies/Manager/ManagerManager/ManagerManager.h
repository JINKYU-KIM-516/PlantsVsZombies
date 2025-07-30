#pragma once
#include "../../CoreFunction/Singleton/SingletonT.h"
#include "../Managers/GameBoardManager/GameBoard.h"
#include "../Managers/PlantManager/PlantManager.h"
#include "../Managers/SunlightManager/SunlightManager.h"
#include "../Managers/BulletManager/BulletManager.h"
#include "../Managers/ZombieManager/ZombieManager.h"
#include "../Managers/CollisionManager/CollisionManager.h"
#include "../Managers/StoreManager/Store.h"
#include "../Managers/PlayerManager/Player.h"
#include "../Managers/LawnMowerManager/LawnMowerManager.h"

class MainGame;

class ManagerManager : public BaseManager, public SingletonT<ManagerManager>
{
protected:
	MainGame* m_mainGame;
	vector<BaseManager*> m_managers;
public:
	ManagerManager(MainGame* p_mainGame);
	~ManagerManager();
	void Init() override;
	void Link(MainGame* p_mainGame);
	void Update() override;
	void ClickHandle() override;
	void Draw(HDC p_hdc) override;

	void AddManager(BaseManager* p_manager);
	const vector<BaseManager*>& GetManagers() const;
};