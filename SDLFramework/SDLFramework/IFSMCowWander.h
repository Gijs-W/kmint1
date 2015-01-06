#pragma once
#include "IFSMCow.h"

class IFSMCowWander :
	public IFSMCow
{
public:
	IFSMCowWander();
	void Calculate(MovingEntity* entity, Instance* instance);
	virtual ~IFSMCowWander();
};

