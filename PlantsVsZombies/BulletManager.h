#pragma once
#include <vector>
#include <algorithm>
#include "Bullet.h"

using namespace std;

class BulletManager
{
protected:
    vector<Bullet*> m_bullets;

    void CheckBulletsInScreen();
public:
    ~BulletManager();
    void Update();

    void AddBullets(Bullet* p_bullet);
    void DeleteBullet(Bullet* p_bullet);
    const vector<Bullet*>& GetBullets() const;
};