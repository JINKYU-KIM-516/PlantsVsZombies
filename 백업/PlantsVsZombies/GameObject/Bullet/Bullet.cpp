#include "Bullet.h"

//protected
void Bullet::Move()
{
	m_position.SetX(m_position.GetX() + m_moveSpeed);
}

//public
Bullet::Bullet(Point p_pos, Size p_size, const wstring p_imagePath)
	:PictureBox(p_pos, p_size, p_imagePath)
{
	m_attackPower = 0;
	m_moveSpeed = 0;
}

Bullet::~Bullet()
{

}

void Bullet::Init(int p_ap, int p_ms)
{
	m_attackPower = p_ap;
	m_moveSpeed = p_ms;
}

void Bullet::Update()
{
	Move();
}

void Bullet::Active(BaseZombie* p_zombie)
{

}

int Bullet::GetAttackPower()
{
	return m_attackPower;
}
