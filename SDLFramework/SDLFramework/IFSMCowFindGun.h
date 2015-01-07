#pragma once
#include "IFSMCow.h"
class IFSMCowFindGun :
	public IFSMCow
{
public:
	IFSMCowFindGun();
	void Calculate(MovingEntity* entity, Instance* instance);
	~IFSMCowFindGun();
};

