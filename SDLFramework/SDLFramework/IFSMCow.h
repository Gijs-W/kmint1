#pragma once
#include "IFSM.h"

class IFSMCow :
	public IFSM {

public:
	IFSMCow(){};
	virtual void Calculate(MovingEntity* entity, Instance* instance){};
	virtual int CatchPoints(Instance* instance){ return 10; };
	virtual ~IFSMCow(){};
};