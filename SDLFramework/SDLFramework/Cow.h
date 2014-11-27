#pragma once
#include "IGameEntity.h"

class Cow: public IGameEntity
{
public:
	Cow();
	void Update(float deltaTime);
	~Cow();
};

