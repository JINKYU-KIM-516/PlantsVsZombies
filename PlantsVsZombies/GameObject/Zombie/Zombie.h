#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
#include "../../CoreFunction/IntervalTimer/IntervalTimer.h"
#include "../Plant/Plant.h"

using namespace std;

class Zombie : public PictureBox
{
protected:
	IntervalTimer m_attackTimer;
	IntervalTimer m_frozenDuration;
	Plant* m_plant;

	int m_hp;
	int m_attackSpeed;
	int m_attackPower;
	int m_moveSpeed;
	ZombieState m_state;

	bool m_isAlive;
	bool m_isAttacking;

	void Move();

	void CheckAlive();
	void ResetState();
public:
	Zombie();
	void Init(Point p_pos);
	void Update();

	void Attack();

	int GetAttackPower();
	bool IsAlive();	
	bool IsAttacking();

	void SetStateFrozen();

	void Target(Plant* p_plant);
	void TakeDamage(int p_damage);
	void StopAttacking();
};