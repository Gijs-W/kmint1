#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareChaseCowState.h"
#include "HareWanderingState.h"
void HareChaseCowState::Handle(Rabbit* rabbit){
	rabbit->setRoute(eRabbit, eCow);


}

void HareChaseCowState::Finished(Rabbit* rabbit) {
	printf("Cow caught!\n");
	rabbit->getGraph()->respawn(eCow);
	delete rabbit->m_State;
	rabbit->m_State = new HareWanderingState;

}