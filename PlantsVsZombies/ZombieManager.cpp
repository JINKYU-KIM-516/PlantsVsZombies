#include "ZombieManager.h"
#include "Field.h"  // 만약 타일 참조 필요시

void ZombieManager::Init() {
    m_lastSpawnTime = std::chrono::steady_clock::now();
}

void ZombieManager::Update() {
    for (auto* z : m_zombies)
        z->Move();

    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::seconds>(now - m_lastSpawnTime).count() >= 5) {
        int row = rand() % 5;
        int x = 800; // 예: 오른쪽 끝 위치
        int y = 100 + row * 64; // 예: 행에 따라 y 위치 계산
        m_zombies.push_back(new Zombie(Point(x, y)));
        m_lastSpawnTime = now;
    }
}

void ZombieManager::Draw(HDC hdc) {
    for (auto* z : m_zombies)
        z->Draw(hdc);
}

const std::vector<Zombie*>& ZombieManager::GetZombies() const {
    return m_zombies;
}

ZombieManager::~ZombieManager() {
    for (auto* z : m_zombies)
        delete z;
}
