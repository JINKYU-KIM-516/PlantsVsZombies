#pragma once
#include "../../Zombie/BaseZombie.h"
class FunnelZombie : public BaseZombie
{
protected:
	void CheckState() override;
public:
	FunnelZombie();
};