#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareChaseCowState.h"
#include "HareAcquireGunState.h"
void HareChaseCowState::Handle(Rabbit* rabbit){
	rabbit->setRoute(eRabbit, eCow);


}

void HareChaseCowState::Finished(Rabbit* rabbit) {
	delete rabbit->m_State;
	rabbit->m_State = new HareAcquireGunState;

}