#include "Bullet.h"

//protected
void Bullet::Move()
{
	m_positon.SetX(m_positon.GetX() + m_moveSpeed);
}

//public
Bullet::Bullet(Point p_pos, Size p_size, const wstring& p_imagePath)
	:PictureBox(p_pos, p_size, p_imagePath)
{
	m_attackPower = 0;
	m_moveSpeed = 0;
}

Bullet::~Bullet()
{

}

void Bullet::Init(float p_ap, float p_ms)
{
	m_attackPower = p_ap;
	m_moveSpeed = p_ms;
}

void Bullet::Update()
{
	Move();
}

float Bullet::GetAttackPower()
{
	return m_attackPower;
}
