#pragma once
#include "IGameEntity.h"
#include "Graph.h"

class Rabbit : public IGameEntity
{
public:
	Rabbit(Graph* graph);
	void Update(float deltaTime);
	void setRoute(eGameEntity source, eGameEntity target);
	~Rabbit();
};

