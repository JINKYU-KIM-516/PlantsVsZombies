#include "Zombie.h"
#include "Bullet.h"
//protected
void Zombie::Move()
{
	m_location.SetX(m_location.GetX() - m_moveSpeed);
}

void Zombie::CheckAlive()
{
	if (m_hp <= 0)
		m_isAlive = false;
}

//public
Zombie::Zombie()
	:PictureBox(DEFAULT_LOCATION, ZOMBIE_SIZE, IMAGEPATH_ZOMBIE)
{
	m_hp = 100;
	m_attackPower = ATTACKPOWER_ZOMBIE;
	m_attackSpeed = 1;
	m_moveSpeed = MOVESPEED_ZOMBIE;
	m_isAlive = true;
}
void Zombie::Init(Point p_pos)
{
	m_location = p_pos;
}
void Zombie::Update()
{
	Move();
	CheckAlive();
}

void Zombie::TakeDamage(int p_damage)
{
	m_hp -= p_damage;
}

int Zombie::GetAttackPower()
{
	return m_attackPower;
}

bool Zombie::IsAlive()
{
	return m_isAlive;
}