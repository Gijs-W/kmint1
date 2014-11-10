#include "Graph.h"


Graph::Graph()
{
	m_Vertices = new vector <Vertex*>;
}

void Graph::addVertex(Vertex* vertex){
	if (std::find(m_Vertices->begin(), m_Vertices->end(), vertex) == m_Vertices->end()) {
		m_Vertices->push_back(vertex);
	}
}

Graph::~Graph()
{
}
