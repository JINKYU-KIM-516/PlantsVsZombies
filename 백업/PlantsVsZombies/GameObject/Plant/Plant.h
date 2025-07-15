#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"

class Plant : public PictureBox
{
protected:
	float m_hp;
	bool m_isAlive;

	void CheckAlive();
public:
	Plant(Point p_pos, Size p_size, const wstring& p_imagePath);
	virtual ~Plant();
	virtual void Init(float p_hp);
	virtual void Update();

	void TakeDamage(float p_damage);
	bool IsAlive();
};