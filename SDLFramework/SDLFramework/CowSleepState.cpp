#include "CowSleepState.h"
#include "ChaseRabbitState.h"
#include "Cow.h"
#include "Graph.h"


void CowSleepState::Handle(Cow* cow) {
	if (sleepRounds > 5) {
		delete cow->m_State;
		cow->m_State = new ChaseRabbitState;
	}
	++sleepRounds;
}

void CowSleepState::Finished(Cow* cow) {

}

std::string CowSleepState::GetTexturePath() {
	return "cow-hulk.png";
}