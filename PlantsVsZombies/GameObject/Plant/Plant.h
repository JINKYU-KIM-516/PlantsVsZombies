#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"

class Plant : public PictureBox
{
protected:
	int m_hp;
	bool m_isAlive;

	void CheckAlive();
public:
	Plant(Point p_pos, Size p_size, const wstring& p_imagePath);
	virtual ~Plant();
	virtual void Init(int p_hp);
	virtual void Update();

	void TakeDamage(int p_damage);
	bool IsAlive();
};