#include "Rabbit.h"


Rabbit::Rabbit(Graph* graph)
{
	m_Enum = eGameEntity::eRabbit;
	m_Graph = graph;
}

void Rabbit::Update(float dt){
	SetTexture(m_Graph->m_application->LoadTexture(m_State->GetTexturePath()));
	if (m_Route.size() > 1){
		Vertex* target = m_Route.front();
		m_Route.pop_front();
		m_Graph->moveGameObject(target, eRabbit);
	}

	else if (m_Route.size() == 1){
		Vertex* target = m_Route.front();
		m_Route.pop_front();

		m_Graph->moveGameObject(target, eRabbit);

		m_State->Handle(this);
		m_State->Finished(this);
	}

	else {
		m_State->Handle(this);
	}
}

void Rabbit::setRoute(eGameEntity source, eGameEntity target){
	m_Route = m_Graph->getRoute(source, target);
}

Rabbit::~Rabbit()
{
}
