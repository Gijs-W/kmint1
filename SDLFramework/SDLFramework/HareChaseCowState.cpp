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

void HareChaseCowState::nextVertex(Vertex* target) {

	if (target->getGameObject(eCow) != nullptr) {
		printf("Hare - Cow caught!\n");
		m_Rabbit->getGraph()->respawn(eCow);
		m_Rabbit->setState(new HareWanderingState(m_Rabbit));
	}

}