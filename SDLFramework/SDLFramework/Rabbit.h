#pragma once
#include "MovingEntity.h"
#include "Instance.h"

class Rabbit :
	public MovingEntity
{
private:
public:
	Rabbit();
	void Update(Instance* Instance, float deltatime);
	void ResetState();
	~Rabbit();
};

