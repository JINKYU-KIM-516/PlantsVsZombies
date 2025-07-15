#include "Zombie.h"

//protected
void Zombie::Move()
{
	m_moveIntervalCount++;
	if (m_moveInterval <= m_moveIntervalCount)
	{
		m_positon.SetX(m_positon.GetX() - m_moveSpeed);
		m_moveIntervalCount = 0;
	}
}

void Zombie::ResetState()
{
	m_state = ZOMBIE_STATE_NORMAL;
	m_attackSpeed = ATTACKSPEED_ZOMBIE;
	m_attackTimer.Init(m_attackSpeed);
	m_moveInterval = 1;
	SetImage(IMAGEPATH_ZOMBIE);
}

void Zombie::CheckAlive()
{
	if (m_hp <= 0)
		m_isAlive = false;
}


void Zombie::CheckState()
{
	if (m_frozenDuration.HasElapsed())
		ResetState();
}


//public
Zombie::Zombie()
	:PictureBox(DEFAULT_POSITION, ZOMBIE_SIZE, IMAGEPATH_ZOMBIE)
{
	m_hp = 100;
	m_attackPower = ATTACKPOWER_ZOMBIE;
	m_attackSpeed = ATTACKSPEED_ZOMBIE;
	m_moveSpeed = MOVESPEED_ZOMBIE;
	m_moveInterval = 1;
	m_moveIntervalCount = 0;
	m_state = ZOMBIE_STATE_NORMAL;

	m_isAlive = true;
	m_isAttacking = false;

	m_plant = nullptr;
	m_attackTimer.Init(m_attackSpeed);
	m_frozenDuration.Init(DURATION_FROZEN_BY_ICEPEA);
}

void Zombie::Init(Point p_pos)
{
	m_positon = p_pos;
}
void Zombie::Update()
{
	CheckAlive();
	CheckState();
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
	if (m_plant->IsAlive() || m_plant)
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

void Zombie::SetStateFrozen()
{
	m_state = ZOMBIE_STATE_FROZEN;
	m_attackSpeed = ATTACKSPEED_ZOMBIE * 2;
	m_attackTimer.Init(m_attackSpeed);
	m_moveInterval = 2;
	SetImage(IMAGEPATH_ZOMBIE_FROZEN);
	m_frozenDuration.Tick();
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
