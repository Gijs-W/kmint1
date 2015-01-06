#pragma once
#include "IFSMRabbit.h"

class IFSMRabbitChase :
	public IFSMRabbit
{
public:
	IFSMRabbitChase();
	void Calculate(MovingEntity* entity, Instance* instance);
	virtual ~IFSMRabbitChase();
};

