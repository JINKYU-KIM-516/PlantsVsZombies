#include "IcePeaBullet.h"
#include "../../Zombie/BaseZombie.h"

IcePeaBullet::IcePeaBullet(Point p_pos)
	:Bullet(p_pos, BULLET_SIZE, ICEPEA_BULLET_IMAGEPATH)
{

}

void IcePeaBullet::Active(BaseZombie* p_zombie)
{
	p_zombie->SetStateFrozen();
}
