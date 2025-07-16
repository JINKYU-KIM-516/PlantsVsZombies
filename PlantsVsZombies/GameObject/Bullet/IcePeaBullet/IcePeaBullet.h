#pragma once
#include "../Bullet.h"

class IcePeaBullet : public Bullet
{
public:
	IcePeaBullet(Point p_pos);
	void Active(BaseZombie* p_zombie) override;
};

