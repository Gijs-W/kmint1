#include "IFSMHare.h"
#include "Rabbit.h"
IFSMHare::IFSMHare(Rabbit* rabbit) : m_Rabbit{ rabbit } {
//	std::string path = m_hasPill ? "rabbit-2-sleep.png" : "rabbit-2.png";



}

void IFSMHare::Handle() {
	
	if (!m_Rabbit->m_Route.empty()){
		Vertex* target = m_Rabbit->m_Route.front();

		if (shouldMove(target)) {
			
			m_Rabbit->getGraph()->moveGameObject(target, eRabbit);
			m_Rabbit->m_Route.pop_front();
			nextVertex(target);
		}
		
	}
	else {
		generateRoute();
	}
}


bool IFSMHare::containsSelf(Vertex* vertex) {
	return vertex->getGameObject(eRabbit) != nullptr;
}