#include "Pole.h"

Pole::Pole()
	:PictureBox(DEFAULT_POSITION, POLE_SIZE, POLE_IMAGEPATH)
{

}

void Pole::Init(Point p_pos)
{
	m_position = p_pos;
}
void Pole::Update(Point p_pos)
{
	m_position = p_pos;
}