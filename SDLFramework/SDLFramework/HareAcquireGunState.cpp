#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareAcquireGunState.h"
#include "HareChaseCowState.h"
HareAcquireGunState::HareAcquireGunState(Rabbit* rabbit)  {
	m_Rabbit = rabbit;
	generateRoute();
}

void HareAcquireGunState::generateRoute() {
	m_Rabbit->setRoute(eRabbit, eGun);
}

void HareAcquireGunState::nextVertex(Vertex* target) {

	if (target->getGameObject(eGun) != nullptr) {
		printf("Hare - Gun found!\n");
	}

}