#pragma once

enum PlayerState
{
	PLAYER_STATE_NORMAL, PLAYER_STATE_SELECTING
};

enum PlantCode
{
	CODE_SUNFLOWER = 1,
	CODE_PEA = 2,
	CODE_ICEPEA = 3
};

enum ManagerIndex
{
	GAMEBOARD_INDEX,
	PLANT_MANAGER_INDEX,
	SUNLIGHT_MANAGER_INDEX,
	BULLET_MANAGER_INDEX,
	ZOMBIE_MANAGER_INDEX,
	COLLISION_MANAGER_INDEX,
	STORE_INDEX,
	PLAYER_INDEX
};

enum StorePlantIndex
{
	SUNFLOWER_INDEX,
	PEA_INDEX,
	ICEPEA_INDEX
};

enum ZombieState
{
	ZOMBIE_STATE_NORMAL, ZOMBIE_STATE_FROZEN
};

#define COST_SUNFLOWER 50
#define COST_PEA 100
#define COST_ICEPEA 150

#define TILE_WIDTH 64
#define TILE_HEIGHT 64
#define TILE_SIZE Size(TILE_WIDTH, TILE_HEIGHT)

#define PLANT_WIDTH 64
#define PLANT_HEIGHT 64
#define PLANT_SIZE Size(PLANT_WIDTH, PLANT_HEIGHT)

#define SUNLIGHT_WIDTH 40
#define SUNLIGHT_HEIGHT 40
#define SUNLIGHT_SIZE Size(SUNLIGHT_WIDTH, SUNLIGHT_HEIGHT)

#define BULLET_WIDTH 16
#define BULLET_HEIGHT 16
#define BULLET_SIZE Size(BULLET_WIDTH, BULLET_HEIGHT)

#define ZOMBIE_WIDTH 47
#define ZOMBIE_HEIGHT 64
#define ZOMBIE_SIZE Size(ZOMBIE_WIDTH, ZOMBIE_HEIGHT)

#define GAMEBOARD_START_X 64
#define GAMEBOARD_START_Y 90
#define GAMEBOARD_START_LOCATION Point(GAMEBOARD_START_X, GAMEBOARD_START_Y)

#define GAMEBOARD_WIDTH 10
#define GAMEBOARD_HEIGHT 5

#define TRANSPARENT_COLOR RGB(255,50,150) //ũ�θ�Ű�� ��ũ
#define DEFAULT_POSITION Point(0, 0)
#define INVISIBLE_POS Point(-512, -512)

//****�̹��� ���****
//���Ӻ���(Ÿ��) �̹���
#define IMAGEPATH_GAMEBOARD_GROUND_BRIGHTER L"../Bmp_Resources_ver2/UI/Ground_Brighter.bmp"
#define IMAGEPATH_GAMEBOARD_GROUND_DARKER L"../Bmp_Resources_ver2/UI/Ground_Darker.bmp"

//�Ĺ� �̹���
#define IMAGEPATH_SUNFLOWER L"../Bmp_Resources_ver2/Plant/Sunflower/Sunflower.bmp"
#define IMAGEPATH_SUNFLOWER_GRAYSCALE L"../Bmp_Resources_ver2/Plant/Sunflower/Sunflower_Grayscale.bmp"
#define IMAGEPATH_PEA L"../Bmp_Resources_ver2/Plant/Pea/Pea.bmp"
#define IMAGEPATH_PEA_GRAYSCALE L"../Bmp_Resources_ver2/Plant/Pea/Pea_Grayscale.bmp"
#define IMAGEPATH_NUT L"../Bmp_Resources_ver2/Plant/Nut/Nut.bmp"
#define IMAGEPATH_NUT_GRAYSCALE L"../Bmp_Resources_ver2/Plant/Nut/Nut_Grayscale.bmp"
#define IMAGEPATH_NUT_DAMAGED L"../Bmp_Resources_ver2/Plant/Nut/Nut_Damaged.bmp"
#define IMAGEPATH_NUT_EMERGENCY L"../Bmp_Resources_ver2/Plant/Nut/Nut_Emergency.bmp"
#define IMAGEPATH_ICEPEA L"../Bmp_Resources_ver2/Plant/IcePea/IcePea.bmp"
#define IMAGEPATH_ICEPEA_GRAYSCALE L"../Bmp_Resources_ver2/Plant/IcePea/IcePea_Grayscale.bmp"

//�޺� �̹���
#define IMAGEPATH_SUNLIGHT L"../Bmp_Resources_ver2/Sunlight/Sunlight.bmp"

//�Ѿ� �̹���
#define IMAGEPATH_PEA_BULLET L"../Bmp_Resources_ver2/Bullet/PeaBullet.bmp"
#define IMAGEPATH_ICEPEA_BULLET L"../Bmp_Resources_ver2/Bullet/IcePeaBullet.bmp"

//���� �̹���
#define IMAGEPATH_ZOMBIE L"../Bmp_Resources_ver2/Zombie/Zombie.bmp"
#define IMAGEPATH_FUNNEL_ZOMBIE L"../Bmp_Resources_ver2/Zombie/FunnelZombie.bmp"

//****�ֱ� �ð�****
//�޺� ��ȯ �ֱ�
#define INTERVAL_SEC_SPAWN_SUNLIGHT 4

//���� ��ȯ �ֱ�
#define INTERVAL_SEC_SPAWN_ZOMBIE 5

//****�̵��ӵ�****
#define MOVESPEED_SUNLIGHT 2
#define MOVESPEED_BULLET_PEA 5
#define MOVESPEED_ZOMBIE 1

//****������****
#define ATTACKPOWER_ZOMBIE 15
#define ATTACKPOWER_PEA 25
#define ATTACKPOWER_ICEPEA 25


//****���ݼӵ�****
#define ATTACKSPEED_ZOMBIE 1
#define ATTACKSPEED_PEA 2
#define ATTACKSPEED_ICEPEA 3

//****�����̻�****
#define DURATION_FROZEN_BY_ICEPEA 5