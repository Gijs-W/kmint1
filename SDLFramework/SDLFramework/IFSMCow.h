#pragma once
#include "IFSM.h"

class IFSMCow :
	public IFSM {

public:
	IFSMCow(){};
	virtual void Calculate(MovingEntity* entity, MovingEntity* other){};
	virtual ~IFSMCow(){};
};