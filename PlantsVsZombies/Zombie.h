#pragma once
#include "PictureBox.h"
#include "Constants.h"

class Zombie : public PictureBox
{
protected:
	int m_hp;
	int m_attackSpeed;
	int m_attackPower;
	int m_moveSpeed;
	
public:
	Zombie(Point p_pos);
	void Move();
};

