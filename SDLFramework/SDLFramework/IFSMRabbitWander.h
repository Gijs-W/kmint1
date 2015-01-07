#pragma once
#include "IFSMRabbit.h"

class IFSMRabbitWander :
	public IFSMRabbit
{
public:
	IFSMRabbitWander();
	void Calculate(MovingEntity* entity, Instance* instance);
	virtual ~IFSMRabbitWander();
};

