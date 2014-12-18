#include "ChaseRabbitState.h"
#include "WanderingState.h"
#include "Cow.h"
#include "Graph.h"
#include "CowSleepState.h"
#include "Rabbit.h"
ChaseRabbitState::ChaseRabbitState(Cow* cow) {
	m_Cow = cow;
	generateRoute();
}


void ChaseRabbitState::generateRoute() {
	m_Cow->setRoute(eCow, eRabbit);
}

void ChaseRabbitState::nextVertex(Vertex* target) {
	if (target->getGameObject(eRabbit) != nullptr && containsSelf(target)) {
		
		if (target->getGameObject(eRabbit)->m_hasPill) {
			printf("Cow - Going to sleep mode!\n");
			m_Cow->getGraph()->respawn(eCow);
			m_Cow->m_State = new CowSleepState(m_Cow);

			Rabbit* rabbit = (Rabbit*)target->getGameObject(eRabbit);
			rabbit->setState(new HareWanderingState(rabbit));
			rabbit->m_hasPill = false;
		}
		else {
			printf("Cow - Rabbit caught!\n");

			Rabbit* rabbit = (Rabbit*)target->getGameObject(eRabbit);
			rabbit->setState(new HareWanderingState(rabbit));
			m_Cow->getGraph()->respawn(eRabbit);
		}
		
	}

}
