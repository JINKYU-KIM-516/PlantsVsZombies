#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
#include "../../CoreFunction/IntervalTimer/IntervalTimer.h"
#include "../Plant/Plant.h"

using namespace std;

class BaseZombie : public PictureBox
{
protected:
	IntervalTimer m_attackTimer;
	IntervalTimer m_frozenDuration;
	Plant* m_plant;

	wstring m_basicImagePath;
	wstring m_frozenImagePath;
	int m_hp;
	int m_attackSpeed;
	int m_attackPower;
	int m_moveSpeed;
	int m_moveInterval;
	int m_moveIntervalCount;
	ZombieState m_state;

	//void* m_StateFN[(int)ZombieState::FROZEN + 1];

	bool m_isAlive;
	bool m_isAttacking;

	void Move();
	void ResetState();

	void CheckAlive();
	virtual void CheckState();
public:
	BaseZombie(int p_hp, int p_ap, int p_as, int p_ms, wstring p_imagePath);
	BaseZombie(int p_hp, int p_ap, int p_as, int p_ms, wstring p_imagePath, wstring p_frozenIP);
	void Init(Point p_pos);
	virtual void Update();

	void Attack();

	int GetAttackPower();
	bool IsAlive();	
	bool IsAttacking();

	void SetStateFrozen();
	//void SetStateNORMAL();
	void SetState(ZombieState p_state);

	void Target(Plant* p_plant);
	void TakeDamage(int p_damage);
	void StopAttacking();
};