#include "Zombie.h"
#include "Bullet.h"
//protected
void Zombie::Move()
{
	m_positon.SetX(m_positon.GetX() - m_moveSpeed);
}

void Zombie::CheckAlive()
{
	if (m_hp <= 0)
		m_isAlive = false;
}

//public
Zombie::Zombie()
	:PictureBox(DEFAULT_POSITION, ZOMBIE_SIZE, IMAGEPATH_ZOMBIE)
{
	m_hp = 100;
	m_attackPower = ATTACKPOWER_ZOMBIE;
	m_attackSpeed = ATTACKSPEED_ZOMBIE;
	m_moveSpeed = MOVESPEED_ZOMBIE;
	m_isAlive = true;
	m_isAttacking = false;
}
void Zombie::Init(Point p_pos)
{
	m_positon = p_pos;
	m_attackTimer.Init(m_attackSpeed);
}
void Zombie::Update()
{
	CheckAlive();
	if (!m_isAttacking)
		Move();
	else
		Attack();
}

void Zombie::Attack()
{
	if (m_attackTimer.HasElapsed())
	{
		m_plant->TakeDamage(m_attackPower);
		m_attackTimer.Tick();
	}
	if (!m_plant->IsAlive())
	{
		StopAttacking();
	}
}

int Zombie::GetAttackPower()
{
	return m_attackPower;
}

bool Zombie::IsAlive()
{
	return m_isAlive;
}

bool Zombie::IsAttacking()
{
	return m_isAttacking;
}

void Zombie::Target(Plant* p_plant)
{
	m_plant = p_plant;
	m_isAttacking = true;
}

void Zombie::TakeDamage(int p_damage)
{
	m_hp -= p_damage;
}

void Zombie::StopAttacking()
{
	m_plant = nullptr;
	m_isAttacking = false;
}
