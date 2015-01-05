#pragma once
#include "IFSMRabbit.h"

#define WANDERINGSPEED 0.5f

class IFSMRabbitWander :
	public IFSMRabbit
{
public:
	IFSMRabbitWander();
	void Calculate(MovingEntity* entity, MovingEntity* other);
	virtual ~IFSMRabbitWander();
};

