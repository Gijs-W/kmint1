#pragma once
#include <vector>
#include "IGameEntity.h"

using std::vector;

class Edge;

class Vertex : public IGameEntity
{
private:
	vector<Edge*>* m_Edges;
	vector<IGameEntity*>* m_GameEntities;
public:
	Vertex();
	void Update(float dt);

	void ConnectTo(Vertex* vertex, int distance);
	vector<Edge*>* getEdges();
	void addGameObject(IGameEntity* gameObject);
	IGameEntity* takeGameObject(eGameEntity entity);

	void Draw();

	Vertex* m_VisitedBy = nullptr;
	int m_MinDistance;
	int m_GuessedTotalDistance;

	~Vertex();
};

