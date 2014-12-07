#pragma once
#include "IGameEntity.h"
#include "Graph.h"
#include "WanderingState.h"

class IFSMCow;
class Cow: public IGameEntity
{
public:
	Cow(Graph* graph);
	void Update(float deltaTime);
	IFSMCow* m_State = new WanderingState;
	void setRoute(eGameEntity source, eGameEntity target);
	~Cow();
};

