#define TILE_WIDTH 64
#define TILE_HEIGHT 64
#define TILE_SIZE Size(TILE_WIDTH, TILE_HEIGHT)

#define PLANT_WIDTH 64
#define PLANT_HEIGHT 64
#define PLANT_SIZE Size(PLANT_WIDTH, PLANT_HEIGHT)

#define SUNLIGHT_WIDTH 32
#define SUNLIGHT_HEIGHT 32
#define SUNLIGHT_SIZE Size(SUNLIGHT_WIDTH, SUNLIGHT_HEIGHT)

#define BULLET_WIDTH 16
#define BULLET_HEIGHT 16
#define BULLET_SIZE Size(BULLET_WIDTH, BULLET_HEIGHT)

#define ZOMBIE_WIDTH 47
#define ZOMBIE_HEIGHT 64
#define ZOMBIE_SIZE Size(ZOMBIE_WIDTH, ZOMBIE_HEIGHT)

#define GAMEBOAORD_WIDTH 10
#define GAMEBOAORD_HEIGHT 5

#define TRANSPARENT_COLOR RGB(255,50,150) //ũ�θ�Ű�� ��ũ
#define DEFAULT_LOCATION Point(0, 0)

//****�̹��� ���****
//���Ӻ���(Ÿ��) �̹���
#define IMAGEPATH_GAMEBOARD_GRASS L"../Resources_PlantsVsZombies_bmp/GameBoard_Grass.bmp"

//�Ĺ� �̹���
#define IMAGEPATH_SUNFLOWER L"../Resources_PlantsVsZombies_bmp/Plant_Sunflower.bmp"
#define IMAGEPATH_PEA L"../Resources_PlantsVsZombies_bmp/Plant_Pea.bmp"

//�޺� �̹���
#define IMAGEPATH_SUNLIGHT L"../Resources_PlantsVsZombies_bmp/sunlight.bmp"

//�Ѿ� �̹���
#define IMAGEPATH_BULLET_PEA L"../Resources_PlantsVsZombies_bmp/Bullet_Pea.bmp"

//���� �̹���
#define IMAGEPATH_ZOMBIE L"../Resources_PlantsVsZombies_bmp/Zombie.bmp"

//****�ֱ� �ð�****
//���� ��ȯ �ֱ�
#define INTERVAL_SEC_SPAWN_ZOMBIE 5

//�Ѿ� ��ȯ �ֱ�
#define INTERVAL_SEC_SPAWN_BULLET_PEA 2

//****�̵��ӵ�****
#define MOVESPEED_SUNLIGHT 2
#define MOVESPEED_BULLET_PEA 5
#define MOVESPEED_ZOMBIE 1

//****������****
#define ATTACKPOWER_ZOMBIE 15
#define ATTACKPOWER_PEA 25

//****���ݼӵ�****
#define ATTACKSPEED_ZOMBIE 1