#pragma once
#include "IFSMCow.h"
class IFSMCowPillFound :
	public IFSMCow
{
public:
	IFSMCowPillFound();
	void Calculate(MovingEntity* entity, Instance* instance);
	int CatchPoints(Instance* instance);
	bool ShouldResetState();
	virtual ~IFSMCowPillFound();
};

