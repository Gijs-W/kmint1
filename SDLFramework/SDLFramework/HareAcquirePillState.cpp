#include "Graph.h"
#include "Edge.h"
#include "Rabbit.h"
#include "HareAcquirePillState.h"
#include "HareWanderingStateGreen.h"
void HareAcquirePillState::Handle(Rabbit* rabbit){
	rabbit->setRoute(eRabbit, ePill);

	printf("HareAcquirePillState\n");
}

void HareAcquirePillState::Finished(Rabbit* rabbit) {
	printf("Pill caught\n");
	delete rabbit->m_State;
	rabbit->m_hasPill = true;
	rabbit->m_State = new HareWanderingStateGreen;

}