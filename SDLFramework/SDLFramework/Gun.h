#pragma once
#include "IGameEntity.h"
#include "Graph.h"

class Gun : public IGameEntity
{
public:
	Gun(Graph* graph);
	void Update(float deltaTime);
	void setRoute(eGameEntity source, eGameEntity target);
	~Gun();
};

