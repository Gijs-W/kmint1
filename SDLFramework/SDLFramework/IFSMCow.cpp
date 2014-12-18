#include "IFSMCow.h"
#include "Cow.h"
IFSMCow::IFSMCow(Cow* cow) : m_Cow{ cow } {

}

void IFSMCow::Handle() {
	generateRoute();
	if (m_Cow->m_Route.size() >= 1){
		Vertex* target = m_Cow->m_Route.front();
		m_Cow->m_Route.pop_front();
		m_Cow->getGraph()->moveGameObject(target, eCow);
		nextVertex(target);
		
	}
	else {
		generateRoute();
	}
}

bool IFSMCow::containsSelf(Vertex* vertex) {
	return vertex->getGameObject(eCow) != nullptr;
}