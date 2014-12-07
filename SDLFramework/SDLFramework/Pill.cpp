#include "Pill.h"


Pill::Pill(Graph* graph)
{
	m_Enum = eGameEntity::ePill;
	m_Graph = graph;
}

void Pill::Update(float dt){

}

void Pill::setRoute(eGameEntity source, eGameEntity target){
	m_Route = m_Graph->getRoute(source, target);
}

Pill::~Pill()
{
}
