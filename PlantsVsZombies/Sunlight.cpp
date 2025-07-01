#include "Sunlight.h"
//protected
void Sunlight::Move()
{
	if(m_location.GetY() < m_limitY)
		m_location.SetY(m_location.GetY() + m_moveSpeed);
}

//public
Sunlight::Sunlight()
	:PictureBox(DEFAULT_LOCATION, SUNLIGHT_SIZE, IMAGEPATH_SUNLIGHT)
{
	m_moveSpeed = MOVESPEED_SUNLIGHT;
	m_limitY = 0;
}

void Sunlight::Init(Point p_pos, int p_limitY)
{
	m_location = p_pos;
	m_limitY = p_limitY;
}

void Sunlight::Update()
{
	Move();
}