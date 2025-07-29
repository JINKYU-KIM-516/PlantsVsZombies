#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
//#include "../Zombie/Zombie.h"

class BaseZombie;

class Bullet : public PictureBox
{
protected:
	int m_attackPower;
	int m_moveSpeed;

	void Move();
public:
	Bullet(Point p_pos, Size p_size, const wstring p_imagePath);
	virtual ~Bullet();
	void Init(int p_ap, int p_ms);
	void Update();

	virtual void Active(BaseZombie* p_zombie);

	int GetAttackPower();
};