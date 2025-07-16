#include "FunnelZombie.h"

//protected
void FunnelZombie::CheckState()
{
	if (m_hp < 100)
	{
		m_basicImagePath = ZOMBIE_IMAGEPATH;
		wstring tempStr = m_basicImagePath;
		tempStr.replace(tempStr.length() - 4, 4, L"_Frozen.bmp");
		m_frozenImagePath = tempStr;
		if (m_state == ZOMBIE_STATE_FROZEN)
			SetImage(m_frozenImagePath);
		else
			SetImage(m_basicImagePath);
		
	}
	if (m_frozenDuration.HasElapsed())
		ResetState();
}

//public
FunnelZombie::FunnelZombie()
	:BaseZombie(FUNNEL_ZOMBIE_HEALTHPOINT, ZOMBIE_ATTACKPOWER, ZOMBIE_ATTACKSPEED, ZOMBIE_MOVESPEED, FUNNEL_ZOMBIE_IMAGEPATH)
{

}