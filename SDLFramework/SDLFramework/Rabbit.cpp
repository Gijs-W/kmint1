#include "Rabbit.h"


Rabbit::Rabbit(Graph* graph)
{
	m_Enum = eGameEntity::eRabbit;
	m_Graph = graph;
}

void Rabbit::Update(float dt){
	// Ja, zou in een state moeten ofzo maar ben nog brak van gister dus dat komt later wel :3
	std::string path = m_hasPill ? "rabbit-2-sleep.png" : "rabbit-2.png";

	SetTexture(m_Graph->m_application->LoadTexture(path));
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
