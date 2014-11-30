#include "HareWanderingState.h"
#include "Graph.h"
#include "Edge.h"
#include <time.h>
void HareWanderingState::Handle(Graph* graph) {
	srand(time(NULL));
	std::vector<Edge*>* edges = graph->m_VertexRabbit->getEdges();

	std::vector<Vertex*> escapeRoute;

	bool mark = false;
	for (auto *edge : *edges) {
		Vertex* vertex = edge->getDestination();

		if (vertex == graph->m_VertexCow) {
			mark = true;
			continue;
		}
		else {
			escapeRoute.push_back(vertex);
		}
	}

	// Geen escape routes? GG!
	if (mark && escapeRoute.size() >= 1) {
		Vertex* escapeVertex = escapeRoute.at(escapeRoute.size() -1 % rand());
		IGameEntity* rabbit = graph->m_VertexRabbit->takeGameObject(eRabbit);
		escapeVertex->addGameObject(rabbit);
		graph->m_VertexRabbit = escapeVertex;
		graph->calculateRoute(graph->m_VertexCow, graph->m_VertexRabbit);
	}


}