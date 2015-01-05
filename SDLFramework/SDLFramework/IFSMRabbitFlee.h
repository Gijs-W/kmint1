#pragma once
#include "IFSMRabbit.h"

#define FLEESPEED 5.0f

class IFSMRabbitFlee :
	public IFSMRabbit
{
public:
	IFSMRabbitFlee();
	void Calculate(MovingEntity* entity, MovingEntity* other);
	virtual ~IFSMRabbitFlee();
};

