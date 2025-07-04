#include "Sunlight.h"
//protected
void Sunlight::Move()
{
	if(m_positon.GetY() < m_limitY)
		m_positon.SetY(m_positon.GetY() + m_moveSpeed);
}

//public
Sunlight::Sunlight()
	:PictureBox(DEFAULT_POSITION, SUNLIGHT_SIZE, IMAGEPATH_SUNLIGHT)
{
	m_moveSpeed = MOVESPEED_SUNLIGHT;
	m_limitY = 0;
}

void Sunlight::Init(Point p_pos, int p_limitY)
{
	m_positon = p_pos;
	m_limitY = p_limitY;
}

void Sunlight::Update()
{
	Move();
}