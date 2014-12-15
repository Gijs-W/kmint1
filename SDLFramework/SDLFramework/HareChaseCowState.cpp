#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareChaseCowState.h"
#include "HareWanderingState.h"
void HareChaseCowState::Handle(Rabbit* rabbit){
	rabbit->setRoute(eRabbit, eCow);
	printf("Rabbit - Chasing cow!\n");

}

void HareChaseCowState::Finished(Rabbit* rabbit) {
	printf("Rabbit - Cow caught!\n");
	rabbit->getGraph()->respawn(eCow);
	delete rabbit->m_State;
	rabbit->m_State = new HareWanderingState;

}