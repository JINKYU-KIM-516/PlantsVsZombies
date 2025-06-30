#pragma once
#include "PictureBox.h"

class Sunlight : public PictureBox
{
protected:
	int m_moveSpeed;

	void Move();
public:
	Sunlight();
	void Init(Point p_pos);
	void Update();
};