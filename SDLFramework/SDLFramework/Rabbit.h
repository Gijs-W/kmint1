#pragma once
#include "IGameEntity.h"

class Rabbit : public IGameEntity
{
public:
	Rabbit();
	void Update(float deltaTime);
	~Rabbit();
};

