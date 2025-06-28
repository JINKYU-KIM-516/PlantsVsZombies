#pragma once
#include "PictureBox.h"
#include "Constants.h"

class Plant : public PictureBox
{
protected:
	int m_hp;
public:
	Plant(Point p_pos, Size p_size, const wstring& p_imagePath);
};