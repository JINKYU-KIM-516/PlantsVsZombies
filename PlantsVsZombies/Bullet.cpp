#include "Bullet.h"

void Bullet::Move()
{
	m_location.SetX(m_location.GetX() + m_moveSpeed);
}

Bullet::Bullet(Point p_pos, Size p_size, const wstring& p_imagePath)
	:PictureBox(p_pos, p_size, p_imagePath)
{
	m_attackPower = 0;
	m_moveSpeed = 0;
}

void Bullet::Init(int p_ap, int p_ms)
{
	m_attackPower = p_ap;
	m_moveSpeed = p_ms;
}

void Bullet::Update()
{
	Move();
	/*
	if (m_location.GetX() > (GAMEBOAORD_WIDTH + 1) * TILE_WIDTH)
	{
		delete this;
	}
	*/
}