#pragma once
#include "IGameObject.h"
#include "eGameEntity.h"
#include <list>

class Graph;
class Vertex;
class IGameEntity : public IGameObject
{
protected:
	eGameEntity m_Enum;
	
	Graph* m_Graph;
public:
	std::list<Vertex*> m_Route;
	IGameEntity(){};
	eGameEntity getEnum(){ return m_Enum; };
	virtual void Update(float deltaTime) = 0;
	virtual void setRoute(eGameEntity source, eGameEntity target) = 0;
	virtual ~IGameEntity(){};

	Graph* getGraph() { return m_Graph; }

	virtual void entityMovedNotification(eGameEntity entity) {};
	void clearRoute() { m_Route.clear();  }
	bool m_hasPill = false;
};

