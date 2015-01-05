#pragma once
#include "MovingEntity.h"
#include "Game.h"

class Cow :
	public MovingEntity
{
public:
	Cow();
	void Update(Game* game, float deltatime);
	~Cow();
};

