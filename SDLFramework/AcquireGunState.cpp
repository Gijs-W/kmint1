#include "AcquireGunState.h"

#include "Graph.h"
void AcquireGunState::Handle(Graph* graph) {
	graph->calculateRoute(graph->m_VertexCow, graph->m_MachineGun);
}

void AcquireGunState::Finished(Graph* graph) {
	printf("Gun found\n");
	delete graph->cowState;
	graph->cowState = new ChaseRabbitState;
}

std::string AcquireGunState::GetTexturePath() {
	return "cow-hulk.png";
}