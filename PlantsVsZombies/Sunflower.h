#pragma once
#include "PictureBox.h"

#include "Constants.h"


class Sunflower : public PictureBox
{
private:
	int m_hp;
public:
	Sunflower(Point p_pos);

	void Init();

};