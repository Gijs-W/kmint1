#pragma once
#include "IGameEntity.h"
#include "Graph.h"

class Pill : public IGameEntity
{
public:
	Pill(Graph* graph);
	void Update(float deltaTime);
	void setRoute(eGameEntity source, eGameEntity target);
	~Pill();
};

