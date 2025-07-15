#include "Zombie.h"

//protected
void Zombie::Move()
{
	m_positon.SetX(m_positon.GetX() - m_moveSpeed);
}

void Zombie::ResetState()
{
	m_state = ZOMBIE_STATE_NORMAL;
	m_attackSpeed = ATTACKSPEED_ZOMBIE;
	m_moveSpeed = MOVESPEED_ZOMBIE;
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
	/*
	switch (m_state)
	{
	case ZOMBIE_STATE_NORMAL:
		m_attackSpeed = ATTACKSPEED_ZOMBIE;
		m_moveSpeed = MOVESPEED_ZOMBIE;
		break;
	case ZOMBIE_STATE_FROZEN:
		m_attackSpeed = ATTACKSPEED_ZOMBIE / 2;
		m_moveSpeed = MOVESPEED_ZOMBIE / 2;
		break;
	}
	*/
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
	m_plant = nullptr;
	m_state = ZOMBIE_STATE_NORMAL;
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

float Zombie::GetAttackPower()
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
	m_attackSpeed = ATTACKSPEED_ZOMBIE / 2;
	m_moveSpeed = MOVESPEED_ZOMBIE / 2;
	m_frozenDuration.Tick();
}

void Zombie::Target(Plant* p_plant)
{
	m_plant = p_plant;
	m_isAttacking = true;
}

void Zombie::TakeDamage(float p_damage)
{
	m_hp -= p_damage;
}

void Zombie::StopAttacking()
{
	m_plant = nullptr;
	m_isAttacking = false;
}
