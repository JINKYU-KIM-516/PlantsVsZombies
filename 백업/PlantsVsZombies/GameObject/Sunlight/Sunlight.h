#pragma once
#include "../../CoreFunction//PictureBox/PictureBox.h"

class Sunlight : public PictureBox
{
protected:
	int m_moveSpeed;
	int m_limitY;

	void Move();
public:
	Sunlight();
	void Init(Point p_pos, int p_limitY);
	void Update();
};