#pragma once
#include "IFSM.h"

class IFSMRabbit :
	public IFSM {

public:
	IFSMRabbit(){};
	virtual void Calculate(MovingEntity* entity, Instance* instance){};
	virtual ~IFSMRabbit(){};
};