#pragma once
#include "IFSMCow.h"

#define PURSUITSPEED 2.0f

class IFSMCowPursuit :
	public IFSMCow
{
public:
	IFSMCowPursuit();
	void Calculate(MovingEntity* entity, MovingEntity* other);
	virtual ~IFSMCowPursuit();
};

