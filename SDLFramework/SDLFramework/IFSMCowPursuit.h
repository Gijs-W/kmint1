#pragma once
#include "IFSMCow.h"

class IFSMCowPursuit :
	public IFSMCow
{
public:
	IFSMCowPursuit();
	void Calculate(MovingEntity* entity, Instance* instance);
	virtual ~IFSMCowPursuit();
};

