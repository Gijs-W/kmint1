#include "HareFleeState.h"
#include "HareAcquireGunState.h"
#include "HareAcquirePillState.h"
#include "Graph.h"
#include "Edge.h"
#include <time.h>
#include "Rabbit.h"
HareFleeState::HareFleeState(Rabbit* rabbit) {
	m_Rabbit = rabbit;
}
void HareFleeState::Handle(){
	printf("HareFleeState\n");
	std::vector<Edge*>* edges = m_Rabbit->getGraph()->m_phoneBook.at(eRabbit)->getEdges();

	std::vector<Vertex*> escapeRoute;

	Vertex* cow = m_Rabbit->getGraph()->m_phoneBook.at(eCow);

	for (auto &edge : *edges) {
		Vertex* vertex = edge->getDestination();

		if (vertex != cow) {
			escapeRoute.push_back(vertex);
		}

	}

	if (escapeRoute.size() >= 1) {
		
		Vertex* escapeVertex = escapeRoute.at(rand() % (escapeRoute.size()) );
		m_Rabbit->getGraph()->moveGameObject(escapeVertex, eRabbit);

		m_Rabbit->setState(new HareAcquirePillState(m_Rabbit));

		
	}
}