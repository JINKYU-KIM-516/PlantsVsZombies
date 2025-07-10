#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
#include "../../CoreFunction/IntervalTimer/IntervalTimer.h"
#include "../Plant/Plant.h"

using namespace std;

class Zombie : public PictureBox
{
protected:
	IntervalTimer m_attackTimer;
	Plant* m_plant;

	int m_hp;
	int m_attackSpeed;
	int m_attackPower;
	int m_moveSpeed;

	bool m_isAlive;
	bool m_isAttacking;

	void Move();

	void CheckAlive();
public:
	Zombie();
	void Init(Point p_pos);
	void Update();

	void Attack();

	int GetAttackPower();
	bool IsAlive();	
	bool IsAttacking();

	void Target(Plant* p_plant);
	void TakeDamage(int p_damage);
	void StopAttacking();
};