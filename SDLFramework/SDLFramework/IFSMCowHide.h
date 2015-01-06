#pragma once
#include "IFSMCow.h"
class IFSMCowHide :
	public IFSMCow
{
public:
	IFSMCowHide();
	void Calculate(MovingEntity* entity, Instance* instance);
	virtual ~IFSMCowHide();
};

