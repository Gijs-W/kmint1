#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareAcquirePillState.h"
#include "HareWanderingState.h"

HareAcquirePillState::HareAcquirePillState(Rabbit* rabbit)  {
	m_Rabbit = rabbit;
	generateRoute();
	printf("HareAcquirePillState\n");
}

void HareAcquirePillState::generateRoute() {
	m_Rabbit->setRoute(eRabbit, ePill);
}

void HareAcquirePillState::nextVertex(Vertex* target) {

	if (target->getGameObject(ePill) != nullptr && containsSelf(target)) {
		printf("Hare -Pill found!\n");
		m_Rabbit->m_hasPill = true;
		m_Rabbit->setState(new HareWanderingState(m_Rabbit));
	}

}

bool HareAcquirePillState::shouldMove(Vertex* target) {
	bool containsCow = (target->getGameObject(eCow) != nullptr);

	if (containsCow) {
		m_Rabbit->setState(new HareWanderingState(m_Rabbit));

	}

	return !containsCow;

}
