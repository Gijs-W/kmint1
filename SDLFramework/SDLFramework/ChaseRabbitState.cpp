#include "ChaseRabbitState.h"
#include "WanderingState.h"
#include "Cow.h"
#include "Graph.h"


void ChaseRabbitState::Handle(Cow* cow) {
	cow->setRoute(eCow, eRabbit);
}

void ChaseRabbitState::Finished(Cow* cow) {
	printf("Rabbit caught\n");
	delete cow->m_State;
	cow->m_State = new WanderingState;
}

std::string ChaseRabbitState::GetTexturePath() {
	return "cow-red.png";
}