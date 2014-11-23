#include "WanderingState.h"
#include "Graph.h"
void WanderingState::Handle(Graph* graph) {
	graph->calculateRoute(graph->m_VertexCow, graph->m_Pill);
}

void WanderingState::Finished(Graph* graph) {
		printf("Pill caught\n");
		delete graph->cowState;
		graph->cowState = new AcquireGunState;
}

std::string WanderingState::GetTexturePath() {
	return "cow-1.png";
}