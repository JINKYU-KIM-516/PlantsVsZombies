#pragma once
#include "PictureBox.h"

using namespace std;

class Zombie : public PictureBox
{
protected:
	int m_hp;
	int m_attackSpeed;
	int m_attackPower;
	int m_moveSpeed;

	void Move();
public:
	Zombie(Point p_pos);
	void Update();
	void TakeDamage(int p_damage);
	int GetAttackPower();
};