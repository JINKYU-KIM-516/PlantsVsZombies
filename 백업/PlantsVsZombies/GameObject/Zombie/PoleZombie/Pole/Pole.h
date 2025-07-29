#pragma once
#include "../../../../CoreFunction/PictureBox/PictureBox.h"
class Pole : public PictureBox
{
public:
	Pole();
	void Init(Point p_pos);
	void Update(Point p_pos);
	void Deleted();
};