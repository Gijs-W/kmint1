#pragma once
#include <vector>
#include "IGameObject.h"

using std::vector;

class Edge;

class Vertex: public IGameObject
{
private:
	vector<Edge*>* m_Edges;
	IGameObject* m_GameObject;
	IGameObject* m_OldObject = nullptr; // zodat we even een game object aan de kant kunnen schuiven
public:
	Vertex();
	void Update(float dt);

	void ConnectTo(Vertex* vertex, int distance);
	vector<Edge*>* getEdges();
	void setGameObject(IGameObject* gameObject);
	IGameObject* takeGameObject();

	void Draw();

	Vertex* m_VisitedBy = nullptr;
	int m_MinDistance;
	int m_GuessedTotalDistance;

	~Vertex();
};

