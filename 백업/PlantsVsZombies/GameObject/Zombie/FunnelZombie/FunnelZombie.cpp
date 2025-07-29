#include "FunnelZombie.h"

//protected
/*
void FunnelZombie::CheckState()
{
	if (m_hp < 100 && m_wearingFunnel)
	{
		m_wearingFunnel = false;
		m_basicImagePath = ZOMBIE_IMAGEPATH;

		wstring tempStr = m_basicImagePath;
		tempStr.replace(tempStr.length() - 4, 4, L"_Frozen.bmp");
		m_frozenImagePath = tempStr;

		if (m_state == ZOMBIE_STATE_FROZEN)
			SetImage(ZOMBIE_FROZEN_IMAGEPATH);
		else
			SetImage(ZOMBIE_IMAGEPATH);
	}
	if (m_frozenDuration.HasElapsed())
		ResetState();
}
*/
void FunnelZombie::CheckFunnel()
{
	if (m_hp < 100 && m_wearingFunnel)
	{
		m_wearingFunnel = false;
		m_basicImagePath = ZOMBIE_IMAGEPATH;

		wstring tempStr = m_basicImagePath;
		tempStr.replace(tempStr.length() - 4, 4, L"_Frozen.bmp");
		m_frozenImagePath = tempStr;

		if (m_state == ZOMBIE_STATE_FROZEN)
			SetImage(ZOMBIE_FROZEN_IMAGEPATH);
		else
			SetImage(ZOMBIE_IMAGEPATH);
	}
}

//public
FunnelZombie::FunnelZombie()
	:BaseZombie(FUNNEL_ZOMBIE_HEALTHPOINT, FUNNEL_ZOMBIE_ATTACKPOWER, FUNNEL_ZOMBIE_ATTACKSPEED, FUNNEL_ZOMBIE_MOVESPEED, FUNNEL_ZOMBIE_IMAGEPATH, FUNNEL_ZOMBIE_FROZEN_IMAGEPATH)
{
	m_wearingFunnel = true;
}

void FunnelZombie::Update()
{
	CheckAlive();
	CheckFunnel();
	CheckState();
	if (!m_isAttacking)
		Move();
	else
		Attack();
}
