#pragma once
#include "Vertex.h"

class Edge
{
private:
	Vertex *m_Source, *m_Destination;
	int m_Distance;
public:
	Edge(Vertex* source, Vertex* destination, int distance);
	Vertex* getSource();
	Vertex* getDestination();
	~Edge();
};

