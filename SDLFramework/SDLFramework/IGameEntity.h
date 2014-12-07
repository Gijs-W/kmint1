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
	std::list<Vertex*> m_Route;
	Graph* m_Graph;
public:
	IGameEntity(){};
	eGameEntity getEnum(){ return m_Enum; };
	virtual void Update(float deltaTime) = 0;
	virtual void setRoute(eGameEntity source, eGameEntity target) = 0;
	virtual ~IGameEntity(){};
};

