#include "CowStartState.h"
#include "Cow.h"

CowStartState::CowStartState(Cow* cow) {
	m_Cow = cow;
}
void CowStartState::generateRoute() {

	m_Cow->m_State = new ChaseRabbitState(m_Cow);
}