#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex()
{
	m_Edges = new vector <Edge*>;
}


void  Vertex::ConnectTo(Vertex* vertex, int distance){
	Edge* edge = new Edge(this, vertex, distance);

	if (std::find(m_Edges->begin(), m_Edges->end(), vertex) == m_Edges->end()) {
		m_Edges->push_back(edge);
	}
}

vector<Edge*>* Vertex::getEdges(){
	return m_Edges;
}

Vertex::~Vertex()
{
	//todo: delete list -> doen we wss in graph klasse
}
