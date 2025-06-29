#pragma once
#include <vector>
#include <algorithm>
#include "Bullet.h"

using namespace std;

class BulletManager
{
protected:
	vector<Bullet*> m_bullets;
public:
    ~BulletManager();
    void Update();

    void AddBullets(Bullet* p_bullet);
    void DeleteBullets();
    const vector<Bullet*>& GetBullets() const;
};