#include "Cow.h"

Cow::Cow(Graph* graph)
{
	m_Enum = eGameEntity::eCow;
	m_Graph = graph;

	
}

void Cow::Update(float dt){

	if (m_Route.size() > 1){
		Vertex* target = m_Route.front();
		m_Route.pop_front();
		m_Graph->moveGameObject(target, eCow);
	}
	
	else if (m_Route.size() == 1){
		Vertex* target = m_Route.front();
		m_Route.pop_front();

		m_Graph->moveGameObject(target, eCow);

		m_Graph->ReShuffleAllExcept(eCow);
		m_State->Finished(this);
		m_State->Handle(this);
		SetTexture(m_Graph->m_application->LoadTexture(m_State->GetTexturePath()));
	}
	
	else {
		m_State->Handle(this);
	}
}

void Cow::setRoute(eGameEntity source, eGameEntity target){
	m_Route = m_Graph->getRoute(source, target);
}


Cow::~Cow()
{
}
