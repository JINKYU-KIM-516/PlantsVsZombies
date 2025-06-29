#pragma once
#include <vector>
#include "Bullet.h"

using namespace std;

class BulletManager
{
protected:
	vector<Bullet*> m_bullets;
public:
    ~BulletManager();

    void AddBullets(Bullet* p_bullet);
    const vector<Bullet*>& GetBullets() const;
};