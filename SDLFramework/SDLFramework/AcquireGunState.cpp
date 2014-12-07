#include "AcquireGunState.h"
#include "ChaseRabbitState.h"
#include "Cow.h"
#include "Graph.h"


void AcquireGunState::Handle(Cow* cow) {
	cow->setRoute(eCow, eGun);
}

void AcquireGunState::Finished(Cow* cow) {
	printf("Gun found\n");
	delete cow->m_State;
	cow->m_State = new ChaseRabbitState;
}

std::string AcquireGunState::GetTexturePath() {
	return "cow-hulk.png";
}