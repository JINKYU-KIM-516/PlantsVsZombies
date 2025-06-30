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

	bool m_isAlive;

	void Move();

	void CheckAlive();
public:
	Zombie();
	void Init(Point p_pos);
	void Update();
	void TakeDamage(int p_damage);

	int GetAttackPower();
	bool IsAlive();
};