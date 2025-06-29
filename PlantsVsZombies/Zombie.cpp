#include "Zombie.h"
#include "Bullet.h"

Zombie::Zombie(Point p_pos)
	:PictureBox(p_pos, ZOMBIE_SIZE, IMAGEPATH_ZOMBIE)
{
	m_hp = 100;
	m_attackPower = ATTACKPOWER_ZOMBIE;
	m_attackSpeed = 1;
	m_moveSpeed = MOVESPEED_ZOMBIE;
}

void Zombie::Update()
{
	Move();
}

void Zombie::Move()
{
	m_location.SetX(m_location.GetX() - m_moveSpeed);
}