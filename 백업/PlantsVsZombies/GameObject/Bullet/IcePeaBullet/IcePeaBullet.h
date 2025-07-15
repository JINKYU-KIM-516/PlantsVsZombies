#pragma once
#include "../Bullet.h"

class IcePeaBullet : public Bullet
{
public:
	IcePeaBullet(Point p_pos);
	void Active(Zombie* p_zombie) override;
};

