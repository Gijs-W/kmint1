#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex()
{
	m_Edges = new vector <Edge*>;
}

void Vertex::Update(float dt){

	if (m_GameObject != nullptr){
		m_GameObject->SetOffset(this->mX, this->mY);
		m_GameObject->Draw();
	}
}


void  Vertex::ConnectTo(Vertex* vertex, int distance){
	
	bool found = false;
	for(Edge* edge : *m_Edges){
		if (edge->getSource() == vertex){
			found = true;
			break;
		}
	}

	if (!found){
		Edge* edge = new Edge(this, vertex, distance);
		m_Edges->push_back(edge);
	}
	
}

vector<Edge*>* Vertex::getEdges(){
	return m_Edges;
}

void Vertex::setGameObject(IGameObject* gameObject){
	if (gameObject != nullptr){
		//todo: Error? Delete?
	}
	m_GameObject = gameObject;
}
IGameObject* Vertex::takeGameObject(){
	IGameObject* temp = m_GameObject;
	m_GameObject = nullptr;
	return temp;
}

Vertex::~Vertex()
{
	//todo: delete list -> doen we wss in graph klasse
	delete m_GameObject;
}
