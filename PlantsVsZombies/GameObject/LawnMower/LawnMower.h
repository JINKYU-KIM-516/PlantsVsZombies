#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
class LawnMower : public PictureBox
{
protected:
	int m_moveSpeed;
	bool m_activing;

	void Move();
public:
	LawnMower();
	void Init(Point p_pos);
	void Update();

	void StartActiving();
	bool IsActiving();
};

