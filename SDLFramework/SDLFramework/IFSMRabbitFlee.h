#pragma once
#include "IFSMRabbit.h"

class IFSMRabbitFlee :
	public IFSMRabbit
{
public:
	IFSMRabbitFlee();
	void Calculate(MovingEntity* entity, Instance* instance);
	virtual ~IFSMRabbitFlee();
};

