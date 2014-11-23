#pragma once
#include "IGameEntity.h"

class Gun : public IGameEntity
{
public:
	Gun();
	void Update(float deltaTime);
	~Gun();
};

