#include "IcePeaBullet.h"

IcePeaBullet::IcePeaBullet(Point p_pos)
	:Bullet(p_pos, BULLET_SIZE, IMAGEPATH_ICEPEA_BULLET)
{

}

void IcePeaBullet::Active(Zombie* p_zombie)
{
	p_zombie->SetStateFrozen();
}
