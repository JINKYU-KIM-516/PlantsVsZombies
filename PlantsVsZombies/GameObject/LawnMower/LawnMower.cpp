#include "LawnMower.h"

void LawnMower::Move()
{
	m_position.IncreaseX(m_moveSpeed);
}

LawnMower::LawnMower()
	:PictureBox(DEFAULT_POSITION, LAWNMOWER_SIZE, LAWNMOWER_IMAGEPATH)
{
	Init(DEFAULT_POSITION);
}

void LawnMower::Init(Point p_pos)
{
	m_activing = false;
	m_moveSpeed = LAWNMOWER_MOVESPEED;
	m_position = p_pos;
}

void LawnMower::Update()
{
	if (m_activing)
		Move();
}

void LawnMower::StartActiving()
{
	m_activing = true;
}

bool LawnMower::IsActiving()
{
	return m_activing;
}
