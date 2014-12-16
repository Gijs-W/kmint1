#pragma once
#include "IGameEntity.h"
#include "Graph.h"
#include "HareWanderingState.h"
class IFSMHare;
class Graph;
class Rabbit : public IGameEntity
{
public:
	Rabbit(Graph* graph);
	void Update(float deltaTime);
	void setRoute(eGameEntity source, eGameEntity target);
	~Rabbit();

	void setState(IFSMHare* state) { delete m_State; m_State = state;}
	IFSMHare* m_State = new HareWanderingState(this);

};

