#include "ChaseRabbitState.h"

#include "Graph.h"
void ChaseRabbitState::Handle(Graph* graph) {
	graph->calculateRoute(graph->m_VertexCow, graph->m_VertexRabbit);
}

void ChaseRabbitState::Finished(Graph* graph) {
	printf("Rabbit caught\n");
	delete graph->cowState;
	graph->cowState = new WanderingState;
}

std::string ChaseRabbitState::GetTexturePath() {
	return "cow-red.png";
}