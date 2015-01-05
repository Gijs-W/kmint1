#pragma once
#include "IFSM.h"

#define PANNICDISTANCE 60.0f

class IFSMRabbit :
	public IFSM {

public:
	IFSMRabbit(){};
	virtual void Calculate(MovingEntity* entity, MovingEntity* other){};
	virtual ~IFSMRabbit(){};
};