#include "ManagerManager.h"
#include "../../Main/MainGame.h"
//#include "../Managers/PlantManager/PlantManager.h"

ManagerManager::ManagerManager(MainGame* p_mainGame)
{
	m_mainGame = p_mainGame;
	Init();
}

ManagerManager::~ManagerManager()
{
	//¸Å´ÏÀúµé ½Ì±ÛÅæ¿¡¼­ ÀÚµ¿¼Ò¸êµÊ
}

void ManagerManager::Init()
{
	GameBoard* gameBoard = GameBoard::GetI();
	PlantManager* plantManager = PlantManager::GetI();
	SunlightManager* sunlightManager = SunlightManager::GetI();
	BulletManager* bulletManager = BulletManager::GetI();
	ZombieManager* zombieManager = ZombieManager::GetI();
	CollisionManager* collisionManager = CollisionManager::GetI();
	Store* store = Store::GetI();
	Player* player = Player::GetI();
	LawnMowerManager* mowerManager = LawnMowerManager::GetI();

	AddManager(gameBoard);
	AddManager(plantManager);
	AddManager(sunlightManager);
	AddManager(bulletManager);
	AddManager(zombieManager);
	AddManager(collisionManager);
	AddManager(store);
	AddManager(player);
	AddManager(mowerManager);

	Link(m_mainGame);
}

void ManagerManager::Link(MainGame* p_mainGame)
{
	dynamic_cast<GameBoard*>(m_managers[GAMEBOARD_INDEX])->Link(m_mainGame);
	dynamic_cast<SunlightManager*>(m_managers[SUNLIGHT_MANAGER_INDEX])->Link(m_mainGame);
	dynamic_cast<ZombieManager*>(m_managers[ZOMBIE_MANAGER_INDEX])->Link(m_mainGame);
	dynamic_cast<Store*>(m_managers[STORE_INDEX])->Link(m_mainGame);
}

void ManagerManager::Update()
{
	for (auto* manager : m_managers)
	{
		manager->Update();
	}
}

void ManagerManager::ClickHandle()
{
	for (auto* manager : m_managers)
	{
		manager->ClickHandle();
	}
}

void ManagerManager::Draw(HDC p_hdc)
{
	for (auto* manager : m_managers)
	{
		manager->Draw(p_hdc);
	}
}

void ManagerManager::AddManager(BaseManager* p_manager)
{
	m_managers.push_back(p_manager);
}

const vector<BaseManager*>& ManagerManager::GetManagers() const
{
	return m_managers;
}
