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

	float m_hp;
	float m_attackSpeed;
	float m_attackPower;
	float m_moveSpeed;
	ZombieState m_state;

	bool m_isAlive;
	bool m_isAttacking;

	void Move();
	void ResetState();

	void CheckAlive();
	void CheckState();
public:
	Zombie();
	void Init(Point p_pos);
	void Update();

	void Attack();

	float GetAttackPower();
	bool IsAlive();	
	bool IsAttacking();

	void SetStateFrozen();

	void Target(Plant* p_plant);
	void TakeDamage(float p_damage);
	void StopAttacking();
};