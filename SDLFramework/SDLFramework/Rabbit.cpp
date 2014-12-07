#include "Rabbit.h"


Rabbit::Rabbit(Graph* graph)
{
	m_Enum = eGameEntity::eRabbit;
	m_Graph = graph;
}

void Rabbit::Update(float dt){

}

void Rabbit::setRoute(eGameEntity source, eGameEntity target){
	m_Route = m_Graph->getRoute(source, target);
}

Rabbit::~Rabbit()
{
}
