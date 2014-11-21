#include "Vertex.h"
#include "Edge.h"
#include <string>
#include <algorithm>

bool sortByDistance(Edge *lhs, Edge *rhs) { //todo: give this method a proper position in the code
	return lhs->getDistance() < rhs->getDistance();
}

Vertex::Vertex()
{
	m_Edges = new vector <Edge*>;
}

void Vertex::Update(float dt){

}

void Vertex::Draw()
{
	if (!mIsActive)
		return;

	if (mWidth == 0 || mHeight == 0)
		mApplication->DrawTexture(mTexture, mX, mY);
	else
		mApplication->DrawTexture(mTexture, mX, mY, mWidth, mHeight);


	if (m_GameObject != nullptr){
		m_GameObject->SetOffset(this->mX, this->mY);
		m_GameObject->Draw();
	}

	mApplication->SetColor(Color(0, 0, 0, 255));
	for (Edge* edge : *m_Edges){
		Vertex* target = edge->getDestination();
		mApplication->DrawLine(mX, mY, target->mX, target->mY);
		int x = mX / 2 + target->mX / 2;
		int y = mY / 2 + target->mY / 2;
		mApplication->DrawText(std::to_string(edge->getDistance()), x, y);
	}
	mApplication->SetColor(Color(255, 255, 255, 255));

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
	std::sort(m_Edges->begin(), m_Edges->end(), sortByDistance);
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
