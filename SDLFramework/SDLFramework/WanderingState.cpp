#include "WanderingState.h"
#include "AcquireGunState.h"
#include "Cow.h";
#include "Graph.h"


void WanderingState::Handle(Cow* cow) {
	cow->setRoute(eCow, ePill);
}

void WanderingState::Finished(Cow* cow) {
	printf("Pill caught\n");
	delete cow->m_State;
	cow->m_State = new AcquireGunState;
}

std::string WanderingState::GetTexturePath() {
	return "cow-1.png";
}