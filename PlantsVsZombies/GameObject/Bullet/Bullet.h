#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
#include "../Zombie/Zombie.h"

class Bullet : public PictureBox
{
protected:
	float m_attackPower;
	float m_moveSpeed;

	void Move();
public:
	Bullet(Point p_pos, Size p_size, const wstring& p_imagePath);
	virtual ~Bullet();
	void Init(float p_ap, float p_ms);
	void Update();

	virtual void Active(Zombie* p_zombie);

	float GetAttackPower();
};