#include "IFSMHare.h"
#include "Rabbit.h"
IFSMHare::IFSMHare(Rabbit* rabbit) : m_Rabbit{ rabbit } {
//	std::string path = m_hasPill ? "rabbit-2-sleep.png" : "rabbit-2.png";



}

void IFSMHare::Handle() {
	
	if (m_Rabbit->m_Route.size() >= 1){
		Vertex* target = m_Rabbit->m_Route.front();
		m_Rabbit->m_Route.pop_front();
		
		nextVertex(target);
	//	m_Rabbit->getGraph()->moveGameObject(target, eRabbit);
	}
	else {
		generateRoute();
	}
}