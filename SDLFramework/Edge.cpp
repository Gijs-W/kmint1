#include "Edge.h"


Edge::Edge(Vertex* source, Vertex* destination, int distance)
{
	m_Source = source;
	m_Destination = destination;
	m_Distance = distance;
}

Vertex* Edge::getDestination(){
	return m_Destination;
}

Vertex* Edge::getSource(){
	return m_Source;
}

int Edge::getDistance(){
	return m_Distance;
}

Edge::~Edge()
{
	delete m_Source;
	delete m_Destination;
}

