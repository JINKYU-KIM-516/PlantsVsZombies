#include "Zombie.h"

void Zombie::Move()
{
	m_location.SetX(m_location.GetX() - m_moveSpeed);
}

Zombie::Zombie(Point p_pos)
	:PictureBox(p_pos, Size(ZOMBIE_SIZE, ZOMBIE_SIZE), IMAGEPATH_ZOMBIE)
{
	m_hp = 100;
	m_attackPower = 25;
	m_attackSpeed = 1;
	m_moveSpeed = 50;
}
