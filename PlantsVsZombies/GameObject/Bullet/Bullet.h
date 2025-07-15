#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
#include "../Zombie/Zombie.h"

class Bullet : public PictureBox
{
protected:
	int m_attackPower;
	int m_moveSpeed;

	void Move();
public:
	Bullet(Point p_pos, Size p_size, const wstring& p_imagePath);
	virtual ~Bullet();
	void Init(int p_ap, int p_ms);
	void Update();

	virtual void Active(Zombie* p_zombie);

	int GetAttackPower();
};