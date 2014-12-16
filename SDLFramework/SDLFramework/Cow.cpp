#include "Cow.h"
#include <iostream>
Cow::Cow(Graph* graph)
{
	m_Enum = eGameEntity::eCow;
	m_Graph = graph;

	
}

void Cow::Update(float dt){
	
	m_State->Handle();
	SetTexture(m_Graph->m_application->LoadTexture(m_State->GetTexturePath()));


}

void Cow::setRoute(eGameEntity source, eGameEntity target){
	m_Route = m_Graph->getRoute(source, target);
}

void Cow::entityMovedNotification(eGameEntity entity) {
//	m_State->entityMovedNotification(this, entity);
}

Cow::~Cow()
{
}
