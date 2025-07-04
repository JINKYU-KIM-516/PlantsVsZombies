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
    void Update() override;
    void Draw(HDC p_hdc) override;

    void AddBullets(Bullet* p_bullet);
    void DeleteBullet(Bullet* p_bullet);
    const vector<Bullet*>& GetBullets() const;
};