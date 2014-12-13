#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareAcquireGunState.h"
#include "HareChaseCowState.h"
void HareAcquireGunState::Handle(Rabbit* rabbit){
	rabbit->setRoute(eRabbit, eGun);


}

void HareAcquireGunState::Finished(Rabbit* rabbit) {
	printf("Cow caught\n");
	rabbit->getGraph()->respawn(eCow);
	delete rabbit->m_State;
	rabbit->m_State = new HareChaseCowState;

}