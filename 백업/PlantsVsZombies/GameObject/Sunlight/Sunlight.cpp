#include "Sunlight.h"
//protected
void Sunlight::Move()
{
	if(m_position.GetY() < m_limitY)
		m_position.SetY(m_position.GetY() + m_moveSpeed);
}

//public
Sunlight::Sunlight()
	:PictureBox(DEFAULT_POSITION, SUNLIGHT_SIZE, SUNLIGHT_IMAGEPATH)
{
	m_moveSpeed = SUNLIGHT_MOVESPEED;
	m_limitY = 0;
}

void Sunlight::Init(Point p_pos, int p_limitY)
{
	m_position = p_pos;
	m_limitY = p_limitY;
}

void Sunlight::Update()
{
	Move();
}