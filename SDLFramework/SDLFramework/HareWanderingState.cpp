#include "HareWanderingState.h"
#include "Graph.h"
#include "Edge.h"
void HareWanderingState::Handle(Graph* graph) {
	std::vector<Edge*>* edges = graph->m_VertexRabbit->getEdges();

	bool mark = false;
	for (auto *edge : *edges) {
		Vertex* vertex = edge->getDestination();

		if (vertex = graph->m_VertexCow) {
			mark = true;
		//	continue;
		}
		
		if (mark) {
			IGameEntity* rabbit = graph->m_VertexRabbit->takeGameObject(eRabbit);
			vertex->addGameObject(rabbit);
			graph->m_VertexRabbit = vertex;
			break;
		}

		graph->calculateRoute(graph->m_VertexCow, graph->m_VertexRabbit);


	}
}