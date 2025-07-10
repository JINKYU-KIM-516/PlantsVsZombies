#pragma once
#include "PictureBox.h"

class Bullet : public PictureBox
{
protected:
	int m_attackPower;
	int m_moveSpeed;

	void Move();
public:
	Bullet(Point p_pos, Size p_size, const wstring& p_imagePath);
	void Init(int p_ap, int p_ms);
	void Update();

	int GetAttackPower();
};