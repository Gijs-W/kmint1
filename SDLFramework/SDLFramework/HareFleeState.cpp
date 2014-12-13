#include "HareFleeState.h"
#include "HareAcquireGunState.h"
#include "HareAcquirePillState.h"
#include "Graph.h"
#include "Edge.h"
#include <time.h>
#include "Rabbit.h"
void HareFleeState::Handle(Rabbit* rabbit){

	std::vector<Edge*>* edges = rabbit->getGraph()->m_phoneBook.at(eRabbit)->getEdges();

	std::vector<Vertex*> escapeRoute;

	Vertex* cow = rabbit->getGraph()->m_phoneBook.at(eCow);

	for (auto &edge : *edges) {
		Vertex* vertex = edge->getDestination();

		if (vertex != cow) {
			escapeRoute.push_back(vertex);
		}

	}

	if (escapeRoute.size() >= 1) {
		
		Vertex* escapeVertex = escapeRoute.at(rand() % (escapeRoute.size()) );
		rabbit->getGraph()->moveGameObject(escapeVertex, eRabbit);

		delete rabbit->m_State;

		int dice = rand() % 6;
		if (dice > 3) {
			rabbit->m_State = new HareAcquirePillState;
		}
		else {
			rabbit->m_State = new HareWanderingState;
		}
	//	rabbit->m_State->Handle(rabbit);
	}
}

void HareFleeState::Finished(Rabbit* rabbit) {
}