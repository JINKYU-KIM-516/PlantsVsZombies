#pragma once
#include "PictureBox.h"

class Plant : public PictureBox
{
protected:
	int m_hp;
	bool m_isAlive;

	void CheckAlive();
public:
	Plant(Point p_pos, Size p_size, const wstring& p_imagePath);
	virtual ~Plant();
	virtual void Init(Point p_pos);
	virtual void Update();

	void TakeDamage(int p_damage);
	bool IsAlive();
};