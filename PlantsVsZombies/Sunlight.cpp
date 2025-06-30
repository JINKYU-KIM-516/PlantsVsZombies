#include "Sunlight.h"
//protected
void Sunlight::Move()
{
	m_location.SetY(m_location.GetY() - m_moveSpeed);
}

//public
Sunlight::Sunlight()
	:PictureBox(DEFAULT_LOCATION, SUNLIGHT_SIZE, IMAGEPATH_SUNLIGHT)
{
	m_moveSpeed = MOVESPEED_SUNLIGHT;
}

void Sunlight::Init(Point p_pos)
{
	m_location = p_pos;
}

void Sunlight::Update()
{
	Move();
}