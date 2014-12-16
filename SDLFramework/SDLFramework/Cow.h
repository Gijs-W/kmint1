#pragma once
#include "IGameEntity.h"
#include "Graph.h"
#include "ChaseRabbitState.h"
#include "CowStartState.h"

class IFSMCow;
class Cow: public IGameEntity
{
public:
	Cow(Graph* graph);
	void Update(float deltaTime);
	IFSMCow* m_State = new CowStartState(this);
	void setRoute(eGameEntity source, eGameEntity target);
	~Cow();

	std::string getTexturePath() { return m_State->GetTexturePath();  }

	virtual void entityMovedNotification(eGameEntity entity);
};

