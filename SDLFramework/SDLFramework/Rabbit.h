#pragma once
#include "MovingEntity.h"
#include "Game.h"

class Rabbit :
	public MovingEntity
{
private:
public:
	Rabbit();
	void Update(Game* game, float deltatime);
	~Rabbit();
};

