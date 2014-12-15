#include "ChaseRabbitState.h"
#include "WanderingState.h"
#include "Cow.h"
#include "Graph.h"
#include "CowSleepState.h"


void ChaseRabbitState::Handle(Cow* cow) {
	cow->setRoute(eCow, eRabbit);
}

void ChaseRabbitState::Finished(Cow* cow) {
 	if (cow->getGraph()->m_phoneBook.at(eRabbit)->getGameObject(eRabbit)->m_hasPill) {
	
		printf("Cow - Hare used sleeping pill! ");
		cow->clearRoute();
		cow->getGraph()->respawn(eCow);
	
	//	delete cow->m_State; MemLeak! > Causing memory corruption D:
		cow->m_State = new CowSleepState;
	}
	else {
		printf("Cow - Rabbit caught\n");
		cow->clearRoute();
		cow->getGraph()->respawn(eRabbit);
	}
}

std::string ChaseRabbitState::GetTexturePath() {
	return "cow-red.png";
}

void ChaseRabbitState::entityMovedNotification(Cow *cow, eGameEntity entity) {
	if (entity == eRabbit) {
		cow->setRoute(eCow, eRabbit);
	}
}