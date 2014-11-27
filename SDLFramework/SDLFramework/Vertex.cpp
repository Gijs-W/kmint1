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
	m_GameEntities = new vector <IGameEntity*>;
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


	//Draw images next to eachother:
	int entityCount = m_GameEntities->size();
	int imageWidth = 32;
	int totalSize = entityCount * imageWidth;
	int currentCount = 0;
	for (IGameEntity* entity : *m_GameEntities){
		int addToXPosition = (entityCount > 1) ? (currentCount * imageWidth) - (totalSize / 2) + (imageWidth/2) : 0;
		entity->SetOffset(this->mX + addToXPosition, this->mY);
		entity->Draw();
		currentCount++;
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

void Vertex::addGameObject(IGameEntity* gameObject){
	m_GameEntities->push_back(gameObject);
}
IGameEntity* Vertex::takeGameObject(eGameEntity entityEnum){

	IGameEntity* result = nullptr;

	for (IGameEntity* entity : *m_GameEntities){
		if (entity->getEnum() == entityEnum){
			result = entity;
			break;
		}
	}
	//delete from vector:
	if (result != nullptr){
		m_GameEntities->erase(std::remove(m_GameEntities->begin(), m_GameEntities->end(), result), m_GameEntities->end());
	}

	return result;
}

Vertex::~Vertex()
{
	//todo: delete list 

}
