#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareAcquireGunState.h"
#include "HareChaseCowState.h"
HareAcquireGunState::HareAcquireGunState(Rabbit* rabbit)  {
	m_Rabbit = rabbit;
	generateRoute();
	printf("HareAcquireGunState\n");
}

void HareAcquireGunState::generateRoute() {
	m_Rabbit->setRoute(eRabbit, eGun);
}

bool HareAcquireGunState::shouldMove(Vertex* target) {
	bool containsCow = (target->getGameObject(eCow) != nullptr);

	if (containsCow) {
		m_Rabbit->setState(new HareWanderingState(m_Rabbit));

	}

	return !containsCow;

}

void HareAcquireGunState::nextVertex(Vertex* target) {

	if (target->getGameObject(eGun) != nullptr && containsSelf(target)) {
		printf("Hare - Gun found!\n");
		m_Rabbit->setState(new HareChaseCowState(m_Rabbit));
	}

}