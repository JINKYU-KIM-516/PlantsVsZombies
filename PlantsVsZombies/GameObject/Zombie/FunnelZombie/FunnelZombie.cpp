#include "FunnelZombie.h"

//protected
void FunnelZombie::CheckState()
{
	if (m_hp < 100)
	{
		m_basicImagePath = ZOMBIE_IMAGEPATH;
		/*
		wstring tempStr = m_basicImagePath;
		tempStr.replace(tempStr.length() - 4, 4, L"_Frozen.bmp");
		m_frozenImagePath = tempStr;
		*/
		m_frozenImagePath = ZOMBIE_FROZEN_IMAGEPATH;
		if (m_state == ZOMBIE_STATE_FROZEN)
			SetImage(m_frozenImagePath);
		else
			SetImage(m_basicImagePath);
		//Frozen상태가 되는 동시에 고깔이 벗겨지면 비트맵을 로딩 오류 남
		//근데 보면 Frozen 일반 좀비가 되고 나서 오류가 남
		//?????
	}
	if (m_frozenDuration.HasElapsed())
		ResetState();
}

//public
FunnelZombie::FunnelZombie()
	:BaseZombie(FUNNEL_ZOMBIE_HEALTHPOINT, ZOMBIE_ATTACKPOWER, ZOMBIE_ATTACKSPEED, ZOMBIE_MOVESPEED, FUNNEL_ZOMBIE_IMAGEPATH, FUNNEL_ZOMBIE_FROZEN_IMAGEPATH)
{

}