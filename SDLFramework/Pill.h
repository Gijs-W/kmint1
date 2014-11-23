#pragma once
#include "IGameEntity.h"

class Pill : public IGameEntity
{
public:
	Pill();
	void Update(float deltaTime);
	~Pill();
};

