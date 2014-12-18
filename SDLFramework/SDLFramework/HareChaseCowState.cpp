#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareChaseCowState.h"
#include "HareWanderingState.h"
HareChaseCowState::HareChaseCowState(Rabbit* rabbit)  {
	m_Rabbit = rabbit;
	generateRoute();
	printf("HareChaseCowState\n");
}

void HareChaseCowState::generateRoute() {
	m_Rabbit->setRoute(eRabbit, eCow);
}

void HareChaseCowState::Handle() {
	IFSMHare::Handle();

	std::vector<Edge*>* edges = m_Rabbit->getGraph()->m_phoneBook.at(eRabbit)->getEdges();

	Vertex* cow = m_Rabbit->getGraph()->m_phoneBook.at(eCow);

	for (auto &edge : *edges) {
		Vertex* vertex = edge->getDestination();
		nextVertex(vertex);
	}
}

void HareChaseCowState::nextVertex(Vertex* target) {

	if (target->getGameObject(eCow) != nullptr && containsSelf(target)) {
		printf("Hare - Cow caught!\n");
		m_Rabbit->getGraph()->respawn(eCow);
		m_Rabbit->setState(new HareWanderingState(m_Rabbit));
	}

}