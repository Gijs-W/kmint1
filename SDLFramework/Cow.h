#pragma once
#include "IGameObject.h"

class Cow: public IGameObject
{
public:
	Cow();
	void Update(float deltaTime);
	~Cow();
};

