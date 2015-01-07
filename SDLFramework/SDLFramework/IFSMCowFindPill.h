#pragma once
#include "IFSMCow.h"
class IFSMCowFindPill :
	public IFSMCow
{
public:
	IFSMCowFindPill();
	void Calculate(MovingEntity* entity, Instance* instance);
	virtual ~IFSMCowFindPill();
};

