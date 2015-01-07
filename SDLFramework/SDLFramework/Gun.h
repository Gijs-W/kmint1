#pragma once
#include "MovingEntity.h"
#include "Instance.h"

class Gun :
	public MovingEntity
{
public:
	Gun();
	void Update(Instance* Instance, float deltatime);
	~Gun();
};

