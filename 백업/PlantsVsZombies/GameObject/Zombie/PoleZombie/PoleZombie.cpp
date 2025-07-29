#include "PoleZombie.h"

void PoleZombie::UpdatePolePos()
{
	if (m_pole)
	{
		Point pos = Point(m_position.GetX(), m_position.GetY());
		pos.DecreaseX(ZOMBIE_WIDTH);
		pos.IncreaseY(ZOMBIE_HEIGHT - 22);
		m_pole->Update(pos);
	}
}

void PoleZombie::CheckPole()
{
	if (m_plant && m_pole)
	{
		m_hasPole = false;
		m_position.DecreaseX(PLANT_WIDTH + ZOMBIE_WIDTH);
		m_plant = nullptr;
		delete m_pole;
		m_pole = nullptr;
		m_isAttacking = false;
	}
}

PoleZombie::PoleZombie()
	:BaseZombie(POLE_ZOMBIE_HEALTHPOINT, POLE_ZOMBIE_ATTACKPOWER, POLE_ZOMBIE_ATTACKSPEED, POLE_ZOMBIE_MOVESPEED, POLE_ZOMBIE_IMAGEPATH, POLE_ZOMBIE_FROZEN_IMAGEPATH)
{
	m_pole = new Pole();
	m_hasPole = true;
	Init(m_position);
}

void PoleZombie::Update()
{
	CheckAlive();
	CheckPole();
	UpdatePolePos();
	CheckState();
	if (!m_isAttacking)
		Move();
	else
		Attack();
}

void PoleZombie::Draw(HDC p_hdc)
{
	PictureBox::Draw(p_hdc);
	if (m_pole)
		m_pole->Draw(p_hdc);
}