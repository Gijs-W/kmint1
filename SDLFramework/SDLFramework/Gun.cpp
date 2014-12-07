#include "Gun.h"


Gun::Gun(Graph* graph)
{
	m_Enum = eGameEntity::eGun;
	m_Graph = graph;
}

void Gun::Update(float dt){

}

void Gun::setRoute(eGameEntity source, eGameEntity target){
	m_Route = m_Graph->getRoute(source, target);
}
Gun::~Gun()
{
}
