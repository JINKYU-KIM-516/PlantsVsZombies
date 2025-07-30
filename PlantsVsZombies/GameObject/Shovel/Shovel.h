#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"

class Shovel : public PictureBox
{
public:
	Shovel();
	void Init(Point p_pos);
	void Update(Point p_pos);
};