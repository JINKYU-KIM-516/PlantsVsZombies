#include "BaseZombie.h"
#include <iostream>
#include <string>

//protected
void BaseZombie::Move()
{
	m_moveIntervalCount++;
	if (m_moveInterval <= m_moveIntervalCount)
	{
		m_position.DecreaseX(m_moveSpeed);
		m_moveIntervalCount = 0;
	}
}

void BaseZombie::ResetState()
{
	m_state = ZombieState::NORMAL;
	m_attackSpeed = ZOMBIE_ATTACKSPEED;
	m_attackTimer.Init(m_attackSpeed);
	m_moveInterval = 1;
	SetImage(m_basicImagePath);
}

void BaseZombie::CheckAlive()
{
	if (m_hp <= 0)
		m_isAlive = false;
}


void BaseZombie::CheckState()
{
	if (m_frozenDuration.HasElapsed())
		ResetState();
}


//public
BaseZombie::BaseZombie(int p_hp, int p_ap, int p_as, int p_ms, wstring p_imagePath)
	:PictureBox(DEFAULT_POSITION, ZOMBIE_SIZE, p_imagePath)
{
	m_basicImagePath = p_imagePath;
	wstring tempStr = m_basicImagePath;
	tempStr.replace(tempStr.length() - 4, 4, L"_Frozen.bmp");
	m_frozenImagePath = tempStr;
	m_hp = p_hp;
	m_attackPower = p_ap;
	m_attackSpeed = p_as;
	m_moveSpeed = p_ms;
	m_moveInterval = 1;
	m_moveIntervalCount = 0;
	m_state = ZombieState::NORMAL;

	m_isAlive = true;
	m_isAttacking = false;

	m_plant = nullptr;
	m_attackTimer.Init(m_attackSpeed);
	m_frozenDuration.Init(DURATION_FROZEN_BY_ICEPEA);
}

BaseZombie::BaseZombie(int p_hp, int p_ap, int p_as, int p_ms, wstring p_imagePath, wstring p_frozenIP)
	:PictureBox(DEFAULT_POSITION, ZOMBIE_SIZE, p_imagePath)
{
	m_basicImagePath = p_imagePath;
	m_frozenImagePath = p_frozenIP;

	m_hp = p_hp;
	m_attackPower = p_ap;
	m_attackSpeed = p_as;
	m_moveSpeed = p_ms;
	m_moveInterval = 1;
	m_moveIntervalCount = 0;
	m_state = ZombieState::NORMAL;

	m_isAlive = true;
	m_isAttacking = false;

	m_plant = nullptr;
	m_attackTimer.Init(m_attackSpeed);
	m_frozenDuration.Init(DURATION_FROZEN_BY_ICEPEA);
}

void BaseZombie::Init(Point p_pos)
{
	m_position = p_pos;
	/*
	for (size_t i = 0; i < (int)ZombieState::MAX; i++)
	{
		//m_StateFN[(int)ZombieState::NORMAL] = "SetState"+"NORMAL";
	}
	*/
}

void BaseZombie::Update()
{
	CheckAlive();
	CheckState();
	if (!m_isAttacking)
		Move();
	else
		Attack();
}

void BaseZombie::Attack()
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

int BaseZombie::GetAttackPower()
{
	return m_attackPower;
}

bool BaseZombie::IsAlive()
{
	return m_isAlive;
}

bool BaseZombie::IsAttacking()
{
	return m_isAttacking;
}

void BaseZombie::SetStateFrozen()
{
	m_state = ZombieState::FROZEN;
	m_attackSpeed = ZOMBIE_ATTACKSPEED * 2;
	m_attackTimer.Init(m_attackSpeed);
	m_moveInterval = 2;
	SetImage(m_frozenImagePath);
	m_frozenDuration.Tick();
}

void BaseZombie::SetState(ZombieState p_state)
{
	m_state = p_state;
	/*
	if(m_StateFN[(int)m_state] != nullptr)
		m_StateFN[(int)m_state]()

	if (m_state == ZombieState::FROZEN)
	{
		SetStateFrozen();
	}
	*/
}

void BaseZombie::Target(Plant* p_plant)
{
	m_plant = p_plant;
	m_isAttacking = true;
}

void BaseZombie::TakeDamage(int p_damage)
{
	m_hp -= p_damage;
}

void BaseZombie::StopAttacking()
{
	m_plant = nullptr;
	m_isAttacking = false;
}
