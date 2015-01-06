#pragma once
#include "MovingEntity.h"
#include "Instance.h"

class Pill :
	public MovingEntity
{
public:
	Pill();
	void Update(Instance* Instance, float deltatime);
	~Pill();
};

