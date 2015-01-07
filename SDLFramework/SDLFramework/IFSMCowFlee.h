#pragma once
#include "IFSMCow.h"
class IFSMCowFlee :
	public IFSMCow
{
public:
	IFSMCowFlee();
	void Calculate(MovingEntity* entity, Instance* instance);
	virtual ~IFSMCowFlee();
};

