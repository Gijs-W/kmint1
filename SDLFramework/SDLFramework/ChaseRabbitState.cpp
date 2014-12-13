#include "ChaseRabbitState.h"
#include "WanderingState.h"
#include "Cow.h"
#include "Graph.h"
#include "CowSleepState.h"

void ChaseRabbitState::Handle(Cow* cow) {
	cow->setRoute(eCow, eRabbit);
}

void ChaseRabbitState::Finished(Cow* cow) {
	printf("Rabbit caught\n");

 	if (cow->getGraph()->m_phoneBook.at(eRabbit)->getGameObject(eRabbit)->m_hasPill) {
		delete cow->m_State;
		cow->m_State = new CowSleepState;
		cow->clearRoute();
		cow->getGraph()->respawn(eCow);
		cow->getGraph()->m_phoneBook.at(eRabbit)->getGameObject(eRabbit)->m_hasPill = false;
	}
	else {
		cow->clearRoute();
		cow->getGraph()->respawn(eRabbit);
		cow->getGraph()->respawn(eCow);
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