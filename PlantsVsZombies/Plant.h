#pragma once
#include "PictureBox.h"

class Plant : public PictureBox
{
protected:
	int m_hp;
public:
	Plant(Point p_pos, Size p_size, const wstring& p_imagePath);
	virtual ~Plant();
	virtual void Update();

	void TakeDamage(int p_damage);
};