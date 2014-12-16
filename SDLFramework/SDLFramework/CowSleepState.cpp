#include "CowSleepState.h"
#include "ChaseRabbitState.h"
#include "Cow.h"
#include "Graph.h"

CowSleepState::CowSleepState(Cow* cow) {
	m_Cow = cow;
}

void CowSleepState::generateRoute() {
	if (sleepRounds > 5) {
		m_Cow->m_State = new ChaseRabbitState(m_Cow);
	}
	++sleepRounds;
}

void CowSleepState::nextVertex(Vertex* vertex) {
 // 
}

