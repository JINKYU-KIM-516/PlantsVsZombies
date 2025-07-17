#pragma once
#include "../../Zombie/BaseZombie.h"
class FunnelZombie : public BaseZombie
{
protected:
	bool m_wearingFunnel;
	void CheckState() override;
public:
	FunnelZombie();
};