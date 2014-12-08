#include "HareWanderingState.h"
#include "HareFleeState.h"
#include "Graph.h"
#include "Edge.h"
#include <time.h>
#include "Rabbit.h"
void HareWanderingState::Handle(Rabbit* rabbit){

	srand(time(NULL));
	std::vector<Edge*>* edges = rabbit->getGraph()->m_phoneBook.at(eRabbit)->getEdges();

	for (auto &edge : *edges) {
		Vertex* vertex = edge->getDestination();

		if (vertex == rabbit->getGraph()->m_phoneBook.at(eCow)) {

			delete rabbit->m_State;
			rabbit->m_State = new HareFleeState;
			rabbit->m_State->Handle(rabbit);
			break;
		}

	}

}