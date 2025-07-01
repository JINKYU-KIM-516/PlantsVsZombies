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

#define TRANSPARENT_COLOR RGB(255,50,150) //크로마키용 핑크
#define DEFAULT_LOCATION Point(0, 0)

//****이미지 경로****
//게임보드(타일) 이미지
#define IMAGEPATH_GAMEBOARD_GRASS L"../Resources_PlantsVsZombies_bmp/GameBoard_Grass.bmp"

//식물 이미지
#define IMAGEPATH_SUNFLOWER L"../Resources_PlantsVsZombies_bmp/Plant_Sunflower.bmp"
#define IMAGEPATH_PEA L"../Resources_PlantsVsZombies_bmp/Plant_Pea.bmp"

//햇빛 이미지
#define IMAGEPATH_SUNLIGHT L"../Resources_PlantsVsZombies_bmp/sunlight.bmp"

//총알 이미지
#define IMAGEPATH_BULLET_PEA L"../Resources_PlantsVsZombies_bmp/Bullet_Pea.bmp"

//좀비 이미지
#define IMAGEPATH_ZOMBIE L"../Resources_PlantsVsZombies_bmp/Zombie.bmp"

//****주기 시간****
//햇빛 소환 주기
#define INTERVAL_SEC_SPAWN_SUNLIGHT 4

//총알 소환 주기
#define INTERVAL_SEC_SPAWN_BULLET_PEA 2

//좀비 소환 주기
#define INTERVAL_SEC_SPAWN_ZOMBIE 5

//****이동속도****
#define MOVESPEED_SUNLIGHT 2
#define MOVESPEED_BULLET_PEA 5
#define MOVESPEED_ZOMBIE 1

//****전투력****
#define ATTACKPOWER_ZOMBIE 15
#define ATTACKPOWER_PEA 25

//****공격속도****
#define ATTACKSPEED_ZOMBIE 1