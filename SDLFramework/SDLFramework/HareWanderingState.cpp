#include "HareWanderingState.h"
#include "HareAcquirePillState.h"
#include "HareFleeState.h"
#include "Graph.h"
#include "Edge.h"
#include <time.h>
#include "Rabbit.h"
HareWanderingState::HareWanderingState(Rabbit* rabbit) {
	m_Rabbit = rabbit;
}
void HareWanderingState::Handle(){

	srand(time(NULL));
	std::vector<Edge*>* edges = m_Rabbit->getGraph()->m_phoneBook.at(eRabbit)->getEdges();

	for (auto &edge : *edges) {
		Vertex* vertex = edge->getDestination();

		if (vertex == m_Rabbit->getGraph()->m_phoneBook.at(eCow)) {


			run();
			return;
		}

	}


}

void HareWanderingState::run() {
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

		Vertex* escapeVertex = escapeRoute.at(rand() % (escapeRoute.size()));
		m_Rabbit->getGraph()->moveGameObject(escapeVertex, eRabbit);

		m_Rabbit->setState(new HareAcquirePillState(m_Rabbit));


	}
}