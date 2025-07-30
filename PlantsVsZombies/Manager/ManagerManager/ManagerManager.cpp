#include "ManagerManager.h"
#include "../../Main/MainGame.h"

ManagerManager::ManagerManager()
{
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
