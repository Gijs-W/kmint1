#pragma once
#include "MovingEntity.h"
#include "Instance.h"

class Rabbit :
	public MovingEntity
{
public:
	Rabbit();
	void Update(Instance* Instance, float deltatime);
	void ResetState();
	~Rabbit();
};

