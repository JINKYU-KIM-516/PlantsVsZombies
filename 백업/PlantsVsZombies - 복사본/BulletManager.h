#pragma once
#include "BaseManager.h"
#include <vector>
#include <algorithm>
#include "Bullet.h"

using namespace std;

class BulletManager : public BaseManager
{
protected:
    vector<Bullet*> m_bullets;

    void CheckBulletsInScreen();
public:
    ~BulletManager();
    void Init() override;
    void Link() override;
    void Update() override;

    void AddBullets(Bullet* p_bullet);
    void DeleteBullet(Bullet* p_bullet);
    const vector<Bullet*>& GetBullets() const;
};